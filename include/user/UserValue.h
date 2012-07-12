#ifndef USERVALUE_H
#define USERVALUE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class UserValue : public Table
{
    public:
        UserValue();
        virtual ~UserValue();
        
        static std::string TRIGRAM;
        std::string value;
        
        UserValueId uvid;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["VALUE"]=this->value;
            FIELD_FILLER();
            Wt::Dbo::id(a,uvid,"PRIMARY_KEY");
        }
    protected:
    private:
};


#endif // USERVALUE_H
