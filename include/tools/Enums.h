/* 
 * Header of DBO Enums
 * @author ECHOES Technologies (TSA, FPO)
 * @date 21/03/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef DBO_ENUMS_H
#define	DBO_ENUMS_H

namespace Echoes
{
  namespace Dbo
  {
        
        enum EAlertCriteria {
            LT = 1,
            LE = 2,
            EQ = 3,
            NE = 4,
            GE = 5,
            GT = 6
        };

        enum EInformationUnitType {
            TEXT = 1,
            NUMBER = 2
        };

        enum EMedia {
            MAIL = 1,
            SMS = 2,
            MOBILE_APP = 3
        };

        enum EOption {
            QUOTA_ASSET = 1,
            QUOTA_SMS = 2
        };
        
        enum EAddon {
            FILESYSTEM = 1,
            FILE = 2,
            LOG = 3,
            MYSQL = 4,
            SNMP = 5
        };
        
        enum EOrganizationType {
            INDIVIDUAL = 1,
            ASSOCIATION = 2,
            COMPANY = 3
        };
        
        enum ESearchType {
            REGEX = 1,
            LOCATION = 2,
            QUERY = 3,
            REGEX_OID = 4,
            OID = 5
        };
        
        enum ESourceParameter {
            PATH = 1,
            HOST = 2,
            USER = 3,
            PASSWD = 4,
            DB = 5,
            PORT = 6,
            COMMUNITY = 7,
            VERSION = 8,
            AUTH_PROTO = 9,
            AUTH_PATH = 10,
            PRIV_PROTO = 11,
            PRIV_PATH = 12
        };
  
  }
}


#endif	/* DBO_ENUMS_H */

