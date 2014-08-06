/* 
 * Header of Plugin Data Table
 * @author ECHOES Technologies (TSA)
 * @date 05/11/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef PLUGINDATA_H
#define	PLUGINDATA_H

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
            Table::fieldFiller(a, *this);

            Wt::Dbo::id(a, pk, TRIGRAM_PLUGIN_DATA ID);
        }
        
    private:
    };
  }
}

#endif	/* PLUGINDATA_H */

