#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"
#include "UserValueId.h"

class User;

class UserProfile : public Table
{
public:
    UserProfile();
    virtual ~UserProfile();
    
    static std::string TRIGRAM;
    
    std::string name;

    Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=this->name;
        
        FIELD_FILLER();
        //Wt::Dbo::belongsTo(a, user, User::getName().c_str());
        Wt::Dbo::hasMany(a,
                         users,
                         Wt::Dbo::ManyToOne,
                         "USR_UPR");
    }

};




#endif // USERPROFILE_H
