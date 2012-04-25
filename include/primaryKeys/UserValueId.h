/* 
 * File:   UserValueId.h
 * Author: tom
 *
 * Created on 25 avril 2012, 17:33
 */

#ifndef USERVALUEID_H
#define	USERVALUEID_H

#include <Wt/Dbo/Dbo>

class User;
class UserField;
class UserValue;

struct UserValueId
{
    Wt::Dbo::ptr<User> user;
    Wt::Dbo::ptr<UserField> userField;

    UserValueId(Wt::Dbo::ptr<User> u,  Wt::Dbo::ptr<UserField> uf)
        : user(u), userField(uf) { }

    UserValueId(){ }

    bool operator== (const UserValueId& other) const {
        return user == other.user && userField == other.userField;
    }

    bool operator< (const UserValueId& other) const {
        if (user < other.user)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const UserValueId& uv)
{
    return o << "(" << uv.user << " ; " << uv.userField << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, UserValueId& uvid,
                   const std::string& name, int size = -1)
        {
            Wt::Dbo::belongsTo(a, uvid.user, "USR_ID");
            Wt::Dbo::belongsTo(a, uvid.userField, "UFI_ID");
        }
        template<>
        struct dbo_traits<UserValue> : public dbo_default_traits
        {
            typedef UserValueId IdType;
            static IdType invalidId() { return UserValueId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* USERVALUEID_H */
