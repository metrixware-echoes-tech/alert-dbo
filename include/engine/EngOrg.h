/* 
 * File:   EngOrg.h
 * Author: tsa
 *
 * Created on 21 avril 2013, 14:10
 */

#ifndef ENGORG_H
#define	ENGORG_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>
#include "primaryKeys/EngOrgId.h"

class EngOrg : public Table {
public:
    EngOrg();
    EngOrg(const EngOrg& orig);
    virtual ~EngOrg();
    
    static std::string TRIGRAM;
    
    EngOrgId pk;
    
    Wt::WString token;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["TOKEN"]=&this->token;
        FIELD_FILLER();

        Wt::Dbo::id(a,pk,"PRIMARY_KEY");
    }
    
    
    
private:

};

#endif	/* ENGORG_H */

