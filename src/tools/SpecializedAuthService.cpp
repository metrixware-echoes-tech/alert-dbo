/**
 * @file SpecializedAuthService.cpp
 * @author Thomas Saquet, Florent Poinsaut
 * @date 
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Alert - Dbo is the database objects library, part of the Alert software
 * Copyright (C) 2013-2017
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
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
