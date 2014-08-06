/* 
 * Alert Media Alias Plugin Table
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

#include "alert/AlertMessageAliasPlugin.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string AlertMessageAliasPlugin::TRIGRAM(TRIGRAM_ALERT_MESSAGE_ALIAS_PLUGIN);

    AlertMessageAliasPlugin::AlertMessageAliasPlugin()
    {
    }

    AlertMessageAliasPlugin::AlertMessageAliasPlugin(const AlertMessageAliasPlugin& orig)
    {
    }

    AlertMessageAliasPlugin::~AlertMessageAliasPlugin()
    {
    }
  }
}

