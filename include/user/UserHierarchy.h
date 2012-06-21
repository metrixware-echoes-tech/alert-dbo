#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>



#include "MainIncludeFile.h"

#include "UserHierarchyId.h"

class UserHierarchy : public Table
{
    public:
        UserHierarchy();
        virtual ~UserHierarchy();
        
        static std::string TRIGRAM;
        
        UserHierarchyId pk;

        template<class Action>
        void persist(Action& a)
        {

            FIELD_FILLER();
            Wt::Dbo::id(a,pk,"PRIMARY_KEY");
        }
    protected:
    private:
};

#endif // HIERARCHY_H
