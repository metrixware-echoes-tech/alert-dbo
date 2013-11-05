/* 
 * Header of Plugin Table
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

#ifndef PLUGIN_H
#define PLUGIN_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Source;
    class Asset;

    class Plugin : public Table
    {
        public:
            Plugin();
            virtual ~Plugin();

            static std::string TRIGRAM;
            //   Wt::WString name;
            Wt::WString desc;
            Wt::WString versionRef;
            Wt::WString versionClient;
            
            Wt::Dbo::ptr<PluginReference> pluginReference;

            Wt::Dbo::collection<Wt::Dbo::ptr<Source>> sources;
            Wt::Dbo::collection<Wt::Dbo::ptr<Organization>> organizations;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["DESC"] = &this->desc;
                mapClassAttributesStrings["VERSION_REF"] = &this->versionRef;
                mapClassAttributesStrings["VERSION_CLIENT"] = &this->versionClient;
                FIELD_FILLER();
                
                Wt::Dbo::belongsTo(a, pluginReference, TRIGRAM_PLUGIN SEP TRIGRAM_PLUGIN_REFERENCE);
                
                //TJ
                Wt::Dbo::hasMany(a, sources, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN SEP TRIGRAM_SOURCE);
                Wt::Dbo::hasMany(a, organizations, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN SEP TRIGRAM_ORGANIZATION);
                
            }
            virtual std::string toJSON() const;

        protected:
        private:
    };
  }
}

#endif // PLUGIN_H

