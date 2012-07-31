/* 
 * File:   AlertAcknowledgeEvent.h
 * Author: tsa
 *
 * Created on 30 juillet 2012, 17:02
 */

#ifndef ALERTACKNOWLEDGEEVENT_H
#define	ALERTACKNOWLEDGEEVENT_H

#include <tools/MainIncludeFile.h>
#include <Wt/Dbo/Dbo>

#include <boost/optional.hpp>

class AlertTrackingEvent : public Table
{
public:
    AlertTrackingEvent();
    AlertTrackingEvent(const AlertTrackingEvent& orig);
    virtual ~AlertTrackingEvent();
    static std::string TRIGRAM;
//    boost::optional<std::string> eventValue;
    std::string eventValue;
    
     Wt::Dbo::ptr<AlertTracking> alertTracking;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["EVENT_VALUE"]=this->eventValue;
//        Wt::Dbo::field(a, this->eventValue, formatColumnName(*this,"EVENT_VALUE"));
        FIELD_FILLER();
        Wt::Dbo::belongsTo(a,alertTracking,TRIGRAM_ALERT_TRACKING_EVENT SEP TRIGRAM_ALERT_TRACKING);
    }
private:

};

#endif	/* ALERTACKNOWLEDGEEVENT_H */

