/* 
 * File:   AddonCommonPackage.h
 * Author: mla
 *
 * Created on 8 octobre 2013, 12:14
 */

#ifndef ADDONCOMMONPACKAGE_H
#define	ADDONCOMMONPACKAGE_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

namespace Echoes {
    namespace Dbo {

        class AddonCommonPackage : public Table {
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

                FIELD_FILLER();

                Wt::Dbo::hasMany(a, addonCommonPackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_ADDON_COMMON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON_COMMON_PACKAGE);
            }
        private:

        };
    }
}

#endif	/* ADDONCOMMONPACKAGE_H */

