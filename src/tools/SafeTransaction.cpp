/* 
 * File:   SafeTransaction.cpp
 * Author: tsa
 * 
 * Created on 19 décembre 2013, 18:02
 */

#include "tools/SafeTransaction.h"

namespace Echoes
{
    namespace Dbo
    {
        
        boost::mutex SafeTransaction::mutex_;

        SafeTransaction::SafeTransaction(Wt::Dbo::Session& session) : Wt::Dbo::Transaction(session)
        {
            mutex_.lock();
        }

        SafeTransaction::~SafeTransaction()
        {
            mutex_.unlock();
        }

    }
}

