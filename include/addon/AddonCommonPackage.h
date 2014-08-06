/* 
 * Header of Addon Common Package Table
 * @author ECHOES Technologies (MLA)
 * @date 08/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ADDONCOMMONPACKAGE_H
#define	ADDONCOMMONPACKAGE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AddonCommonPackage : public Table
    {
        public:
            AddonCommonPackage();
            AddonCommonPackage(const AddonCommonPackage& orig);
            virtual ~AddonCommonPackage();

            static std::string TRIGRAM;

            Wt::WString filename;

            Wt::Dbo::collection<Wt::Dbo::ptr<AddonCommonPackageParameter >> addonCommonPackageParameters;

            template<class Action>
            void persist(Action& a) {
                mapClassAttributesStrings["FILENAME"] = &this->filename;

                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a, addonCommonPackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_ADDON_COMMON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON_COMMON_PACKAGE);
            }
        private:
    };
  }
}

#endif	/* ADDONCOMMONPACKAGE_H */

