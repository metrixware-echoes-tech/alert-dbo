/* 
 * Header of Organization Type Table
 * @author ECHOES Technologies (RHI)
 * @date 03/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
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
        
        enum eType 
        {
            Company = 1, 
            Individual = 2, 
            Association = 3 
        };
        
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Organization> > organization;
        Wt::Dbo::collection<Wt::Dbo::ptr<OrganizationField> > organizationField;   
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=&this->name;
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
    virtual std::string toJSON() const;
private:
};

#endif // ORGANIZATIONTYPE_H

