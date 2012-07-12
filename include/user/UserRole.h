#ifndef USERROLE_H
#define USERROLE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"
#include "primaryKeys/UserValueId.h"

class UserRole : public Table
{
public:
    UserRole();
    virtual ~UserRole();
    
    static std::string TRIGRAM;
    
    std::string name;

    Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=this->name;
        FIELD_FILLER();
        
        Wt::Dbo::hasMany(a,
                         users,
                         Wt::Dbo::ManyToOne,
                         "USR_URO");
        
        
    }



};


#endif // USERROLE_H
