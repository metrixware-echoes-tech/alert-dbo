/* 
 * Header of Information Value Table
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

#ifndef INFORMATIONVALUE_H
#define INFORMATIONVALUE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Plugin;
    class Probe;
    class Information;

    class InformationValue : public Table
    {
        public:
            InformationValue();
            ~InformationValue();

            static std::string TRIGRAM;

            Wt::WDateTime creationDate;
            Wt::WString value;

            short state;
            int lotNumber;
            int lineNumber;

            Wt::Dbo::ptr<Syslog> syslog;
            Wt::Dbo::ptr<InformationData> informationData;
            //        InformationId informationId;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesDates["CREA_DATE"] = &this->creationDate;
                mapClassAttributesStrings["VALUE"] = &this->value;
                mapClassAttributesShorts["STATE"] = &this->state;
                mapClassAttributesInts["LOT_NUM"] = &this->lotNumber;
                mapClassAttributesInts["LINE_NUM"] = &this->lineNumber;

                FIELD_FILLER();
                Wt::Dbo::belongsTo(a, syslog, TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_SYSLOG, Wt::Dbo::OnDeleteSetNull);
                Wt::Dbo::belongsTo(a, informationData, TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_INFORMATION_DATA);


            }

            virtual std::string toJSON() const;

        protected:
        private:
    };
  }
}

#endif // INFORMATIONVALUE_H

