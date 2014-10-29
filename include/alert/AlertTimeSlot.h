/* 
 * File:   AlertTimeSlots.h
 * Author: vpl
 *
 * Created on 22 octobre 2014, 15:23
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

