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

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {
    class SearchParameterValue;

    class SearchParameter : public Table
    {
        public:
            SearchParameter();
            SearchParameter(const SearchParameter& orig);
            virtual ~SearchParameter();

            static std::string TRIGRAM;
            Wt::WString name;
            Wt::WString format;

            Wt::Dbo::collection<Wt::Dbo::ptr<SearchType> > searchTypes;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["FORMAT"] = &this->format;
                FIELD_FILLER();
                Wt::Dbo::hasMany(a,
                        searchTypes,
                        Wt::Dbo::ManyToMany,
                        "TJ_STY_SEP");
            }

            virtual std::string toJSON() const;

        private:
    };
  }
}

#endif	/* SEARCHPARAMETER_H */

