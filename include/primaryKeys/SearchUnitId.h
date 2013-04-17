/* 
 * File:   SearchUnitId.h
 * Author: rhi
 *
 * Created on 9 octobre 2012, 11:34
 */

#ifndef SEARCHUNITID_H
#define	SEARCHUNITID_H

#include "tools/MainIncludeFile.h"

#include "primaryKeys/SearchId.h"

class SearchUnit;
class Search;

struct SearchUnitId
{
    Wt::Dbo::ptr<Search> search;
    int infValueNum; 

    SearchUnitId(Wt::Dbo::ptr<Search> ptr, int ssn)
        : search(ptr), infValueNum(ssn) { }

    SearchUnitId(){ infValueNum = 0; }

    bool operator== (const SearchUnitId& other) const {
        return search == other.search && infValueNum == other.infValueNum;
    }

    bool operator< (const SearchUnitId& other) const {
        if ((search < other.search) || (infValueNum < other.infValueNum))
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const SearchUnitId& pk)
{
    //return o << "(" << pk.search << ")" << "(" << pk.infValueNum << ")";
    return o <<  pk.search.id()
         << ",\n\t\t\"inf_value_num\": " << pk.infValueNum;
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, SearchUnitId& suid,
                   const std::string& name, int size = -1)
        {
            field(a, suid.search, "SEA_ID");
            field(a, suid.infValueNum, TRIGRAM_INFORMATION SEP "VALUE_NUM");
        }
        template<>
        struct dbo_traits<SearchUnit> : public dbo_default_traits
        {
            typedef SearchUnitId IdType;
            static IdType invalidId() { return SearchUnitId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* SEARCHUNITID_H */