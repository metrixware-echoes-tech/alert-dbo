/**
 * @file SourceParameterValueId.h
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

#ifndef SOURCEPARAMETERVALUEID_H
#define	SOURCEPARAMETERVALUEID_H

#include <Wt/Dbo/Dbo>
#include "primaryKeys/SourceId.h"

namespace Echoes
{
  namespace Dbo
  {

    class SourceParameter;
    class SourceParameterValue;
    class Source;

    struct SourceParameterValueId {
        Wt::Dbo::ptr<SourceParameter> sourceParameter;
        Wt::Dbo::ptr<Source> source;

        SourceParameterValueId(Wt::Dbo::ptr<SourceParameter> sourceParameter, Wt::Dbo::ptr<Source> source)
        : sourceParameter(sourceParameter), source(source) {
        }

        SourceParameterValueId() {
        }

        bool operator==(const SourceParameterValueId& other) const {
            return sourceParameter == other.sourceParameter && source == other.source;
        }

        bool operator<(const SourceParameterValueId& other) const {
            if (sourceParameter < other.sourceParameter)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const SourceParameterValueId& pk) {
        //return o << "(" << pk.sourceParameter << ")";
        return o << "\n    {"
                << "\n        \"source_id\": " << pk.source.id()
                << ",\n        \"source_parameter_id\": " << pk.sourceParameter.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::SourceParameterValueId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.sourceParameter, "SRP_ID");
        field(a, spvid.source, "SRC_ID");
    }

    template<>
    struct dbo_traits<Echoes::Dbo::SourceParameterValue> : public dbo_default_traits {
        typedef Echoes::Dbo::SourceParameterValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::SourceParameterValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* SOURCEPARAMETERVALUEID_H */
