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

            Wt::Dbo::collection<Wt::Dbo::ptr<Filter>> filters;
            
            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesInts["PERIOD"] = &this->period;

                FIELD_FILLER();

                Wt::Dbo::belongsTo(a, searchType, TRIGRAM_SEARCH SEP TRIGRAM_SEARCH_TYPE);
                Wt::Dbo::belongsTo(a, source, TRIGRAM_SEARCH SEP TRIGRAM_SOURCE);
                Wt::Dbo::hasMany(a, filters, Wt::Dbo::ManyToOne, TRIGRAM_FILTER SEP TRIGRAM_SEARCH);
            }
        private:
    };
  }
}

#endif	/* SEARCH_H */

