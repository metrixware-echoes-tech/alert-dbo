/* 
 * Information Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "information/Information.h"

using namespace std;

namespace Echoes {
  namespace Dbo {
    string Information::TRIGRAM(TRIGRAM_INFORMATION);

    Information::Information()
    {
    }

    Information::Information(const Information &orig)
    : Table(orig)
    {
        this->calculate = orig.calculate;
        this->desc = orig.desc;
        this->display = orig.display;
    //    this->pk = orig.pk;
    }

    Information::~Information()
    {
    }
  }
}

