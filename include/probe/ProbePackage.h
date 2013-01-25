/* 
 * File:   ProbePackage.h
 * Author: tsa
 *
 * Created on 25 janvier 2013, 16:25
 */

#ifndef PROBEPACKAGE_H
#define	PROBEPACKAGE_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

class ProbePackage : public Table {
public:
    ProbePackage();
    ProbePackage(const ProbePackage& orig);
    virtual ~ProbePackage();
    
    static std::string TRIGRAM;
    
    Wt::WString filename;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<ProbePackageParameter>> probePackageParameters;
    
    template<class Action>
    void persist(Action& a)
    { 
        mapClassAttributesStrings["FILENAME"]=&this->filename;

        FIELD_FILLER();

        Wt::Dbo::hasMany(a, probePackageParameters, Wt::Dbo::ManyToOne, TRIGRAM_PROBE_PACKAGE_PARAMETER SEP TRIGRAM_PROBE_PACKAGE);
   }
private:

};

#endif	/* PROBEPACKAGE_H */

