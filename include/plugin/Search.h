/* 
 * Header of Search Table
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

#ifndef SEARCH_H
#define	SEARCH_H

#include "Wt/Dbo/Dbo"

#include "tools/MainIncludeFile.h"

#include "primaryKeys/SearchId.h"

namespace Echoes
{
  namespace Dbo
  {
    class Search : public Table
    {
        public:
            Search();
            Search(const Search& orig);
            virtual ~Search();

            static std::string TRIGRAM;
            int nbValue;
            int period;
            bool searchIsStatic;

            SearchId pk;
            Wt::Dbo::ptr<SearchType> searchType;


            int pos_key_value;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesInts["NB_VALUE"] = &this->nbValue;
                mapClassAttributesInts["PERIOD"] = &this->period;
                mapClassAttributesBools["IS_STATIC"] = &this->searchIsStatic;
                mapClassAttributesInts["POS_KEY_VALUE"] = &this->pos_key_value;

                FIELD_FILLER();

                Wt::Dbo::id(a, pk, "SEA_ID");

                Wt::Dbo::belongsTo(a, searchType, "SEA_STY");

            }
            virtual std::string toJSON() const;
        private:
    };
  }
}

#endif	/* SEARCH_H */

