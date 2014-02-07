/* 
 * Header of Alert Media Alias Asset Table
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

#ifndef ALERTMEDIAMESSAGEALIASASSET_H
#define	ALERTMEDIAMESSAGEALIASASSET_H


#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"
#include "primaryKeys/AlertMessageAliasAssetId.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertMessageAliasAsset : public Table
    {
        public:
            AlertMessageAliasAsset();
            AlertMessageAliasAsset(const AlertMessageAliasAsset& orig);
            virtual ~AlertMessageAliasAsset();

            static std::string TRIGRAM;

            Wt::WString alias;
            AlertMessageAliasAssetId pk;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["ALIAS"] = &this->alias;

                FIELD_FILLER();

                Wt::Dbo::id(a, pk, TRIGRAM_ALERT_MESSAGE_ALIAS_ASSET ID);
            }

            virtual std::string toJSON() const;

        private:
    };
  }
}

#endif	/* ALERTMEDIAMESSAGEALIASASSET_H */

