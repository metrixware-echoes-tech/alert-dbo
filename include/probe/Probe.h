/**
 * @file Probe.h
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

#ifndef PROBE_H
#define PROBE_H

#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {
    class Probe : public Table
    {
        public:
            Probe();
            virtual ~Probe();

            static std::string TRIGRAM;

            int             timer;
            Wt::WString     cert;
            Wt::WDateTime   lastlog;
            bool            sendAlertIfDown;
            int             snoozeBeforeNextWarning;
            Wt::WDateTime   lastDownAlert;

            Wt::Dbo::ptr<ProbePackageParameter> probePackageParameter;
            Wt::Dbo::ptr<Asset> asset;

            Wt::Dbo::collection<Wt::Dbo::ptr<Syslog> > syslogs;

            template<class Action>
            void persist(Action& a)
            {
                mapClassAttributesStrings["NAME"] = &this->name;
                mapClassAttributesStrings["CERT"] = &this->cert;
                mapClassAttributesInts["TIMER"] = &this->timer;
                mapClassAttributesDates["LASTLOG"] = &this->lastlog;
                mapClassAttributesBools["ALERT_IF_DOWN"] = &this->sendAlertIfDown;
                mapClassAttributesInts["SNOOZE_BEFORE_NEXT_WARNING"] = &this->snoozeBeforeNextWarning;
                mapClassAttributesDates["LAST_DOWN_ALERT"] = &this->lastDownAlert;
                Table::fieldFiller(a, *this);

                Wt::Dbo::belongsTo(a, probePackageParameter, TRIGRAM_PROBE SEP TRIGRAM_PROBE_PACKAGE_PARAMETER);
                Wt::Dbo::belongsTo(a, asset, TRIGRAM_PROBE SEP TRIGRAM_ASSET);

                Wt::Dbo::hasMany(a,
                        syslogs,
                        Wt::Dbo::ManyToOne,
                        TRIGRAM_SYSLOG SEP TRIGRAM_PROBE);
            }

        protected:
        private:
    };
  }
}

#endif // PROBE_H

