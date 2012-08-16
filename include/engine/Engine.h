/* 
 * File:   Engine.h
 * Author: tsa
 *
 * Created on 16 août 2012, 14:27
 */

#ifndef ENGINE_H
#define	ENGINE_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

class Engine : public Table
{
public:
    Engine();
    Engine(const Engine& orig);
    virtual ~Engine();
    static std::string TRIGRAM;
    Wt::WString fqdn;
    Wt::WString state;
    Wt::WDateTime keepAlive;
    int nbThread;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["FQDN"]=&this->fqdn;
        mapClassAttributesStrings["STATE"]=&this->state;
        mapClassAttributesDates["KEEP_ALIVE"]=&this->keepAlive;
        mapClassAttributesInts["NB_THREAD"]=&this->nbThread;
        FIELD_FILLER();
        
        Wt::Dbo::hasMany(a, alerts, Wt::Dbo::ManyToOne, TRIGRAM_ALERT SEP TRIGRAM_ENGINE);
        
    }
private:

};

#endif	/* ENGINE_H */

