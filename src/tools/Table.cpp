/* 
 * Parent Class for Table
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

#include "tools/Table.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    Table::Table()
    {
        this->name = "";
        this->id = -2;
    }

    Table::Table(const Table& orig)
    {
        this->name = orig.name;
        this->id = orig.id;
        this->deleteTag = orig.deleteTag;
        this->mapClassAttributesBools = orig.mapClassAttributesBools;
        this->mapClassAttributesDates = orig.mapClassAttributesDates;
        this->mapClassAttributesInts = orig.mapClassAttributesInts;
        this->mapClassAttributesIntsNn = orig.mapClassAttributesIntsNn;
        this->mapClassAttributesSerials = orig.mapClassAttributesSerials;
        this->mapClassAttributesShorts = orig.mapClassAttributesShorts;
        this->mapClassAttributesStrings = orig.mapClassAttributesStrings;
        this->mapClassAttributesStringsNn = orig.mapClassAttributesStringsNn;
    }

    Table::~Table()
    {
    }
  }
}

