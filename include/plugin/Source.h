/* 
 * Header of Source Table
 * @author ECHOES Technologies (TSA)
 * @date 04/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef SOURCE_H
#define	SOURCE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"
#include "primaryKeys/SourceId.h"

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
    
    virtual std::string toJSON() const;
     
private:

};

#endif	/* SOURCE_H */

