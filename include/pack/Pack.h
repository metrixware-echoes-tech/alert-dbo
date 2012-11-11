#ifndef PACK_H
#define PACK_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class Pack : public Table
{
    public:
        Pack();
        virtual ~Pack();
        
        static std::string TRIGRAM;
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<PackOption> > packOptions;
        Wt::Dbo::collection<Wt::Dbo::ptr<Organization> > organizations;
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;                       
            FIELD_FILLER();            
                    
            Wt::Dbo::hasMany(a,
                             organizations,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_ORGANIZATION SEP TRIGRAM_PACK);
            
            Wt::Dbo::hasMany(a,
                             packOptions,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_PACK_OPTION SEP TRIGRAM_PACK);
        }
        
    protected:
    private:
};

#endif // PACK_H
