/* 
 * File:   SessionPool.h
 * Author: tsa
 *
 * Created on 8 janvier 2013, 18:05
 */

#ifndef SESSIONPOOL_H
#define	SESSIONPOOL_H

#include "tools/Session.h"
#include <boost/thread/thread.hpp>

class Session;

class SessionPool {
public:
    virtual ~SessionPool();
    static SessionPool* getInstance();
    Session* getSession();
    void returnSession(Session* session);
    static std::string credentials;

    
private:
    std::list<Session*> sessions;
        
    static SessionPool* instance;
    SessionPool();
    static boost::mutex mutex;
    
};

#endif	/* SESSIONPOOL_H */

