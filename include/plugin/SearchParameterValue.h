/* 
 * File:   SearchParameterValue.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:27
 */

#ifndef SEARCHPARAMETERVALUE_H
#define	SEARCHPARAMETERVALUE_H

#include "tools/MainIncludeFile.h"

#include <Wt/Dbo/Dbo>

#include "primaryKeys/SearchParameterValueId.h"

class SearchParameterValue : public Table {
public:
    SearchParameterValue();
    SearchParameterValue(const SearchParameterValue& orig);
    virtual ~SearchParameterValue();
    
    static std::string TRIGRAM;             
    Wt::WString value;
    
    SearchParameterValueId searchParameterValueId;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["VALUE"]=&this->value;  
        FIELD_FILLER();
        Wt::Dbo::id(a,searchParameterValueId,"SEV_ID");
        
    }
    
    virtual std::string toJSON();
       
private:

};

#endif	/* SEARCHPARAMETERVALUE_H */

