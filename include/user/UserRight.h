/* 
 * Header of User Right Table
 * @author ECHOES Technologies (RHI)
 * @date 10/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef USERRIGHT_H
#define	USERRIGHT_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"

class UserRight : public Table
{
public:
    UserRight();
    virtual ~UserRight();
    
    static std::string TRIGRAM;
    
    Wt::WString name;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=&this->name;
        FIELD_FILLER();            
    }
};


#endif	/* USERRIGHT_H */

