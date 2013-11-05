/* 
 * File:   PluginData.h
 * Author: tsa
 *
 * Created on 5 novembre 2013, 12:07
 */

#ifndef PLUGINDATA_H
#define	PLUGINDATA_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"
#include "primaryKeys/PluginDataId.h"

namespace Echoes
{
  namespace Dbo
  {

    class PluginData : public Table {
    public:
        PluginData();
        PluginData(const PluginData& orig);
        virtual ~PluginData();
        
        static std::string TRIGRAM;
        
        PluginDataId pk;
        
        template<class Action>
        void persist(Action& a)
        {
            FIELD_FILLER();

            Wt::Dbo::id(a, pk, TRIGRAM_PLUGIN_DATA SEP ID);
        }

        
    private:

    };

  }
}

#endif	/* PLUGINDATA_H */

