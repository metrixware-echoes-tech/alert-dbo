/* 
 * File:   SearchId.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:39
 */

#ifndef SEARCHID_H
#define	SEARCHID_H

#include <Wt/Dbo/Dbo>
#include "primaryKeys/SourceId.h"

namespace Echoes
{
  namespace Dbo
  {


    class Search;
    class Source;

    struct SearchId {
        long long id;
        Wt::Dbo::ptr<Source> source;

        SearchId(long long id, Wt::Dbo::ptr<Source> ptr)
        : id(id), source(ptr) {
        }

        SearchId() {
            id = 0;
        }

        bool operator==(const SearchId& other) const {
            return id == other.id && source == other.source;
        }

        bool operator<(const SearchId& other) const {
            if ((id < other.id) || (source < other.source))
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const SearchId& pk) {
        //return o << "(" << pk.id << ")" << "(" << pk.source << ")";
        return o << pk.source.id() << ",\n\t\t"
                << "\"search_id\": " << pk.id;
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::SearchId& srid,
            const std::string& name, int size = -1) {
        field(a, srid.id, TRIGRAM_SEARCH SEP ID);
        field(a, srid.source, TRIGRAM_SOURCE SEP ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::Search> : public dbo_default_traits {
        typedef Echoes::Dbo::SearchId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::SearchId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* SEARCHID_H */

