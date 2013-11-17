/* 
 * Header of Search Unit Table
 * @author ECHOES Technologies (RHI)
 * @date 09/10/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef SEARCHUNIT_H
#define	SEARCHUNIT_H

#include "Wt/Dbo/Dbo"

#include "tools/MainIncludeFile.h"

#include "primaryKeys/SearchUnitId.h"

namespace Echoes
{
  namespace Dbo
  {
    class SearchUnit : public Table
    {
        public:
            SearchUnit();
            virtual ~SearchUnit();

            static std::string TRIGRAM;

            SearchUnitId pk;
            Wt::Dbo::ptr<InformationUnit> informationUnit;

            template<class Action>
            void persist(Action& a)
            {
                FIELD_FILLER();

                Wt::Dbo::id(a, pk, TRIGRAM_SEARCH_UNIT ID);

                Wt::Dbo::belongsTo(a, informationUnit, TRIGRAM_SEARCH_UNIT SEP TRIGRAM_INFORMATION_UNIT);
            }

            virtual std::string toJSON() const;

        private:
    };
  }
}

#endif	/* SEARCHUNIT_H */

