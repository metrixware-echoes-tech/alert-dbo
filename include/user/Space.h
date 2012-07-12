/* 
 * File:   Space.h
 * Author: rhi
 *
 * Created on 10 juillet 2012, 09:08
 */

#ifndef SPACE_H
#define	SPACE_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"

class Space : public Table
{
public:
    Space();
    virtual ~Space();
    
    static std::string TRIGRAM;
    
    std::string name;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=this->name;
        FIELD_FILLER();            
    }
};

#endif	/* SPACE_H */

