#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"

class Unit;
class WidgetType;

class UnitType : public Table
{
    public:
        UnitType();
        virtual ~UnitType();
        
        static std::string TRIGRAM;
        
        std::string name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Unit> > units;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<WidgetType> > widgetTypes;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             units,
                             Wt::Dbo::ManyToOne,
                             "UNT_UTY");
            

            //TJ
            Wt::Dbo::hasMany(a,
                             widgetTypes,
                             Wt::Dbo::ManyToMany,
                             "TJ_WTY_UTY");

            
        }
    protected:
    private:
};

#endif // UNITTYPE_H
