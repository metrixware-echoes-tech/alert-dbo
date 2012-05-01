#include "AlertParam.h"

namespace Wt
{
    namespace Dbo
    {        
        template<>
        struct dbo_traits<AlertParam> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                return "APA_ID";
            }
        };
    }
}

AlertParam::AlertParam()
{
    //ctor
}

AlertParam::~AlertParam()
{
    //dtor
}
