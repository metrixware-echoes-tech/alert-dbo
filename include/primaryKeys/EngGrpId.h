/* 
 * File:   EngGrpId.h
 * Author: tsa
 *
 * Created on 21 avril 2013, 16:33
 */

#ifndef ENGGRPID_H
#define	ENGGRPID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    struct EngGrpId {
        Wt::Dbo::ptr<Engine> engine;
        Wt::Dbo::ptr<Group> group;

        EngGrpId(Wt::Dbo::ptr<Engine> ptrEng, Wt::Dbo::ptr<Group> ptrGrp)
        : engine(ptrEng), group(ptrGrp) {
        }

        EngGrpId() {
        }

        bool operator==(const EngGrpId& other) const {
            return engine == other.engine && group == other.group;
        }

        bool operator<(const EngGrpId& other) const {
            if ((engine < other.engine) || (group < other.group))
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const EngGrpId& pk) {
        //return o << "(" << pk.id << ")" << "(" << pk.source << ")";
        return o << "\n    {"
                << "\n        \"engine_id\": " << pk.engine.id()
                << ",\n        \"group_id\": " << pk.group.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::EngGrpId& srid,
            const std::string& name, int size = -1) {
        field(a, srid.engine, "ENG_ID");
        field(a, srid.group, "ORG_ID");
    }

    template<>
    struct dbo_traits<Echoes::Dbo::EngGrp> : public dbo_default_traits {
        typedef Echoes::Dbo::EngGrpId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::EngGrpId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* ENGGRPID_H */

