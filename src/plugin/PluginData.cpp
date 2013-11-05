/* 
 * File:   PluginData.cpp
 * Author: tsa
 * 
 * Created on 5 novembre 2013, 12:07
 */

#include "plugin/PluginData.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string PluginData::TRIGRAM(TRIGRAM_PLUGIN_DATA);

        PluginData::PluginData()
        {
            this->jsonName = "plugin_data";
        }

        PluginData::PluginData(const PluginData& orig)
        {
        }

        PluginData::~PluginData()
        {
        }
    }
}



