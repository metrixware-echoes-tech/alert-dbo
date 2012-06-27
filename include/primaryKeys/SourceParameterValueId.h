/* 
 * File:   SourceParameterValueId.h
 * Author: tsa
 *
 * Created on 4 juin 2012, 18:30
 */

#ifndef SOURCEPARAMETERVALUEID_H
#define	SOURCEPARAMETERVALUEID_H

#include <Wt/Dbo/Dbo>
#include "SourceId.h"

class SourceParameter;
class SourceParameterValue;

struct SourceParameterValueId
{
    Wt::Dbo::ptr<SourceParameter> sourceParameter;
    SourceId sourceId;

    SourceParameterValueId(Wt::Dbo::ptr<SourceParameter> sourceParameter, SourceId sourceId)
        : sourceParameter(sourceParameter), sourceId(sourceId) { }

    SourceParameterValueId(){ }

    bool operator== (const SourceParameterValueId& other) const {
        return sourceParameter == other.sourceParameter && sourceId == other.sourceId;
    }

    bool operator< (const SourceParameterValueId& other) const {
        if (sourceParameter < other.sourceParameter)
            return true;
        else
            return false;
    }
};

inline std::ostream& operator<< (std::ostream& o, const SourceParameterValueId& pk)
{
    return o << "(" << pk.sourceParameter << ")";
}

namespace Wt
{
    namespace Dbo
    {
        template <class Action>
        void field(Action& a, SourceParameterValueId& spvid,
                   const std::string& name, int size = -1)
        {
            Wt::Dbo::belongsTo(a, spvid.sourceParameter, "SPV_SRP");
            field(a, spvid.sourceId.id, "SRC_ID");
            field(a, spvid.sourceId.plugin, "PLG_ID");
        }
        template<>
        struct dbo_traits<SourceParameterValue> : public dbo_default_traits
        {
            typedef SourceParameterValueId IdType;
            static IdType invalidId() { return SourceParameterValueId(); }
            static const char *surrogateIdField() { return 0; }
        };
    }
}

#endif	/* SOURCEPARAMETERVALUEID_H */

