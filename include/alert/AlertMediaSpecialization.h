/* 
 * File:   AlertMediaSpecialization.h
 * Author: tsa
 *
 * Created on 24 septembre 2012, 14:27
 */

#ifndef ALERTMEDIASPECIALIZATION_H
#define	ALERTMEDIASPECIALIZATION_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

class AlertMediaSpecialization : public Table 
{
public:
    AlertMediaSpecialization();
    AlertMediaSpecialization(const AlertMediaSpecialization& orig);
    virtual ~AlertMediaSpecialization();
    static std::string TRIGRAM;
    Wt::WDateTime lastSend; //last time the alert was send to a media
    bool notifEndOfAlert;
    int snoozeDuration;
    Wt::WString message;
    
    Wt::Dbo::ptr<Alert> alert;
    Wt::Dbo::ptr<MediaValue> mediaValue;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesBools["NOTIF_END_OF_ALERT"]=&this->notifEndOfAlert;
        mapClassAttributesInts["SNOOZE"]=&this->snoozeDuration;
        mapClassAttributesDates["LAST_SEND"]=&this->lastSend;
        mapClassAttributesStrings["MESSAGE"]=&this->message;
        
        FIELD_FILLER();
        
        Wt::Dbo::belongsTo(a,alert, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_ALERT);
        Wt::Dbo::belongsTo(a,mediaValue, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_MEDIA_VALUE);
    }
    
    virtual std::string toJSON();
    
private:

};

#endif	/* ALERTMEDIASPECIALIZATION_H */


