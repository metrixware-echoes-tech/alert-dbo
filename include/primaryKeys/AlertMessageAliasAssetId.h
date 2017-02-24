/**
 * @file AlertMessageAliasAssetId.h
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

#ifndef ALERTMESSAGEALIASASSETID_H
#define	ALERTMESSAGEALIASASSETID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {
    class UserRole;
    class Asset;
    class MediaType;

    struct AlertMessageAliasAssetId {
        Wt::Dbo::ptr<UserRole> userRole;
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<MediaType> mediaType;

        AlertMessageAliasAssetId(Wt::Dbo::ptr<UserRole> ptrUserRole, Wt::Dbo::ptr<Asset> ptrAsset, Wt::Dbo::ptr<MediaType> ptrMediaType)
        : userRole(ptrUserRole), asset(ptrAsset), mediaType(ptrMediaType) {
        }

        AlertMessageAliasAssetId() {
        }

        bool operator==(const AlertMessageAliasAssetId& other) const {
            return userRole == other.userRole && asset == other.asset && mediaType == other.mediaType;
        }

        bool operator<(const AlertMessageAliasAssetId& other) const {
            if ((userRole < other.userRole) || (asset < other.asset) || mediaType < other.mediaType)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const AlertMessageAliasAssetId& pk) {
        return o << "\n    {"
                << "\n        \"user_role_id\": " << pk.userRole.id()
                << ",\n        \"asset_id\": " << pk.asset.id()
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
    void field(Action& a, Echoes::Dbo::AlertMessageAliasAssetId& aaaid,
            const std::string& name, int size = -1) {
        field(a, aaaid.userRole, TRIGRAM_USER_ROLE ID);
        field(a, aaaid.asset, TRIGRAM_ASSET ID);
        field(a, aaaid.mediaType, TRIGRAM_MEDIA_TYPE ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::AlertMessageAliasAsset> : public dbo_default_traits {
        typedef Echoes::Dbo::AlertMessageAliasAssetId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::AlertMessageAliasAssetId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* ALERTMESSAGEALIASASSETID_H */
