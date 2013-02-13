/* 
 * File:   AssetArchitecture.cpp
 * Author: tsa
 * 
 * Created on 25 janvier 2013, 15:41
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

