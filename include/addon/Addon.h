/* 
 * Header of Addon Table
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

#ifndef ADDON_H
#define ADDON_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Addon : public Table
    {
        public:
            Addon();
            virtual ~Addon();

            static std::string TRIGRAM;

            Wt::Dbo::collection<Wt::Dbo::ptr<Source> > sources;
            Wt::Dbo::collection<Wt::Dbo::ptr<SourceParameter> > sourceParameters;
            Wt::Dbo::collection<Wt::Dbo::ptr<SearchType> > searchTypes;

            Wt::Dbo::collection<Wt::Dbo::ptr<AddonPackageParameter> > addonPackageParameter;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                Table::fieldFiller(a, *this);
                Wt::Dbo::hasMany(a,
                        sources,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_SOURCE SEP TRIGRAM_ADDON);

                //TJ
                Wt::Dbo::hasMany(a,
                        sourceParameters,
                        Wt::Dbo::ManyToMany,
                        TABLE_JOINT_PREFIX SEP TRIGRAM_ADDON SEP TRIGRAM_SOURCE_PARAMETER);

                Wt::Dbo::hasMany(a,
                        searchTypes,
                        Wt::Dbo::ManyToMany,
                        TABLE_JOINT_PREFIX SEP TRIGRAM_ADDON SEP TRIGRAM_SEARCH_TYPE);                        

                Wt::Dbo::hasMany(a,
                        addonPackageParameter, 
                        Wt::Dbo::ManyToOne, 
                        TRIGRAM_ADDON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON);
            }

        protected:
        private:
    };
  }
}

#endif // ADDON_H

