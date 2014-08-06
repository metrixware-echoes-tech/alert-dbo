/* 
 * Filter Type Table
 * @author ECHOES Technologies (TSA)
 * @date 30/10/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "filter/FilterType.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string FilterType::TRIGRAM(TRIGRAM_FILTER_TYPE);

    FilterType::FilterType()
    {
    }

    FilterType::FilterType(const FilterType& orig)
    {
    }

    FilterType::~FilterType()
    {
    }
  }
}

