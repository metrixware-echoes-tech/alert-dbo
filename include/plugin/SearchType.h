/* 
 * File:   SearchType.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:26
 */

#ifndef SEARCHTYPE_H
#define	SEARCHTYPE_H

#include <Wt/Dbo/Dbo>

#include "MainIncludeFile.h"

class SearchType : public Table {
public:
    SearchType();
    SearchType(const SearchType& orig);
    virtual ~SearchType();
    
    Wt::WDateTime deleteTag;
    static std::string TRIGRAM;             
    std::string name;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<Search> > searches;
    Wt::Dbo::collection<Wt::Dbo::ptr<SearchParameter> > searchParameters;

    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::hasMany(a,
                         searches,
                         Wt::Dbo::ManyToOne,
                         "STY");
        
        
        Wt::Dbo::hasMany(a,
                        searchParameters,
                        Wt::Dbo::ManyToMany,
                        "TJ_STY_SEP");
        mapClassAttributesDates["DELETE"]=this->deleteTag;
        mapClassAttributesStrings["NAME"]=this->name;  
    }
    
private:

};

#endif	/* SEARCHTYPE_H */

