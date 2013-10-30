/* 
 * Header of Filter Table
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

#ifndef FILTER_H
#define	FILTER_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {

    class Filter : public Table {
    public:
        Filter();
        Filter(const Filter& orig);
        virtual ~Filter();
        
        static std::string TRIGRAM;
        
        Wt::Dbo::ptr<FilterType> filterType;
        
        template<class Action>
        void persist(Action& a)
        {
            FIELD_FILLER();
            Wt::Dbo::belongsTo(a, filterType, TRIGRAM_FILTER SEP TRIGRAM_FILTER_TYPE);
        }
        virtual std::string toJSON() const;
        
    private:

    };
  }
}



#endif	/* FILTER_H */

