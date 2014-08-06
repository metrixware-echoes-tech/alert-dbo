/* 
 * Header of Filter Parameter Table
 * @author ECHOES Technologies (TSA)
 * @date 30/10/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef FILTERPARAMETER_H
#define	FILTERPARAMETER_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class FilterParameter : public Table {
        public:
            FilterParameter();
            FilterParameter(const FilterParameter& orig);
            virtual ~FilterParameter();

            static std::string TRIGRAM;

            Wt::WString format;

            Wt::Dbo::collection<Wt::Dbo::ptr<FilterType> > filterTypes;

            template<class Action>
            void persist(Action& a) {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["FORMAT"] = &this->format;
                Table::fieldFiller(a, *this);
                Wt::Dbo::hasMany(a,
                        filterTypes,
                        Wt::Dbo::ManyToMany,
                        TABLE_JOINT_PREFIX SEP TRIGRAM_FILTER_TYPE SEP TRIGRAM_FILTER_PARAMETER);
            }

        private:
    };
  }
}

#endif	/* FILTERPARAMETER_H */

