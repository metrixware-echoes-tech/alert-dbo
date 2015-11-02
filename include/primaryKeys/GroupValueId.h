/* 
 * File:   GroupValueId.h
 * Author: rhi
 *
 * Created on 9 juillet 2012, 14:02
 */

#ifndef GROUPVALUEID_H
#define	GROUPVALUEID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    class Group;
    class GroupValue;

    struct GroupValueId {
        Wt::Dbo::ptr<GroupField> groupField;
        Wt::Dbo::ptr<Group> group;

        GroupValueId(Wt::Dbo::ptr<GroupField> groupField, Wt::Dbo::ptr<Group> group)
        : groupField(groupField), group(group) {
        }

        GroupValueId() {
        }

        bool operator==(const GroupValueId& other) const {
            return groupField == other.groupField && group == other.group;
        }

        bool operator<(const GroupValueId& other) const {
            if (groupField < other.groupField)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const GroupValueId& pk) {
        //return o << "(" << pk.group << ")";
        return o << "\n    {"
                << "\n        \"group_id\": " << pk.group.id()
                << ",\n        \"group_field_id\": " << pk.groupField.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::GroupValueId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.groupField, "GFI_ID");
        field(a, spvid.group, "GRP_ID");
    }

    template<>
    struct dbo_traits<Echoes::Dbo::GroupValue> : public dbo_default_traits {
        typedef Echoes::Dbo::GroupValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::GroupValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* GROUPVALUEID_H */
