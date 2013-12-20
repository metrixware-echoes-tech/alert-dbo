/* 
 * File:   SafeTransaction.h
 * Author: tsa
 *
 * Created on 19 décembre 2013, 18:02
 */

#ifndef SAFETRANSACTION_H
#define	SAFETRANSACTION_H

#include <boost/thread/mutex.hpp>
#include <Wt/Dbo/Transaction>

namespace Echoes
{
namespace Dbo
{
    
    class SafeTransaction : public Wt::Dbo::Transaction
    {
    public:
        SafeTransaction(Wt::Dbo::Session& session);
        virtual ~SafeTransaction();
        static boost::mutex mutex_;
    private:
        
        boost::mutex::scoped_lock lock;

    };
}
}



#endif	/* SAFETRANSACTION_H */

