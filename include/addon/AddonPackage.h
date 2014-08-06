/* 
 * Header of Addon Package Table
 * @author ECHOES Technologies (MLA)
 * @date 09/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ADDONPACKAGE_H
#define	ADDONPACKAGE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AddonPackage : public Table
    {
        public:
            AddonPackage();
            AddonPackage(const AddonPackage& orig);
            virtual ~AddonPackage();

            static std::string TRIGRAM;

            Wt::WString filename;

            Wt::Dbo::collection<Wt::Dbo::ptr<AddonPackageParameter >> addonPackageParameters;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["FILENAME"] = &this->filename;

                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a, addonPackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_ADDON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON_PACKAGE);
            }

        private:
  };
}
}

#endif	/* ADDONPACKAGE_H */

