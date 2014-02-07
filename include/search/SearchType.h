/* 
 * Header of Search Type Table
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

#ifndef SEARCHTYPE_H
#define	SEARCHTYPE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Search;

    class SearchType : public Table
    {
        public:
            SearchType();
            SearchType(const SearchType& orig);
            virtual ~SearchType();

            static std::string TRIGRAM;
            Wt::WString name;

            Wt::Dbo::collection<Wt::Dbo::ptr<Search> > searches;
            Wt::Dbo::collection<Wt::Dbo::ptr<SearchParameter> > searchParameters;
            Wt::Dbo::collection<Wt::Dbo::ptr<Addon> > addons;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                FIELD_FILLER();
                Wt::Dbo::hasMany(a,
                        searches,
                        Wt::Dbo::ManyToOne,
                        "SEA_STY");


                Wt::Dbo::hasMany(a,
                        searchParameters,
                        Wt::Dbo::ManyToMany,
                        "TJ_STY_SEP");

                Wt::Dbo::hasMany(a,
                        addons,
                        Wt::Dbo::ManyToMany,
                        "TJ_ADO_STY");
            }

            virtual std::string toJSON() const;

        private:
    };
  }
}

#endif	/* SEARCHTYPE_H */

