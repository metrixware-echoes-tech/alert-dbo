/* 
 * Header of Alert Criteria Table
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

#ifndef ALERTCRITERIA_H
#define ALERTCRITERIA_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class AlertCriteria : public Table
{
    public:
        AlertCriteria();
        virtual ~AlertCriteria();
        
        static std::string TRIGRAM;
        Wt::WString name;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationUnitType> > informationUnitTypes;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a,alertValues,Wt::Dbo::ManyToOne, TRIGRAM_ALERT_VALUE SEP TRIGRAM_ALERT_CRITERIA);
            
            Wt::Dbo::hasMany(a,informationUnitTypes,Wt::Dbo::ManyToMany, "TJ" SEP TRIGRAM_ALERT_CRITERIA SEP TRIGRAM_INFORMATION_UNIT_TYPE);
            
        }
        
        virtual std::string toJSON() const;
        
        
    protected:
    private:
};

#endif // ALERTCRITERIA_H

