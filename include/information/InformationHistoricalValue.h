#ifndef INFORMATIONHISTORICALVALUE_H
#define INFORMATIONHISTORICALVALUE_H

#include <Wt/Dbo/Types>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>
#include <Wt/WGlobal>

#include "tools/MainIncludeFile.h"

#include "primaryKeys/InformationId.h"

class Plugin;
//class Probe;
class Asset;
class Syslog;
class Information2;



class InformationHistoricalValue : public Table
{
    public:
        InformationHistoricalValue();
        virtual ~InformationHistoricalValue();
        
        static std::string TRIGRAM;
        
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<Syslog> syslog;
        Wt::Dbo::ptr<Information2> information;

        Wt::WString value;
        Wt::WDateTime CreatedDate;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesDates["CREA_DATE"]=&this->CreatedDate;
            mapClassAttributesStrings["VALUE"]=&this->value;
            FIELD_FILLER();
            Wt::Dbo::belongsTo(a, asset, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_ASSET);
            Wt::Dbo::belongsTo(a, syslog, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_SYSLOG);
            Wt::Dbo::field(a,information, TRIGRAM_INFORMATION ID);
        }

    protected:
    private:
};

#endif // INFORMATIONHISTORICALVALUE_H
