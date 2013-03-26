/* 
 * File:   OptionValue.h
 * Author: rhi
 *
 * Created on 10 septembre 2012, 22:26
 */

#ifndef OPTIONVALUE_H
#define	OPTIONVALUE_H

#include "tools/MainIncludeFile.h"
#include "Wt/Dbo/Dbo"
#include "primaryKeys/OptionValueId.h"

class OptionValue : public Table {
public:
    OptionValue();
    virtual ~OptionValue();

    static std::string TRIGRAM;
    Wt::WString value;

    OptionValueId pk;

    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["VALUE"]=&this->value;        
        
        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, "OPV_ID");
        
    }
    
    virtual std::string toJSON();
    
    private:
};


#endif	/* OPTIONVALUE_H */

