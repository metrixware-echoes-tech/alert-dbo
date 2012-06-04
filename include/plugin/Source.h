/* 
 * File:   Source.h
 * Author: tsa
 *
 * Created on 4 juin 2012, 14:15
 */

#ifndef SOURCE_H
#define	SOURCE_H

#include "Table.h"
#include <Wt/Dbo/Dbo>

#include "SourceId.h"
#include "Plugin.h"
#include "SourceParameter.h"
#include "SourceParameterValue.h"

class Source : public Table
{
public:
    Source();
    Source(const Source& orig);
    virtual ~Source();
    
    static std::string TRIGRAM;

    SourceId pk;
    
    Wt::Dbo::ptr<Addon> addon;
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::id (a, pk, "PRIMARY_KEY");
        
        Wt::Dbo::belongsTo(a, addon, "ADO");
    }
     
private:

};

#endif	/* SOURCE_H */

