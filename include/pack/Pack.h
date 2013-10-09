/* 
 * Header of Pack Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef PACK_H
#define PACK_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class Pack : public Table
{
    public:
        Pack();
        virtual ~Pack();
        
        static std::string TRIGRAM;
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<PackOption> > packOptions;
        Wt::Dbo::collection<Wt::Dbo::ptr<Organization> > organizations;
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;                       
            FIELD_FILLER();            
                    
            Wt::Dbo::hasMany(a,
                             organizations,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_ORGANIZATION SEP TRIGRAM_PACK);
            
            Wt::Dbo::hasMany(a,
                             packOptions,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_PACK_OPTION SEP TRIGRAM_PACK);
        }
        
        virtual std::string toJSON() const;
        
    protected:
    private:
};

#endif // PACK_H

