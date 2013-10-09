/* 
 * Header of Pack Option Table
 * @author ECHOES Technologies (RHI)
 * @date 10/09/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef PACKOPTION_H
#define	PACKOPTION_H

#include "tools/MainIncludeFile.h"
#include "Wt/Dbo/Dbo"
#include "primaryKeys/PackOptionId.h"

class PackOption : public Table {
public:
    PackOption();
    virtual ~PackOption();

    static std::string TRIGRAM;
    Wt::WString value;

    PackOptionId pk;

    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["VALUE"]=&this->value;        
        
        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, "POP_ID");
        
    }
 
    virtual std::string toJSON() const;
        
    private:
};

#endif	/* PACKOPTION_H */

