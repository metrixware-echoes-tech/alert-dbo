/* 
 * File:   SourceParameterValueId.h
 * Author: tsa
 *
 * Created on 4 juin 2012, 18:30
 */

#ifndef SOURCEPARAMETERVALUEID_H
#define	SOURCEPARAMETERVALUEID_H

#include <Wt/Dbo/Dbo>
#include "primaryKeys/SourceId.h"

namespace Echoes
{
  namespace Dbo
  {

    class SourceParameter;
    class SourceParameterValue;
    class Source;

    struct SourceParameterValueId {
        Wt::Dbo::ptr<SourceParameter> sourceParameter;
        Wt::Dbo::ptr<Source> source;

        SourceParameterValueId(Wt::Dbo::ptr<SourceParameter> sourceParameter, Wt::Dbo::ptr<Source> source)
        : sourceParameter(sourceParameter), source(source) {
        }

        SourceParameterValueId() {
        }

        bool operator==(const SourceParameterValueId& other) const {
            return sourceParameter == other.sourceParameter && source == other.source;
        }

        bool operator<(const SourceParameterValueId& other) const {
            if (sourceParameter < other.sourceParameter)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const SourceParameterValueId& pk) {
        //return o << "(" << pk.sourceParameter << ")";
        return o << pk.source.id()
                << ",\n\t\t\"source_parameter_id\": " << pk.sourceParameter.id();
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::SourceParameterValueId& spvid,
            const std::string& name, int size = -1) {
        field(a, spvid.sourceParameter, "SRP_ID");
        field(a, spvid.source, "SRC_ID");
    }

    template<>
    struct dbo_traits<Echoes::Dbo::SourceParameterValue> : public dbo_default_traits {
        typedef Echoes::Dbo::SourceParameterValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::SourceParameterValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* SOURCEPARAMETERVALUEID_H */

