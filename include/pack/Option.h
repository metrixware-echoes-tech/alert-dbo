#ifndef OPTION_H
#define OPTION_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class Option : public Table
{
    public:
        Option();
        virtual ~Option();
        static std::string TRIGRAM;
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<PackOption> > packOptions;
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;                       
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             packOptions,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_PACK_OPTION SEP TRIGRAM_OPTION );
        }
    protected:
    private:
};

#endif // OPTION_H
