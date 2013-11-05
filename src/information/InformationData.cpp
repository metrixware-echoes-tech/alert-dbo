/* 
 * File:   InformationData.cpp
 * Author: tsa
 * 
 * Created on 31 octobre 2013, 16:42
 */

#include "information/InformationData.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string InformationData::TRIGRAM(TRIGRAM_INFORMATION_DATA);

        InformationData::InformationData()
        {
            this->jsonName = "information_data";
        }

        InformationData::InformationData(const InformationData& orig)
        {
        }

        InformationData::~InformationData()
        {
        }

    }
}

