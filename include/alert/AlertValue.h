#ifndef ALERTVALUE_H
#define ALERTVALUE_H

#include "Table.h"
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "Alert.h"
#include "AlertHisto.h"
#include "AlertCriteria.h"

class Alert;

class AlertValue : public Table
{
    public:
        AlertValue();
        virtual ~AlertValue();
        
        static std::string TRIGRAM;
        
        std::string value;
        Wt::Dbo::ptr<Alert> alert;
        Wt::Dbo::ptr<AlertParam> alertParam;
        Wt::WDateTime deleteTag;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::id(a,alert,"AVA");
            
            Wt::Dbo::belongsTo(a,alertParam,"APA");
            mapClassAttributesStrings["VALUE"]=this->value;
            mapClassAttributesDates["DELETE"]=this->deleteTag;       
        }
    protected:
    private:
};

#endif // ALERTVALUE_H
