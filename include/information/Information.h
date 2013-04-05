#ifndef INFORMATION_H
#define INFORMATION_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

#include "primaryKeys/InformationId.h"

class Information2 : public Table
{
    public:
        Information2();
        virtual ~Information2();
        
        static std::string TRIGRAM;
        
        InformationId pk;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        
        Wt::WString name;
        boost::optional<Wt::WString> desc;
        bool display;
        boost::optional<Wt::WString> calculate;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            mapClassAttributesBools["DISPLAY"]=&this->display;
            mapClassAttributesStringsNn["DESC"]=&this->desc;
            mapClassAttributesStringsNn["CALCULATE"]=&this->calculate;
            FIELD_FILLER();
            Wt::Dbo::id(a,pk,"PRIMARY_KEY");
            
            Wt::Dbo::hasMany(a,
                             alertValues,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_ALERT_VALUE SEP TRIGRAM_INFORMATION);
        }    

        virtual std::string toJSON();
        
    protected:
    private:
};

#endif // INFORMATION_H
