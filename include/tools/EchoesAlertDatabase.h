/* 
 * Header of Echoes Alert Database
 * @author ECHOES Technologies (TSA)
 * @date 17/08/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ECHOESALERTDATABASE_H
#define	ECHOESALERTDATABASE_H

#include <boost/foreach.hpp>

#include <Wt/Auth/AbstractUserDatabase>
#include <Wt/Auth/Dbo/AuthInfo>
#include <Wt/WLogger>

#include "user/User.h"

namespace Echoes
{
  namespace Dbo
  {

    /*! \class WtUserDatabase Wt/Auth/Dbo/UserDatabase
     *  \brief A default implementation for a authentication data in %Wt::%Dbo.
     * 
     * This is a template class, and needs as parameter the Dbo type which
     * models holds the authentication information. A suitable
     * implementation, which stores authentication information outside the
     * "user" class, is provided by AuthInfo.
     *
     * \sa WtUserDatabase
     *
     * \ingroup auth
     */

    typedef Wt::Auth::User WtUser;
    typedef Wt::Auth::Token Token;
    typedef Wt::Auth::PasswordHash PasswordHash;
    typedef Wt::Dbo::Transaction Transaction;

    template <class DboType, class CustomUser>
    class EchoesAlertDatabase : public Wt::Auth::AbstractUserDatabase {
        typedef typename DboType::AuthTokenType AuthTokenType;
        typedef Wt::Dbo::collection< Wt::Dbo::ptr<AuthTokenType> > AuthTokens;

        typedef typename DboType::AuthIdentityType AuthIdentityType;
        typedef Wt::Dbo::collection< Wt::Dbo::ptr<AuthIdentityType> > AuthIdentities;

    public:

        /*! \brief Constructor
         */
        EchoesAlertDatabase(Wt::Dbo::Session& session)
        : session_(session),
        maxAuthTokensPerUser_(50) {
        }

        virtual Transaction *startTransaction() {
            return new TransactionImpl(session_);
        }

        /*! \brief Returns the %Dbo user type corresponding to an Auth::User.
         */
        Wt::Dbo::ptr<DboType> find(const WtUser& user) const {
            getUser(user.id());
            return user_;
        }

        /*! \brief Returns the Auth::User corresponding to a %Dbo user.
         */
        WtUser find(const Wt::Dbo::ptr<DboType> user) const {
            setUser(user);
            return WtUser(boost::lexical_cast<std::string > (user_->id()), *this);
        }

        virtual WtUser findWithId(const std::string& id) const {
            getUser(id);

            if (user_)
                return WtUser(id, *this);
            else
                return WtUser();
        }

        virtual WtUser findWithIdentity(const std::string& provider,
                const Wt::WString& identity) const {
            if (userProvider_ != provider || userIdentity_ != identity) {
                Wt::Dbo::Transaction t(session_);
                setUser(session_.query< Wt::Dbo::ptr<DboType> >
                        (std::string() +
                        "select u from \"" + session_.tableName<DboType > () + "\" u "
                        "join \"" + session_.tableName<AuthIdentityType > () + "\" i "
                        "on u.id = i." + session_.tableName<DboType > () + "_id")
                        .where("i.provider = ?").bind(provider)
                        .where("i.identity = ?").bind(identity));
                t.commit();
            }

            if (user_) {
                userProvider_ = provider;
                userIdentity_ = identity;
                return WtUser(boost::lexical_cast<std::string > (user_.id()), *this);
            } else
                return WtUser();
        }

        virtual Wt::WString identity(const WtUser& user,
                const std::string& provider) const {
            WithUser find(*this, user);

            AuthIdentities c
                    = user_->authIdentities().find().where("provider = ?").bind(provider);

            typename AuthIdentities::const_iterator i = c.begin();

            if (i != c.end())
                return (*i)->identity();
            else
                return Wt::WString::Empty;
        }

        virtual void removeIdentity(const WtUser& user,
                const std::string& provider) {
            Wt::Dbo::Transaction t(session_);

            session_.execute
                    (std::string() +
                    "delete from \"" + session_.tableName<AuthIdentityType > () +
                    "\" where " + session_.tableName<DboType > () + "_id = ?"
                    " and provider = ?").bind(user.id()).bind(provider);

            t.commit();
        }

        virtual WtUser registerNew() {
            DboType *user = new DboType();
            CustomUser *customUser = new CustomUser();
            user->setUser(session_.add(customUser));
            setUser(session_.add(user));
            user_.flush();
            return WtUser(boost::lexical_cast<std::string > (user_.id()), *this);
        }

        virtual void deleteUser(const WtUser& user) {
            Wt::Dbo::Transaction t(session_);
            Wt::Dbo::ptr<DboType> u = find(user);
            u.remove();
            t.commit();
        }

        virtual WtUser::Status status(const WtUser& user) const {
            WithUser find(*this, user);
            return user_->status();
        }

        virtual void setPassword(const WtUser& user, const PasswordHash& password) {
            WithUser find(*this, user);
            user_.modify()->setPassword(password.value(),
                    password.function(),
                    password.salt());
        }

        virtual PasswordHash password(const WtUser& user) const {
            WithUser find(*this, user);
            return PasswordHash(user_->passwordMethod(), user_->passwordSalt(),
                    user_->passwordHash());
        }

        virtual void addIdentity(const WtUser& user, const std::string& provider,
                const Wt::WT_USTRING& identity) {
            WithUser find(*this, user);

            if (session_.find<AuthIdentityType > ()
                    .where("identity = ?").bind(identity)
                    .where("provider = ?").bind(provider).resultList().size() != 0) {
                Wt::log("error") << "cannot add identity " << provider
                        << ":'" << identity << "': already exists";
            }

            /*
             * It's okay to have more than one identity from that provider
             */
            user_.modify()->authIdentities().insert
                    (Wt::Dbo::ptr<AuthIdentityType > (new AuthIdentityType(provider,
                    identity)));
        }
        
        virtual void setIdentity(const WtUser& user, const std::string& provider,
			   const Wt::WT_USTRING& identity) {
            WithUser find(*this, user);

            AuthIdentities c
              = user_->authIdentities().find().where("provider = ?").bind(provider);

            typename AuthIdentities::const_iterator i = c.begin();

            if (i != c.end())
              i->modify()->setIdentity(identity);
            else
              user_.modify()->authIdentities().insert
            (Wt::Dbo::ptr<AuthIdentityType>(new AuthIdentityType(provider,
                                         identity)));
        }

        virtual bool setEmail(const WtUser& user, const std::string& address) {
            WithUser find(*this, user);

            if (session_.find<DboType > ().where("email = ?")
                    .bind(address).resultList().size() != 0)
                return false;

            user_.modify()->setEmail(address);

            return true;
        }

        virtual std::string email(const WtUser& user) const {
            WithUser find(*this, user);
            return user_->email();
        }

        virtual void setUnverifiedEmail(const WtUser& user,
                const std::string& address) {
            WithUser find(*this, user);
            user_.modify()->setUnverifiedEmail(address);
        }

        virtual std::string unverifiedEmail(const WtUser& user) const {
            WithUser find(*this, user);
            return user_->unverifiedEmail();
        }

        virtual WtUser findWithEmail(const std::string& address) const {
            Wt::Dbo::Transaction t(session_);
            setUser(session_.find<DboType > ().where("email = ?").bind(address));
            t.commit();

            if (user_)
                return WtUser(boost::lexical_cast<std::string > (user_.id()), *this);
            else
                return WtUser();
        }

        virtual void setEmailToken(const WtUser& user, const Token& token,
                WtUser::EmailTokenRole role) {
            WithUser find(*this, user);
            user_.modify()->setEmailToken(token.hash(), token.expirationTime(), role);
        }

        virtual Token emailToken(const WtUser& user) const {
            WithUser find(*this, user);
            return Token(user_->emailToken(), user_->emailTokenExpires());
        }

        virtual WtUser::EmailTokenRole emailTokenRole(const WtUser& user) const {
            WithUser find(*this, user);
            return user_->emailTokenRole();
        }

        virtual WtUser findWithEmailToken(const std::string& hash) const {
            Wt::Dbo::Transaction t(session_);
            setUser(session_.find<DboType > ()
                    .where("email_token = ?").bind(hash));
            t.commit();

            if (user_)
                return WtUser(boost::lexical_cast<std::string > (user_.id()), *this);
            else
                return WtUser();
        }

        virtual void addAuthToken(const WtUser& user, const Token& token) {
            WithUser find(*this, user);

            /*
             * This should be statistically very unlikely but also a big
             * security problem if we do not detect it ...
             */
            if (session_.find<AuthTokenType > ().where("value = ?")
                    .bind(token.hash())
                    .resultList().size() > 0)
                throw std::runtime_error("Token hash collision");

            /*
             * Prevent a user from piling up the database with tokens
             */
            size_t tokens_number = user_->authTokens().size();
            if (tokens_number >= maxAuthTokensPerUser_) {
              // remove so many tokens, that their number
              // would be (maxAuthTokensPerUser_ - 1)
              int tokens_to_remove = tokens_number - (maxAuthTokensPerUser_ - 1);
              // remove the first token(s) to expire
              Wt::Dbo::collection<Wt::Dbo::ptr<AuthTokenType> > earliest_tokens =
                user_->authTokens().find().orderBy("expires").limit(tokens_to_remove);
              std::vector<Wt::Dbo::ptr<AuthTokenType> > earliest_tokens_v(
                earliest_tokens.begin(), earliest_tokens.end());
              BOOST_FOREACH (Wt::Dbo::ptr<AuthTokenType> token, earliest_tokens_v) {
                token.remove();
              }
            }
            
            user_.modify()->authTokens().insert
                    (Wt::Dbo::ptr<AuthTokenType >
                    (new AuthTokenType(token.hash(), token.expirationTime())));
        }

        virtual void removeAuthToken(const WtUser& user, const std::string& hash) {
            WithUser find(*this, user);

            for (typename AuthTokens::const_iterator i = user_->authTokens().begin();
                    i != user_->authTokens().end(); ++i) {
                Wt::Dbo::ptr<AuthTokenType> t = *i;
                if (t->value() == hash) {
                    t.remove();
                    break;
                }
            }
        }
        
        virtual int updateAuthToken(const WtUser& user, const std::string& hash,
			      const std::string& newHash) {
            WithUser find(*this, user);

            for (typename AuthTokens::const_iterator i = user_->authTokens().begin();
             i != user_->authTokens().end(); ++i) 
            {
                Wt::Dbo::ptr<AuthTokenType> t = *i;
                if (t->value() == hash) {
                    t.modify()->setValue(newHash);
                    return std::max(0, Wt::WDateTime::currentDateTime().secsTo(t->expires()));
                }
            }

            return 0;
        }

        virtual WtUser findWithAuthToken(const std::string& hash) const {
            Wt::Dbo::Transaction t(session_);
            setUser(session_.query< Wt::Dbo::ptr<DboType> >
                    (std::string() +
                    "select u from \"" + session_.tableName<DboType > () + "\" u "
                    "join \"" + session_.tableName<AuthTokenType > () + "\" t "
                    "on u.id = t." + session_.tableName<DboType > () + "_id")
                    .where("t.value = ?").bind(hash)
                    .where("t.expires > ?").bind(Wt::WDateTime::currentDateTime()));
            t.commit();

            if (user_)
                return WtUser(boost::lexical_cast<std::string > (user_.id()), *this);
            else
                return WtUser();
        }

        virtual void setFailedLoginAttempts(const WtUser& user, int count) {
            WithUser find(*this, user);
            return user_.modify()->setFailedLoginAttempts(count);
        }

        virtual int failedLoginAttempts(const WtUser& user) const {
            WithUser find(*this, user);
            return user_->failedLoginAttempts();
        }

        virtual void setLastLoginAttempt(const WtUser& user, const Wt::WDateTime& t) {
            WithUser find(*this, user);
            return user_.modify()->setLastLoginAttempt(t);
        }

        virtual Wt::WDateTime lastLoginAttempt(const WtUser& user) const {
            WithUser find(*this, user);
            return user_->lastLoginAttempt();
        }
        
        Wt::Dbo::Session& session_;
    private:

        mutable Wt::Dbo::ptr<DboType> user_;
        mutable std::string userProvider_;
        mutable Wt::WString userIdentity_;
        unsigned maxAuthTokensPerUser_;

        struct WithUser {

            WithUser(const EchoesAlertDatabase<DboType, CustomUser>& self, const WtUser & user)
            : transaction(self.session_) {
                self.getUser(user.id());
                if (!self.user_)
                    throw Wt::WException("Invalid user");
            }

            ~WithUser() {
                transaction.commit();
            }

            Wt::Dbo::Transaction transaction;
        };

        void getUser(const std::string& id) const {
            if (!user_ || boost::lexical_cast<std::string > (user_.id()) != id) {
                Wt::Dbo::Transaction t(session_);
                setUser(session_.load<DboType > (boost::lexical_cast<long long>(id)));
                t.commit();
            }
        }

        void setUser(Wt::Dbo::ptr<DboType> user) const {
            user_ = user;
            userProvider_.clear();
            userIdentity_ = Wt::WString::Empty;
        }

        struct TransactionImpl : public Transaction, public Wt::Dbo::Transaction {

            TransactionImpl(Wt::Dbo::Session & session)
            : Wt::Dbo::Transaction(session) {
            }

            virtual ~TransactionImpl() {
            }

            virtual void commit() {
                Wt::Dbo::Transaction::commit();
            }

            virtual void rollback() {
                Wt::Dbo::Transaction::rollback();
            }
        };
    };
  }
}

#endif	/* ECHOESALERTDATABASE_H */

