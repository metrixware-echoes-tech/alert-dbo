/* 
 * File:   AlertMessageAliasAssetId.h
 * Author: tsa
 *
 * Created on 25 février 2013, 12:09
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
    class Media;

    struct AlertMessageAliasAssetId {
        Wt::Dbo::ptr<UserRole> userRole;
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<Media> media;

        AlertMessageAliasAssetId(Wt::Dbo::ptr<UserRole> ptrUserRole, Wt::Dbo::ptr<Asset> ptrAsset, Wt::Dbo::ptr<Media> ptrMedia)
        : userRole(ptrUserRole), asset(ptrAsset), media(ptrMedia) {
        }

        AlertMessageAliasAssetId() {
        }

        bool operator==(const AlertMessageAliasAssetId& other) const {
            return userRole == other.userRole && asset == other.asset && media == other.media;
        }

        bool operator<(const AlertMessageAliasAssetId& other) const {
            if ((userRole < other.userRole) || (asset < other.asset) || media < other.media)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const AlertMessageAliasAssetId& pk) {
        return o << "\n\t\t\"user_role_id\": " << pk.userRole.id()
                << ",\n\t\t\"asset_id\": " << pk.asset.id()
                << ",\n\t\t\"media_id\": " << pk.media.id();
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
        field(a, aaaid.media, TRIGRAM_MEDIA ID);
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

