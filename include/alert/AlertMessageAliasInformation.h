/* 
 * File:   AlertMessageAliasInformation.h
 * Author: tsa
 *
 * Created on 25 février 2013, 18:29
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
    
    virtual std::string toJSON();
private:

};

#endif	/* ALERTMESSAGEALIASINFORMATION_H */

