#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class User;

class UserProfile
{
public:
    UserProfile();
    virtual ~UserProfile();

    Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

    template<class Action>
    void persist(Action& a)
    {
        //Wt::Dbo::belongsTo(a, user, User::getName().c_str());
        Wt::Dbo::hasMany(a,
                         users,
                         Wt::Dbo::ManyToOne,
                         "UPR");
    }

};




#endif // USERPROFILE_H
