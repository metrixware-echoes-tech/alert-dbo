/* 
 * File:   AlertMessageDefinitionId.h
 * Author: tsa
 *
 * Created on 22 février 2013, 17:08
 */

#ifndef ALERTMESSAGEDEFINITIONID_H
#define	ALERTMESSAGEDEFINITIONID_H

#include "tools/MainIncludeFile.h"

struct AlertMessageDefinitionId
{
    Wt::Dbo::ptr<Alert> alert;
    Wt::Dbo::ptr<UserRole> userRole;
    Wt::Dbo::ptr<Media> media;
    

    AlertMessageDefinitionId(Wt::Dbo::ptr<Alert> ptrAle, Wt::Dbo::ptr<UserRole> ptrUro, Wt::Dbo::ptr<Media> ptrMed)
        : alert(ptrAle), userRole(ptrUro), media(ptrMed) { }

    AlertMessageDefinitionId(){ }

    bool operator== (const AlertMessageDefinitionId& other) const {
        return alert == other.alert && userRole == other.userRole && media == other.media;
    }

    bool operator< (const AlertMessageDefinitionId& other) const {
        if ((alert < other.alert) || (userRole < other.userRole) || media < other.media)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const AlertMessageDefinitionId& pk)
{
    return o << "\"alert_id\": " << pk.alert.id()
             << ",\n\t\t\"user_role\": " << pk.userRole.id()
             << ",\n\t\t\"media_id\": " << pk.media.id() ;
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, AlertMessageDefinitionId& amdid,
                   const std::string& name, int size = -1)
        {
            field(a, amdid.alert, TRIGRAM_ALERT ID);
            field(a, amdid.userRole, TRIGRAM_USER_ROLE ID);
            field(a, amdid.media, TRIGRAM_MEDIA ID);
        }
        template<>
        struct dbo_traits<AlertMessageDefinition> : public dbo_default_traits
        {
            typedef AlertMessageDefinitionId IdType;
            static IdType invalidId() { return AlertMessageDefinitionId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* ALERTMESSAGEDEFINITIONID_H */

