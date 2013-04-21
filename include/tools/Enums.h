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

class Enums
{
    public:
        Enums();
        Enums(const Enums& orig);
        virtual ~Enums();

        enum EReturnCode
        {
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
        enum EAlertCriteria
        {
            LT = 1,
            LE = 2,
            EQ = 3,
            NE = 4,
            GE = 5,
            GT = 6
        };
        enum EInformationUnitType
        {
            TEXT = 1,
            NUMBER = 2
        };
        enum EMedia {
            MAIL = 1,
            SMS = 2
        };
        enum EOption {
            QUOTA_ASSET = 1,
            QUOTA_SMS = 2
        };
    private:

};

#endif	/* ENUMS_H */

