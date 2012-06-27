#ifndef ADDON_H
#define ADDON_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"

class Plugin;

class Addon : public Table
{
    public:
        Addon();
        virtual ~Addon();
        
        static std::string TRIGRAM;
        
        std::string name;
        Wt::WDateTime deleteTag;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Source> > sources;
        Wt::Dbo::collection<Wt::Dbo::ptr<SourceParameter> > sourceParameters;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             sources,
                             Wt::Dbo::ManyToOne,
                             "SRC_ADO"); 
            
            //TJ
            Wt::Dbo::hasMany(a,
                             sourceParameters,
                             Wt::Dbo::ManyToMany,
                             "TJ_ADO_SRP"); 
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesDates["DELETE"]=this->deleteTag;
        }
    protected:
    private:
};

#endif // ADDON_H
