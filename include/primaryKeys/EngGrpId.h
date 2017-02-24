/**
 * @file EngGrpId.h
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

#ifndef ENGGRPID_H
#define	ENGGRPID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    struct EngGrpId {
        Wt::Dbo::ptr<Engine> engine;
        Wt::Dbo::ptr<Group> group;

        EngGrpId(Wt::Dbo::ptr<Engine> ptrEng, Wt::Dbo::ptr<Group> ptrGrp)
        : engine(ptrEng), group(ptrGrp) {
        }

        EngGrpId() {
        }

        bool operator==(const EngGrpId& other) const {
            return engine == other.engine && group == other.group;
        }

        bool operator<(const EngGrpId& other) const {
            if ((engine < other.engine) || (group < other.group))
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const EngGrpId& pk) {
        //return o << "(" << pk.id << ")" << "(" << pk.source << ")";
        return o << "\n    {"
                << "\n        \"engine_id\": " << pk.engine.id()
                << ",\n        \"group_id\": " << pk.group.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::EngGrpId& srid,
            const std::string& name, int size = -1) {
        field(a, srid.engine, "ENG_ID");
        field(a, srid.group, "GRP_ID");
    }

    template<>
    struct dbo_traits<Echoes::Dbo::EngGrp> : public dbo_default_traits {
        typedef Echoes::Dbo::EngGrpId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::EngGrpId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* ENGGRPID_H */
