#ifndef ALERT_H
#define ALERT_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"

class AlertHisto;
class AlertValue;
class AlertType;

class Alert : public Table
{
    public:
        Alert();
        virtual ~Alert();
        
        static std::string TRIGRAM;
        
        std::string name;
        Wt::WDateTime date;
        Wt::WDateTime deleteTag;
        
        // RHI: manque TJ_ALE_USR_MED
        Wt::Dbo::ptr<AlertType> alertType;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertHisto> > alertHistos;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, alertType,"ATY");
            
            Wt::Dbo::hasMany(a,
                             alertHistos,
                             Wt::Dbo::ManyToOne,
                             "ALH");
            Wt::Dbo::hasMany(a,
                             alertValues,
                             Wt::Dbo::ManyToOne,
                             "ALE_ID");
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesDates["DATE"]=this->date;
            mapClassAttributesDates["DELETE"]=this->deleteTag;
        }
    protected:
    private:
};

#endif // ALERT_H
