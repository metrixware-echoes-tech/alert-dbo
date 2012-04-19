#include "Session.h"
#include "Constants.h"

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

    mapClass<User>(Constants::T_USER_USR);
    mapClass<UserRole>(Constants::T_USER_ROLE_URO);
    mapClass<UserProfile>(Constants::T_USER_PROFILE_UPR);
    mapClass<Hierarchy>(Constants::T_HIERARCHY_HRC);
    mapClass<UserField>(Constants::T_USER_FIELD_UFI);
    mapClass<UserValue>(Constants::T_USER_VALUE_UVA);
    mapClass<HistoricalAction>(Constants::T_HISTORICAL_ACTION_HAC);
    mapClass<Action>(Constants::T_ACTION_ACT);
    mapClass<Organization>(Constants::T_ORGANIZATION_ORG);
    mapClass<Probe>(Constants::T_PROBE_PRB);
    mapClass<Value>(Constants::T_VALUE_VAL);
    mapClass<HistoricalValue>(Constants::T_HISTORICAL_VALUE_VAL);
    mapClass<Information2>(Constants::T_INFORMATION_INF);
    mapClass<Plugin>(Constants::T_PLUGIN_PLG);

    mapClass<AuthInfo>("T_AUTH_INFO_AIN");
    mapClass<AuthInfo::AuthIdentityType>("T_AUTH_IDENTITY_AID");
    mapClass<AuthInfo::AuthTokenType>("T_AUTH_TOKEN_ATO");

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
