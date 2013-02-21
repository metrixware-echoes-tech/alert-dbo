#include "probe/Probe.h"

std::string Probe::TRIGRAM(TRIGRAM_PROBE);

Probe::Probe()
{
    this->jsonName = "probe";
}

Probe::~Probe()
{

}

std::string Probe::toJSON()
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->organization);
    res += this->probePackageParameter.modify()->toJSON();
    
    res += Table::formatJSONForDboCollection(this->syslogs, "syslogs");
    res += Table::formatJSONForDboCollection(this->syslogsHistory, "syslogs_history");
    res += Table::formatJSONForDboCollection(this->assets, "assets");
    
    
    res += "}\n";
    return res;
}
