/* 
 * File:   PackOption.h
 * Author: rhi
 *
 * Created on 10 septembre 2012, 22:07
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
 
    virtual std::string toJSON();
        
    private:
};

#endif	/* PACKOPTION_H */

