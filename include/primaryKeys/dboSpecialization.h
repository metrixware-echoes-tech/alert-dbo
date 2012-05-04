/* 
 * File:   dboSpecialization.h
 * Author: tom
 *
 * Created on 4 mai 2012, 18:15
 */

#ifndef DBOSPECIALIZATION_H
#define	DBOSPECIALIZATION_H

#include <Wt/Dbo/Dbo>

class UserField;
class UserRole;
class Unit;
class User;
class UserProfile;
class HistoricalAction;
class AlertParam;
class AlertValue;
class Alert;
class AlertType;

namespace Wt
{
    namespace Dbo
    {        
        template<>
        struct dbo_traits<UserField> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UFI_ID";
            }
        };
        template<>
        struct dbo_traits<UserRole> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "URO_ID";
            }
        };
        template<>
        struct dbo_traits<Unit> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UNT_ID";
            }
        };
        template<>
        struct dbo_traits<User> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "USR_ID";
            }
        };
        template<>
        struct dbo_traits<HistoricalAction> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "HAC_ID";
            }
        };
        template<>
        struct dbo_traits<UserProfile> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UPR_ID";
            }
        };
        template<>
        struct dbo_traits<AlertParam> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "APA_ID";
            }
        };
        template<>
        struct dbo_traits<AlertValue> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return 0;
            }
        };
        template<>
        struct dbo_traits<Alert> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ALE_ID";
            }
        };
        template<>
        struct dbo_traits<AlertType> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ATY_ID";
            }
        };
    }
}


        


#endif	/* DBOSPECIALIZATION_H */

