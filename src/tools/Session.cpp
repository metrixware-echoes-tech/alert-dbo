#include "tools/Session.h"

using namespace Wt;

namespace
{

class MyOAuth : public std::vector<const Auth::OAuthService *>
{
public:
    ~MyOAuth()
    {
        for (unsigned i = 0; i < size(); ++i)
            delete (*this)[i];
    }
};

Auth::AuthService myAuthService;
Auth::PasswordService myPasswordService(myAuthService);
MyOAuth myOAuthServices;

}

void Session::configureAuth()
{
    myAuthService.setAuthTokensEnabled(true, "logincookie");
    myAuthService.setEmailVerificationEnabled(true);

    Auth::PasswordVerifier *verifier = new Auth::PasswordVerifier();
    verifier->addHashFunction(new Auth::BCryptHashFunction(7));
    myPasswordService.setVerifier(verifier);
    myPasswordService.setAttemptThrottlingEnabled(true);
    myPasswordService.setStrengthValidator(new Auth::PasswordStrengthValidator());

//    if (Auth::GoogleService::configured())
//        myOAuthServices.push_back(new Auth::GoogleService(myAuthService));
}


Session::Session(std::string connectionParams)
: connection_(connectionParams)
{
    //"hostaddr=127.0.0.1 port=5432 dbname=echoes user=echoes password=toto"
    connection_.setProperty("show-queries", "true");

    setConnection(connection_);

    mapClass<UserAction>(Constants::T_USER_ACTION_UAC);
    mapClass<UserHierarchy>(Constants::T_USER_HIERARCHY_UHI);
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
    
    mapClass<Information2>(Constants::T_INFORMATION_INF);
    mapClass<Organization>(Constants::T_ORGANIZATION_ORG);
    mapClass<OrganizationType>(Constants::T_ORGANIZATION_TYPE_OTY);
    mapClass<OrganizationValue>(Constants::T_ORGANIZATION_VALUE_OVA);
    mapClass<OrganizationField>(Constants::T_ORGANIZATION_FIELD_OFI);
    mapClass<Probe>(Constants::T_PROBE_PRB);
    mapClass<InformationValue>(Constants::T_INFORMATION_VALUE_IVA);
    mapClass<InformationHistoricalValue>(Constants::T_INFORMATION_HISTORICAL_VALUE_IHV);
    
    mapClass<InformationUnit>(Constants::T_INFORMATION_UNIT_UNT);
    mapClass<InformationUnitType>(Constants::T_INFORMATION_UNIT_TYPE_UTY);
    
//    mapClass<Widget>(Constants::T_WIDGET_WGT);
//    mapClass<WidgetType>(Constants::T_WIDGET_TYPE_WTY);
//    mapClass<WidgetValue>(Constants::T_WIDGET_VALUE_WVA);
    
//    mapClass<Tab>(Constants::T_TAB_TAB);
//    mapClass<TabVersion>(Constants::T_TAB_VERSION_TVS);
//    mapClass<TabWidgetAssociation>(Constants::T_TAB_WIDGET_TWG);
    
    mapClass<Addon>(Constants::T_ADDON_ADO);
    
    mapClass<Alert>(Constants::T_ALERT_ALE);
    mapClass<AlertAcknowledge>(Constants::T_ALERT_ACKNOWLEDGE_ACK);
    mapClass<AlertValue>(Constants::T_ALERT_VALUE_AVA);
    mapClass<AlertCriteria>(Constants::T_ALERT_CRITERIA_ACR);
    mapClass<AlertSequence>(Constants::T_ALERT_SEQUENCE_ASE);
    mapClass<AlertTracking>(Constants::T_ALERT_TRACKING_ATR);
    mapClass<AlertTrackingEvent>(Constants::T_ALERT_TRACKING_EVENT_ATE);
    
    mapClass<Engine>(Constants::T_ENGINE_ENG);
    
    mapClass<Source>(Constants::T_SOURCE_SRC);
    mapClass<SourceParameter>(Constants::T_SOURCE_PARAMETER_SRP);
    mapClass<SourceParameterValue>(Constants::T_SOURCE_PARAMETER_VALUE_SPV);
    
    mapClass<Asset>(Constants::T_ASSET_AST);
    
    mapClass<Syslog>(Constants::T_SYSLOG_SLO);
    
    mapClass<Search>(Constants::T_SEARCH_SEA);
    mapClass<SearchType>(Constants::T_SEARCH_TYPE_STY);
    mapClass<SearchParameter>(Constants::T_SEARCH_PARAMETER_SEP);
    mapClass<SearchParameterValue>(Constants::T_SEARCH_PARAMETER_VALUE_SEV);
    
    mapClass<Pack>(Constants::T_PACK_PCK);
    
    mapClass<Option>(Constants::T_OPTION_OPT);
    
    mapClass<Media>(Constants::T_MEDIA_MED);
    mapClass<MediaValue>(Constants::T_MEDIA_VALUE_MEV);
    

    mapClass<AuthInfo>("auth_info");
    mapClass<AuthInfo::AuthIdentityType>("auth_identity");
    mapClass<AuthInfo::AuthTokenType>("auth_token");
//    mapClass<AuthInfo>("T_AUTH_INFO_AIN");
//    mapClass<AuthInfo::AuthIdentityType>("T_AUTH_IDENTITY_AID");
//    mapClass<AuthInfo::AuthTokenType>("T_AUTH_TOKEN_ATO");nn

    users_ = new UserDatabase(*this);
}

Session::~Session()
{
    delete users_;
}

UserDatabase& Session::users()
{
    return *users_;
}

Wt::Dbo::ptr<User> Session::user() const
{
    if (login_.loggedIn())
    {
//        users_ = new UserDatabase(*this);
        Wt::Dbo::ptr<AuthInfo> authInfo = users_->find(login_.user());
        return authInfo->user();
    }
    else
        return Wt::Dbo::ptr<User>();
}

const Auth::AuthService& Session::auth()
{
    return myAuthService;
}

const Auth::PasswordService& Session::passwordAuth()
{
    return myPasswordService;
}

const std::vector<const Auth::OAuthService *>& Session::oAuth()
{
    return myOAuthServices;
}
