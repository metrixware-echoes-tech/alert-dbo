/* 
 * File:   InformationId.h
 * Author: tsa
 *
 * Created on 8 juin 2012, 10:48
 */

#ifndef INFORMATIONID_H
#define	INFORMATIONID_H

#include "tools/MainIncludeFile.h"

#include "primaryKeys/SearchId.h"

class Information2;
class Search;
class InformationUnit;

struct InformationId
{
    Wt::Dbo::ptr<Search> search;
    int subSearchNumber; 
    Wt::Dbo::ptr<InformationUnit> unit;

    InformationId(Wt::Dbo::ptr<Search> ptr, int ssn, Wt::Dbo::ptr<InformationUnit> ptrUnit)
        : search(ptr), subSearchNumber(ssn), unit(ptrUnit) { }

    InformationId(){ subSearchNumber = 0; }

    bool operator== (const InformationId& other) const {
        return search == other.search && subSearchNumber == other.subSearchNumber && unit == other.unit;
    }

    bool operator< (const InformationId& other) const {
        if ((search < other.search) || (subSearchNumber < other.subSearchNumber) || unit < other.unit)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const InformationId& pk)
{
    //return o << "(" << pk.search << ")" << "(" << pk.subSearchNumber << ")" << "(" << pk.unit << ")";
    return o <<  pk.search.id()
             << ",\n\t\t\"sub_search_number\": " << pk.subSearchNumber 
             << ",\n\t\t\"unit_id\": " << pk.unit.id() ;
             //<< "\n\t},";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, InformationId& infid,
                   const std::string& name, int size = -1)
        {
            field(a, infid.search, "SEA_ID");
            field(a, infid.subSearchNumber, TRIGRAM_INFORMATION SEP "VALUE_NUM");
            field(a, infid.unit, TRIGRAM_INFORMATION_UNIT "_ID");
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

