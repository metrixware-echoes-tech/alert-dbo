/* 
 * File:   UserRight.h
 * Author: rhi
 *
 * Created on 10 juillet 2012, 08:51
 */

#ifndef USERRIGHT_H
#define	USERRIGHT_H

#include <Wt/Dbo/Dbo>
#include "MainIncludeFile.h"

class UserRight : public Table
{
public:
    UserRight();
    virtual ~UserRight();
    
    static std::string TRIGRAM;
    
    std::string name;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=this->name;
        FIELD_FILLER();            
    }
};


#endif	/* USERRIGHT_H */

