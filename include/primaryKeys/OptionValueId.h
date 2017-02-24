/**
 * @file OptionValueId.h
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

#ifndef OPTIONVALUEID_H
#define	OPTIONVALUEID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    class Organization;
    class Option;
    class OptionType;

    struct OptionValueId {
        Wt::Dbo::ptr<Organization> organization;
        Wt::Dbo::ptr<OptionType> optionType;

        OptionValueId(Wt::Dbo::ptr<Organization> organization, Wt::Dbo::ptr<OptionType> optionType)
        : organization(organization), optionType(optionType) {
        }

        OptionValueId() {
        }

        bool operator==(const OptionValueId& other) const {
            return organization == other.organization && optionType == other.optionType;
        }

        bool operator<(const OptionValueId& other) const {
            if (organization < other.organization)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const OptionValueId& pk) {
        //return o << "(" << pk.organization << ")";
        return o << "\"option_id\": " << pk.optionType.id() << ",\n\t\t"
                << "\"organization_id\": " << pk.organization.id();
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::OptionValueId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.optionType, TRIGRAM_OPTION_TYPE ID);
        field(a, spvid.organization, TRIGRAM_ORGANIZATION ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::Option> : public dbo_default_traits {
        typedef Echoes::Dbo::OptionValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::OptionValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* OPTIONVALUE_H */
