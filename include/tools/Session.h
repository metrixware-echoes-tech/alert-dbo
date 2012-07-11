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

#include "MainIncludeFile.h"

class User;
class Search;

typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

typedef Wt::Auth::Dbo::UserDatabase<AuthInfo> UserDatabase;

class Session : public Wt::Dbo::Session
{
public:
  static void configureAuth();

  Session();
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
