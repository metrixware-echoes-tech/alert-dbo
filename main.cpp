/* 
 * DBO Create Table
 * @author ECHOES Technologies (FPO)
 * @date 21/04/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include <Wt/WLogger>

#include "tools/SessionPool.h"

using namespace std;

SessionPool* SessionPool::instance = 0;
std::string SessionPool::credentials = "";
boost::mutex SessionPool::mutex;

int main(int argc, char** argv)
{
    Session sessionThread("hostaddr=172.16.3.102 port=5432 dbname=echoes user=echoes password=toto");
    
    try 
    {
        Wt::Dbo::Transaction transaction(sessionThread);

        sessionThread.createTables();
        
        transaction.commit();
    }
    catch (Wt::Dbo::Exception e)
    {
        Wt::log("error") << e.what();
    }

    return 0;
}

