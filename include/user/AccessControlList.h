/* 
 * File:   AccessControlList.h
 * Author: rhi
 *
 * Created on 10 juillet 2012, 09:41
 */

#ifndef ACCESSCONTROLLIST_H
#define	ACCESSCONTROLLIST_H

#include "MainIncludeFile.h"
#include "Wt/Dbo/Dbo"
#include "AccessControlListId.h"

class AccessControlList : public Table {
public:
    AccessControlList();
    virtual ~AccessControlList();

    static std::string TRIGRAM;
    std::string value;

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

