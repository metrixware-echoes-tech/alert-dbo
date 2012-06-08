/* 
 * File:   InformationId.h
 * Author: tsa
 *
 * Created on 8 juin 2012, 10:48
 */

#ifndef INFORMATIONID_H
#define	INFORMATIONID_H

#include "SearchId.h"
#include "Information.h"

class Information2;

struct InformationId
{
    SearchId searchId;

    InformationId(SearchId ptr)
        : searchId(ptr) { }

    InformationId(){ }

    bool operator== (const InformationId& other) const {
        return searchId == other.searchId;
    }

    bool operator< (const InformationId& other) const {
        if (searchId < other.searchId)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const InformationId& pk)
{
    return o << "(" << pk.searchId << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, InformationId& infid,
                   const std::string& name, int size = -1)
        {
            field(a, infid.searchId.id, "SEA_ID");
            field(a, infid.searchId.sourceId.id, "SRC_ID");
            field(a, infid.searchId.sourceId.plugin, "PLG_ID");
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

