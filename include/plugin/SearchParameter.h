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
    
    Wt::Dbo::collection<Wt::Dbo::ptr<SearchType> > searchTypes;
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::hasMany(a,
                        searchTypes,
                        Wt::Dbo::ManyToMany,
                        "TJ_STY_SEP");
    }
private:

};

#endif	/* SEARCHPARAMETER_H */

