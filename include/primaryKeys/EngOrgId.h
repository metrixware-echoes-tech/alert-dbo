/* 
 * File:   EngOrgId.h
 * Author: tsa
 *
 * Created on 21 avril 2013, 16:33
 */

#ifndef ENGORGID_H
#define	ENGORGID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    struct EngOrgId {
        Wt::Dbo::ptr<Engine> engine;
        Wt::Dbo::ptr<Organization> organization;

        EngOrgId(Wt::Dbo::ptr<Engine> ptrEng, Wt::Dbo::ptr<Organization> ptrOrg)
        : engine(ptrEng), organization(ptrOrg) {
        }

        EngOrgId() {
        }

        bool operator==(const EngOrgId& other) const {
            return engine == other.engine && organization == other.organization;
        }

        bool operator<(const EngOrgId& other) const {
            if ((engine < other.engine) || (organization < other.organization))
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const EngOrgId& pk) {
        //return o << "(" << pk.id << ")" << "(" << pk.source << ")";
        return o << "\n    {"
                << "\n        \"engine_id\": " << pk.engine.id()
                << ",\n        \"organization_id\": " << pk.organization.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::EngOrgId& srid,
            const std::string& name, int size = -1) {
        field(a, srid.engine, "ENG_ID");
        field(a, srid.organization, "ORG_ID");
    }

    template<>
    struct dbo_traits<Echoes::Dbo::EngOrg> : public dbo_default_traits {
        typedef Echoes::Dbo::EngOrgId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::EngOrgId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* ENGORGID_H */

