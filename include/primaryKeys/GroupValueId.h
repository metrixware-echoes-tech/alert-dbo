/**
 * @file GroupValueId.h
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

#ifndef GROUPVALUEID_H
#define	GROUPVALUEID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    class Group;
    class GroupValue;

    struct GroupValueId {
        Wt::Dbo::ptr<GroupField> groupField;
        Wt::Dbo::ptr<Group> group;

        GroupValueId(Wt::Dbo::ptr<GroupField> groupField, Wt::Dbo::ptr<Group> group)
        : groupField(groupField), group(group) {
        }

        GroupValueId() {
        }

        bool operator==(const GroupValueId& other) const {
            return groupField == other.groupField && group == other.group;
        }

        bool operator<(const GroupValueId& other) const {
            if (groupField < other.groupField)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const GroupValueId& pk) {
        //return o << "(" << pk.group << ")";
        return o << "\n    {"
                << "\n        \"group_id\": " << pk.group.id()
                << ",\n        \"group_field_id\": " << pk.groupField.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::GroupValueId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.groupField, "GFI_ID");
        field(a, spvid.group, "GRP_ID");
    }

    template<>
    struct dbo_traits<Echoes::Dbo::GroupValue> : public dbo_default_traits {
        typedef Echoes::Dbo::GroupValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::GroupValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* GROUPVALUEID_H */
