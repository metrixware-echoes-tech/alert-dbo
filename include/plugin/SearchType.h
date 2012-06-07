/* 
 * File:   SearchType.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:26
 */

#ifndef SEARCHTYPE_H
#define	SEARCHTYPE_H

#include "Table.h"

#include <Wt/Dbo/Dbo>

#include "Search.h"

class SearchType {
public:
    SearchType();
    SearchType(const SearchType& orig);
    virtual ~SearchType();
    
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
    }
    
private:

};

#endif	/* SEARCHTYPE_H */

