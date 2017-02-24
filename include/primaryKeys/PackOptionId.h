/**
 * @file PackOptionId.h
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

#ifndef PACKOPTIONID_H
#define	PACKOPTIONID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    class Pack;
    class PackOption;
    class OptionType;

    struct PackOptionId {
        Wt::Dbo::ptr<Pack> pack;
        Wt::Dbo::ptr<OptionType> optionType;

        PackOptionId(Wt::Dbo::ptr<Pack> pack, Wt::Dbo::ptr<OptionType> optionType)
        : pack(pack), optionType(optionType) {
        }

        PackOptionId() {
        }

        bool operator==(const PackOptionId& other) const {
            return pack == other.pack && optionType == other.optionType;
        }

        bool operator<(const PackOptionId& other) const {
            if (pack < other.pack)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const PackOptionId& pk) {
        //return o << "(" << pk.pack << ")";
        return o << "\n    {"
                << "\n        \"pack_id\": " << pk.pack.id()
                << ",\n        \"option_type_id\": " << pk.optionType.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::PackOptionId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.pack, TRIGRAM_PACK_OPTION SEP TRIGRAM_PACK);
        field(a, spvid.optionType, TRIGRAM_PACK_OPTION SEP TRIGRAM_OPTION_TYPE);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::PackOption> : public dbo_default_traits {
        typedef Echoes::Dbo::PackOptionId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::PackOptionId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}
#endif	/* PACKOPTIONID_H */
