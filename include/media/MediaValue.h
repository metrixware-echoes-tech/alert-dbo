/* 
 * File:   MediaValue.h
 * Author: tsa
 *
 * Created on 23 juillet 2012, 13:58
 */

#ifndef MEDIAVALUE_H
#define	MEDIAVALUE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class MediaValue : public Table
{
    public:
        MediaValue();
        virtual ~MediaValue();
        
        static std::string TRIGRAM;
        Wt::WString value;

        Wt::Dbo::ptr<Media> media;
        Wt::Dbo::ptr<User> user;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertTracking> > alertTrackings;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
        
        bool notifEndOfAlert;
        int snoozeDuration;
        

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["VALUE"]=&this->value;
            mapClassAttributesBools["NOTIF_END_OF_ALERT"]=&this->notifEndOfAlert;
            mapClassAttributesInts["SNOOZE"]=&this->snoozeDuration;
            FIELD_FILLER();

            Wt::Dbo::belongsTo(a,media,TRIGRAM_MEDIA_VALUE SEP TRIGRAM_MEDIA);
            Wt::Dbo::belongsTo(a,user,TRIGRAM_MEDIA_VALUE SEP TRIGRAM_USER);
            
            Wt::Dbo::hasMany(a, alertTrackings, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_TRACKING SEP TRIGRAM_MEDIA_VALUE);
            
            Wt::Dbo::hasMany(a,
                             alerts,
                             Wt::Dbo::ManyToMany,
                             "TJ" SEP TRIGRAM_MEDIA_VALUE SEP TRIGRAM_ALERT);
            
            
        }
    protected:
    private:
};


#endif	/* MEDIAVALUE_H */

