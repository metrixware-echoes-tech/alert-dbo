/* 
 * Header of Media Value Table
 * @author ECHOES Technologies (TSA)
 * @date 23/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
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
        Wt::WString token;
        bool isConfirmed;

        Wt::Dbo::ptr<Media> media;
        Wt::Dbo::ptr<User> user;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertTracking> > alertTrackings;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertMediaSpecialization> > alertMediaSpecializations;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["VALUE"]=&this->value;
            mapClassAttributesBools["IS_DEFAULT"]=&this->isDefault;
//            mapClassAttributesStrings["TOKEN"]=&this->token;
//            mapClassAttributesBools["IS_CONFIRMED"]=&this->isConfirmed;
            FIELD_FILLER();

            Wt::Dbo::belongsTo(a,media,TRIGRAM_MEDIA_VALUE SEP TRIGRAM_MEDIA);
            Wt::Dbo::belongsTo(a,user,TRIGRAM_MEDIA_VALUE SEP TRIGRAM_USER);
            
            Wt::Dbo::hasMany(a, alertTrackings, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_TRACKING SEP TRIGRAM_MEDIA_VALUE);
            Wt::Dbo::hasMany(a, alertMediaSpecializations, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_MEDIA_VALUE);
            
            
        }
        
        virtual std::string toJSON() const;
        
    protected:
    private:
};


#endif	/* MEDIAVALUE_H */

