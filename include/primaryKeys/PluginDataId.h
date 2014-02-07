/* 
 * File:   PluginDataId.h
 * Author: tsa
 *
 * Created on 8 juin 2012, 10:48
 */

#ifndef PLUGINDATAID_H
#define	PLUGINDATAID_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {

    class PluginData;

    struct PluginDataId {
        Wt::Dbo::ptr<Plugin> plugin;
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<InformationData> informationData;

        PluginDataId(Wt::Dbo::ptr<Plugin> plugin, Wt::Dbo::ptr<Asset> asset, Wt::Dbo::ptr<InformationData> informationData)
        : plugin(plugin), asset(asset), informationData(informationData) {
        }

        PluginDataId() {
        }

        bool operator==(const PluginDataId& other) const {
            return plugin == other.plugin && asset == other.asset && informationData == other.informationData;
        }

        bool operator<(const PluginDataId& other) const {
            if ((plugin < other.plugin) || (asset < other.asset) || (informationData < other.informationData))
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const PluginDataId& pk) {
        return o << pk.plugin.id()
                << pk.asset.id()
                << pk.informationData.id();
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::PluginDataId& pluginDataId,
            const std::string& name, int size = -1) {
        field(a, pluginDataId.plugin, TRIGRAM_PLUGIN ID);
        field(a, pluginDataId.asset, TRIGRAM_ASSET ID);
        field(a, pluginDataId.informationData, TRIGRAM_INFORMATION_DATA ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::PluginData> : public dbo_default_traits {
        typedef Echoes::Dbo::PluginDataId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::PluginDataId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* PLUGINDATAID_H */

