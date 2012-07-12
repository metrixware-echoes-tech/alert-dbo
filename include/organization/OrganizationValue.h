/* 
 * File:   OrganizationType.h
 * Author: rhi
 *
 * Created on 3 juillet 2012, 19:04
 */

#ifndef ORGANIZATIONVALUE_H
#define ORGANIZATIONVALUE_H

#include "tools/MainIncludeFile.h"
#include "Wt/Dbo/Dbo"
#include "primaryKeys/OrganizationValueId.h"

class OrganizationValue : public Table {
public:
    OrganizationValue();
    virtual ~OrganizationValue();

    static std::string TRIGRAM;
    std::string value;

    OrganizationValueId pk;

    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["VALUE"]=this->value;        
        
        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, "OVA_ID");
        
    }
    private:
};

#endif // ORGANIZATIONVALUE_H
