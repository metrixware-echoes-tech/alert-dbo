/* 
 * File:   Source.h
 * Author: tsa
 *
 * Created on 4 juin 2012, 14:15
 */

#ifndef SOURCE_H
#define	SOURCE_H

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"
#include "SourceId.h"

class Source : public Table
{
public:
    Source();
    Source(const Source& orig);
    virtual ~Source();
    
    static std::string TRIGRAM;
    Wt::WDateTime deleteTag;  
    
    SourceId pk;
    
    Wt::Dbo::ptr<Addon> addon;
    
    template<class Action>
    void persist(Action& a)
    {
        FIELD_FILLER();
        Wt::Dbo::id (a, pk, "SRC_ID");
        
        Wt::Dbo::belongsTo(a, addon, "SRC_ADO");    
    }
     
private:

};

#endif	/* SOURCE_H */

