/* 
 * Alert Media Alias Information Criteria Table
 * @author ECHOES Technologies (TSA)
 * @date 25/02/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ALERTMESSAGEALIASINFORMATIONCRITERIA_H
#define	ALERTMESSAGEALIASINFORMATIONCRITERIA_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"
#include "primaryKeys/AlertMessageAliasInformationCriteriaId.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertMessageAliasInformationCriteria : public Table
    {
        public:
            AlertMessageAliasInformationCriteria();
            AlertMessageAliasInformationCriteria(const AlertMessageAliasInformationCriteria& orig);
            virtual ~AlertMessageAliasInformationCriteria();

            static std::string TRIGRAM;

            Wt::WString alias;
            AlertMessageAliasInformationCriteriaId pk;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["ALIAS"] = &this->alias;

                FIELD_FILLER();

                Wt::Dbo::id(a, pk, TRIGRAM_ALERT_MESSAGE_ALIAS_INFORMATION_CRITERIA ID);
            }

            virtual std::string toJSON() const;
        private:
    };
  }
}

#endif	/* ALERTMESSAGEALIASINFORMATIONCRITERIA_H */

