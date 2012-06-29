/* 
 * File:   SearchId.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:39
 */

#ifndef SEARCHID_H
#define	SEARCHID_H

#include <Wt/Dbo/Dbo>
#include "SourceId.h"

class Search;
class Source;


struct SearchId
{
    int id;
    Wt::Dbo::ptr<Source> source;

    SearchId(int id, Wt::Dbo::ptr<Source> ptr)
        : id(id), source(ptr) { }

    SearchId(){ }

    bool operator== (const SearchId& other) const {
        return id == other.id && source == other.source;
    }

    bool operator< (const SearchId& other) const {
        if (id < other.id)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const SearchId& pk)
{
    return o << "(" << pk.id << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, SearchId& srid,
                   const std::string& name, int size = -1)
        {
            field(a, srid.id, "SEA_ID");
            field(a, srid.source, "SEA_ID");
        }
        template<>
        struct dbo_traits<Search> : public dbo_default_traits
        {
            typedef SearchId IdType;
            static IdType invalidId() { return SearchId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* SEARCHID_H */

