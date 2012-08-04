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

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["VALUE"]=&this->value;
            FIELD_FILLER();

            Wt::Dbo::belongsTo(a,media,TRIGRAM_MEDIA_VALUE SEP TRIGRAM_MEDIA);
            Wt::Dbo::belongsTo(a,user,TRIGRAM_MEDIA_VALUE SEP TRIGRAM_USER);
            
            
        }
    protected:
    private:
};


#endif	/* MEDIAVALUE_H */

