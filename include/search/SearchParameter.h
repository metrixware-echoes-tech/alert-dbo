/* 
 * Header of Search Parameter Table
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

#ifndef SEARCHPARAMETER_H
#define	SEARCHPARAMETER_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class SearchParameter : public Table
    {
        public:
            SearchParameter();
            SearchParameter(const SearchParameter& orig);
            virtual ~SearchParameter();

            static std::string TRIGRAM;

            Wt::WString format;

            Wt::Dbo::collection<Wt::Dbo::ptr<SearchType> > searchTypes;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["FORMAT"] = &this->format;
                Table::fieldFiller(a, *this);
                Wt::Dbo::hasMany(a,
                        searchTypes,
                        Wt::Dbo::ManyToMany,
                        "TJ_STY_SEP");
            }

        private:
    };
  }
}

#endif	/* SEARCHPARAMETER_H */

