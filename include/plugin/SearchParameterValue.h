/* 
 * File:   SearchParameterValue.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:27
 */

#ifndef SEARCHPARAMETERVALUE_H
#define	SEARCHPARAMETERVALUE_H

#include "Table.h"

#include <Wt/Dbo/Dbo>

#include "SearchParameterValueId.h"
#include "SearchParameter.h"

class SearchParameterValue {
public:
    SearchParameterValue();
    SearchParameterValue(const SearchParameterValue& orig);
    virtual ~SearchParameterValue();
    
    SearchParameterValueId searchParameterValueId;
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::id(a,searchParameterValueId,"PRIMARY_KEY");
    }
private:

};

#endif	/* SEARCHPARAMETERVALUE_H */

