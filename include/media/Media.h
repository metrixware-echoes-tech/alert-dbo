#ifndef MEDIA_H
#define MEDIA_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

class MediaValue;

class Media : public Table
{
    public:
        Media();
        virtual ~Media();
        static std::string TRIGRAM;
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<MediaValue> > mediaValues;
        template<class Action>
        void persist(Action& a)
        { 
            mapClassAttributesStrings["NAME"]=&this->name;
            
            FIELD_FILLER();
            Wt::Dbo::hasMany(a,
                             mediaValues,
                             Wt::Dbo::ManyToOne,
                             "MEV_MED");

       }
    protected:
    private:
};

#endif // MEDIA_H
