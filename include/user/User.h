/**
 * @file User.h
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

#ifndef USER_H
#define USER_H

#include <Wt/Auth/AbstractUserDatabase>
#include <Wt/Auth/Dbo/AuthInfo>

#include "tools/MainIncludeFile.h"

typedef Wt::Auth::Dbo::AuthInfo<Echoes::Dbo::User> AuthInfo;
typedef Wt::Dbo::collection< Wt::Dbo::ptr<Echoes::Dbo::User> > Users;

namespace Echoes
{
  namespace Dbo
  {
    class User : public Table
    {
        public:
            User();
            User(std::string firstName, std::string lastName, std::string eMail, std::string password, std::string token);
            virtual ~User();

            static std::string TRIGRAM;

            Wt::WString firstName;
            Wt::WString lastName;
            Wt::WString eMail;
            Wt::WString password;
            Wt::WString token;

            static std::string getName();

            Wt::Dbo::ptr<UserRole> userRole;
            Wt::Dbo::ptr<UserProfile> userProfile;

            Wt::Dbo::ptr<Group> group;

            Wt::Dbo::collection<Wt::Dbo::ptr<UserValue> > userValues;
            Wt::Dbo::collection<Wt::Dbo::ptr<UserHistoricalAction> > historicalActions;
            Wt::Dbo::collection<Wt::Dbo::ptr<AlertAcknowledge> > alertAcks;
            Wt::Dbo::collection<Wt::Dbo::ptr<Media> > medias;
            Wt::Dbo::collection<Wt::Dbo::ptr<Message> > message;
            
            Wt::Dbo::collection<Wt::Dbo::ptr<UserField> > userFields;

            //link to auth_info table
            Wt::Dbo::collection< Wt::Dbo::ptr<AuthInfo> > authInfos;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["FIRST_NAME"] = &this->firstName;
                mapClassAttributesStrings["LAST_NAME"] = &this->lastName;
                mapClassAttributesStrings["MAIL"] = &this->eMail;
                mapClassAttributesStrings["PWD"] = &this->password;
                mapClassAttributesStrings["TOKEN"] = &this->token;

                Table::fieldFiller(a, *this);

                //Other tables ids as foreign keys for user table

                Wt::Dbo::belongsTo(a, userRole, TRIGRAM_USER SEP TRIGRAM_USER_ROLE);
                Wt::Dbo::belongsTo(a, group, TRIGRAM_USER SEP TRIGRAM_GROUP);
                Wt::Dbo::belongsTo(a, userProfile, TRIGRAM_USER SEP TRIGRAM_USER_PROFILE);

                //User id as foreign key in other tables
                Wt::Dbo::hasMany(a, userValues, Wt::Dbo::ManyToOne, TRIGRAM_USER_VALUE SEP TRIGRAM_USER);
                Wt::Dbo::hasMany(a, historicalActions, Wt::Dbo::ManyToOne, TRIGRAM_USER_HISTORICAL_ACTION SEP TRIGRAM_USER);
                Wt::Dbo::hasMany(a, alertAcks, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_ACKNOWLEDGE SEP TRIGRAM_USER);
                Wt::Dbo::hasMany(a, medias, Wt::Dbo::ManyToOne, TRIGRAM_MEDIA SEP TRIGRAM_USER);
                Wt::Dbo::hasMany(a, message, Wt::Dbo::ManyToOne, TRIGRAM_MESSAGE SEP TRIGRAM_USER);
                
                // join tables
                Wt::Dbo::hasMany(a, userFields, Wt::Dbo::ManyToMany, TABLE_JOINT_PREFIX SEP TRIGRAM_USER SEP TRIGRAM_USER_FIELD);
                //"user" hard coded in auth Info
                Wt::Dbo::hasMany(a, authInfos, Wt::Dbo::ManyToOne, "user");
            }

    };

    // Auth
    //typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;
  }
}

//DBO_EXTERN_TEMPLATES(Echoes::Dbo::User)
#endif // USER_H
