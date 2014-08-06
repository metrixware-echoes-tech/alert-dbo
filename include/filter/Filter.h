/* 
 * Header of Filter Table
 * @author ECHOES Technologies (TSA)
 * @date 30/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef FILTER_H
#define	FILTER_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Filter : public Table {
        public:
            Filter();
            Filter(const Filter& orig);
            virtual ~Filter();

            static std::string TRIGRAM;

            int nbValue;
            int posKeyValue;

            Wt::Dbo::ptr<FilterType> filterType;
            Wt::Dbo::ptr<Search> search;        

            Wt::Dbo::collection<Wt::Dbo::ptr<InformationData>> informationDatas;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesInts["NB_VALUE"] = &this->nbValue;
                mapClassAttributesInts["POS_KEY_VALUE"] = &this->posKeyValue;
                Table::fieldFiller(a, *this);
                Wt::Dbo::belongsTo(a, filterType, TRIGRAM_FILTER SEP TRIGRAM_FILTER_TYPE);
                Wt::Dbo::belongsTo(a, search, TRIGRAM_FILTER SEP TRIGRAM_SEARCH);
                Wt::Dbo::hasMany(a, informationDatas, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_FILTER);
            }

        private:
    };
  }
}

#endif	/* FILTER_H */

