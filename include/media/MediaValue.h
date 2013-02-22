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
        bool isDefault;

        Wt::Dbo::ptr<Media> media;
        Wt::Dbo::ptr<User> user;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertTracking> > alertTrackings;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertMediaSpecialization> > alertMediaSpecializations;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["VALUE"]=&this->value;
            mapClassAttributesBools["IS_DEFAULT"]=&this->isDefault;
            FIELD_FILLER();

            Wt::Dbo::belongsTo(a,media,TRIGRAM_MEDIA_VALUE SEP TRIGRAM_MEDIA);
            Wt::Dbo::belongsTo(a,user,TRIGRAM_MEDIA_VALUE SEP TRIGRAM_USER);
            
            Wt::Dbo::hasMany(a, alertTrackings, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_TRACKING SEP TRIGRAM_MEDIA_VALUE);
            Wt::Dbo::hasMany(a, alertMediaSpecializations, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_MEDIA_VALUE);
            
            
        }
    protected:
    private:
};


#endif	/* MEDIAVALUE_H */

