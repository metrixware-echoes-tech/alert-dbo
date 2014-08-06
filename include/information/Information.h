/* 
 * Header of Information Table
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

#ifndef INFORMATION_H
#define INFORMATION_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Information : public Table
    {
        public:
            Information();
            Information(const Information& orig);
            virtual ~Information();

            static std::string TRIGRAM;

            //        InformationId pk;

            Wt::Dbo::collection<Wt::Dbo::ptr<InformationData> > informationDatas;
            
            Wt::Dbo::ptr<InformationUnit> informationUnit;
            Wt::Dbo::ptr<Organization> organization;

            boost::optional<Wt::WString> desc;
            bool display;
            boost::optional<Wt::WString> calculate;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesBools["DISPLAY"] = &this->display;
                mapClassAttributesStringsNn["DESC"] = &this->desc;
                mapClassAttributesStringsNn["CALCULATE"] = &this->calculate;
                Table::fieldFiller(a, *this);
                //            Wt::Dbo::id(a,pk,"PRIMARY_KEY");
                
                Wt::Dbo::hasMany(a, informationDatas, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_INFORMATION);

                Wt::Dbo::belongsTo(a, informationUnit, TRIGRAM_INFORMATION SEP TRIGRAM_INFORMATION_UNIT);
                Wt::Dbo::belongsTo(a, organization, TRIGRAM_INFORMATION SEP TRIGRAM_ORGANIZATION);
            }

        protected:
        private:
    };
  }
}

#endif // INFORMATION_H

