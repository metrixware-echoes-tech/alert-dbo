/* 
 * Header of Access Control List Table
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

#ifndef ACCESSCONTROLLIST_H
#define	ACCESSCONTROLLIST_H

#include "tools/MainIncludeFile.h"
#include "Wt/Dbo/Dbo"
#include "primaryKeys/AccessControlListId.h"

class AccessControlList : public Table {
public:
    AccessControlList();
    virtual ~AccessControlList();

    static std::string TRIGRAM;
    Wt::WString value;

    AccessControlListId pk;

    template<class Action>
    void persist(Action& a)
    {             
        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, "ACL_ID");     
    }
    private:
};

#endif	/* ACCESSCONTROLLIST_H */

