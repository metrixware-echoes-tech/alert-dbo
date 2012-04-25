/* 
 * File:   ProbeId.h
 * Author: tom
 *
 * Created on 23 avril 2012, 17:35
 */


#ifndef PROBEID_H
#define	PROBEID_H

/*
class Organization;

#include <Wt/Dbo/Dbo>

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
 * */
#endif	/* PROBEID_H */