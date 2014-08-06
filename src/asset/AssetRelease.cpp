/* 
 * Asset Release Table
 * @author ECHOES Technologies (TSA)
 * @date 25/01/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "asset/AssetRelease.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string AssetRelease::TRIGRAM(TRIGRAM_ASSET_RELEASE);

    AssetRelease::AssetRelease()
    {
    }

    AssetRelease::AssetRelease(const AssetRelease& orig)
    {
    }

    AssetRelease::~AssetRelease()
    {
    }
  }
}

