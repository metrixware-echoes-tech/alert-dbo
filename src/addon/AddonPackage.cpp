/* 
 * Addon Package Table
 * @author ECHOES Technologies (MLA)
 * @date 09/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "addon/AddonPackage.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string AddonPackage::TRIGRAM(TRIGRAM_ADDON_PACKAGE);

    AddonPackage::AddonPackage()
    {
    }

    AddonPackage::AddonPackage(const AddonPackage& orig)
    {
    }

    AddonPackage::~AddonPackage()
    {
    }
  }
}

