#ifndef ALERT_H
#define ALERT_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "MainIncludeFile.h"

class AlertAcknowledge;
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
        
        // RHI: manque TJ_ALE_USR_MED
        Wt::Dbo::ptr<AlertType> alertType;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertAcknowledge> > alertAcks;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;
            mapClassAttributesDates["DATE"]=this->date;
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a, alertType,"ALE_ATY");
            
            Wt::Dbo::hasMany(a,
                             alertAcks,
                             Wt::Dbo::ManyToOne,
                             "ACK_ALE");
            Wt::Dbo::hasMany(a,
                             alertValues,
                             Wt::Dbo::ManyToOne,
                             "ALE_ID");
        }
    protected:
    private:
};

#endif // ALERT_H
