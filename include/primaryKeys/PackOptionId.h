/* 
 * File:   PackOptionId.h
 * Author: rhi
 *
 * Created on 10 septembre 2012, 21:50
 */

#ifndef PACKOPTIONID_H
#define	PACKOPTIONID_H

#include <Wt/Dbo/Dbo>

class Pack;
class PackOption;
class Option;


struct PackOptionId
{
    Wt::Dbo::ptr<Pack> pack;
    Wt::Dbo::ptr<Option> option;

    PackOptionId(Wt::Dbo::ptr<Pack> pack, Wt::Dbo::ptr<Option> option)
        : pack(pack), option(option) { }

    PackOptionId(){ }

    bool operator== (const PackOptionId& other) const {
        return pack == other.pack && option == other.option;
    }

    bool operator< (const PackOptionId& other) const {
        if (pack < other.pack)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const PackOptionId& pk)
{
    return o << "(" << pk.pack << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, PackOptionId& spvid,
                   const std::string& name, int size = -1)
        {
            field(a, spvid.pack, "PCK_ID");
            field(a, spvid.option, "OPT_ID");
        }
        template<>
        struct dbo_traits<PackOption> : public dbo_default_traits
        {
            typedef PackOptionId IdType;
            static IdType invalidId() { return PackOptionId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}
#endif	/* PACKOPTIONID_H */

