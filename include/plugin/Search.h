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

class Search : public Table {
public:
    Search();
    Search(const Search& orig);
    virtual ~Search();
    
    static std::string TRIGRAM;
    Wt::WDateTime deleteTag; 
    int nbValue;
    std::string period;
    bool searchIsStatic;
    
    SearchId pk;
    Wt::Dbo::ptr<SearchType> searchType;
    
    //RHI : manque 2 poiinteurs, vers SOURCE et SEARCH_PARAMETER_VALUE
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::id (a, pk, "PRIMARY_KEY");
        
        Wt::Dbo::belongsTo(a, searchType, "STY");
        mapClassAttributesDates["DELETE"]=this->deleteTag;
       // mapClassAttributesInt["NB_VALUE"]=this->nbValue;        
        mapClassAttributesStrings["PERIOD"]=this->period;        
      //  mapClassAttributesBools["IS_STATIC"]=this->searchIsStatic;              
    }
    
private:

};

#endif	/* SEARCH_H */

