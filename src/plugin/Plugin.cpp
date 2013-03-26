#include "plugin/Plugin.h"

std::string Plugin::TRIGRAM(TRIGRAM_PLUGIN);

Plugin::Plugin()
{
    this->jsonName = "plugin";
    //ctor
}

Plugin::~Plugin()
{

}

std::string Plugin::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    
    res += Table::formatJSONForDboCollection(this->assets, "assets", false);

    res += "}\n";
    return res;
}