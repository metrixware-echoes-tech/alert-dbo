/* 
 * File:   Syslog.h
 * Author: tsa
 *
 * Created on 5 juin 2012, 17:44
 */

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"

#ifndef SYSLOG_H
#define	SYSLOG_H

class Syslog : public Table
{
public:
    Syslog();
    Syslog(const Syslog& orig);
    virtual ~Syslog();

    static std::string TRIGRAM;
    Wt::WDateTime deleteTag;
    std::string sd;
    Wt::WDateTime rcptDate;  
    Wt::WDateTime sentDate;
    std::string hostname;
    std::string appName;
    int procId;
    int msgId;
    int syslogVers;
    
    Wt::Dbo::ptr<Probe> probe;
    Wt::Dbo::collection<Wt::Dbo::ptr<Value> > values;
    Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue> > historicalValues;
        
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::belongsTo(a, probe, "PRB");
        
        Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             "VAL_SLO");
        Wt::Dbo::hasMany(a,
                            historicalValues,
                            Wt::Dbo::ManyToOne,
                            "HVA_SLO");
        mapClassAttributesStrings["SD"]=this->sd;  
        mapClassAttributesDates["RCPT_DATE"]=this->rcptDate;  
        mapClassAttributesDates["SENT_DATE"]=this->sentDate;
        mapClassAttributesStrings["HOSTNAME"]=this->hostname;          
        mapClassAttributesStrings["APP-NAME"]=this->appName;  
      //  mapClassAttributesInts["PROCID"]=this->procId; 
      //  mapClassAttributesInts["MSGID"]=this->msgId; 
      //  mapClassAttributesInts["VER"]=this->syslogVers;         
    }
private:

};

#endif	/* SYSLOG_H */

