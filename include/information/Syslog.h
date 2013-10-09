/* 
 * Header of Syslog Table
 * @author ECHOES Technologies (TSA)
 * @date 05/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

#ifndef SYSLOG_H
#define	SYSLOG_H

class Syslog : public Table
{
public:
    Syslog();
    Syslog(const Syslog& orig);
    virtual ~Syslog();

    static std::string TRIGRAM;
    Wt::WString sd;
    Wt::WDateTime rcptDate;  
    Wt::WDateTime sentDate;
    Wt::WString hostname;
    Wt::WString appName;
    Wt::WString msgId;
    int priority;
    int procId;
    
    boost::optional<int> version;
    // state : 0 = pending, 1 = processing, 2 = done
    short state;
    
    Wt::Dbo::ptr<Probe> probe;
    Wt::Dbo::collection<Wt::Dbo::ptr<InformationValue> > values;
    Wt::Dbo::collection<Wt::Dbo::ptr<InformationHistoricalValue> > historicalValues;
        
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["SD"]=&this->sd;  
        mapClassAttributesDates["RCPT_DATE"]=&this->rcptDate;  
        mapClassAttributesDates["SENT_DATE"]=&this->sentDate;
        mapClassAttributesStrings["HOSTNAME"]=&this->hostname;          
        mapClassAttributesStrings["APP_NAME"]=&this->appName;  
        mapClassAttributesStrings["MSG_ID"]=&this->msgId;
        mapClassAttributesInts["PROC_ID"]=&this->procId;
        mapClassAttributesInts["PRI"]=&this->priority;
        mapClassAttributesIntsNn["VERSION"]=&this->version;
        mapClassAttributesShorts["STATE"]=&this->state;
     
        
        FIELD_FILLER();

        Wt::Dbo::belongsTo(a, probe, "SLO_PRB");
        
        Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_SYSLOG);
        Wt::Dbo::hasMany(a,
                            historicalValues,
                            Wt::Dbo::ManyToOne,
                            TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_SYSLOG);
            
    }
    
    virtual std::string toJSON() const;
    
private:

};

#endif	/* SYSLOG_H */

