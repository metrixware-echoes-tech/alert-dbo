#ifndef HISTORICALVALUE_H
#define HISTORICALVALUE_H

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"

#include "InformationId.h"

class Plugin;
class Probe;
//class Information2;

class HistoricalValue : public Table
{
    public:
        HistoricalValue();
        virtual ~HistoricalValue();
        
        static std::string TRIGRAM;
        
        int subSearchNumber;
        Wt::WDateTime creationDate;        
        Wt::WDateTime deleteTag;
        std::string value;
        
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<Syslog> syslog;
        InformationId informationId;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::field(a, informationId.searchId.id, "SEA_ID");
            Wt::Dbo::field(a, informationId.searchId.sourceId.id, "SRC_ID");
            Wt::Dbo::field(a, informationId.searchId.sourceId.plugin, "PLG_ID");
            Wt::Dbo::belongsTo(a, asset, "HVA_AST");
            Wt::Dbo::belongsTo(a, syslog, "HVA_SLO");
            mapClassAttributesDates["DELETE"]=this->deleteTag;
            mapClassAttributesDates["CREA_DATE"]=this->creationDate;  
            mapClassAttributesStrings["VALUE"]=this->value;             
        //RHI : map class for the int type     mapClassAttributesInt["SEA-SUB_NUM"]=this->subSearchNumber;
        }

    protected:
    private:
};

#endif // HISTORICALVALUE_H
