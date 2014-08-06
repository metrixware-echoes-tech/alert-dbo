/* 
 * Header of Probe Table
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

#ifndef PROBE_H
#define PROBE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Probe : public Table
    {
        public:
            Probe();
            virtual ~Probe();

            static std::string TRIGRAM;

            Wt::WString cert;

            Wt::Dbo::ptr<ProbePackageParameter> probePackageParameter;
            Wt::Dbo::ptr<Asset> asset;

            Wt::Dbo::collection<Wt::Dbo::ptr<Syslog> > syslogs;
//            Wt::Dbo::collection<Wt::Dbo::ptr<Asset> > assets;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["CERT"] = &this->cert;
                Table::fieldFiller(a, *this);
                Wt::Dbo::belongsTo(a, probePackageParameter, TRIGRAM_PROBE SEP TRIGRAM_PROBE_PACKAGE_PARAMETER);
                Wt::Dbo::belongsTo(a, asset, TRIGRAM_PROBE SEP TRIGRAM_ASSET);

                Wt::Dbo::hasMany(a,
                        syslogs,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_SYSLOG SEP TRIGRAM_PROBE);

//                Wt::Dbo::hasMany(a,
//                        assets,
//                        Wt::Dbo::ManyToOne,
//                        TRIGRAM_ASSET SEP TRIGRAM_PROBE);

            }

        protected:
        private:
    };
  }
}

#endif // PROBE_H

