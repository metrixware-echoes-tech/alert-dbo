/**
 * @file Constants.h
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

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "tools/MainIncludeFile.h"
#include "tools/MacroTrigram.h"

//#include "primaryKeys/UserValueId.h"
//
//#include "primaryKeys/WidgetValueId.h"

namespace Echoes
{
  namespace Dbo
  {
    class Constants {
        public:
            Constants();
            virtual ~Constants();

            static const char *T_USER_USR;
            static const char *T_USER_ROLE_URO;
            static const char *T_USER_RIGHT_URI;
            static const char *T_SPACE_SPA;
            static const char *T_ACCESS_CONTROL_LIST_ACL;
            static const char *T_USER_PROFILE_UPR;
            static const char *T_USER_VALUE_UVA;
            static const char *T_USER_FIELD_UFI;
            static const char *T_USER_HISTORICAL_ACTION_UHA;

            static const char *T_GROUP_GRP;
            static const char *T_GROUP_VALUE_GVA;
            static const char *T_GROUP_FIELD_GFI;
            static const char *T_PROBE_PRB;
            static const char *T_PROBE_PACKAGE_PPA;
            static const char *T_PROBE_PACKAGE_PARAMETER_PPP;

            static const char *T_INFORMATION_VALUE_IVA;
            static const char *T_INFORMATION_HISTORICAL_VALUE_IHV;
            static const char *T_INFORMATION_INF;
            static const char *T_INFORMATION_UNIT_INU;
    //        static const char *T_INFORMATION_SUB_UNIT_ISU;
            static const char *T_INFORMATION_DATA_IDA;

            static const char *T_PLUGIN_PLG;
            static const char *T_PLUGIN_REFERENCE_PRE;
            static const char *T_PLUGIN_DATA_PDA;

            static const char *T_FILTER_FIL;
            static const char *T_FILTER_PARAMETER_VALUE_FPV;

            static const char *T_WIDGET_VALUE_WVA;
            static const char *T_WIDGET_TYPE_WTY;
            static const char *T_WIDGET_WGT;
            static const char *T_TAB_TAB;
            static const char *T_TAB_VERSION_TVS;
            //        static const char *T_TAB_WIDGET_TWG;

            static const char *T_ADDON_ADO;
            static const char *T_ADDON_COMMON_PACKAGE_CPA;
            static const char *T_ADDON_COMMON_PACKAGE_PARAMETER_CPP;
            static const char *T_ADDON_PACKAGE_APA;
            static const char *T_ADDON_PACKAGE_PARAMETER_APP;

            static const char *T_ALERT_ALE;
            static const char *T_ALERT_ACKNOWLEDGE_ACK;
            static const char *T_ALERT_MEDIA_SPECIALIZATION_AMS;
            static const char *T_ALERT_MESSAGE_ALIAS_ASSET_AAA;
            static const char *T_ALERT_MESSAGE_ALIAS_PLUGIN_AAP;
            static const char *T_ALERT_MESSAGE_ALIAS_INFORMATION_AAI;
            static const char *T_ALERT_MESSAGE_ALIAS_INFORMATION_CRITERIA_AIC;
            static const char *T_ALERT_VALUE_AVA;
            static const char *T_ALERT_PARAM_APA;
            static const char *T_ALERT_SEQUENCE_ASE;
            static const char *T_ALERT_TIMESLOT_ATS;
            static const char *T_ALERT_TRACKING_EVENT_ATE;
            
            static const char *T_MESSAGE_TRACKING_EVENT_MTE;
            static const char *T_MESSAGE_MSG;
            static const char *T_SOURCE_SRC;
            static const char *T_SOURCE_PARAMETER_VALUE_SPV;
            static const char *T_ASSET_AST;
            static const char *T_ASSET_ARCHITECTURE_ASA;
            static const char *T_ASSET_DISTRIBUTION_ASD;
            static const char *T_ASSET_RELEASE_ASR;
            static const char *T_SYSLOG_SLO;
            static const char *T_SYSLOG_HISTORY_SLH;
            static const char *T_SEARCH_SEA;
            static const char *T_SEARCH_PARAMETER_VALUE_SEV;
            static const char *T_PACK_PCK;
            static const char *T_PACK_OPTION_POP;
            static const char *T_OPTION_OPT;
            static const char *T_MEDIA_MED;

            static const char *TJ_ENG_GRP;

            static const char *TR_INFORMATION_UNIT_TYPE_IUT;
            static const char *TR_ALERT_CRITERIA_ACR;
            static const char *TR_ALERT_STATUS_ALS;
            static const char *TR_MESSAGE_STATUS_MSA;
            static const char *TR_OPTION_TYPE_OTP;
            static const char *TR_MEDIA_TYPE_MTY;
            static const char *TR_ADDON_ADO;
            static const char *TR_SEARCH_TYPE_STY;
            static const char *TR_GROUP_TYPE_GTY;
            static const char *TR_SOURCE_PARAMETER_SRP;
            static const char *TR_ENGINE_ENG;
            static const char *TR_USER_ACTION_TYPE_UAT;
            static const char *TR_SEARCH_PARAMETER_SEP;
            static const char *TR_FILTER_TYPE_FTY;
            static const char *TR_FILTER_PARAMETER_FPA;
        protected:
        private:
    };
  }
}

#endif // CONSTANTS_H
