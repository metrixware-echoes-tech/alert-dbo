#ifndef INFORMATION_H
#define INFORMATION_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

#include "primaryKeys/InformationId.h"

class Information2 : public Table
{
    public:
        Information2();
        virtual ~Information2();
        
        static std::string TRIGRAM;
        
        InformationId pk;
        
        Wt::Dbo::ptr<InformationUnit> unit;
        
        Wt::WString name;
                   



        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            FIELD_FILLER();
            Wt::Dbo::id(a,pk,"PRIMARY_KEY");
            Wt::Dbo::belongsTo(a, unit, "INF_UNT");
        }    

    protected:
    private:
};

#endif // INFORMATION_H
