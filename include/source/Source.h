/* 
 * Header of Source Table
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

#ifndef SOURCE_H
#define	SOURCE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Source : public Table
    {
        public:
            Source();
            Source(const Source& orig);
            virtual ~Source();

            static std::string TRIGRAM;
            Wt::WDateTime deleteTag;

            Wt::Dbo::ptr<Addon> addon;
            
            Wt::Dbo::collection<Wt::Dbo::ptr<Search>> searches;

            Wt::Dbo::collection<Wt::Dbo::ptr<Plugin>> plugins;

            template<class Action>
            void persist(Action& a)
            {
                FIELD_FILLER();

                Wt::Dbo::belongsTo(a, addon, TRIGRAM_SOURCE SEP TRIGRAM_ADDON);
                
                Wt::Dbo::hasMany(a, searches, Wt::Dbo::ManyToOne, TRIGRAM_SEARCH SEP TRIGRAM_SOURCE);
                
                Wt::Dbo::hasMany(a, plugins, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_PLUGIN SEP TRIGRAM_SOURCE);
            }

            virtual std::string toJSON() const;

        private:
    };
  }
}

#endif	/* SOURCE_H */

