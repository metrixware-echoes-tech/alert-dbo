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

#ifndef ENUMS_H
#define	ENUMS_H

namespace Echoes
{
  namespace Dbo
  {
      enum EReturnCode {
            OK = 200,
            CREATED = 201,
            ACCEPTED = 202,
            NO_CONTENT = 204,
            RESET_CONTENT = 205,
            PARTIAL_CONTENT = 206,

            MULTIPE_CHOICES = 300,
            MOVED_PERMANENTLY = 301,
            MOVED_TEMPORARILY = 302,
            SEE_OTHER = 303,
            NOT_MODIFIED = 304,
            USE_PROXY = 305,
            TEMPORARY_REDIRECT = 307,
            TOO_MANY_REDIRECT = 310,

            BAD_REQUEST = 400,
            UNAUTHORIZED = 401,
            PAYMENT_REQUIRED = 402,
            FORBIDDEN = 403,
            NOT_FOUND = 404,
            METHOD_NOT_ALLOWED = 405,
            NOT_ACCEPTABLE = 406,
            PROXY_AUTHENTICATION_REQUIRED = 407,
            REQUEST_TIME_OUT = 408,
            CONFLICT = 409,
            GONE = 410,
            LENGTH_REQUIRED = 411,
            PRECONDITION_FAILED = 412,
            REQUEST_ENTITY_TOO_LARGE = 413,
            REQUEST_URI_TOO_LONG = 414,
            UNSUPPORTED_MEDIA_TYPE = 415,
            REQUESTED_RANGE_UNSATISFIABLE = 416,
            EXPECTATION_FAILED = 417,
            I_AM_A_TEAPOT = 418,
            UPGRADE_REQUIRED = 426,

            INTERNAL_SERVER_ERROR = 500,
            NOT_IMPLEMENTED = 501,
            BAD_GATEWAY_OR_PROXY_ERROR = 502,
            SERVICE_UNAVAILABLE = 503,
            GATEWAY_TIME_OUT = 504,
            HTTP_VERSION_NOT_SUPPORTED = 505,
            BANDWIDTH_LIMIT_EXCEDED = 509
        };
      

        
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


#endif	/* ENUMS_H */

