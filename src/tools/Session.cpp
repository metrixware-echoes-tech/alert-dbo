#include "Session.h"

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

    if (Auth::GoogleService::configured())
        myOAuthServices.push_back(new Auth::GoogleService(myAuthService));
}

Session::Session(Wt::Dbo::backend::Postgres *pgBackend)
{

    setConnection(*pgBackend);

    mapClass<UserAction>(Constants::T_ACTION_ACT);
    mapClass<UserHierarchy>(Constants::T_USER_HIERARCHY_UHI);
    mapClass<UserHistoricalAction>(Constants::T_USER_HISTORICAL_ACTION_UHA);
    mapClass<User>(Constants::T_USER_USR);
    mapClass<UserRole>(Constants::T_USER_ROLE_URO);
    mapClass<UserProfile>(Constants::T_USER_PROFILE_UPR);
    mapClass<UserField>(Constants::T_USER_FIELD_UFI);
    mapClass<UserValue>(Constants::T_USER_VALUE_UVA);
    
    mapClass<Plugin>(Constants::T_PLUGIN_PLG);
    
    mapClass<Information2>(Constants::T_INFORMATION_INF);
    mapClass<Organization>(Constants::T_ORGANIZATION_ORG);
    mapClass<Probe>(Constants::T_PROBE_PRB);
    mapClass<Value>(Constants::T_VALUE_VAL);
    mapClass<HistoricalValue>(Constants::T_HISTORICAL_VALUE_HVA);
    
    mapClass<Unit>(Constants::T_UNIT_UNT);
    mapClass<UnitType>(Constants::T_UNIT_TYPE_UTY);
    
    mapClass<Widget>(Constants::T_WIDGET_WGT);
    mapClass<WidgetType>(Constants::T_WIDGET_TYPE_WTY);
//    mapClass<WidgetValue>(Constants::T_WIDGET_VALUE_WVA);
    
    mapClass<Tab>(Constants::T_TAB_TAB);
    mapClass<TabVersion>(Constants::T_TAB_VERSION_TVS);
    mapClass<TabWidgetAssociation>(Constants::T_TAB_WIDGET_TWG);
    
    mapClass<Addon>(Constants::T_ADDON_ADO);
    
    mapClass<Alert>(Constants::T_ALERT_ALE);
    mapClass<AlertAcknowledge>(Constants::T_ALERT_ACKNOWLEDGE_ACK);
    mapClass<AlertValue>(Constants::T_ALERT_VALUE_AVA);
    mapClass<AlertParam>(Constants::T_ALERT_PARAM_APA);
    mapClass<AlertType>(Constants::T_ALERT_TYPE_ATY);
    mapClass<AlertCriteria>(Constants::T_ALERT_CRITERIA_ACR);
    
    mapClass<Source>(Constants::T_SOURCE_SRC);
    mapClass<SourceParameter>(Constants::T_SOURCE_PARAMETER_SRP);
    mapClass<SourceParameterValue>(Constants::T_SOURCE_PARAMETER_VALUE_SPV);
    
    mapClass<Asset>(Constants::T_ASSET_AST);
    
    mapClass<Syslog>(Constants::T_SYSLOG_SLO);
    
    mapClass<Search>(Constants::T_SEARCH_SEA);
    mapClass<SearchType>(Constants::T_SEARCH_TYPE_STY);
    mapClass<SearchParameter>(Constants::T_SEARCH_PARAMETER_SEP);
    mapClass<SearchParameterValue>(Constants::T_SEARCH_PARAMETER_VALUE_SEV);
    
    

    mapClass<AuthInfo>("auth_info");
    mapClass<AuthInfo::AuthIdentityType>("auth_identity");
    mapClass<AuthInfo::AuthTokenType>("auth_token");
//    mapClass<AuthInfo>("T_AUTH_INFO_AIN");
//    mapClass<AuthInfo::AuthIdentityType>("T_AUTH_IDENTITY_AID");
//    mapClass<AuthInfo::AuthTokenType>("T_AUTH_TOKEN_ATO");

    try
    {
        createTables();
        std::cerr << "Created database." << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << "createTables problem : Session.cpp";
    }

    users_ = new UserDatabase(*this);
}

Session::~Session()
{
    delete users_;
}

Auth::AbstractUserDatabase& Session::users()
{
    return *users_;
}

Wt::Dbo::ptr<User> Session::user() const
{
    if (login_.loggedIn())
    {
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
