/**
 * @file Group.h
 * @author Thomas Saquet, Florent Poinsaut
 * @date 
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Alert - Dbo is the database objects library, part of the Alert software
 * Copyright (C) 2013-2017
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 * 
 */

#ifndef GROUP_H
#define GROUP_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Group : public Table
    {
        public:
            Group();
            virtual ~Group();

            static std::string TRIGRAM;

            // attributes
            Wt::WString address;
            Wt::WString cp;
            Wt::WString city;
            Wt::WString token;
            // methods

            // dbo collections (This table id as foreign key in other tables)
            Wt::Dbo::collection<Wt::Dbo::ptr<User>> users;
            Wt::Dbo::collection<Wt::Dbo::ptr<Asset>> assets;
            Wt::Dbo::collection<Wt::Dbo::ptr<UserRole>> userRoles;
            Wt::Dbo::collection<Wt::Dbo::ptr<Plugin>> plugins;
            Wt::Dbo::collection<Wt::Dbo::ptr<Option>> options;
            Wt::Dbo::collection<Wt::Dbo::ptr<Information>> informations;
            
            Wt::Dbo::ptr<Media> defaultMedia;
            Wt::Dbo::ptr<Pack> pack;
            Wt::Dbo::ptr<GroupType> groupType;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["ADR"] = &this->address;
                mapClassAttributesStrings["CP"] = &this->cp;
                mapClassAttributesStrings["CITY"] = &this->city;
                mapClassAttributesStrings["TOKEN"] = &this->token;

                Table::fieldFiller(a, *this);

                //User id as foreign key in other tables
                Wt::Dbo::hasMany(a, assets, Wt::Dbo::ManyToOne, TRIGRAM_ASSET SEP TRIGRAM_GROUP);
                Wt::Dbo::hasMany(a, userRoles, Wt::Dbo::ManyToOne, TRIGRAM_USER_ROLE SEP TRIGRAM_GROUP);
                Wt::Dbo::hasMany(a, plugins, Wt::Dbo::ManyToOne, TRIGRAM_PLUGIN SEP TRIGRAM_GROUP);
                Wt::Dbo::hasMany(a, users, Wt::Dbo::ManyToOne, TRIGRAM_USER SEP TRIGRAM_GROUP);
                Wt::Dbo::hasMany(a, informations, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION SEP TRIGRAM_GROUP);
                Wt::Dbo::hasMany(a, options, Wt::Dbo::ManyToOne, TRIGRAM_OPTION SEP TRIGRAM_GROUP);

                Wt::Dbo::belongsTo(a, pack, TRIGRAM_GROUP SEP TRIGRAM_PACK);
                Wt::Dbo::belongsTo(a, groupType, TRIGRAM_GROUP SEP TRIGRAM_GROUP_TYPE);
                Wt::Dbo::belongsTo(a, defaultMedia, TRIGRAM_GROUP SEP TRIGRAM_MEDIA);
            }
    };
  }
}

#endif // GROUP_H

