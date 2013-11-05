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
            int period;

            Wt::Dbo::ptr<SearchType> searchType;
            Wt::Dbo::ptr<Source> source;
            Wt::Dbo::ptr<Filter> filter;
            
            
            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesInts["PERIOD"] = &this->period;

                FIELD_FILLER();

                Wt::Dbo::belongsTo(a, searchType, TRIGRAM_SEARCH SEP TRIGRAM_SEARCH_TYPE);
                Wt::Dbo::belongsTo(a, source, TRIGRAM_SEARCH SEP TRIGRAM_SOURCE);
                Wt::Dbo::belongsTo(a, filter, TRIGRAM_SEARCH SEP TRIGRAM_FILTER);

            }
            virtual std::string toJSON() const;
        private:
    };
  }
}

#endif	/* SEARCH_H */

