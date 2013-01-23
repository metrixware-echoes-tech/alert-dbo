/* 
 * File:   SessionPool.cpp
 * Author: tsa
 * 
 * Created on 8 janvier 2013, 18:05
 */

#include "tools/SessionPool.h"

SessionPool::SessionPool() 
{
}

SessionPool::~SessionPool() 
{
}

SessionPool* SessionPool::getInstance()
{
    mutex.lock();
    if (instance == 0)
    {
        instance = new SessionPool();
    }
    mutex.unlock();
    return instance;
    
}

Session* SessionPool::getSession()
{
    mutex.lock();
    if (sessions.empty())
    {
        mutex.unlock();
        return new Session(credentials);
    }
    else
    {
        Session* session = sessions.front();
        sessions.pop_front();
        mutex.unlock();
        return session;
    }
}

void SessionPool::returnSession(Session* session)
{
    mutex.lock();
    sessions.push_back(session);
    mutex.unlock();
}



