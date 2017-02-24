/**
 * @file UserHistoricalAction.h
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

#ifndef USERHISTORICALACTION_H
#define USERHISTORICALACTION_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class UserHistoricalAction : public Table
    {
        public:
            UserHistoricalAction();
            virtual ~UserHistoricalAction();

            static std::string TRIGRAM;

            // attributes
            Wt::WDateTime dateTime;

            int actionBefore;
            int actionAfter;
            int actionRelative;
            Wt::WString tableObject;
            long long tableObjectId;

            // methods


            // dbo pointers (Other tables ids as foreign keys for this table)
            Wt::Dbo::ptr<User> user;
            Wt::Dbo::ptr<UserActionType> userAction;

            // dbo collections (This table id as foreign key in other tables)
            //        Wt::Dbo::collection<Wt::Dbo::ptr<UserAction> > userActions;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesDates["DATETIME"] = &this->dateTime;
                mapClassAttributesInts["BEFORE"] = &this->actionBefore;
                mapClassAttributesInts["AFTER"] = &this->actionAfter;
                mapClassAttributesInts["RELATIVE"] = &this->actionRelative;
                mapClassAttributesStrings["TABLE_OBJECT"] = &this->tableObject;
                mapClassAttributesSerials["TAO_ID"] = &this->tableObjectId;
                Table::fieldFiller(a, *this);
                //Other tables ids as foreign keys for user table

                Wt::Dbo::belongsTo(a, user, TRIGRAM_USER_HISTORICAL_ACTION SEP TRIGRAM_USER);

                Wt::Dbo::belongsTo(a, userAction, TRIGRAM_USER_HISTORICAL_ACTION SEP TRIGRAM_USER_ACTION_TYPE);
            }
    };
  }
}

#endif // USERHISTORICALACTION_H

