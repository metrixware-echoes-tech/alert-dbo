/* 
 * Header of Search Parameter Value Table
 * @author ECHOES Technologies (TSA)
 * @date 07/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef SEARCHPARAMETERVALUE_H
#define	SEARCHPARAMETERVALUE_H

#include "tools/MainIncludeFile.h"
#include "primaryKeys/SearchParameterValueId.h"

namespace Echoes
{
  namespace Dbo
  {
    class SearchParameterValue : public Table
    {
        public:
            SearchParameterValue();
            virtual ~SearchParameterValue();

            static std::string TRIGRAM;

            Wt::WString value;

            SearchParameterValueId searchParameterValueId;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;
                Table::fieldFiller(a, *this);
                Wt::Dbo::id(a, searchParameterValueId, "SEV_ID");
            }

        private:
    };
  }
}

#endif	/* SEARCHPARAMETERVALUE_H */

