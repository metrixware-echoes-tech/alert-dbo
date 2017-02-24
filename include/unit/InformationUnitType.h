/**
 * @file InformationUnitType.h
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

#ifndef INFORMATIONUNITTYPE_H
#define INFORMATIONUNITTYPE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class InformationUnitType : public Table
    {
        public:
            InformationUnitType();
            virtual ~InformationUnitType();

            static std::string TRIGRAM;

            Wt::Dbo::collection<Wt::Dbo::ptr<InformationUnit> > units;

            Wt::Dbo::collection<Wt::Dbo::ptr<AlertCriteria> > alertCriterias;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                Table::fieldFiller(a, *this);

                Wt::Dbo::hasMany(a,
                        units,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_INFORMATION_UNIT SEP TRIGRAM_INFORMATION_UNIT_TYPE);

                //TJ
                Wt::Dbo::hasMany(a, alertCriterias, Wt::Dbo::ManyToMany, "TJ" SEP TRIGRAM_ALERT_CRITERIA SEP TRIGRAM_INFORMATION_UNIT_TYPE);
            }

        protected:
        private:
    };
  }
}

#endif // INFORMATIONUNITTYPE_H

