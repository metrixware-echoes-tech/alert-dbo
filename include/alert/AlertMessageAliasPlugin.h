/* 
 * File:   AlertMessageAliasPlugin.h
 * Author: tsa
 *
 * Created on 25 février 2013, 18:08
 */

#ifndef ALERTMESSAGEALIASPLUGIN_H
#define	ALERTMESSAGEALIASPLUGIN_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

#include "primaryKeys/AlertMessageAliasPluginId.h"

class AlertMessageAliasPlugin : public Table {
public:
    AlertMessageAliasPlugin();
    AlertMessageAliasPlugin(const AlertMessageAliasPlugin& orig);
    virtual ~AlertMessageAliasPlugin();
    
    static std::string TRIGRAM;
    
    Wt::WString alias;
    
    AlertMessageAliasPluginId pk;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["ALIAS"]=&this->alias;

        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, TRIGRAM_ALERT_MESSAGE_ALIAS_PLUGIN SEP ID);

    }
    
    virtual std::string toJSON();
private:

};

#endif	/* ALERTMESSAGEALIASPLUGIN_H */

