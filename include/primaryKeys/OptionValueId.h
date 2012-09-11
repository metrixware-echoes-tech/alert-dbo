/* 
 * File:   OptionValueId.h
 * Author: rhi
 *
 * Created on 10 septembre 2012, 22:00
 */

#ifndef OPTIONVALUEID_H
#define	OPTIONVALUEID_H

#include <Wt/Dbo/Dbo>

class Organization;
class OptionValue;
class Option;


struct OptionValueId
{
    Wt::Dbo::ptr<Organization> organization;
    Wt::Dbo::ptr<Option> option;

    OptionValueId(Wt::Dbo::ptr<Organization> organization, Wt::Dbo::ptr<Option> option)
        : organization(organization), option(option) { }

    OptionValueId(){ }

    bool operator== (const OptionValueId& other) const {
        return organization == other.organization && option == other.option;
    }

    bool operator< (const OptionValueId& other) const {
        if (organization < other.organization)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const OptionValueId& pk)
{
    return o << "(" << pk.organization << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, OptionValueId& spvid,
                   const std::string& name, int size = -1)
        {
            field(a, spvid.option, "OPT_ID");
            field(a, spvid.organization, "ORG_ID");
        }
        template<>
        struct dbo_traits<OptionValue> : public dbo_default_traits
        {
            typedef OptionValueId IdType;
            static IdType invalidId() { return OptionValueId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* OPTIONVALUE_H */

