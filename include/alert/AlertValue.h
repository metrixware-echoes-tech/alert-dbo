#ifndef ALERTVALUE_H
#define ALERTVALUE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"

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
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["VALUE"]=this->value; 
            
            FIELD_FILLER();
            
            Wt::Dbo::id(a,alert,"AVA");
            
            Wt::Dbo::belongsTo(a,alertParam,"AVA_APA");
                 
        }
    protected:
    private:
};

#endif // ALERTVALUE_H
