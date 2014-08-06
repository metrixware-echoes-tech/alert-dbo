/* 
 * Plugin Reference Table
 * @author ECHOES Technologies (TSA)
 * @date 04/11/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "plugin/PluginReference.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string PluginReference::TRIGRAM(TRIGRAM_PLUGIN_REFERENCE);

    PluginReference::PluginReference()
    {
    }

    PluginReference::PluginReference(const PluginReference& orig)
    {
    }

    PluginReference::~PluginReference()
    {
    }
  }
}

