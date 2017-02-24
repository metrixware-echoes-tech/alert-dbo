/**
 * @file Enums.h
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

#ifndef DBO_ENUMS_H
#define	DBO_ENUMS_H

namespace Echoes
{
  namespace Dbo
  {
    namespace EAlertCriteria
    {
      enum {
          LT = 1,
          LE = 2,
          EQ = 3,
          NE = 4,
          GE = 5,
          GT = 6
      };
    }
    
    namespace EInformationUnitType
    {
      enum {
          TEXT = 1,
          NUMBER = 2,
          BOOL = 3,
          CUSTOM = 4
      };
    }
    
    namespace EMediaType {
      enum {
          MAIL = 1,
          SMS = 2,
          MOBILE_APP = 3
      };
    }
    
    namespace EOptionType
    {
      enum {
          QUOTA_ASSET = 1,
          QUOTA_SMS = 2
      };
    }
    
    namespace EAddon {
      enum {
          FILESYSTEM = 1,
          FILE = 2,
          LOG = 3,
          ODBC = 4,
          SNMP = 5,
          HASH = 6,
          XML = 7,
          PROCESS = 8
      };
    }
    
    namespace EOrganizationType
    {
      enum {
          INDIVIDUAL = 1,
          ASSOCIATION = 2,
          COMPANY = 3
      };
    }
    
    namespace ESearchType {
      enum  {
          PATH = 1,
          PATH_LINE = 2,
          PATH_LAST_LINE = 3,
          QUERY = 4,
          OID = 5,
          PATH_ALGORITHM = 6,
          PATH_XPATH = 7,
          NAME = 8
      };
    }
    
    namespace EFilterType {
      enum {
          ALL = 1,
          REGEX = 2,
          LOCATION = 3
      };
    }
    
    namespace EFilterParameter {
      enum {
          REGEX = 1,
          FIRST_CHAR = 2,
          LENGTH = 3
      };
    }
    
    namespace ESourceParameter {
      enum ESourceParameter {
          CONNECTION_STRING = 1,
          COMMUNITY = 2,
          VERSION = 3,
          AUTH_PROTO = 4,
          AUTH_PATH = 5,
          PRIV_PROTO = 6,
          PRIV_PATH = 7,
          HOST = 8,
          USER = 9
      };
    }
    
    namespace ESearchParameter {
      enum  {
          PATH = 1,
          LINE = 2,
          LAST_LINE = 3,
          QUERY = 4,
          OID = 5,
          ALGORITHM = 6,
          XPATH = 7,
          NAME = 8
      };
    }
    
    namespace EUserActionType {
      enum {
          LOGIN = 1,
          REGISTER = 2,
          LOGOUT = 3,
          DISPLAY = 4,
          DOWNLOAD = 5,
          ADD = 6,
          DEL = 7
      };
    }
    
    namespace EBooleanOperator {
      enum {
          AND = 1,
          OR = 2
      };
    }
  }
}


#endif	/* DBO_ENUMS_H */
