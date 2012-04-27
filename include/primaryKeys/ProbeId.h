/* 
 * File:   ProbeId.h
 * Author: tom
 *
 * Created on 23 avril 2012, 17:35
 */


#ifndef PROBEID_H
#define	PROBEID_H

#include <Wt/Dbo/Dbo>

class Organization;
class Probe;


struct ProbeId
{
    int id;
    Wt::Dbo::ptr<Organization> orga;

    ProbeId(int id, Wt::Dbo::ptr<Organization> ptr)
        : id(id), orga(ptr) { }

    ProbeId(){ }

    bool operator== (const ProbeId& other) const {
        return id == other.id && orga == other.orga;
    }

    bool operator< (const ProbeId& other) const {
        if (id < other.id)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const ProbeId& pk)
{
    return o << "(" << pk.id << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, ProbeId& prid,
                   const std::string& name, int size = -1)
        {
            Wt::Dbo::belongsTo(a, prid.orga, "ORG_ID");
        }
        template<>
        struct dbo_traits<Probe> : public dbo_default_traits
        {
            typedef ProbeId IdType;
            static IdType invalidId() { return ProbeId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}
#endif	/* PROBEID_H */