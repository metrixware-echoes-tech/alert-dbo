#ifndef USERFIELD_H
#define USERFIELD_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"
#include "primaryKeys/UserHierarchyId.h"
#include "primaryKeys/UserValueId.h"

//class User;
//class UserValue;

class UserField : public Table
{
    public:
        UserField();
        virtual ~UserField();
        
        static std::string TRIGRAM;
        
        std::string name;
        std::string format;

        Wt::Dbo::collection<Wt::Dbo::ptr<User> > users;

        Wt::Dbo::collection<Wt::Dbo::ptr<UserValue> > userValues;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesStrings["FORMAT"]=this->format;
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
