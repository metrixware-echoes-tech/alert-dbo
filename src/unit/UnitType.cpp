#include "ProbeId.h"
#include "Probe.h"

#include "UnitType.h"

class UnitType;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<UnitType> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "UTY_ID";
            }
        };
    }  
}

#include "Unit.h"

#include "HistoricalValue.h"
#include "Value.h"
#include "Plugin.h"
#include "Information.h"


#include "Organization.h"

UnitType::UnitType()
{
    //ctor
}

UnitType::~UnitType()
{
    //dtor
}
