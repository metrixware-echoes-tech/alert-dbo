/* 
 * Gui SpecializedAuthService.cpp
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

#include <Wt/Auth/AuthService>
#include <Wt/Auth/AbstractUserDatabase>
#include <Wt/Auth/HashFunction>
#include <Wt/Auth/Identity>
#include <Wt/WRandom>
#include <Wt/Mail/Client>
#include <Wt/Mail/Message>
#include <Wt/Mail/Mailbox>
#include <Wt/WApplication>

#include "tools/SpecializedAuthService.h"

void SpecializedAuthService::sendMail(const Wt::Mail::Message& message) const
{
  Wt::Mail::Message m = message;

    if (m.from().empty())
    {
        std::string senderName = "Echoes Alert";
        std::string senderAddress = "noreply@echoes-tech.com";

        Wt::WApplication::readConfigurationProperty("auth-mail-sender-name",
                                                    senderName);
        Wt::WApplication::readConfigurationProperty("auth-mail-sender-address",
                                                    senderAddress);
#ifndef WT_TARGET_JAVA
        m.setFrom(Wt::Mail::Mailbox(senderAddress, Wt::WString::fromUTF8(senderName)));
#else
        m.setFrom(Mail::Mailbox(senderAddress, senderName));
#endif
    }

    m.write(std::cout);

    Wt::Mail::Client client;
    client.connect();
    client.send(m);
  
}

