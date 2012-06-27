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
    std::string sd;
    Wt::WDateTime rcptDate;  
    Wt::WDateTime sentDate;
    std::string hostname;
    std::string appName;
    int procId;
    int msgId;
    int version;
    
    Wt::Dbo::ptr<Probe> probe;
    Wt::Dbo::collection<Wt::Dbo::ptr<Value> > values;
    Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue> > historicalValues;
        
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["SD"]=this->sd;  
        mapClassAttributesDates["RCPT_DATE"]=this->rcptDate;  
        mapClassAttributesDates["SENT_DATE"]=this->sentDate;
        mapClassAttributesStrings["HOSTNAME"]=this->hostname;          
        mapClassAttributesStrings["APP_NAME"]=this->appName;  
        mapClassAttributesInts["PROC_ID"]=this->procId;
        mapClassAttributesInts["MSG_ID"]=this->msgId;
        mapClassAttributesInts["VERSION"]=this->version;
        FIELD_FILLER();
        
        Wt::Dbo::belongsTo(a, probe, "SLO_PRB");
        
        Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             "VAL_SLO");
        Wt::Dbo::hasMany(a,
                            historicalValues,
                            Wt::Dbo::ManyToOne,
                            "HVA_SLO");
            
    }
private:

};

#endif	/* SYSLOG_H */

