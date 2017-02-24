/**
 * @file UserValueId.h
 * @author Thomas Saquet, Florent Poinsaut
 * @date 
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Alert - Dbo is the database objects library, part of the Alert software
 * Copyright (C) 2013-2017
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 * 
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
