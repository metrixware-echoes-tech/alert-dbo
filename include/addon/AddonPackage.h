/* 
 * File:   AddonPackage.h
 * Author: mla
 *
 * Created on 9 octobre 2013, 14:52
 */

#ifndef ADDONPACKAGE_H
#define	ADDONPACKAGE_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>


namespace Echoes {
    namespace Dbo {

        class AddonPackage : public Table {
        public:
            AddonPackage();
            AddonPackage(const AddonPackage& orig);
            virtual ~AddonPackage();

            static std::string TRIGRAM;

            Wt::WString filename;

            Wt::Dbo::collection<Wt::Dbo::ptr<AddonPackageParameter >> addonPackageParameters;

            template<class Action>
            void persist(Action& a) {
                mapClassAttributesStrings["FILENAME"] = &this->filename;

                FIELD_FILLER();

                Wt::Dbo::hasMany(a, addonPackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_ADDON_PACKAGE_PARAMETER SEP TRIGRAM_ADDON_PACKAGE);
            }
        private:

        };
    }
}

#endif	/* ADDONPACKAGE_H */

