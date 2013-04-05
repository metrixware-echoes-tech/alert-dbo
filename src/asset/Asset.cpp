#include "asset/Asset.h"

std::string Asset::TRIGRAM(TRIGRAM_ASSET);

Asset::Asset()
{
    this->jsonName = "asset";
}

Asset::~Asset()
{

}

std::string Asset::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->probe);
    res += Table::formatJSONForDboPtr(this->assetArchitecture);
    res += Table::formatJSONForDboPtr(this->assetDistribution);
    res += Table::formatJSONForDboPtr(this->assetRelease);
    
    res += Table::formatJSONForDboCollection(this->plugins, "plugins");
    res += Table::formatJSONForDboCollection(this->values, "information_values");
    res += Table::formatJSONForDboCollection(this->historicalValues, "historical_information_values", false);
    
    
    res += "}\n";
    return res;
}
