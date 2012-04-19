#ifndef PROBE_H
#define PROBE_H

#include "Organization.h"
#include "Value.h"
#include "HistoricalValue.h"

class Organization;
class Value;
class HistoricalValue;

class Probe : public Table
{
    public:
        Probe();
        virtual ~Probe();

        Wt::Dbo::ptr<Organization> organization;

        Wt::Dbo::collection<Wt::Dbo::ptr<Value>> values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue>> historicalValues;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::belongsTo(a, organization, "PRB");

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
