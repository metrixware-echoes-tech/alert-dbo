/* 
 * File:   Search.h
 * Author: tsa
 *
 * Created on 7 juin 2012, 15:23
 */

#ifndef SEARCH_H
#define	SEARCH_H

#include "Wt/Dbo/Dbo"

#include "tools/MainIncludeFile.h"

#include "primaryKeys/SearchId.h"

class Search : public Table {
public:
    Search();
    Search(const Search& orig);
    virtual ~Search();
    
    static std::string TRIGRAM;
    int nbValue;
    Wt::WString period;
    bool searchIsStatic;
    
    SearchId pk;
    Wt::Dbo::ptr<SearchType> searchType;
    
    Wt::WString lot_key_value;        

    
    //RHI : manque 2 poiinteurs, vers SOURCE et SEARCH_PARAMETER_VALUE
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesInts["NB_VALUE"]=&this->nbValue;        
        mapClassAttributesStrings["PERIOD"]=&this->period;        
        mapClassAttributesBools["IS_STATIC"]=&this->searchIsStatic;
        mapClassAttributesStrings["LOT_KEY_VALUE"]=&this->lot_key_value;
        
        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, "SEA_ID");
        
        Wt::Dbo::belongsTo(a, searchType, "SEA_STY");
    }
    
private:

};

#endif	/* SEARCH_H */

