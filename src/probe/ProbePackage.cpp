/* 
 * Probe Package Table
 * @author ECHOES Technologies (TSA)
 * @date 25/01/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "probe/ProbePackage.h"

namespace Echoes
{
    namespace Dbo
    {
        std::string ProbePackage::TRIGRAM(TRIGRAM_PROBE_PACKAGE);

        ProbePackage::ProbePackage()
        {
        }

        ProbePackage::ProbePackage(const ProbePackage& orig)
        {
        }

        ProbePackage::~ProbePackage()
        {
        }
    }
}

