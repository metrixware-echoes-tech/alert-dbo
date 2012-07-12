/* 
 * File:   OrganizationType.h
 * Author: rhi
 *
 * Created on 3 juillet 2012, 17:56
 */
#ifndef ORGANIZATIONTYPE_H
#define ORGANIZATIONTYPE_H

#include "tools/MainIncludeFile.h"
#include "Wt/Dbo/Dbo"

class OrganizationType : public Table {
public:
        OrganizationType();
        virtual ~OrganizationType();
        static std::string TRIGRAM;
        std::string name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Organization> > organization;
        Wt::Dbo::collection<Wt::Dbo::ptr<OrganizationField> > organizationField;   
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=this->name;
        FIELD_FILLER();
        Wt::Dbo::hasMany(a,
                         organizationField,
                         Wt::Dbo::ManyToMany,
                         "TJ_OFI_OTY");
        
        
        Wt::Dbo::hasMany(a,
                        organization,
                        Wt::Dbo::ManyToOne,
                        "ORG_OTY");


    }
private:
};

#endif // ORGANIZATIONTYPE_H