#include "Alert.h"

class Alert;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<Alert> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "ALE_ID";
            }
        };
    }  
}

#include "AlertHisto.h"
#include "AlertValue.h"

Alert::Alert()
{
    //ctor
}

Alert::~Alert()
{
    //dtor
}
