/* 
 * Header of Media Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef MEDIATYPE_H
#define MEDIATYPE_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {
    class Media;

    class MediaType : public Table
    {
    public:
        MediaType();
        virtual ~MediaType();
        static std::string TRIGRAM;
        Wt::WString name;

        Wt::Dbo::collection<Wt::Dbo::ptr<Media> > medias;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"] = &this->name;

            FIELD_FILLER();
            Wt::Dbo::hasMany(a,
                    medias,
                    Wt::Dbo::ManyToOne,
                    TRIGRAM_MEDIA SEP TRIGRAM_MEDIA_TYPE);
        }

    protected:
    private:
    };
  }
}

#endif // MEDIATYPE_H

