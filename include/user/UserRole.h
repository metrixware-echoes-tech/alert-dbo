#ifndef USERROLE_H
#define USERROLE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"
#include "UserValueId.h"

class UserRole : public Table
{
public:
    UserRole();
    virtual ~UserRole();
    
    static std::string TRIGRAM;

    Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

    template<class Action>
    void persist(Action& a)
    {
        FIELD_FILLER();
        
        Wt::Dbo::hasMany(a,
                         users,
                         Wt::Dbo::ManyToOne,
                         "URO");
    }



};


#endif // USERROLE_H
