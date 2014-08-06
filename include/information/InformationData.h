/* 
 * Header of Information Data Table
 * @author ECHOES Technologies (TSA)
 * @date 31/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef INFORMATIONDATA_H
#define	INFORMATIONDATA_H

#include "tools/MainIncludeFile.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    class InformationData : public Table {
    public:
        InformationData();
        InformationData(const InformationData& orig);
        virtual ~InformationData();

        static std::string TRIGRAM;

        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationValue> > informationValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationHistoricalValue> > informationHistoricalValues;
        
        Wt::Dbo::ptr<Information> information;
        Wt::Dbo::ptr<Filter> filter;
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<InformationUnit> informationUnit;
        int filterFieldIndex;

        template<class Action>
        void persist(Action& a) {
            mapClassAttributesInts["FILTER_FIELD_INDEX"] = &this->filterFieldIndex;
            Table::fieldFiller(a, *this);
            
            Wt::Dbo::belongsTo(a, information, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_INFORMATION);
            Wt::Dbo::belongsTo(a, filter, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_FILTER);
            Wt::Dbo::belongsTo(a, asset, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_ASSET);
            Wt::Dbo::belongsTo(a, informationUnit, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_INFORMATION_UNIT);

            Wt::Dbo::hasMany(a, alertValues, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_VALUE SEP TRIGRAM_INFORMATION_DATA);
            Wt::Dbo::hasMany(a, informationValues, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_INFORMATION_DATA);
            Wt::Dbo::hasMany(a, informationHistoricalValues, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_INFORMATION_DATA);
        }

    private:
    };
  }
}

#endif	/* INFORMATIONDATA_H */

