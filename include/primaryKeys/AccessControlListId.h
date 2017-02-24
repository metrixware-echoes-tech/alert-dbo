/**
 * @file AccessControlListId.h
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

#ifndef ACCESSCONTROLLISTID_H
#define	ACCESSCONTROLLISTID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {


    class Space;
    class UserRight;
    class UserProfile;

    struct AccessControlListId {
        Wt::Dbo::ptr<Space> space;
        Wt::Dbo::ptr<UserProfile> userProfile;
        Wt::Dbo::ptr<UserRight> userRight;

        AccessControlListId(Wt::Dbo::ptr<Space> space, Wt::Dbo::ptr<UserProfile> userProfile, Wt::Dbo::ptr<UserRight> userRight)
        : space(space), userProfile(userProfile), userRight(userRight) {
        }

        AccessControlListId() {
        }

        bool operator==(const AccessControlListId& other) const {
            return space == other.space && userProfile == other.userProfile && userRight == other.userRight;
        }

        bool operator<(const AccessControlListId& other) const {
            if (space < other.space)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const AccessControlListId& pk) {
        return o << "\n    {"
                << "\n        \"space_id\": " << pk.space.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::AccessControlListId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.space, "SPA_ID");
        field(a, spvid.userProfile, "UPR_ID");
        field(a, spvid.userRight, "URI_ID");
    }

    template<>
    struct dbo_traits<Echoes::Dbo::AccessControlList> : public dbo_default_traits {
        typedef Echoes::Dbo::AccessControlListId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::AccessControlListId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}


#endif	/* ACCESSCONTROLLISTID_H */
