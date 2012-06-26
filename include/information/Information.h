#ifndef INFORMATION_H
#define INFORMATION_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"

#include "InformationId.h"

class Information2 : public Table
{
    public:
        Information2();
        virtual ~Information2();
        
        static std::string TRIGRAM;
        
        InformationId pk;
        
        Wt::Dbo::ptr<Unit> unit;
        
        std::string name;
        Wt::WDateTime deleteTag;
                   



        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;
            FIELD_FILLER();
            Wt::Dbo::id(a,pk,"PRIMARY_KEY");
            Wt::Dbo::belongsTo(a, unit, "UIN");
        }    

    protected:
    private:
};

#endif // INFORMATION_H
