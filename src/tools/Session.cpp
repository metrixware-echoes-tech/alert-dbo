#include "Constants.h"
#include "Hierarchy.h"
#include "UserAction.h"
#include "UserRole.h"
#include "UserProfile.h"
#include "UserField.h"
#include "UserValue.h"
#include "User.h"
#include "HistoricalAction.h"
#include "Session.h"

#include "Plugin.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "Probe.h"
//#include "ProbeId.h"
#include "Organization.h"

#include "WidgetType.h"
#include "Widget.h"

#include "Unit.h"
#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Wt/Auth/AuthService"
#include "Wt/Auth/HashFunction"
#include "Wt/Auth/PasswordService"
#include "Wt/Auth/PasswordStrengthValidator"
#include "Wt/Auth/PasswordVerifier"
#include "Wt/Auth/GoogleService"
#include "Wt/Auth/Dbo/AuthInfo"
#include "Wt/Auth/Dbo/UserDatabase"

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
    mapClass<Hierarchy>(Constants::T_HIERARCHY_HRC);
    mapClass<HistoricalAction>(Constants::T_HISTORICAL_ACTION_HAC);
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
    mapClass<HistoricalValue>(Constants::T_HISTORICAL_VALUE_VAL);
    
    mapClass<Unit>(Constants::T_UNIT_UNT);
    mapClass<UnitType>(Constants::T_UNIT_TYPE_UTY);
    
    mapClass<Widget>(Constants::T_WIDGET_WGT);
    mapClass<WidgetType>(Constants::T_WIDGET_TYPE_WTY);
    
    mapClass<Tab>(Constants::T_TAB_TAB);
    mapClass<TabVersion>(Constants::T_TAB_VERSION_TVS);
    mapClass<TabWidgetAssociation>(Constants::T_TAB_WIDGET_TWG);

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
