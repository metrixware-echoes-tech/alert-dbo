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

namespace Echoes {
    namespace Dbo {
        std::string Information::TRIGRAM(TRIGRAM_INFORMATION);

        Information::Information()
        {
             this->jsonName = "information";
            //ctor
        }

        Information::Information(const Information &orig)
        : Table(orig)
        {
            this->alertValues = orig.alertValues;
            this->calculate = orig.calculate;
            this->desc = orig.desc;
            this->display = orig.display;
        //    this->pk = orig.pk;
        }

        Information::~Information()
        {
        }

        std::string Information::toJSON() const
        {
            std::string res = "";
            res = "{\n\t";
        //    res += "\"id\": {" + boost::lexical_cast<std::string>(this->pk) + " },\n";
            res += Table::toJSON();

            res += Table::formatJSONForDboCollection(this->alertValues, "alert_values", false);

            res += "}";
            return res;
        }
    }
}

