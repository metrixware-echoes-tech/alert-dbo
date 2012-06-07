#ifndef SESSION_H_
#define SESSION_H_

#include <Wt/Auth/Login>
#include "Wt/Auth/AuthService"
#include "Wt/Auth/HashFunction"
#include "Wt/Auth/PasswordService"
#include "Wt/Auth/PasswordStrengthValidator"
#include "Wt/Auth/PasswordVerifier"
#include "Wt/Auth/GoogleService"
#include "Wt/Auth/Dbo/AuthInfo"
#include "Wt/Auth/Dbo/UserDatabase"

#include <Wt/Dbo/Session>
#include <Wt/Dbo/ptr>
#include <Wt/Dbo/backend/Postgres>

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "UserField.h"
#include "UserProfile.h"
#include "UserRole.h"
#include "User.h"
#include "Constants.h"
#include "Unit.h"
#include "HistoricalAction.h"
#include "Hierarchy.h"
#include "UserAction.h"
#include "UserValue.h"

#include "Plugin.h"


#include "Organization.h"

#include "WidgetType.h"
#include "WidgetValue.h"
#include "Widget.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

#include "Alert.h"
#include "AlertHisto.h"
#include "AlertValue.h"
#include "AlertParam.h"
#include "AlertType.h"
#include "AlertCriteria.h"

#include "Source.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

#include "Asset.h"

#include "Syslog.h"

#include "Search.h"
#include "SearchType.h"
#include "SearchParameter.h"
#include "SearchParameterValue.h"

class User;

typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

typedef Wt::Auth::Dbo::UserDatabase<AuthInfo> UserDatabase;

class Session : public Wt::Dbo::Session
{
public:
  static void configureAuth();

  Session(Wt::Dbo::backend::Postgres *pgBackend);
  ~Session();

  Wt::Dbo::ptr<User> user() const;

  Wt::Auth::AbstractUserDatabase& users();
  Wt::Auth::Login& login() { return login_; }

  static const Wt::Auth::AuthService& auth();
  static const Wt::Auth::PasswordService& passwordAuth();
  static const std::vector<const Wt::Auth::OAuthService *>& oAuth();

private:
  Wt::Dbo::backend::Postgres connection_;
  UserDatabase *users_;
  Wt::Auth::Login login_;
};

#endif // SESSION_H_
