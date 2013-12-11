/* 
 * File:   FilterParameterValueId.h
 * Author: tsa
 *
 * Created on 9 décembre 2013, 22:34
 */

#ifndef FILTERPARAMETERVALUEID_H
#define	FILTERPARAMETERVALUEID_H

namespace Echoes
{
  namespace Dbo
  {

    class FilterParameter;
    class FilterParameterValue;

    struct FilterParameterValueId {
        Wt::Dbo::ptr<FilterParameter> filterParameter;
        Wt::Dbo::ptr<Filter> filter;

        FilterParameterValueId(Wt::Dbo::ptr<FilterParameter> filterParameter, Wt::Dbo::ptr<Filter> filter)
        : filterParameter(filterParameter), filter(filter) {
        }

        FilterParameterValueId() {
        }

        bool operator==(const FilterParameterValueId& other) const {
            return filterParameter == other.filterParameter && filter == other.filter;
        }

        bool operator<(const FilterParameterValueId& other) const {
            if (filterParameter < other.filterParameter)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const FilterParameterValueId& pk) {
        // return o << "(" << pk.filterParameter << ")";
        return o << "\n    {"
                << "\n        \"filter_id\": " << pk.filter.id()
                << ",\n        \"filter_parameter_id\": " << pk.filterParameter.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::FilterParameterValueId& fpvid,
            const std::string& name, int size = -1) {
        field(a, fpvid.filter, TRIGRAM_FILTER ID);
        field(a, fpvid.filterParameter, TRIGRAM_FILTER_PARAMETER ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::FilterParameterValue> : public dbo_default_traits {
        typedef Echoes::Dbo::FilterParameterValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::FilterParameterValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* FILTERPARAMETERVALUEID_H */

