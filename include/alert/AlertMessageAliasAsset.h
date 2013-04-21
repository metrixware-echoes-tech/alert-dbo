/* 
 * File:   AlertMediaMessageAliasAsset.h
 * Author: tsa
 *
 * Created on 25 février 2013, 11:38
 */

#ifndef ALERTMEDIAMESSAGEALIASASSET_H
#define	ALERTMEDIAMESSAGEALIASASSET_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

#include "primaryKeys/AlertMessageAliasAssetId.h"

class AlertMessageAliasAsset : public Table {
public:
    AlertMessageAliasAsset();
    AlertMessageAliasAsset(const AlertMessageAliasAsset& orig);
    virtual ~AlertMessageAliasAsset();
    
    static std::string TRIGRAM;
    
    Wt::WString alias;
    AlertMessageAliasAssetId pk;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["ALIAS"]=&this->alias;

        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, TRIGRAM_ALERT_MESSAGE_ALIAS_ASSET SEP ID);

    }
    
    virtual std::string toJSON();
    
    
    
    

private:

};

#endif	/* ALERTMEDIAMESSAGEALIASASSET_H */

