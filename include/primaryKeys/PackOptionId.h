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
    class Option;

    struct PackOptionId {
        Wt::Dbo::ptr<Pack> pack;
        Wt::Dbo::ptr<Option> option;

        PackOptionId(Wt::Dbo::ptr<Pack> pack, Wt::Dbo::ptr<Option> option)
        : pack(pack), option(option) {
        }

        PackOptionId() {
        }

        bool operator==(const PackOptionId& other) const {
            return pack == other.pack && option == other.option;
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
                << "\"option_id\": " << pk.option.id();
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
        field(a, spvid.option, TRIGRAM_PACK_OPTION SEP TRIGRAM_OPTION);
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

