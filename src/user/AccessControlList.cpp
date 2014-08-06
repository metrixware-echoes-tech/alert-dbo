/* 
 * Access Control List Table
 * @author ECHOES Technologies (RHI)
 * @date 10/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "user/AccessControlList.h"

using namespace std;

namespace Echoes
{
    namespace Dbo
    {
        string AccessControlList::TRIGRAM(TRIGRAM_ACCESS_CONTROL_LIST);

        AccessControlList::AccessControlList()
        {
        }

        AccessControlList::~AccessControlList()
        {
        }
    }
}

