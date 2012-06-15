/* 
 * File:   SearchParameterValue.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:27
 */

#ifndef SEARCHPARAMETERVALUE_H
#define	SEARCHPARAMETERVALUE_H

#include "MainIncludeFile.h"

#include <Wt/Dbo/Dbo>

#include "SearchParameterValueId.h"

class SearchParameterValue : public Table {
public:
    SearchParameterValue();
    SearchParameterValue(const SearchParameterValue& orig);
    virtual ~SearchParameterValue();
    
    Wt::WDateTime deleteTag;
    static std::string TRIGRAM;             
    std::string value;
    
    SearchParameterValueId searchParameterValueId;
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::id(a,searchParameterValueId,"PRIMARY_KEY");
        mapClassAttributesDates["DELETE"]=this->deleteTag;
        mapClassAttributesStrings["VALUE"]=this->value;  
    }
private:

};

#endif	/* SEARCHPARAMETERVALUE_H */

