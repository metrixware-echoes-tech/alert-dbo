/* 
 * Header of Alert Message Definition Table
 * @author ECHOES Technologies (TSA)
 * @date 22/02/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ALERTMESSAGEDEFINITION_H
#define	ALERTMESSAGEDEFINITION_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"
#include "primaryKeys/AlertMessageDefinitionId.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertMessageDefinition : public Table
    {
        public:
            AlertMessageDefinition();
            AlertMessageDefinition(const AlertMessageDefinition& orig);
            virtual ~AlertMessageDefinition();

            static std::string TRIGRAM;

            Wt::WString message;
            bool isCustom;

            AlertMessageDefinitionId pk;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["MESSAGE"] = &this->message;
                mapClassAttributesBools["IS_CUSTOM"] = &this->isCustom;
                FIELD_FILLER();

                Wt::Dbo::id(a, pk, TRIGRAM_ALERT_MESSAGE_DEFINITION ID);
            }

            virtual std::string toJSON() const;

        private:
    };
  }
}

#endif	/* ALERTMESSAGEDEFINITION_H */

