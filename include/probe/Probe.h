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

            int             timer;
            Wt::WString     cert;
            Wt::WDateTime   lastlog;
            bool            sendAlertIfDown;
            int             snoozeBeforeNextWarning;
            Wt::WDateTime   lastDownAlert;

            Wt::Dbo::ptr<ProbePackageParameter> probePackageParameter;
            Wt::Dbo::ptr<Asset> asset;

            Wt::Dbo::collection<Wt::Dbo::ptr<Syslog> > syslogs;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["CERT"] = &this->cert;
                mapClassAttributesInts["TIMER"] = &this->timer;
                mapClassAttributesDates["LASTLOG"] = &this->lastlog;
                mapClassAttributesBools["ALERT_IF_DOWN"] = &this->sendAlertIfDown;
                mapClassAttributesInts["SNOOZE_BEFORE_NEXT_WARNING"] = &this->snoozeBeforeNextWarning;
                mapClassAttributesDates["LAST_DOWN_ALERT"] = &this->lastDownAlert;
                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, probePackageParameter, TRIGRAM_PROBE SEP TRIGRAM_PROBE_PACKAGE_PARAMETER);
                Wt::Dbo::belongsTo(a, asset, TRIGRAM_PROBE SEP TRIGRAM_ASSET);

                Wt::Dbo::hasMany(a,
                        syslogs,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_SYSLOG SEP TRIGRAM_PROBE);
            }

        protected:
        private:
    };
  }
}

#endif // PROBE_H

