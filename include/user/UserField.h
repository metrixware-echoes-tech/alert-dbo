#ifndef USERFIELD_H
#define USERFIELD_H

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"
#include "UserHierarchyId.h"
#include "UserValueId.h"

//class User;
//class UserValue;

class UserField : public Table
{
    public:
        UserField();
        virtual ~UserField();
        
        static std::string TRIGRAM;

        Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

        Wt::Dbo::collection<Wt::Dbo::ptr<UserValue> > userValues;

        template<class Action>
        void persist(Action& a)
        {
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             users,
                             Wt::Dbo::ManyToMany,
                             "TJ_USR_UFI");

            Wt::Dbo::hasMany(a,
                             userValues,
                             Wt::Dbo::ManyToOne,
                             "UVA_UFI");
        }
};

#endif // USERFIELD_H
