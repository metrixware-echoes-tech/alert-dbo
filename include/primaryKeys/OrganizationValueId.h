/**
 * @file OrganizationValueId.h
 * @author Thomas Saquet, Florent Poinsaut
 * @date 
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Alert - Dbo is the database objects library, part of the Alert software
 * Copyright (C) 2013-2017
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 * 
 */

#ifndef ORGANIZATIONVALUEID_H
#define	ORGANIZATIONVALUEID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    class Organization;
    class OrganizationValue;

    struct OrganizationValueId {
        Wt::Dbo::ptr<OrganizationField> organizationField;
        Wt::Dbo::ptr<Organization> organization;

        OrganizationValueId(Wt::Dbo::ptr<OrganizationField> organizationField, Wt::Dbo::ptr<Organization> organization)
        : organizationField(organizationField), organization(organization) {
        }

        OrganizationValueId() {
        }

        bool operator==(const OrganizationValueId& other) const {
            return organizationField == other.organizationField && organization == other.organization;
        }

        bool operator<(const OrganizationValueId& other) const {
            if (organizationField < other.organizationField)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const OrganizationValueId& pk) {
        //return o << "(" << pk.organization << ")";
        return o << "\n    {"
                << "\n        \"organization_id\": " << pk.organization.id()
                << ",\n        \"orgnanization_field_id\": " << pk.organizationField.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::OrganizationValueId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.organizationField, "OFI_ID");
        field(a, spvid.organization, "ORG_ID");
    }

    template<>
    struct dbo_traits<Echoes::Dbo::OrganizationValue> : public dbo_default_traits {
        typedef Echoes::Dbo::OrganizationValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::OrganizationValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* ORGANIZATIONVALUEID_H */
