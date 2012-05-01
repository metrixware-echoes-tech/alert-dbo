#include "AlertHisto.h"

class AlertHisto;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<AlertHisto> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "AHI_ID";
            }
        };
    }  
}

#include "Alert.h"
#include "AlertValue.h"

AlertHisto::AlertHisto()
{
    //ctor
}

AlertHisto::~AlertHisto()
{
    //dtor
}
