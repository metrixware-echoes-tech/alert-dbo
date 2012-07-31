/* 
 * File:   AlertTracking.h
 * Author: tsa
 *
 * Created on 23 juillet 2012, 16:31
 */

#ifndef ALERTTRACKING_H
#define	ALERTTRACKING_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class AlertTracking : public Table
{
    public:
        AlertTracking();
        virtual ~AlertTracking();
        
        static std::string TRIGRAM;
        
        
        boost::optional<std::string> senderSrv;
        Wt::WDateTime sendDate;
        boost::optional<std::string> receiverSrv;
        Wt::WDateTime receiveDate;
        boost::optional<std::string> ackGw;
        boost::optional<std::string> ackPort;
        boost::optional<std::string> ackId;
        boost::optional<std::string> ackEvent;

        Wt::Dbo::ptr<MediaValue> mediaValue;
        Wt::Dbo::ptr<Alert> alert;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertTrackingEvent> > alertTrackingEvents;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStringsNn["SENDER_SRV"]=this->senderSrv;
            mapClassAttributesStringsNn["RECEIVER_SRV"]=this->receiverSrv;
            mapClassAttributesStringsNn["ACK_GW"]=this->ackGw;
            mapClassAttributesStringsNn["ACK_PORT"]=this->ackPort;
            mapClassAttributesStringsNn["ACK_ID"]=this->ackId;
            mapClassAttributesStringsNn["ACK_EVENT"]=this->ackEvent;
            mapClassAttributesDates["SEND_DATE"]=this->sendDate;
            mapClassAttributesDates["RECEIV_DATE"]=this->receiveDate;
            
            
            FIELD_FILLER();

            Wt::Dbo::belongsTo(a,mediaValue,TRIGRAM_ALERT_TRACKING SEP TRIGRAM_MEDIA_VALUE);
            Wt::Dbo::belongsTo(a,alert,TRIGRAM_ALERT_TRACKING SEP TRIGRAM_ALERT);
            
            Wt::Dbo::hasMany(a,
                             alertTrackingEvents,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_ALERT_TRACKING_EVENT SEP TRIGRAM_ALERT_TRACKING);
        }
    protected:
    private:
};


#endif	/* ALERTTRACKING_H */

