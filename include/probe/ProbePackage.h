/* 
 * Header of Probe Package Table
 * @author ECHOES Technologies (TSA)
 * @date 25/01/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef PROBEPACKAGE_H
#define	PROBEPACKAGE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class ProbePackage : public Table
    {
        public:
            ProbePackage();
            ProbePackage(const ProbePackage& orig);
            virtual ~ProbePackage();

            static std::string TRIGRAM;

            Wt::WString filename;

            Wt::Dbo::collection<Wt::Dbo::ptr<ProbePackageParameter >> probePackageParameters;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["FILENAME"] = &this->filename;

                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a, probePackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_PROBE_PACKAGE);
            }

        private:
    };
  }
}

#endif	/* PROBEPACKAGE_H */

