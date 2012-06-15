/* 
 * File:   SourceParameter.h
 * Author: tsa
 *
 * Created on 4 juin 2012, 17:41
 */

#ifndef SOURCEPARAMETER_H
#define	SOURCEPARAMETER_H

#include "MainIncludeFile.h"

#include <Wt/Dbo/Dbo>

class SourceParameterValue;

class SourceParameter : public Table {
public:
    SourceParameter();
    SourceParameter(const SourceParameter& orig);
    virtual ~SourceParameter();
    
    static std::string TRIGRAM;
    
    Wt::WDateTime deleteTag;          
    std::string name;
    std::string format;    
    
    Wt::Dbo::collection<Wt::Dbo::ptr<SourceParameterValue> > sourceParameterValues;
    Wt::Dbo::collection<Wt::Dbo::ptr<Addon> > Addons;
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::hasMany(a,
                        sourceParameterValues,
                        Wt::Dbo::ManyToOne,
                        "SRP");
        
        //TJ
        Wt::Dbo::hasMany(a,
                        Addons,
                        Wt::Dbo::ManyToMany,
                        "TJ_ADO_SRP");
        mapClassAttributesDates["DELETE"]=this->deleteTag;
        mapClassAttributesStrings["NAME"]=this->name;    
        mapClassAttributesStrings["FORMAT"]=this->format;         
    }
private:

};

#endif	/* SOURCEPARAMETER_H */

