/**
 * @file Session.cpp
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

#include "tools/Session.h"
#include "tools/SpecializedAuthService.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    class MyOAuth : public vector<const Wt::Auth::OAuthService *>
    {
        public:
            ~MyOAuth()
            {
                for (unsigned i = 0; i < size(); ++i)
                    delete (*this)[i];
            }
    };

    SpecializedAuthService myAuthService;
    Wt::Auth::PasswordService myPasswordService(myAuthService);
    MyOAuth myOAuthServices;

    void Session::configureAuth()
    {
        myAuthService.setAuthTokensEnabled(true, "logincookie");
        myAuthService.setIdentityPolicy(Wt::Auth::EmailAddressIdentity);
        myAuthService.setEmailVerificationEnabled(true);
        myAuthService.setEmailVerificationRequired(true);

        Wt::Auth::PasswordVerifier *verifier = new Wt::Auth::PasswordVerifier();
        verifier->addHashFunction(new Wt::Auth::BCryptHashFunction(7));
        myPasswordService.setVerifier(verifier);
        myPasswordService.setAttemptThrottlingEnabled(true);
        myPasswordService.setStrengthValidator(new Wt::Auth::PasswordStrengthValidator());

        //    if (Auth::GoogleService::configured())
        //        myOAuthServices.push_back(new Auth::GoogleService(myAuthService));
    }

    Session::Session() : users_(*this)
    {
        initMapClass();
    }


    Session::Session(string connectionParams)
    : connection_(connectionParams),
      users_(*this)
    {
        //"hostaddr=127.0.0.1 port=5432 dbname=echoes user=echoes password=toto"
    //    connection_.setProperty("show-queries", "true");

        setConnection(connection_);

        initMapClass();
    }

    Session::~Session()
    {
    }

    UserDatabase& Session::users()
    {
        return users_;
    }

    void Session::initConnection(string connectionParams)
    {
        if (connection_.connection() == NULL)
            connection_.connect(connectionParams);
        setConnection(connection_);

    }

    void Session::initMapClass()
    {
        mapClass<UserActionType>(Constants::TR_USER_ACTION_TYPE_UAT);
        mapClass<UserHistoricalAction>(Constants::T_USER_HISTORICAL_ACTION_UHA);
        mapClass<User>(Constants::T_USER_USR);
        mapClass<UserRole>(Constants::T_USER_ROLE_URO);
        mapClass<UserRight>(Constants::T_USER_RIGHT_URI);
        mapClass<AccessControlList>(Constants::T_ACCESS_CONTROL_LIST_ACL);
        mapClass<Space>(Constants::T_SPACE_SPA);
        mapClass<UserProfile>(Constants::T_USER_PROFILE_UPR);
        mapClass<UserField>(Constants::T_USER_FIELD_UFI);
        mapClass<UserValue>(Constants::T_USER_VALUE_UVA);

        mapClass<Plugin>(Constants::T_PLUGIN_PLG);
        mapClass<PluginReference>(Constants::T_PLUGIN_REFERENCE_PRE);
        mapClass<PluginData>(Constants::T_PLUGIN_DATA_PDA);

        mapClass<Filter>(Constants::T_FILTER_FIL);
        mapClass<FilterType>(Constants::TR_FILTER_TYPE_FTY);
        mapClass<FilterParameter>(Constants::TR_FILTER_PARAMETER_FPA);
        mapClass<FilterParameterValue>(Constants::T_FILTER_PARAMETER_VALUE_FPV);

        mapClass<Information>(Constants::T_INFORMATION_INF);
        mapClass<Group>(Constants::T_GROUP_GRP);
        mapClass<GroupType>(Constants::TR_GROUP_TYPE_GTY);
        mapClass<GroupValue>(Constants::T_GROUP_VALUE_GVA);
        mapClass<GroupField>(Constants::T_GROUP_FIELD_GFI);

        mapClass<Probe>(Constants::T_PROBE_PRB);
        mapClass<ProbePackage>(Constants::T_PROBE_PACKAGE_PPA);
        mapClass<ProbePackageParameter>(Constants::T_PROBE_PACKAGE_PARAMETER_PPP);

        mapClass<InformationValue>(Constants::T_INFORMATION_VALUE_IVA);
        mapClass<InformationHistoricalValue>(Constants::T_INFORMATION_HISTORICAL_VALUE_IHV);

        mapClass<InformationUnit>(Constants::T_INFORMATION_UNIT_INU);
//        mapClass<InformationSubUnit>(Constants::T_INFORMATION_SUB_UNIT_ISU);
        mapClass<InformationUnitType>(Constants::TR_INFORMATION_UNIT_TYPE_IUT);
        mapClass<InformationData>(Constants::T_INFORMATION_DATA_IDA);

        mapClass<Addon>(Constants::TR_ADDON_ADO);
        mapClass<AddonCommonPackage>(Constants::T_ADDON_COMMON_PACKAGE_CPA);
        mapClass<AddonCommonPackageParameter>(Constants::T_ADDON_COMMON_PACKAGE_PARAMETER_CPP);
        mapClass<AddonPackage>(Constants::T_ADDON_PACKAGE_APA);
        mapClass<AddonPackageParameter>(Constants::T_ADDON_PACKAGE_PARAMETER_APP);

        mapClass<Alert>(Constants::T_ALERT_ALE);
        mapClass<AlertAcknowledge>(Constants::T_ALERT_ACKNOWLEDGE_ACK);
        mapClass<AlertMediaSpecialization>(Constants::T_ALERT_MEDIA_SPECIALIZATION_AMS);
        mapClass<AlertMessageAliasAsset>(Constants::T_ALERT_MESSAGE_ALIAS_ASSET_AAA);
        mapClass<AlertMessageAliasPlugin>(Constants::T_ALERT_MESSAGE_ALIAS_PLUGIN_AAP);
        mapClass<AlertMessageAliasInformation>(Constants::T_ALERT_MESSAGE_ALIAS_INFORMATION_AAI);
        mapClass<AlertMessageAliasInformationCriteria>(Constants::T_ALERT_MESSAGE_ALIAS_INFORMATION_CRITERIA_AIC);
        mapClass<AlertValue>(Constants::T_ALERT_VALUE_AVA);
        mapClass<AlertCriteria>(Constants::TR_ALERT_CRITERIA_ACR);
        mapClass<AlertSequence>(Constants::T_ALERT_SEQUENCE_ASE);
        mapClass<AlertTimeSlot>(Constants::T_ALERT_TIMESLOT_ATS);
        mapClass<AlertTrackingEvent>(Constants::T_ALERT_TRACKING_EVENT_ATE);
        mapClass<AlertStatus>(Constants::TR_ALERT_STATUS_ALS);
        
        mapClass<Message>(Constants::T_MESSAGE_MSG);
        mapClass<MessageTrackingEvent>(Constants::T_MESSAGE_TRACKING_EVENT_MTE);
        mapClass<MessageStatus>(Constants::TR_MESSAGE_STATUS_MSA);

        mapClass<Engine>(Constants::TR_ENGINE_ENG);
        mapClass<EngGrp>(Constants::TJ_ENG_GRP);

        mapClass<Source>(Constants::T_SOURCE_SRC);
        mapClass<SourceParameter>(Constants::TR_SOURCE_PARAMETER_SRP);
        mapClass<SourceParameterValue>(Constants::T_SOURCE_PARAMETER_VALUE_SPV);

        mapClass<Asset>(Constants::T_ASSET_AST);
        mapClass<AssetArchitecture>(Constants::T_ASSET_ARCHITECTURE_ASA);
        mapClass<AssetDistribution>(Constants::T_ASSET_DISTRIBUTION_ASD);
        mapClass<AssetRelease>(Constants::T_ASSET_RELEASE_ASR);

        mapClass<Syslog>(Constants::T_SYSLOG_SLO);

        mapClass<Search>(Constants::T_SEARCH_SEA);
        mapClass<SearchType>(Constants::TR_SEARCH_TYPE_STY);
        mapClass<SearchParameter>(Constants::TR_SEARCH_PARAMETER_SEP);
        mapClass<SearchParameterValue>(Constants::T_SEARCH_PARAMETER_VALUE_SEV);

        mapClass<Pack>(Constants::T_PACK_PCK);
        mapClass<PackOption>(Constants::T_PACK_OPTION_POP);
        mapClass<Option>(Constants::T_OPTION_OPT);

        mapClass<OptionType>(Constants::TR_OPTION_TYPE_OTP);

        mapClass<MediaType>(Constants::TR_MEDIA_TYPE_MTY);
        mapClass<Media>(Constants::T_MEDIA_MED);

        mapClass<AuthInfo>("auth_info");
        mapClass<AuthInfo::AuthIdentityType>("auth_identity");
        mapClass<AuthInfo::AuthTokenType>("auth_token");
    }

    Wt::Dbo::ptr<User> Session::user() const
    {
        if (login_.loggedIn())
        {
            //        users_ = new UserDatabase(*this);
            Wt::Dbo::ptr<AuthInfo> authInfo = users_.find(login_.user());
            return authInfo->user();
        }
        else
            return Wt::Dbo::ptr<User>();
    }

    const Wt::Auth::AuthService& Session::auth()
    {
        return myAuthService;
    }

    const Wt::Auth::PasswordService& Session::passwordAuth()
    {
        return myPasswordService;
    }

    const vector<const Wt::Auth::OAuthService *>& Session::oAuth()
    {
        return myOAuthServices;
    }
  }
}
