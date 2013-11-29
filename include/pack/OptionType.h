/* 
 * Header of Option Table
 * @author ECHOES Technologies (TSA)
 * @date 03/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef OPTIONTYPE_H
#define OPTIONTYPE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class OptionType : public Table
    {
        public:
            OptionType();
            virtual ~OptionType();
            static std::string TRIGRAM;
            Wt::WString name;

            Wt::Dbo::collection<Wt::Dbo::ptr<PackOption> > packOptions;
            Wt::Dbo::collection<Wt::Dbo::ptr<Option> > options;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                FIELD_FILLER();

                Wt::Dbo::hasMany(a, packOptions, Wt::Dbo::ManyToOne, TRIGRAM_PACK_OPTION SEP TRIGRAM_OPTION_TYPE);
                Wt::Dbo::hasMany(a, options, Wt::Dbo::ManyToOne, TRIGRAM_OPTION SEP TRIGRAM_OPTION_TYPE);

            }


        protected:
        private:
    };
  }
}

#endif // OPTIONTYPE_H

