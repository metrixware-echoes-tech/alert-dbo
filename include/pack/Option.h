/* 
 * Header of Option Table
 * @author ECHOES Technologies (TSA)
 * @date 03/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef OPTION_H
#define OPTION_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class Option : public Table
{
    public:
        Option();
        virtual ~Option();
        static std::string TRIGRAM;
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<PackOption> > packOptions;
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;                       
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,
                             packOptions,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_PACK_OPTION SEP TRIGRAM_OPTION );
        }
        
        virtual std::string toJSON() const;
        
    protected:
    private:
};

#endif // OPTION_H

