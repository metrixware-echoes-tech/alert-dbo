#include "AlertValue.h"

class AlertValue;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<AlertValue> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return 0;
            }
        };
    }  
}

#include "Alert.h"
#include "AlertHisto.h"

AlertValue::AlertValue()
{
    //ctor
}

AlertValue::~AlertValue()
{
    //dtor
}
