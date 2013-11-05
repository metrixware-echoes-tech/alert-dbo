/* 
 * File:   PluginReference.h
 * Author: tsa
 *
 * Created on 4 novembre 2013, 16:33
 */

#ifndef PLUGINREFERENCE_H
#define	PLUGINREFERENCE_H

#include <Wt/Dbo/Dbo>
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
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"] = &this->name;
            mapClassAttributesStrings["DESC"] = &this->desc;
            mapClassAttributesStrings["VERSION"] = &this->version;
            FIELD_FILLER();
            
            Wt::Dbo::hasMany(a, plugins, Wt::Dbo::ManyToOne, TRIGRAM_PLUGIN SEP TRIGRAM_PLUGIN_REFERENCE);

            //TJ
            Wt::Dbo::hasMany(a, sources, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN_REFERENCE SEP TRIGRAM_SOURCE);

        }
        virtual std::string toJSON() const;
        
    private:

    };

  }
}

#endif	/* PLUGINREFERENCE_H */

