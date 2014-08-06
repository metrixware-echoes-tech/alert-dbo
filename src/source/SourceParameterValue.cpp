/* 
 * Source Parameter Value Table
 * @author ECHOES Technologies (TSA)
 * @date 04/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "source/SourceParameterValue.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string SourceParameterValue::TRIGRAM(TRIGRAM_SOURCE_PARAMETER_VALUE);

    SourceParameterValue::SourceParameterValue()
    {
    }

    SourceParameterValue::SourceParameterValue(const SourceParameterValue& orig)
    {
    }

    SourceParameterValue::~SourceParameterValue()
    {
    }
  }
}
