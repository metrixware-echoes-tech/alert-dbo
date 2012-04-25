#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "ProbeId.h"
#include "UserValueId.h"



class Constants
{
    public:
        Constants();
        virtual ~Constants();
        static const char *T_USER_USR;
        static const char *T_USER_ROLE_URO;
        static const char *T_HIERARCHY_HRC;
        static const char *T_USER_PROFILE_UPR;
        static const char *T_USER_VALUE_UVA;
        static const char *T_USER_FIELD_UFI;
        static const char *T_HISTORICAL_ACTION_HAC;
        static const char *T_ACTION_ACT;
        static const char *T_ORGANIZATION_ORG;
        static const char *T_PROBE_PRB;
        static const char *T_VALUE_VAL;
        static const char *T_HISTORICAL_VALUE_VAL;
        static const char *T_INFORMATION_INF;
        static const char *T_PLUGIN_PLG;
        static const char *T_WIDGET_VALUE_WVA;
    protected:
    private:
};

#endif // CONSTANTS_H
