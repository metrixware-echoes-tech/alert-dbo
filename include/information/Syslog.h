/* 
 * File:   Syslog.h
 * Author: tsa
 *
 * Created on 5 juin 2012, 17:44
 */

#include "Table.h"

#include <Wt/Dbo/Dbo>

#include "Probe.h"

#ifndef SYSLOG_H
#define	SYSLOG_H

class Syslog : public Table
{
public:
    Syslog();
    Syslog(const Syslog& orig);
    virtual ~Syslog();
    
    Wt::Dbo::ptr<Probe> probe;
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::belongsTo(a, probe, "PRB");
    }
private:

};

#endif	/* SYSLOG_H */

