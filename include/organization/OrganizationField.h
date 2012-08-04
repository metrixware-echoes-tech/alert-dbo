/* 
 * File:   OrganizationField.h
 * Author: rhi
 *
 * Created on 9 juillet 2012, 16:12
 */

#ifndef ORGANIZATIONFIELD_H
#define	ORGANIZATIONFIELD_H

#include "tools/MainIncludeFile.h"
#include "Wt/Dbo/Dbo"

class OrganizationField : public Table {
public:
    OrganizationField();
    virtual ~OrganizationField();
    static std::string TRIGRAM;
    Wt::WString name;
    Wt::WString format;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<OrganizationType> > organizationType;   
    

    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=&this->name;
        mapClassAttributesStrings["FORMAT"]=&this->format;
        FIELD_FILLER();
        
        Wt::Dbo::hasMany(a,
                         organizationType,
                         Wt::Dbo::ManyToMany,
                         "TJ_OFI_OTY");


    }
};

#endif	/* ORGANIZATIONFIELD_H */