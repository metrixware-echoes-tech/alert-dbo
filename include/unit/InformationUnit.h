/* 
 * Header of Information Unit Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef INFORMATIONUNIT_H
#define INFORMATIONUNIT_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Information;
    class InformationUnitType;
    class SearchUnit;

    class InformationUnit : public Table
    {
        public:
            InformationUnit();
            virtual ~InformationUnit();

            static std::string TRIGRAM;

            Wt::WString name;

            Wt::Dbo::collection<Wt::Dbo::ptr<SearchUnit> > searchUnits;
            Wt::Dbo::collection<Wt::Dbo::ptr<InformationSubUnit> > informationSubUnits;
            Wt::Dbo::ptr<InformationUnitType> unitType;
            
            Wt::Dbo::weak_ptr<Information> information;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;

                FIELD_FILLER();

                Wt::Dbo::belongsTo(a, unitType, TRIGRAM_INFORMATION_UNIT SEP TRIGRAM_INFORMATION_UNIT_TYPE);

                Wt::Dbo::hasOne(a, information, TRIGRAM_INFORMATION SEP TRIGRAM_INFORMATION_UNIT);
                
                Wt::Dbo::hasMany(a,
                        searchUnits,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_SEARCH_UNIT SEP TRIGRAM_INFORMATION_UNIT);

                Wt::Dbo::hasMany(a,
                        informationSubUnits,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_INFORMATION_SUB_UNIT SEP TRIGRAM_INFORMATION_UNIT);
                
                
            }

            virtual std::string toJSON() const;

        protected:
        private:
    };
  }
}

#endif // INFORMATIONUNIT_H

