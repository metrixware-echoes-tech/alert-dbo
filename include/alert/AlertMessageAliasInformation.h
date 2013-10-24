/* 
 * Header of Alert Media Alias Information Table
 * @author ECHOES Technologies (TSA)
 * @date 25/02/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef ALERTMESSAGEALIASINFORMATION_H
#define	ALERTMESSAGEALIASINFORMATION_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

#include "primaryKeys/AlertMessageAliasInformationId.h"

class AlertMessageAliasInformation : public Table {
public:
    AlertMessageAliasInformation();
    AlertMessageAliasInformation(const AlertMessageAliasInformation& orig);
    virtual ~AlertMessageAliasInformation();
    
    static std::string TRIGRAM;
    
    Wt::WString alias;
    
    AlertMessageAliasInformationId pk;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["ALIAS"]=&this->alias;

        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, TRIGRAM_ALERT_MESSAGE_ALIAS_INFORMATION SEP ID);

    }
    
    virtual std::string toJSON() const;
private:

};

#endif	/* ALERTMESSAGEALIASINFORMATION_H */

