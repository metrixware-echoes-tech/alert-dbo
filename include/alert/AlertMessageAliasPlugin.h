/* 
 * Header of Alert Media Alias Plugin Table
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

#ifndef ALERTMESSAGEALIASPLUGIN_H
#define	ALERTMESSAGEALIASPLUGIN_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"
#include "primaryKeys/AlertMessageAliasPluginId.h"

namespace Echoes
{
  namespace Dbo
  {

    class AlertMessageAliasPlugin : public Table
    {
        public:
            AlertMessageAliasPlugin();
            AlertMessageAliasPlugin(const AlertMessageAliasPlugin& orig);
            virtual ~AlertMessageAliasPlugin();

            static std::string TRIGRAM;

            Wt::WString alias;

            AlertMessageAliasPluginId pk;

            template<class Action>
            void persist(Action& a) {
                mapClassAttributesStrings["ALIAS"] = &this->alias;

                FIELD_FILLER();

                Wt::Dbo::id(a, pk, TRIGRAM_ALERT_MESSAGE_ALIAS_PLUGIN ID);

            }

            virtual std::string toJSON() const;
        private:
    };
  }
}

#endif	/* ALERTMESSAGEALIASPLUGIN_H */

