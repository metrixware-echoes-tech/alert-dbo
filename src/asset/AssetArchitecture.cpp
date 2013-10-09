/* 
 * Asset Architecture Table
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

#include "asset/AssetArchitecture.h"

std::string AssetArchitecture::TRIGRAM(TRIGRAM_ASSET_ARCHITECTURE);

AssetArchitecture::AssetArchitecture() 
{
    this->jsonName = "architecture";
}

AssetArchitecture::AssetArchitecture(const AssetArchitecture& orig) {
}

AssetArchitecture::~AssetArchitecture() {
}

