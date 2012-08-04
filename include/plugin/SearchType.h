/* 
 * File:   SearchType.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:26
 */

#ifndef SEARCHTYPE_H
#define	SEARCHTYPE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class SearchType : public Table {
public:
    SearchType();
    SearchType(const SearchType& orig);
    virtual ~SearchType();
    
    static std::string TRIGRAM;             
    Wt::WString name;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<Search> > searches;
    Wt::Dbo::collection<Wt::Dbo::ptr<SearchParameter> > searchParameters;

    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["NAME"]=&this->name;
        FIELD_FILLER();
        Wt::Dbo::hasMany(a,
                         searches,
                         Wt::Dbo::ManyToOne,
                         "SEA_STY");
        
        
        Wt::Dbo::hasMany(a,
                        searchParameters,
                        Wt::Dbo::ManyToMany,
                        "TJ_STY_SEP");
        
    }
    
private:

};

#endif	/* SEARCHTYPE_H */

