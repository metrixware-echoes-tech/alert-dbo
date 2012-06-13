/* 
 * File:   SearchParameter.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:26
 */

#ifndef SEARCHPARAMETER_H
#define	SEARCHPARAMETER_H

#include "Table.h"
#include "SearchType.h"

#include <Wt/Dbo/Dbo>

class SearchParameter : public Table {
public:
    SearchParameter();
    SearchParameter(const SearchParameter& orig);
    virtual ~SearchParameter();
    
    Wt::WDateTime deleteTag;
    static std::string TRIGRAM;             
    std::string name;
    std::string format;    
    
    Wt::Dbo::collection<Wt::Dbo::ptr<SearchType> > searchTypes;
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::hasMany(a,
                        searchTypes,
                        Wt::Dbo::ManyToMany,
                        "TJ_STY_SEP");
        mapClassAttributesDates["DELETE"]=this->deleteTag;
        mapClassAttributesStrings["NAME"]=this->name;            
        mapClassAttributesStrings["FORMAT"]=this->format;           
    }
private:

};

#endif	/* SEARCHPARAMETER_H */

