/* 
 * File:   OrganizationType.h
 * Author: rhi
 *
 * Created on 3 juillet 2012, 19:04
 */

#ifndef ORGANIZATIONVALUE_H
#define ORGANIZATIONVALUE_H

#include "MainIncludeFile.h"
#include "Wt/Dbo/Dbo"

class OrganizationValue : public Table {
    public:
        OrganizationValue();
        virtual ~OrganizationValue();
        
        static std::string TRIGRAM;
        std::string value;        
        
    private:
};

#endif // ORGANIZATIONVALUE_H
