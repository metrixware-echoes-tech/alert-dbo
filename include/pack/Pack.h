#ifndef PACK_H
#define PACK_H

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"

class Pack : public Table
{
    public:
        Pack();
        virtual ~Pack();
        
        static std::string TRIGRAM;
        std::string name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Option> > option;
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;                       
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             option,
                             Wt::Dbo::ManyToMany,
                             "TJ_PCK_OPT");
        }
        
    protected:
    private:
};

#endif // PACK_H
