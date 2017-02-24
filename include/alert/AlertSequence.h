/**
 * @file AlertSequence.h
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

#ifndef ALERTSEQUENCE_H
#define	ALERTSEQUENCE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class AlertSequence : public Table
    {
        public:
            AlertSequence();
            AlertSequence(const AlertSequence& orig);
            virtual ~AlertSequence();

            static std::string TRIGRAM;

            bool firstParenthesis;
            Wt::Dbo::ptr<AlertValue> alertValue;
            bool secondParenthesis;
            boost::optional<int> boolOperator;
            Wt::Dbo::weak_ptr<AlertSequence> alertSequenceBelongTo;
            Wt::Dbo::ptr<AlertSequence> alertSequence;

            Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesBools["FIRST_PARENTHESIS"] = &this->firstParenthesis;
                mapClassAttributesBools["SECOND_PARENTHESIS"] = &this->secondParenthesis;
                mapClassAttributesIntsNn["BOOL_OP"] = &this->boolOperator;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, alertSequence, TRIGRAM_ALERT_SEQUENCE SEP "NXT_ID");
                Wt::Dbo::hasOne(a, alertSequenceBelongTo, TRIGRAM_ALERT_SEQUENCE SEP "NXT_ID");

                Wt::Dbo::belongsTo(a, alertValue, TRIGRAM_ALERT_SEQUENCE SEP TRIGRAM_ALERT_VALUE);
                Wt::Dbo::hasMany(a, alerts, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_SEQUENCE SEP "FIRST_ID");
            }

        private:
    };
  }
}

#endif	/* ALERTSEQUENCE_H */
