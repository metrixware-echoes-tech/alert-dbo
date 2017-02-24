/**
 * @file AlertMessageAliasInformationId.h
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

#ifndef ALERTMESSAGEALIASINFORMATIONID_H
#define	ALERTMESSAGEALIASINFORMATIONID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    struct AlertMessageAliasInformationId {
        Wt::Dbo::ptr<UserRole> userRole;
        Wt::Dbo::ptr<Information> information;
        Wt::Dbo::ptr<MediaType> mediaType;

        AlertMessageAliasInformationId(Wt::Dbo::ptr<UserRole> ptrUserRole, Wt::Dbo::ptr<Information> ptrInformation, Wt::Dbo::ptr<MediaType> ptrMediaType)
        : userRole(ptrUserRole), information(ptrInformation), mediaType(ptrMediaType) {
        }

        AlertMessageAliasInformationId() {
        }

        bool operator==(const AlertMessageAliasInformationId& other) const {
            return userRole == other.userRole && information == other.information && mediaType == other.mediaType;
        }

        bool operator<(const AlertMessageAliasInformationId& other) const {
            if ((userRole < other.userRole) || (information < other.information) || mediaType < other.mediaType)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const AlertMessageAliasInformationId& pk) {
        return o << "\n    {"
                << "\n        \"user_role_id\": " << pk.userRole.id()
                << ",\n        \"information_id\": " << pk.information.id()
                << ",\n        \"media_type_id\": " << pk.mediaType.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::AlertMessageAliasInformationId& aaiid,
            const std::string& name, int size = -1) {
        field(a, aaiid.userRole, TRIGRAM_USER_ROLE ID);
        field(a, aaiid.information, TRIGRAM_INFORMATION ID);
        field(a, aaiid.mediaType, TRIGRAM_MEDIA_TYPE ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::AlertMessageAliasInformation> : public dbo_default_traits {
        typedef Echoes::Dbo::AlertMessageAliasInformationId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::AlertMessageAliasInformationId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* ALERTMESSAGEALIASINFORMATIONID_H */
