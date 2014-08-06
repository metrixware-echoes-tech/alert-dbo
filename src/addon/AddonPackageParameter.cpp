/* 
 * Addon Package Parameter Table
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

#include "addon/AddonPackageParameter.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string AddonPackageParameter::TRIGRAM(TRIGRAM_ADDON_PACKAGE_PARAMETER);

    AddonPackageParameter::AddonPackageParameter()
    {
    }

    AddonPackageParameter::AddonPackageParameter(const AddonPackageParameter& orig)
    {
    }

    AddonPackageParameter::~AddonPackageParameter()
    {
    }
  }
}

