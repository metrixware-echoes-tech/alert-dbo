#ifndef ALERTVALUE_H
#define ALERTVALUE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class Alert;

class AlertValue : public Table
{
    public:
        AlertValue();
        virtual ~AlertValue();
        
        static std::string TRIGRAM;
        
        Wt::WString value;
        Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
        Wt::Dbo::ptr<Information2> information;
        Wt::Dbo::ptr<AlertCriteria> alertCriteria;
        
        
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertSequence> > alertSequences;
        
        Wt::WString lot_key_value;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["VALUE"]=&this->value;
            mapClassAttributesStrings["LOT_KEY_VALUE"]=&this->lot_key_value;
            
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,alerts,Wt::Dbo::ManyToOne, TRIGRAM_ALERT SEP TRIGRAM_ALERT_VALUE);
            
            Wt::Dbo::belongsTo(a,information,TRIGRAM_ALERT_VALUE SEP TRIGRAM_INFORMATION);
            Wt::Dbo::belongsTo(a,alertCriteria,TRIGRAM_ALERT_VALUE SEP TRIGRAM_ALERT_CRITERIA);
            
            Wt::Dbo::hasMany(a, alertSequences,Wt::Dbo::ManyToOne, TRIGRAM_ALERT_SEQUENCE SEP TRIGRAM_ALERT_VALUE);
                 
        }
    protected:
    private:
};

#endif // ALERTVALUE_H
