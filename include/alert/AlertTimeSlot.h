/**
 * @file AlertTimeSlot.h
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

#ifndef ALERTTIMESLOTS_H
#define	ALERTTIMESLOTS_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
    namespace Dbo
    {
        class AlertTimeSlot : public Table
        {
            public:
                AlertTimeSlot();
                AlertTimeSlot(const AlertTimeSlot& orig);
                virtual ~AlertTimeSlot();
                
                static std::string TRIGRAM;

                int         start;
                int         duration;
                Wt::WString days;
                Wt::WString months;
                
                Wt::Dbo::ptr<AlertMediaSpecialization> mediaSpecialization;

                template<class Action>
                void persist(Action& a)
                {
                    mapClassAttributesInts["START"] = &this->start;
                    mapClassAttributesInts["DURATION"] = &this->duration;
                    mapClassAttributesStrings["DAYS"] = &this->days;
                    mapClassAttributesStrings["MONTHS"] = &this->months;
                    
                    Table::fieldFiller(a, *this);

                    Wt::Dbo::belongsTo(a, mediaSpecialization, TRIGRAM_ALERT_TIMESLOT SEP TRIGRAM_ALERT_MEDIA_SPECIALIZATION);
                }

            private:
        };
    }
}

#endif	/* ALERTTIMESLOTS_H */
