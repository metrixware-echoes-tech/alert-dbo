#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class InformationUnit;
//class WidgetType;

class InformationUnitType : public Table
{
    public:
        InformationUnitType();
        virtual ~InformationUnitType();
        
        static std::string TRIGRAM;
        
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationUnit> > units;
        
//        Wt::Dbo::collection<Wt::Dbo::ptr<WidgetType> > widgetTypes;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             units,
                             Wt::Dbo::ManyToOne,
                             "UNT_UTY");
            

            //TJ
//            Wt::Dbo::hasMany(a,
//                             widgetTypes,
//                             Wt::Dbo::ManyToMany,
//                             "TJ_WTY_UTY");

            
        }
    protected:
    private:
};

#endif // UNITTYPE_H
