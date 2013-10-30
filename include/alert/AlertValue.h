/* 
 * Header of Alert Value Table
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

#ifndef ALERTVALUE_H
#define ALERTVALUE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Alert;

    class AlertValue : public Table
    {
        public:
            AlertValue();
            virtual ~AlertValue();

            static std::string TRIGRAM;

            Wt::WString value;
            boost::optional<Wt::WString> keyValue;
            Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
            Wt::Dbo::ptr<Information> information;
            Wt::Dbo::ptr<AlertCriteria> alertCriteria;
            Wt::Dbo::ptr<Asset> asset;


            Wt::Dbo::collection<Wt::Dbo::ptr<AlertSequence> > alertSequences;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;
                mapClassAttributesStringsNn["KEY_VALUE"] = &this->keyValue;

                FIELD_FILLER();

                Wt::Dbo::hasMany(a, alerts, Wt::Dbo::ManyToOne, TRIGRAM_ALERT SEP TRIGRAM_ALERT_VALUE);

                Wt::Dbo::belongsTo(a, information, TRIGRAM_ALERT_VALUE SEP TRIGRAM_INFORMATION);
                Wt::Dbo::belongsTo(a, alertCriteria, TRIGRAM_ALERT_VALUE SEP TRIGRAM_ALERT_CRITERIA);
                Wt::Dbo::belongsTo(a, asset, TRIGRAM_ALERT_VALUE SEP TRIGRAM_ASSET);

                Wt::Dbo::hasMany(a, alertSequences, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_SEQUENCE SEP TRIGRAM_ALERT_VALUE);
            }

            virtual std::string toJSON() const;

        protected:
        private:
    };
  }
}

#endif // ALERTVALUE_H

