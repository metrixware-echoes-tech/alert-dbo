/* 
 * File:   AlertMessageAliasInformationCriteriaId.h
 * Author: tsa
 *
 * Created on 25 février 2013, 12:09
 */

#ifndef ALERTMESSAGEALIASINFORMATIONCRITERIAID_H
#define	ALERTMESSAGEALIASINFORMATIONCRITERIAID_H

#include "tools/MainIncludeFile.h" 

struct AlertMessageAliasInformationCriteriaId
{

    Wt::Dbo::ptr<UserRole> userRole;
    Wt::Dbo::ptr<Information2> information;
    Wt::Dbo::ptr<AlertCriteria> alertCriteria;
    Wt::Dbo::ptr<Media> media;


    AlertMessageAliasInformationCriteriaId(Wt::Dbo::ptr<UserRole> ptrUserRole, Wt::Dbo::ptr<Information2> ptrInformation, Wt::Dbo::ptr<AlertCriteria> ptrAlertCriteria, Wt::Dbo::ptr<Media> ptrMedia)
        : userRole(ptrUserRole), information(ptrInformation), alertCriteria(ptrAlertCriteria), media(ptrMedia) { }

    AlertMessageAliasInformationCriteriaId(){ }


    bool operator== (const AlertMessageAliasInformationCriteriaId& other) const {
        return userRole == other.userRole && information == other.information && alertCriteria == other.alertCriteria && media == other.media;
    }

    bool operator< (const AlertMessageAliasInformationCriteriaId& other) const {
        if ((userRole < other.userRole) || (information < other.information) || (alertCriteria < other.alertCriteria) || media < other.media)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const AlertMessageAliasInformationCriteriaId& pk)
{
    return o <<  pk.userRole.id()
             << ",\n\t\t\"information_id\": " << pk.information.id()
             << ",\n\t\t\"alert_criteria_id\": " << pk.alertCriteria.id()
             << ",\n\t\t\"media_id\": " << pk.media.id() ;
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, AlertMessageAliasInformationCriteriaId& aicid,
                   const std::string& name, int size = -1)
        {
            field(a, aicid.userRole, TRIGRAM_USER_ROLE ID);
            field(a, aicid.information, TRIGRAM_INFORMATION ID);
            field(a, aicid.alertCriteria, TRIGRAM_ALERT_CRITERIA ID);
            field(a, aicid.media, TRIGRAM_MEDIA SEP ID);
        }
        template<>
        struct dbo_traits<AlertMessageAliasInformationCriteria> : public dbo_default_traits
        {
            typedef AlertMessageAliasInformationCriteriaId IdType;
            static IdType invalidId() { return AlertMessageAliasInformationCriteriaId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* ALERTMESSAGEALIASINFORMATIONCRITERIAID_H */

