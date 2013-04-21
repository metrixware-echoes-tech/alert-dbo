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
    
    Wt::WString name;

    Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;
    
    Wt::Dbo::ptr<Organization> organization;

    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=&this->name;
        FIELD_FILLER();
        
        Wt::Dbo::belongsTo(a,organization,TRIGRAM_USER_ROLE SEP TRIGRAM_ORGANIZATION);
        
        Wt::Dbo::hasMany(a,
                         users,
                         Wt::Dbo::ManyToOne,
                         TRIGRAM_USER SEP TRIGRAM_USER_ROLE);
        
        
    }



};


#endif // USERROLE_H
