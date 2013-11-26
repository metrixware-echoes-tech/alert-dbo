/* 
 * File:   OrganizationValueId.h
 * Author: rhi
 *
 * Created on 9 juillet 2012, 14:02
 */

#ifndef ORGANIZATIONVALUEID_H
#define	ORGANIZATIONVALUEID_H

#include <Wt/Dbo/Dbo>

class Organization;
class OrganizationValue;

struct OrganizationValueId
{
    Wt::Dbo::ptr<OrganizationField> organizationField;
    Wt::Dbo::ptr<Organization> organization;

    OrganizationValueId(Wt::Dbo::ptr<OrganizationField> organizationField, Wt::Dbo::ptr<Organization> organisation)
        : organizationField(organizationField), organization(organisation) { }

    OrganizationValueId(){ }

    bool operator== (const OrganizationValueId& other) const {
        return organizationField == other.organizationField && organization == other.organization;
    }

    bool operator< (const OrganizationValueId& other) const {
        if (organizationField < other.organizationField)
            return true;
        else
            return false;
    }
};


inline std::ostream& operator<< (std::ostream& o, const OrganizationValueId& pk)
{
    //return o << "(" << pk.organization << ")";
    return o << "\"organization_id\": " << pk.organization.id() << ",\n\t\t"
         << "\"orgnanization_field_id\": " << pk.organizationField.id() ;
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, OrganizationValueId& spvid,
                   const std::string& name, int size = -1)
        {
            field(a, spvid.organizationField, "OFI_ID");
            field(a, spvid.organization, "ORG_ID");
        }
        template<>
        struct dbo_traits<OrganizationValue> : public dbo_default_traits
        {
            typedef OrganizationValueId IdType;
            static IdType invalidId() { return OrganizationValueId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* ORGANIZATIONVALUEID_H */