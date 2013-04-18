#include "organization/OrganizationType.h"

std::string OrganizationType::TRIGRAM(TRIGRAM_ORGANIZATION_TYPE);

OrganizationType::OrganizationType()
{
    this->jsonName = "organization_type";
    //ctor
}

OrganizationType::~OrganizationType()
{

}

std::string OrganizationType::toJSON()
{
    std::string res = "";
    res += Table::toJSON();

    res += Table::formatJSONForDboCollection(this->organization, "organization");
    res += Table::formatJSONForDboCollection(this->organizationField, "organization_field", false);

    res += "}";
    return res;
}
