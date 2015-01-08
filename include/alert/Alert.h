/* 
 * Header of Alert Table
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

#ifndef ALERT_H
#define ALERT_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Alert : public Table
    {
        public:
            Alert();
            virtual ~Alert();

            static std::string TRIGRAM;
            //   Wt::WString name;
            Wt::WDateTime creaDate; //creation date of the alert
            Wt::WDateTime lastAttempt; //last time an engine process the alert (use to detect a zombie alert thread)
            int threadSleep;


            //        const Wt::WString& name_() const {return *name;};

            Wt::Dbo::collection<Wt::Dbo::ptr<AlertAcknowledge> > alertAcks;
            Wt::Dbo::collection<Wt::Dbo::ptr<Message> > alertTrackings;
            Wt::Dbo::collection<Wt::Dbo::ptr<AlertMediaSpecialization> > alertMediaSpecializations;

            Wt::Dbo::ptr<AlertValue> alertValue;
            Wt::Dbo::ptr<AlertSequence> alertSequence;
            Wt::Dbo::ptr<Engine> engine;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesDates["CREA_DATE"] = &this->creaDate;
                mapClassAttributesDates["LAST_ATTEMPT"] = &this->lastAttempt;
                mapClassAttributesInts["THREAD_SLEEP"] = &this->threadSleep;


                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a, alertAcks, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_ACKNOWLEDGE SEP TRIGRAM_ALERT);
                Wt::Dbo::hasMany(a, alertTrackings, Wt::Dbo::ManyToOne, TRIGRAM_MESSAGE SEP TRIGRAM_ALERT);
                Wt::Dbo::hasMany(a, alertMediaSpecializations, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_ALERT);

                Wt::Dbo::belongsTo(a, alertValue, TRIGRAM_ALERT SEP TRIGRAM_ALERT_VALUE);
                Wt::Dbo::belongsTo(a, alertSequence, TRIGRAM_ALERT_SEQUENCE SEP "FIRST_ID");
                Wt::Dbo::belongsTo(a, engine, TRIGRAM_ALERT SEP TRIGRAM_ENGINE);
            }

        protected:
        private:
    };
  }
}
#endif // ALERT_H

