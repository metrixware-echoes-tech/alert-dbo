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
    res += Table::formatJSONForDboPtr(this->probePackageParamater);
    
    res += Table::formatJSONForDboCollection(this->syslogs, "syslogs");
    res += Table::formatJSONForDboCollection(this->syslogsHistory, "syslogs_hostory");
    res += Table::formatJSONForDboCollection(this->assets, "assets");
    
    
    res += "}\n";
    return res;
}
