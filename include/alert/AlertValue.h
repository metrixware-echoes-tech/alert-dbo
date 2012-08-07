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
        Wt::Dbo::ptr<Alert> alert;
        Wt::Dbo::ptr<AlertParam> alertParam;
        Wt::Dbo::ptr<Information2> information;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["VALUE"]=&this->value; 
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a,alert,TRIGRAM_ALERT_VALUE SEP TRIGRAM_ALERT);
            
            Wt::Dbo::belongsTo(a,alertParam,TRIGRAM_ALERT_VALUE SEP TRIGRAM_ALERT_PARAM);
            
            Wt::Dbo::belongsTo(a,information,TRIGRAM_ALERT_VALUE SEP TRIGRAM_INFORMATION);
                 
        }
    protected:
    private:
};

#endif // ALERTVALUE_H
