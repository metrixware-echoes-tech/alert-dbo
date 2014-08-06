/* 
 * Header of Filter Parameter Value Table
 * @author ECHOES Technologies (TSA)
 * @date 09/12/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef FILTERPARAMETERVALUE_H
#define	FILTERPARAMETERVALUE_H

#include "tools/MainIncludeFile.h"

#include "primaryKeys/FilterParameterValueId.h"

namespace Echoes
{
  namespace Dbo
  {
    class FilterParameterValue : public Table
    {
        public:
            FilterParameterValue();
            virtual ~FilterParameterValue();

            static std::string TRIGRAM;
            Wt::WString value;

            FilterParameterValueId filteParameterValueId;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;
                Table::fieldFiller(a, *this);
                Wt::Dbo::id(a, filteParameterValueId, TRIGRAM_FILTER_PARAMETER_VALUE ID);
            }

        private: 
    };
  }
}
#endif	/* FILTERPARAMETERVALUE_H */

