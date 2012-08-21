#ifndef INFORMATIONVALUE_H
#define INFORMATIONVALUE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

#include "primaryKeys/InformationId.h"

class Plugin;
class Probe;
class Information2;

class InformationValue : public Table
{
    public:
        InformationValue();
        virtual ~InformationValue();
        
        static std::string TRIGRAM;
        
        Wt::WDateTime creationDate;        
        Wt::WString value;
        
        int state;
        
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<Syslog> syslog;
        Wt::Dbo::ptr<Information2> information;
//        InformationId informationId;

        template<class Action>
        void persist(Action& a)
        {   
            mapClassAttributesDates["CREA_DATE"]=&this->creationDate;  
            mapClassAttributesStrings["VALUE"]=&this->value;             
            mapClassAttributesInts["STATE"]=&this->state;
            FIELD_FILLER();
            Wt::Dbo::belongsTo(a, asset, TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_ASSET);
            Wt::Dbo::belongsTo(a, syslog, TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_SYSLOG);
            Wt::Dbo::field(a,information, TRIGRAM_INFORMATION ID);

            
        }

    protected:
    private:
};

#endif // INFORMATIONVALUE_H
