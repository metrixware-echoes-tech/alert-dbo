/**
 * @file SearchParameterValueId.h
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

#ifndef SEARCHPARAMETERVALUEID_H
#define	SEARCHPARAMETERVALUEID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {


    class SearchParameter;
    class SearchParameterValue;

    struct SearchParameterValueId {
        Wt::Dbo::ptr<SearchParameter> searchParameter;
        Wt::Dbo::ptr<Search> search;

        SearchParameterValueId(Wt::Dbo::ptr<SearchParameter> searchParameter, Wt::Dbo::ptr<Search> search)
        : searchParameter(searchParameter), search(search) {
        }

        SearchParameterValueId() {
        }

        bool operator==(const SearchParameterValueId& other) const {
            return searchParameter == other.searchParameter && search == other.search;
        }

        bool operator<(const SearchParameterValueId& other) const {
            if (searchParameter < other.searchParameter)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const SearchParameterValueId& pk) {
        // return o << "(" << pk.searchParameter << ")";
        return o << "\n    {"
                << "\n        \"search_id\": " << pk.search.id()
                << ",\n        \"search_parameter_id\": " << pk.searchParameter.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::SearchParameterValueId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.search, TRIGRAM_SEARCH ID);
        field(a, spvid.searchParameter, TRIGRAM_SEARCH_PARAMETER ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::SearchParameterValue> : public dbo_default_traits {
        typedef Echoes::Dbo::SearchParameterValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::SearchParameterValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* SEARCHPARAMETERVALUEID_H */
