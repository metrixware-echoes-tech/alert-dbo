/* 
 * File:   UserValueId.h
 * Author: tom
 *
 * Created on 25 avril 2012, 17:33
 */

#ifndef USERVALUEID_H
#define	USERVALUEID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    class User;
    class UserField;
    class UserValue;

    struct UserValueId {
        Wt::Dbo::ptr<User> user;
        Wt::Dbo::ptr<UserField> userField;

        UserValueId(Wt::Dbo::ptr<User> u, Wt::Dbo::ptr<UserField> uf)
        : user(u), userField(uf) {
        }

        UserValueId() {
        }

        bool operator==(const UserValueId& other) const {
            return user == other.user && userField == other.userField;
        }

        bool operator<(const UserValueId& other) const {
            if (user < other.user)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const UserValueId& uv) {
        return o << "\n    {"
                << "\n        \"user_id\": " << uv.user.id()
                << ",\n        \"user_field_id\": " << uv.userField.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::UserValueId& uvid,
            const std::string& name, int size = -1) {
        Wt::Dbo::belongsTo(a, uvid.user, TRIGRAM_USER_VALUE SEP TRIGRAM_USER);
        Wt::Dbo::belongsTo(a, uvid.userField, TRIGRAM_USER_VALUE SEP TRIGRAM_USER_FIELD);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::UserValue> : public dbo_default_traits {
        typedef Echoes::Dbo::UserValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::UserValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* USERVALUEID_H */
