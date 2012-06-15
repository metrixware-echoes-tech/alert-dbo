#ifndef USERVALUE_H
#define USERVALUE_H

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"

class UserValue : public Table
{
    public:
        UserValue();
        virtual ~UserValue();
        
        static std::string TRIGRAM;
        
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
