#ifndef ADDON_H
#define ADDON_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class Plugin;
class Source;

class Addon : public Table
{
    public:
        Addon();
        virtual ~Addon();
        
        static std::string TRIGRAM;
        
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Source> > sources;
        Wt::Dbo::collection<Wt::Dbo::ptr<SourceParameter> > sourceParameters;
        Wt::Dbo::collection<Wt::Dbo::ptr<SearchType> > searchTypes;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            FIELD_FILLER();
            Wt::Dbo::hasMany(a,
                             sources,
                             Wt::Dbo::ManyToOne,
                             "SRC_ADO"); 
            
            //TJ
            Wt::Dbo::hasMany(a,
                             sourceParameters,
                             Wt::Dbo::ManyToMany,
                             "TJ_ADO_SRP"); 
            
            Wt::Dbo::hasMany(a,
                             searchTypes,
                             Wt::Dbo::ManyToMany,
                             "TJ_ADO_STY");
        }
        
        virtual std::string toJSON();
        
    protected:
    private:
};

#endif // ADDON_H
