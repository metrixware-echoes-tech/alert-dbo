/* 
 * File:   SourceParameterValue.h
 * Author: tsa
 *
 * Created on 4 juin 2012, 17:25
 */

#ifndef SOURCEPARAMETERVALUE_H
#define	SOURCEPARAMETERVALUE_H

#include "tools/MainIncludeFile.h"
#include "primaryKeys/SourceParameterValueId.h"
#include <Wt/Dbo/Dbo>

class SourceParameter;

class SourceParameterValue : public Table {
public:
    SourceParameterValue();
    SourceParameterValue(const SourceParameterValue& orig);
    virtual ~SourceParameterValue();
    
    static std::string TRIGRAM;
            
    Wt::WString value;
   
    
    SourceParameterValueId pk;
    Wt::Dbo::ptr<SourceParameter> sourceParameter;
    
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["VALUE"]=&this->value; 
        FIELD_FILLER();
        Wt::Dbo::id (a, pk, "PRIMARY_KEY");
        
        Wt::Dbo::belongsTo(a, sourceParameter, "SPV_SRP");
    }
private:

};

#endif	/* SOURCEPARAMETERVALUE_H */

