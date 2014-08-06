/* 
 * Header of Asset Table
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

#ifndef ASSET_H
#define ASSET_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Asset : public Table
    {
        public:
            Asset();
            virtual ~Asset();

            static std::string TRIGRAM;

            bool assetIsHost;

            Wt::Dbo::ptr<Organization> organization;

            Wt::Dbo::ptr<AssetArchitecture> assetArchitecture;
            Wt::Dbo::ptr<AssetDistribution> assetDistribution;
            Wt::Dbo::ptr<AssetRelease> assetRelease;
            
            Wt::Dbo::collection<Wt::Dbo::ptr<Probe>> probes;
            Wt::Dbo::collection<Wt::Dbo::ptr<Plugin> > plugins;
            Wt::Dbo::collection<Wt::Dbo::ptr<InformationData> > informationDatas;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesBools["IS_HOST"] = &this->assetIsHost;

                Table::fieldFiller(a, *this);
                
                Wt::Dbo::belongsTo(a, organization, TRIGRAM_ASSET SEP TRIGRAM_ORGANIZATION);

                Wt::Dbo::belongsTo(a, assetArchitecture, TRIGRAM_ASSET SEP TRIGRAM_ASSET_ARCHITECTURE);
                Wt::Dbo::belongsTo(a, assetDistribution, TRIGRAM_ASSET SEP TRIGRAM_ASSET_DISTRIBUTION);
                Wt::Dbo::belongsTo(a, assetRelease, TRIGRAM_ASSET SEP TRIGRAM_ASSET_RELEASE);

                Wt::Dbo::hasMany(a, probes, Wt::Dbo::ManyToOne, TRIGRAM_PROBE SEP TRIGRAM_ASSET);
                Wt::Dbo::hasMany(a, informationDatas, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_ASSET);
                Wt::Dbo::hasMany(a, plugins, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN SEP TRIGRAM_ASSET);
            }

        protected:
        private:
    };
  }
}

#endif // ASSET_H

