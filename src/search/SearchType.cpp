/* 
 * Search Type Table
 * @author ECHOES Technologies (TSA)
 * @date 07/06/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "search/SearchType.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string SearchType::TRIGRAM(TRIGRAM_SEARCH_TYPE);

    SearchType::SearchType()
    {
    }

    SearchType::SearchType(const SearchType& orig)
    {
    }

    SearchType::~SearchType()
    {
    }
  }
}
