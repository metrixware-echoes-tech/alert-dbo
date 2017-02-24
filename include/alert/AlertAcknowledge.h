/**
 * @file AlertAcknowledge.h
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

#ifndef ALERTACKNOWLEDGE_H
#define ALERTACKNOWLEDGE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertAcknowledge : public Table 
    {
        public:
            AlertAcknowledge();
            virtual ~AlertAcknowledge();

            static std::string TRIGRAM;

            Wt::Dbo::ptr<Alert> alert;
            Wt::Dbo::ptr<User> user;

            Wt::WString ackState;
            Wt::WString isLast;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["STATE"] = &this->ackState;
                mapClassAttributesStrings["IS_LAST"] = &this->isLast;
                Table::fieldFiller(a, *this);
                Wt::Dbo::belongsTo(a, alert, "ACK_ALE");
                Wt::Dbo::belongsTo(a, user, "ACK_USR");
            }

        protected:
        private:
    };
  }
}

#endif // ALERTACKNOWLEDGE_H

