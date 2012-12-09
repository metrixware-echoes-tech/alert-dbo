/* 
 * File:   SourceId.h
 * Author: tom
 *
 * Created on 23 avril 2012, 17:35
 */


#ifndef SOURCEID_H
#define	SOURCEID_H

#include <Wt/Dbo/Dbo>

class Plugin;
class Source;


struct SourceId
{
    long long id;
    Wt::Dbo::ptr<Plugin> plugin;

    SourceId(long long id, Wt::Dbo::ptr<Plugin> ptr)
        : id(id), plugin(ptr) { }

    SourceId(){ }

    bool operator== (const SourceId& other) const {
        return id == other.id && plugin == other.plugin;
    }

    bool operator< (const SourceId& other) const {
        if ((id < other.id) || (plugin < other.plugin))
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const SourceId& pk)
{
    return o << "(" << pk.id << ")" << "(" << pk.plugin << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, SourceId& soid,
                   const std::string& name, int size = -1)
        {
            field(a, soid.id, "SRC_ID");
            field(a, soid.plugin, "PLG_ID");
//            Wt::Dbo::belongsTo(a, soid.plugin, "SRC_PLG");
        }
        template<>
        struct dbo_traits<Source> : public dbo_default_traits
        {
            typedef SourceId IdType;
            static IdType invalidId() { return SourceId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}
#endif	/* SOURCEID_H */