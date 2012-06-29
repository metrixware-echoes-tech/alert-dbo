/* 
 * File:   InformationId.h
 * Author: tsa
 *
 * Created on 8 juin 2012, 10:48
 */

#ifndef INFORMATIONID_H
#define	INFORMATIONID_H

#include "MainIncludeFile.h"

#include "SearchId.h"

class Information2;
class Search;

struct InformationId
{
    Wt::Dbo::ptr<Search> search;
    std::string subSearchNumber;

    InformationId(Wt::Dbo::ptr<Search> ptr)
        : search(ptr) { }

    InformationId(){ }

    bool operator== (const InformationId& other) const {
        return search == other.search;
    }

    bool operator< (const InformationId& other) const {
        if (search < other.search)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const InformationId& pk)
{
    return o << "(" << pk.search << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, InformationId& infid,
                   const std::string& name, int size = -1)
        {
            field(a, infid.search, "INF_ID");
            field(a, infid.subSearchNumber, "INF_ID");
        }
        template<>
        struct dbo_traits<Information2> : public dbo_default_traits
        {
            typedef InformationId IdType;
            static IdType invalidId() { return InformationId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* INFORMATIONID_H */

