#ifndef HIERARCHY_H
#define HIERARCHY_H

#include "HierarchyId.h"
#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class User;

class Hierarchy : public Table
{
    public:
        Hierarchy();
        virtual ~Hierarchy();
        
        static std::string TRIGRAM;

        HierarchyId pk;

        template<class Action>
        void persist(Action& a)
        {

            Wt::Dbo::id (a, pk, "PRIMARY_KEY");
        }
    protected:
    private:
};

#endif // HIERARCHY_H
