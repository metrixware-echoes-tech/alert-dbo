#ifndef ALERT_H
#define ALERT_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class AlertAcknowledge;
class AlertValue;
class AlertType;

class Alert : public Table
{
    public:
        Alert();
        virtual ~Alert();
        
        static std::string TRIGRAM;
        
        Wt::WString name;
        Wt::WDateTime date;

        
//        const Wt::WString& name_() const {return *name;};
        
        // RHI: manque TJ_ALE_USR_MED
        Wt::Dbo::ptr<AlertType> alertType;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertAcknowledge> > alertAcks;
//        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesDates["DATE"]=&this->date;
            
//            Wt::Dbo::field(a, this->name, formatColumnName(*this,"NAME"));
            
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a, alertType,"ALE_ATY");
            
            Wt::Dbo::hasMany(a,
                             alertAcks,
                             Wt::Dbo::ManyToOne,
                             "ACK_ALE");
//            Wt::Dbo::hasMany(a,
//                             alertValues,
//                             Wt::Dbo::ManyToOne,
//                             "ALE_ID");
        }
    protected:
    private:
};

#endif // ALERT_H
