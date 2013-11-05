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
        
        int nbValue;
        int posKeyValue;
        
        Wt::Dbo::ptr<FilterType> filterType;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Search>> searches;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationData>> informationDatas;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesInts["NB_VALUE"] = &this->nbValue;
            mapClassAttributesInts["POS_KEY_VALUE"] = &this->posKeyValue;
            FIELD_FILLER();
            Wt::Dbo::belongsTo(a, filterType, TRIGRAM_FILTER SEP TRIGRAM_FILTER_TYPE);
            Wt::Dbo::hasMany(a, searches, Wt::Dbo::ManyToOne, TRIGRAM_SEARCH SEP TRIGRAM_FILTER);
            Wt::Dbo::hasMany(a, informationDatas, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_FILTER);
        }
        virtual std::string toJSON() const;
        
    private:

    };
  }
}



#endif	/* FILTER_H */

