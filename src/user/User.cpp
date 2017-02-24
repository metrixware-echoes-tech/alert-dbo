/**
 * @file User.cpp
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

#include "user/User.h"

#include <Wt/Dbo/Impl>
#include <Wt/Auth/Dbo/AuthInfo>

//DBO_INSTANTIATE_TEMPLATES(Echoes::Dbo::User)

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string User::TRIGRAM(TRIGRAM_USER);

    User::User() : Table()
    {
    }

    User::User(string firstName, string lastName, string eMail, string password, string token) : Table()
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->eMail = eMail;
        this->password = password;
        this->token = token;
    }

    User::~User()
    {
    }

    string User::getName()
    {
        return Constants::T_USER_USR;
    }
  }
}
