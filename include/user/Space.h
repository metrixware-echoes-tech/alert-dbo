/* 
 * Header of Space Table
 * @author ECHOES Technologies (RHI)
 * @date 10/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef SPACE_H
#define	SPACE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Space : public Table
    {
        public:
            Space();
            virtual ~Space();

            static std::string TRIGRAM;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                Table::fieldFiller(a, *this);
            }
    };
  }
}

#endif	/* SPACE_H */

