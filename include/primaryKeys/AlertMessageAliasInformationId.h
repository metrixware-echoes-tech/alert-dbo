/* 
 * File:   AlertMessageAliasInformationId.h
 * Author: tsa
 *
 * Created on 25 février 2013, 12:09
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
        Wt::Dbo::ptr<Media> media;

        AlertMessageAliasInformationId(Wt::Dbo::ptr<UserRole> ptrUserRole, Wt::Dbo::ptr<Information> ptrInformation, Wt::Dbo::ptr<Media> ptrMedia)
        : userRole(ptrUserRole), information(ptrInformation), media(ptrMedia) {
        }

        AlertMessageAliasInformationId() {
        }

        bool operator==(const AlertMessageAliasInformationId& other) const {
            return userRole == other.userRole && information == other.information && media == other.media;
        }

        bool operator<(const AlertMessageAliasInformationId& other) const {
            if ((userRole < other.userRole) || (information < other.information) || media < other.media)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const AlertMessageAliasInformationId& pk) {
        return o << "\"role_id\": " << pk.userRole.id()
                << ",\n" << pk.information.id()
                << ",\n\"media_id\": " << pk.media.id();
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
        field(a, aaiid.media, TRIGRAM_MEDIA ID);
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

