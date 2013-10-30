/* 
 * Header of Source Parameter Table
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

#ifndef SOURCEPARAMETER_H
#define	SOURCEPARAMETER_H

#include "tools/MainIncludeFile.h"

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {
    class SourceParameterValue;

    class SourceParameter : public Table
    {
        public:
            SourceParameter();
            SourceParameter(const SourceParameter& orig);
            virtual ~SourceParameter();

            static std::string TRIGRAM;

            Wt::WString name;
            Wt::WString format;

            //    Wt::Dbo::collection<Wt::Dbo::ptr<SourceParameterValue> > sourceParameterValues;
            Wt::Dbo::collection<Wt::Dbo::ptr<Addon> > Addons;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["FORMAT"] = &this->format;
                FIELD_FILLER();
                //        Wt::Dbo::hasMany(a,
                //                        sourceParameterValues,
                //                        Wt::Dbo::ManyToOne,
                //                        "SPV_SRP");

                //TJ
                Wt::Dbo::hasMany(a,
                        Addons,
                        Wt::Dbo::ManyToMany,
                        "TJ_ADO_SRP");
            }

            virtual std::string toJSON() const;
        private:
    };
  }
}

#endif	/* SOURCEPARAMETER_H */

