/* 
 * File:   OptionValueId.h
 * Author: rhi
 *
 * Created on 10 septembre 2012, 22:00
 */

#ifndef OPTIONVALUEID_H
#define	OPTIONVALUEID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    class Organization;
    class OptionValue;
    class Option;

    struct OptionValueId {
        Wt::Dbo::ptr<Organization> organization;
        Wt::Dbo::ptr<Option> option;

        OptionValueId(Wt::Dbo::ptr<Organization> organization, Wt::Dbo::ptr<Option> option)
        : organization(organization), option(option) {
        }

        OptionValueId() {
        }

        bool operator==(const OptionValueId& other) const {
            return organization == other.organization && option == other.option;
        }

        bool operator<(const OptionValueId& other) const {
            if (organization < other.organization)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const OptionValueId& pk) {
        //return o << "(" << pk.organization << ")";
        return o << "\"option_id\": " << pk.option.id() << ",\n\t\t"
                << "\"organization_id\": " << pk.organization.id();
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::OptionValueId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.option, TRIGRAM_OPTION SEP ID);
        field(a, spvid.organization, TRIGRAM_ORGANIZATION SEP ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::OptionValue> : public dbo_default_traits {
        typedef Echoes::Dbo::OptionValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::OptionValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* OPTIONVALUE_H */

