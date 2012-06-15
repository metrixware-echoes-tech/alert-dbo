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
        int subSearchNumber;
        Wt::WDateTime deleteTag;
                   
//        Wt::Dbo::collection<Wt::Dbo::ptr<Value> > values;
//        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue> > historicalValues;
//        //TJ
//        Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;


        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::id(a,pk,"PRIMARY_KEY");
            Wt::Dbo::belongsTo(a, unit, "UIN");
            
//            Wt::Dbo::hasMany(a,
//                             values,
//                             Wt::Dbo::ManyToOne,
//                             "VIN");
//            Wt::Dbo::hasMany(a,
//                             historicalValues,
//                             Wt::Dbo::ManyToOne,
//                             "HIN");
            mapClassAttributesDates["DELETE"]=this->deleteTag;
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesStrings["SUB-SEA_NUM"]=this->subSearchNumber;       

        }
    protected:
    private:
};

#endif // INFORMATION_H
