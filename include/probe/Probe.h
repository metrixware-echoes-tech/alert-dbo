#ifndef PROBE_H
#define PROBE_H

#include "Organization.h"
#include "Value.h"
#include "HistoricalValue.h"
#include "Constants.h"

class Organization;
class Value;
class HistoricalValue;

struct PrimaryKey
{
    int probeId;
    Wt::Dbo::ptr<Organization> orga;

    PrimaryKey(int id, Wt::Dbo::ptr<Organization> ptr)
        : probeId(id), orga(ptr) { }

    PrimaryKey(){ }

    bool operator== (const PrimaryKey& other) const {
        return probeId == other.probeId && orga == other.orga;
    }

    bool operator< (const PrimaryKey& other) const {
        if (probeId < other.probeId)
            return true;
        else
            return false;
    }
};

std::ostream& operator<< (std::ostream& o, const PrimaryKey& pk)
{
    return o << "(" << pk.probeId << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, PrimaryKey& pk,
                   const std::string& name, int size = -1)
        {
            field(a, pk.probeId, "PRB_ID");
            Wt::Dbo::belongsTo(a, pk.orga, "ORG_ID");
        }
    }
}

class Probe : public Table
{
    public:
        Probe();
        virtual ~Probe();

        PrimaryKey pk;

        Wt::Dbo::collection<Wt::Dbo::ptr<Value>> values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue>> historicalValues;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::id (a, pk, "PRIMARY_KEY");

            //Wt::Dbo::belongsTo(a, pk.orga, "FOREIGN_KEY_TEST");

            Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             "VPR");
            Wt::Dbo::hasMany(a,
                             historicalValues,
                             Wt::Dbo::ManyToOne,
                             "HPR");
        }

    protected:
    private:
};

#endif // PROBE_H
