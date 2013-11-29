/* 
 * File:   AlertMessageDefinitionId.h
 * Author: tsa
 *
 * Created on 22 février 2013, 17:08
 */

#ifndef ALERTMESSAGEDEFINITIONID_H
#define	ALERTMESSAGEDEFINITIONID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    struct AlertMessageDefinitionId {
        Wt::Dbo::ptr<Alert> alert;
        Wt::Dbo::ptr<UserRole> userRole;
        Wt::Dbo::ptr<MediaType> mediaType;

        AlertMessageDefinitionId(Wt::Dbo::ptr<Alert> ptrAle, Wt::Dbo::ptr<UserRole> ptrUro, Wt::Dbo::ptr<MediaType> ptrMedType)
        : alert(ptrAle), userRole(ptrUro), mediaType(ptrMedType) {
        }

        AlertMessageDefinitionId() {
        }

        bool operator==(const AlertMessageDefinitionId& other) const {
            return alert == other.alert && userRole == other.userRole && mediaType == other.mediaType;
        }

        bool operator<(const AlertMessageDefinitionId& other) const {
            if ((alert < other.alert) || (userRole < other.userRole) || mediaType < other.mediaType)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const AlertMessageDefinitionId& pk) {
        return o << "\"alert_id\": " << pk.alert.id()
                << ",\n\t\t\"user_role\": " << pk.userRole.id()
                << ",\n\t\t\"media_id\": " << pk.mediaType.id();
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::AlertMessageDefinitionId& amdid,
            const std::string& name, int size = -1) {
        field(a, amdid.alert, TRIGRAM_ALERT ID);
        field(a, amdid.userRole, TRIGRAM_USER_ROLE ID);
        field(a, amdid.mediaType, TRIGRAM_MEDIA_TYPE ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::AlertMessageDefinition> : public dbo_default_traits {
        typedef Echoes::Dbo::AlertMessageDefinitionId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::AlertMessageDefinitionId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* ALERTMESSAGEDEFINITIONID_H */

