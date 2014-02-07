/* 
 * File:   AlertMessageAliasInformationCriteriaId.h
 * Author: tsa
 *
 * Created on 25 février 2013, 12:09
 */

#ifndef ALERTMESSAGEALIASINFORMATIONCRITERIAID_H
#define	ALERTMESSAGEALIASINFORMATIONCRITERIAID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    struct AlertMessageAliasInformationCriteriaId {
        Wt::Dbo::ptr<UserRole> userRole;
        Wt::Dbo::ptr<Information> information;
        Wt::Dbo::ptr<AlertCriteria> alertCriteria;
        Wt::Dbo::ptr<MediaType> mediaType;

        AlertMessageAliasInformationCriteriaId(Wt::Dbo::ptr<UserRole> ptrUserRole, Wt::Dbo::ptr<Information> ptrInformation, Wt::Dbo::ptr<AlertCriteria> ptrAlertCriteria, Wt::Dbo::ptr<MediaType> ptrMediaType)
        : userRole(ptrUserRole), information(ptrInformation), alertCriteria(ptrAlertCriteria), mediaType(ptrMediaType) {
        }

        AlertMessageAliasInformationCriteriaId() {
        }

        bool operator==(const AlertMessageAliasInformationCriteriaId& other) const {
            return userRole == other.userRole && information == other.information && alertCriteria == other.alertCriteria && mediaType == other.mediaType;
        }

        bool operator<(const AlertMessageAliasInformationCriteriaId& other) const {
            if ((userRole < other.userRole) || (information < other.information) || (alertCriteria < other.alertCriteria) || mediaType < other.mediaType)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const AlertMessageAliasInformationCriteriaId& pk) {
        return o << "\n    {"
                << "\n        \"user_role_id\": " << pk.userRole.id()
                << ",\n        \"information_id\": " << pk.information.id()
                << ",\n        \"media_type_id\": " << pk.mediaType.id()
                << ",\n        \"alert_criteria_id\": " << pk.alertCriteria.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::AlertMessageAliasInformationCriteriaId& aicid,
            const std::string& name, int size = -1) {
        field(a, aicid.userRole, TRIGRAM_USER_ROLE ID);
        field(a, aicid.information, TRIGRAM_INFORMATION ID);
        field(a, aicid.alertCriteria, TRIGRAM_ALERT_CRITERIA ID);
        field(a, aicid.mediaType, TRIGRAM_MEDIA_TYPE ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::AlertMessageAliasInformationCriteria> : public dbo_default_traits {
        typedef Echoes::Dbo::AlertMessageAliasInformationCriteriaId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::AlertMessageAliasInformationCriteriaId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* ALERTMESSAGEALIASINFORMATIONCRITERIAID_H */

