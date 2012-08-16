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
        
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertSequence> > alertSequences;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["VALUE"]=&this->value; 
            
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,alerts,Wt::Dbo::ManyToOne, TRIGRAM_ALERT SEP TRIGRAM_ALERT_VALUE);
            
            Wt::Dbo::belongsTo(a,information,TRIGRAM_ALERT_VALUE SEP TRIGRAM_INFORMATION);
            
            Wt::Dbo::hasMany(a, alertSequences,Wt::Dbo::ManyToOne, TRIGRAM_ALERT_SEQUENCE SEP TRIGRAM_ALERT_VALUE);
                 
        }
    protected:
    private:
};

#endif // ALERTVALUE_H
