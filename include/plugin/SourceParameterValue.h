/* 
 * Header of Source Parameter Value Table
 * @author ECHOES Technologies (TSA)
 * @date 04/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
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
    
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["VALUE"]=&this->value; 
        FIELD_FILLER();
        Wt::Dbo::id (a, pk, "PRIMARY_KEY");
    }
    
    virtual std::string toJSON() const;
    
    
private:

};

#endif	/* SOURCEPARAMETERVALUE_H */

