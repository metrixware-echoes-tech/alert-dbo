#ifndef OPTION_H
#define OPTION_H

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"

class Option : public Table
{
    public:
        Option();
        virtual ~Option();
        static std::string TRIGRAM;
        std::string name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Pack> > pack;
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=this->name;                       
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             pack,
                             Wt::Dbo::ManyToMany,
                             "TJ_PCK_OPT");
        }
    protected:
    private:
};

#endif // OPTION_H
