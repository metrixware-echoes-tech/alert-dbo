/* 
 * File:   Search.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:23
 */

#ifndef SEARCH_H
#define	SEARCH_H

#include "Table.h"

#include "Wt/Dbo/Dbo"

#include "SearchId.h"
#include "Plugin.h"
#include "SearchType.h"
#include "SearchParameter.h"

class Search {
public:
    Search();
    Search(const Search& orig);
    virtual ~Search();
    
    static std::string TRIGRAM;

    SearchId pk;
    Wt::Dbo::ptr<SearchType> searchType;
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::id (a, pk, "PRIMARY_KEY");
        
        Wt::Dbo::belongsTo(a, searchType, "STY");
    }
    
private:

};

#endif	/* SEARCH_H */

