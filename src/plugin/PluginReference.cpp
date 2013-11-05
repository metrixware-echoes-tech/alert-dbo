/* 
 * File:   PluginReference.cpp
 * Author: tsa
 * 
 * Created on 4 novembre 2013, 16:33
 */

#include "plugin/PluginReference.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string PluginReference::TRIGRAM(TRIGRAM_PLUGIN_REFERENCE);

        PluginReference::PluginReference()
        {
            this->jsonName = "plugin_reference";
        }

        PluginReference::PluginReference(const PluginReference& orig)
        {
        }

        PluginReference::~PluginReference()
        {
        }
        
        std::string PluginReference::toJSON() const
        {
            std::string res = "";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->sources, "sources", false);

            res += "}";
            return res;
        }

    }
}

