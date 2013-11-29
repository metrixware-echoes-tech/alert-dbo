/* 
 * File:   PackOptionId.h
 * Author: rhi
 *
 * Created on 10 septembre 2012, 21:50
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
        return o << "\"pack_id\": " << pk.pack.id() << ",\n\t\t"
                << "\"option_id\": " << pk.optionType.id();
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

