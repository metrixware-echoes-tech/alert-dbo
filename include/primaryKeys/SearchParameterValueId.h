/* 
 * File:   SearchParameterValueId.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 17:59
 */

#ifndef SEARCHPARAMETERVALUEID_H
#define	SEARCHPARAMETERVALUEID_H

#include <Wt/Dbo/Dbo>
#include "SourceId.h"
#include "SearchId.h"

class SearchParameter;
class SearchParameterValue;

struct SearchParameterValueId
{
    Wt::Dbo::ptr<SearchParameter> searchParameter;
    SearchId searchId;

    SearchParameterValueId(Wt::Dbo::ptr<SearchParameter> searchParameter, SourceId sourceId)
        : searchParameter(searchParameter), searchId(searchId) { }

    SearchParameterValueId(){ }

    bool operator== (const SearchParameterValueId& other) const {
        return searchParameter == other.searchParameter && searchId == other.searchId;
    }

    bool operator< (const SearchParameterValueId& other) const {
        if (searchParameter < other.searchParameter)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const SearchParameterValueId& pk)
{
    return o << "(" << pk.searchParameter << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, SearchParameterValueId& spvid,
                   const std::string& name, int size = -1)
        {
            Wt::Dbo::belongsTo(a, spvid.searchParameter, "SEV_SEP");
            field(a, spvid.searchId.id, "SEA_ID");
            field(a, spvid.searchId.sourceId.id, "SRC_ID");
            field(a, spvid.searchId.sourceId.plugin, "PLG_ID");
        }
        template<>
        struct dbo_traits<SearchParameterValue> : public dbo_default_traits
        {
            typedef SearchParameterValueId IdType;
            static IdType invalidId() { return SearchParameterValueId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}


#endif	/* SEARCHPARAMETERVALUEID_H */

