/**
 * @file Information.h
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

#ifndef INFORMATION_H
#define INFORMATION_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Information : public Table
    {
        public:
            Information();
            Information(const Information& orig);
            virtual ~Information();

            static std::string TRIGRAM;

            //        InformationId pk;

            Wt::Dbo::collection<Wt::Dbo::ptr<InformationData> > informationDatas;
            
            Wt::Dbo::ptr<InformationUnit> informationUnit;
            Wt::Dbo::ptr<Organization> organization;

            boost::optional<Wt::WString> desc;
            bool display;
            boost::optional<Wt::WString> calculate;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesBools["DISPLAY"] = &this->display;
                mapClassAttributesStringsNn["DESC"] = &this->desc;
                mapClassAttributesStringsNn["CALCULATE"] = &this->calculate;
                Table::fieldFiller(a, *this);
                //            Wt::Dbo::id(a,pk,"PRIMARY_KEY");
                
                Wt::Dbo::hasMany(a, informationDatas, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_INFORMATION);

                Wt::Dbo::belongsTo(a, informationUnit, TRIGRAM_INFORMATION SEP TRIGRAM_INFORMATION_UNIT);
                Wt::Dbo::belongsTo(a, organization, TRIGRAM_INFORMATION SEP TRIGRAM_ORGANIZATION);
            }

        protected:
        private:
    };
  }
}

#endif // INFORMATION_H

