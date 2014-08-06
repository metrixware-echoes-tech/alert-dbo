/* 
 * Header of Plugin Reference Table
 * @author ECHOES Technologies (TSA)
 * @date 04/11/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef PLUGINREFERENCE_H
#define	PLUGINREFERENCE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class PluginReference : public Table {
        public:
            PluginReference();
            PluginReference(const PluginReference& orig);
            virtual ~PluginReference();

            static std::string TRIGRAM;

            Wt::WString desc;
            Wt::WString version;
            Wt::Dbo::collection<Wt::Dbo::ptr<Plugin>> plugins;
            Wt::Dbo::collection<Wt::Dbo::ptr<Source>> sources;
            Wt::Dbo::collection<Wt::Dbo::ptr<Organization>> organizations;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["DESC"] = &this->desc;
                mapClassAttributesStrings["VERSION"] = &this->version;
                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a, plugins, Wt::Dbo::ManyToOne, TRIGRAM_PLUGIN SEP TRIGRAM_PLUGIN_REFERENCE);

                //TJ
                Wt::Dbo::hasMany(a, sources, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN_REFERENCE SEP TRIGRAM_SOURCE);
                Wt::Dbo::hasMany(a, organizations, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN_REFERENCE SEP TRIGRAM_ORGANIZATION);

            }

        private:
    };

  }
}

#endif	/* PLUGINREFERENCE_H */

