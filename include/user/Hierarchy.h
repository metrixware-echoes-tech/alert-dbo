#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>



#include "MainIncludeFile.h"

#include "HierarchyId.h"

class Hierarchy : public Table
{
    public:
        Hierarchy();
        virtual ~Hierarchy();
        
        static std::string TRIGRAM;
        
        Wt::WDateTime deleteTag;
        //RHI : PK/FK USR_ID and USR_ID_CHILD to add

        HierarchyId pk;

        template<class Action>
        void persist(Action& a)
        {

            Wt::Dbo::id (a, pk, "PRIMARY_KEY");
            mapClassAttributesDates["DELETE"]=this->deleteTag;
        }
    protected:
    private:
};

#endif // HIERARCHY_H
