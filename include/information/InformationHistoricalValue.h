/* 
 * Header of Information Historical Value Table
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

#ifndef INFORMATIONHISTORICALVALUE_H
#define INFORMATIONHISTORICALVALUE_H

#include "tools/MainIncludeFile.h"

//#include "primaryKeys/InformationId.h"

namespace Echoes
{
  namespace Dbo
  {
    class InformationHistoricalValue : public Table
    {
        public:
            InformationHistoricalValue();
            virtual ~InformationHistoricalValue();

            static std::string TRIGRAM;

            Wt::WDateTime creationDate;
            Wt::WString value;

            short state;
            int lotNumber;
            int lineNumber;

            Wt::Dbo::ptr<Syslog> syslog;
            Wt::Dbo::ptr<InformationData> informationData;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesDates["CREA_DATE"] = &this->creationDate;
                mapClassAttributesStrings["VALUE"] = &this->value;
                mapClassAttributesShorts["STATE"] = &this->state;
                mapClassAttributesInts["LOT_NUM"] = &this->lotNumber;
                mapClassAttributesInts["LINE_NUM"] = &this->lineNumber;
                Table::fieldFiller(a, *this);
                Wt::Dbo::belongsTo(a, syslog, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_SYSLOG, Wt::Dbo::OnDeleteSetNull);
                Wt::Dbo::belongsTo(a, informationData, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_INFORMATION_DATA);
            }

        protected:
        private:
    };
  }
}

#endif // INFORMATIONHISTORICALVALUE_H

