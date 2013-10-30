/* 
 * Header of Filter Type Table
 * @author ECHOES Technologies (TSA)
 * @date 30/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef FILTERTYPE_H
#define	FILTERTYPE_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {

    class FilterType : public Table {
    public:
        FilterType();
        FilterType(const FilterType& orig);
        virtual ~FilterType();
        
        static std::string TRIGRAM;
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Filter> > filters;
        Wt::Dbo::collection<Wt::Dbo::ptr<FilterParameter> > filterParameters;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"] = &this->name;
            FIELD_FILLER();
            Wt::Dbo::hasMany(a,
                    filters,
                    Wt::Dbo::ManyToOne,
                    TRIGRAM_FILTER SEP TRIGRAM_FILTER_TYPE);


            Wt::Dbo::hasMany(a,
                    filterParameters,
                    Wt::Dbo::ManyToMany,
                    TABLE_JOINT_PREFIX SEP TRIGRAM_FILTER_TYPE SEP TRIGRAM_FILTER_PARAMETER);

        }

        virtual std::string toJSON() const;
        
    private:

    };

  }
}

#endif	/* FILTERTYPE_H */

