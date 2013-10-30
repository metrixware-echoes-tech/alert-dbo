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

#ifndef MEDIA_H
#define MEDIA_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {
    class MediaValue;

    class Media : public Table
    {
    public:
        Media();
        virtual ~Media();
        static std::string TRIGRAM;
        Wt::WString name;

        Wt::Dbo::collection<Wt::Dbo::ptr<MediaValue> > mediaValues;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"] = &this->name;

            FIELD_FILLER();
            Wt::Dbo::hasMany(a,
                    mediaValues,
                    Wt::Dbo::ManyToOne,
                    TRIGRAM_MEDIA_VALUE SEP TRIGRAM_MEDIA);
        }

        virtual std::string toJSON() const;

    protected:
    private:
    };
  }
}

#endif // MEDIA_H

