/* 
 * File:   SearchParameterValueId.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 17:59
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

