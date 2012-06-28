#ifndef VALUE_H
#define VALUE_H

#include <Wt/Dbo/Types>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>
#include <Wt/WGlobal>

#include "MainIncludeFile.h"

#include "InformationId.h"

class Plugin;
//class Probe;
class Asset;
class Syslog;
//class Information2;



class Value : public Table
{
    public:
        Value();
        virtual ~Value();
        
        static std::string TRIGRAM;
        
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<Syslog> syslog;
        InformationId informationId;
        int mNumSubSearch;
        std::string value;
        Wt::WDateTime CreatedDate;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesDates["CREA_DATE"]=this->CreatedDate;
            mapClassAttributesStrings["VALUE"]=this->value;
            FIELD_FILLER();
            Wt::Dbo::field(a, informationId.searchId.id, "SEA_ID");
            Wt::Dbo::field(a, informationId.searchId.sourceId.id, "SRC_ID");
            Wt::Dbo::field(a, informationId.searchId.sourceId.plugin, "PLG_ID");
            Wt::Dbo::belongsTo(a, asset, "VAL_AST");
            Wt::Dbo::belongsTo(a, syslog, "VAL_SLO");
            
            Wt::Dbo::field(a,mNumSubSearch, "SUB_SEARCH_NUM");
        }

    protected:
    private:
};

#endif // VALUE_H
