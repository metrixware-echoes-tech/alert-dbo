#ifndef USERVALUE_H
#define USERVALUE_H

#include <Wt/Dbo/Dbo>
#include "UserValueId.h"

class User;
class UserField;

class UserValue
{
    public:
        UserValue();
        virtual ~UserValue();
        
        UserValueId uvid;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::id(a,uvid,"PK_TEST");
        }
    protected:
    private:
};


#endif // USERVALUE_H
