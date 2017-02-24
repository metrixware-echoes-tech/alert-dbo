/**
 * @file AlertMessageAliasInformation.h
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

#ifndef ALERTMESSAGEALIASINFORMATION_H
#define	ALERTMESSAGEALIASINFORMATION_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"
#include "primaryKeys/AlertMessageAliasInformationId.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertMessageAliasInformation : public Table
    {
        public:
            AlertMessageAliasInformation();
            AlertMessageAliasInformation(const AlertMessageAliasInformation& orig);
            virtual ~AlertMessageAliasInformation();

            static std::string TRIGRAM;

            Wt::WString alias;

            AlertMessageAliasInformationId pk;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["ALIAS"] = &this->alias;

                Table::fieldFiller(a, *this);

                Wt::Dbo::id(a, pk, TRIGRAM_ALERT_MESSAGE_ALIAS_INFORMATION ID);
            }

        private:
    };
  }
}

#endif	/* ALERTMESSAGEALIASINFORMATION_H */
