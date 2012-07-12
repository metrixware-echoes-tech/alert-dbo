#ifndef HISTORICALVALUE_H
#define HISTORICALVALUE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

#include "primaryKeys/InformationId.h"

class Plugin;
class Probe;
class Information2;

class HistoricalValue : public Table
{
    public:
        HistoricalValue();
        virtual ~HistoricalValue();
        
        static std::string TRIGRAM;
        
        Wt::WDateTime creationDate;        
        std::string value;
        
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<Syslog> syslog;
        Wt::Dbo::ptr<Information2> information;
//        InformationId informationId;

        template<class Action>
        void persist(Action& a)
        {   
            mapClassAttributesDates["CREA_DATE"]=this->creationDate;  
            mapClassAttributesStrings["VALUE"]=this->value;             
            FIELD_FILLER();
            Wt::Dbo::belongsTo(a, asset, "HVA_AST");
            Wt::Dbo::belongsTo(a, syslog, "HVA_SLO");
            Wt::Dbo::field(a,information, "INF_ID");

            
        }

    protected:
    private:
};

#endif // HISTORICALVALUE_H
