/* 
 * File:   SourceParameter.h
 * Author: tsa
 *
 * Created on 4 juin 2012, 17:41
 */

#ifndef SOURCEPARAMETER_H
#define	SOURCEPARAMETER_H

#include "Table.h"
#include "SourceParameterValue.h"

#include <Wt/Dbo/Dbo>

class SourceParameterValue;

class SourceParameter : public Table {
public:
    SourceParameter();
    SourceParameter(const SourceParameter& orig);
    virtual ~SourceParameter();
    
    static std::string TRIGRAM;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<SourceParameterValue> > sourceParameterValues;
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::hasMany(a,
                        sourceParameterValues,
                        Wt::Dbo::ManyToOne,
                        "SRP");
    }
private:

};

#endif	/* SOURCEPARAMETER_H */

