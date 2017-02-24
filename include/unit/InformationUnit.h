/**
 * @file InformationUnit.h
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

#ifndef INFORMATIONUNIT_H
#define INFORMATIONUNIT_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class InformationUnit : public Table
    {
        public:
            InformationUnit();
            virtual ~InformationUnit();

            static std::string TRIGRAM;

            Wt::WString baseOperation;
            
            Wt::Dbo::ptr<InformationUnitType> unitType;
            
            Wt::Dbo::weak_ptr<Information> information;
            
            Wt::Dbo::weak_ptr<InformationUnit> informationUnit;
            Wt::Dbo::ptr<InformationUnit> informationUnitBelongTo;
            
            Wt::Dbo::collection<Wt::Dbo::ptr<InformationData>> informationDatas;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["BASE_OPERATION"] = &this->baseOperation;

                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, unitType, TRIGRAM_INFORMATION_UNIT SEP TRIGRAM_INFORMATION_UNIT_TYPE);

                Wt::Dbo::hasOne(a, information, TRIGRAM_INFORMATION SEP TRIGRAM_INFORMATION_UNIT);
                
                Wt::Dbo::hasMany(a, informationDatas, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_INFORMATION_UNIT);

                Wt::Dbo::belongsTo(a, informationUnitBelongTo, TRIGRAM_INFORMATION_UNIT SEP "BASE_ID");
                Wt::Dbo::hasOne(a, informationUnit, TRIGRAM_INFORMATION_UNIT SEP "BASE_ID");
            
            }

        protected:
        private:
    };
  }
}

#endif // INFORMATIONUNIT_H

