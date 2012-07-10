/* 
 * File:   AccessControlListId.h
 * Author: rhi
 *
 * Created on 10 juillet 2012, 09:27
 */

#ifndef ACCESSCONTROLLISTID_H
#define	ACCESSCONTROLLISTID_H

#include <Wt/Dbo/Dbo>

class Space;
class UserRight;
class UserProfile;

struct AccessControlListId
{
    Wt::Dbo::ptr<Space> space;
    Wt::Dbo::ptr<UserProfile> userProfile;
    Wt::Dbo::ptr<UserRight> userRight;

    AccessControlListId(Wt::Dbo::ptr<Space> space, Wt::Dbo::ptr<UserProfile> userProfile, Wt::Dbo::ptr<UserRight> userRight)
        : space(space), userProfile(userProfile), userRight(userRight) { }

    AccessControlListId(){ }

    bool operator== (const AccessControlListId& other) const {
        return space == other.space && userProfile == other.userProfile && userRight == other.userRight;
    }

    bool operator< (const AccessControlListId& other) const {
        if (space < other.space)
            return true;
        else
            return false;
    }
};


inline std::ostream& operator<< (std::ostream& o, const AccessControlListId& pk)
{
    return o << "(" << pk.space << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, AccessControlListId& spvid,
                   const std::string& name, int size = -1)
        {
            field(a, spvid.space, "SPA_ID");
            field(a, spvid.userProfile, "UPR_ID");
            field(a, spvid.userRight, "URI_ID");
        }
        template<>
        struct dbo_traits<AccessControlList> : public dbo_default_traits
        {
            typedef AccessControlListId IdType;
            static IdType invalidId() { return AccessControlListId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}


#endif	/* ACCESSCONTROLLISTID_H */