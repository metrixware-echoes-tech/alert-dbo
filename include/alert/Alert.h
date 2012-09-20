#ifndef ALERT_H
#define ALERT_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class AlertAcknowledge;
class AlertSequence;
class AlertValue;
class Engine;

class Alert : public Table
{
    public:
        Alert();
        virtual ~Alert();
        
        static std::string TRIGRAM;
        
        Wt::WString name;
        Wt::WDateTime creaDate; //creation date of the alert
        Wt::WDateTime lastAttempt; //last time an engine process the alert (use to detect a zombie alert thread)
        int threadSleep;

        
//        const Wt::WString& name_() const {return *name;};
        
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertAcknowledge> > alertAcks;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertTracking> > alertTrackings;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<MediaValue> > mediaValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<Asset> > assets;
        
        Wt::Dbo::ptr<AlertValue> alertValue;
        Wt::Dbo::ptr<AlertSequence> alertSequence;
        Wt::Dbo::ptr<Engine> engine;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesDates["CREA_DATE"]=&this->creaDate;
            mapClassAttributesDates["LAST_ATTEMPT"]=&this->lastAttempt;      
            mapClassAttributesInts["THREAD_SLEEP"]=&this->threadSleep;

            
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a, alertAcks, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_ACKNOWLEDGE SEP TRIGRAM_ALERT);
            Wt::Dbo::hasMany(a, alertTrackings, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_TRACKING SEP TRIGRAM_ALERT);
            Wt::Dbo::hasMany(a, mediaValues, Wt::Dbo::ManyToMany, "TJ" SEP TRIGRAM_MEDIA_VALUE SEP TRIGRAM_ALERT);
            Wt::Dbo::hasMany(a, assets, Wt::Dbo::ManyToMany, "TJ" SEP TRIGRAM_ASSET SEP TRIGRAM_ALERT);
            
            Wt::Dbo::belongsTo(a,alertValue, TRIGRAM_ALERT SEP TRIGRAM_ALERT_VALUE);
            Wt::Dbo::belongsTo(a,alertSequence, TRIGRAM_ALERT_SEQUENCE SEP "FIRST_ID");
            Wt::Dbo::belongsTo(a,engine, TRIGRAM_ALERT SEP TRIGRAM_ENGINE);

        }
    protected:
    private:
};

#endif // ALERT_H
