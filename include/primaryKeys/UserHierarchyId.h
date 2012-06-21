/* 
 * File:   HierarchyId.h
 * Author: tom
 *
 * Created on 1 mai 2012, 19:14
 */

#ifndef HIERARCHYID_H
#define	HIERARCHYID_H

#include <Wt/Dbo/Dbo>

class User;
class UserHierarchy;

struct UserHierarchyId
{
    Wt::Dbo::ptr<User> parent;
    Wt::Dbo::ptr<User> child;

    UserHierarchyId(Wt::Dbo::ptr<User> p, Wt::Dbo::ptr<User> c)
        : parent(p), child(c) { }

    UserHierarchyId(){ }

    bool operator== (const UserHierarchyId& other) const {
        return parent == other.parent && child == other.child;
    }

    bool operator< (const UserHierarchyId& other) const {
        if (parent < other.parent)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const UserHierarchyId& pk)
{
    return o << "(" << pk.parent << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, UserHierarchyId& hiid,
                   const std::string& name, int size = -1)
        {
            Wt::Dbo::belongsTo(a, hiid.parent, "UPA");
            Wt::Dbo::belongsTo(a, hiid.child, "UCH");
        }
        template<>
        struct dbo_traits<UserHierarchy> : public dbo_default_traits
        {
            typedef UserHierarchyId IdType;
            static IdType invalidId() { return UserHierarchyId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* HIERARCHYID_H */

