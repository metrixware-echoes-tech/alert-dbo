/* 
 * Gui SpecializedAuthService.h
 * 
 * @author Echoes Technologies
 * @author Thomas SAQUET (TSA)
 * 
 * @date 13/08/2014
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * AbstractPage
 * COPYRIGHT 2012-2014 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef SPECIALIZEDAUTHSERVICE_H
#define	SPECIALIZEDAUTHSERVICE_H

class SpecializedAuthService : public Wt::Auth::AuthService
{
public:
    SpecializedAuthService() : Wt::Auth::AuthService() {}

    void sendMail(const Wt::Mail::Message& message) const;
private:

};

#endif	/* SPECIALIZEDAUTHSERVICE_H */

