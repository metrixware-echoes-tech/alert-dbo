/* 
 * File:   AlertMessageAliasInformationCriteria.h
 * Author: tsa
 *
 * Created on 25 février 2013, 18:40
 */

#ifndef ALERTMESSAGEALIASINFORMATIONCRITERIA_H
#define	ALERTMESSAGEALIASINFORMATIONCRITERIA_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

#include "primaryKeys/AlertMessageAliasInformationCriteriaId.h"

class AlertMessageAliasInformationCriteria : public Table{
public:
    AlertMessageAliasInformationCriteria();
    AlertMessageAliasInformationCriteria(const AlertMessageAliasInformationCriteria& orig);
    virtual ~AlertMessageAliasInformationCriteria();
    
    static std::string TRIGRAM;
    
    Wt::WString alias;
    AlertMessageAliasInformationCriteriaId pk;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["ALIAS"]=&this->alias;

        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, TRIGRAM_ALERT_MESSAGE_ALIAS_INFORMATION_CRITERIA SEP ID);

    }
    
    virtual std::string toJSON();
private:

};

#endif	/* ALERTMESSAGEALIASINFORMATIONCRITERIA_H */

