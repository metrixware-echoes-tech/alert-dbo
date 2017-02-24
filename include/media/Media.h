/**
 * @file Media.h
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

#ifndef MEDIA_H
#define	MEDIA_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Media : public Table
    {
        public:
            Media();
            virtual ~Media();

            static std::string TRIGRAM;

            Wt::WString value;
            bool isDefault;
            Wt::WString token;
            bool isConfirmed;

            Wt::Dbo::ptr<MediaType> mediaType;
            Wt::Dbo::ptr<User> user;

            Wt::Dbo::collection<Wt::Dbo::ptr<AlertTracking> > alertTrackings;
            Wt::Dbo::collection<Wt::Dbo::ptr<AlertMediaSpecialization> > alertMediaSpecializations;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["VALUE"] = &this->value;
                mapClassAttributesBools["IS_DEFAULT"] = &this->isDefault;
                mapClassAttributesStrings["TOKEN"] = &this->token;
                mapClassAttributesBools["IS_CONFIRMED"] = &this->isConfirmed;
                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, mediaType, TRIGRAM_MEDIA SEP TRIGRAM_MEDIA_TYPE);
                Wt::Dbo::belongsTo(a, user, TRIGRAM_MEDIA SEP TRIGRAM_USER);

                Wt::Dbo::hasMany(a, alertTrackings, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_TRACKING SEP TRIGRAM_MEDIA);
                Wt::Dbo::hasMany(a, alertMediaSpecializations, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_MEDIA_SPECIALIZATION SEP TRIGRAM_MEDIA);
            }

        protected:
        private:
    };
  }
}

#endif	/* MEDIA_H */
