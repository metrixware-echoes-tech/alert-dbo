/**
 * @file Table.cpp
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

#include "tools/Table.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    Table::Table()
    {
        this->name = "";
        this->id = -2;
    }

    Table::Table(const Table& orig)
    {
        this->name = orig.name;
        this->id = orig.id;
        this->deleteTag = orig.deleteTag;
        this->mapClassAttributesBools = orig.mapClassAttributesBools;
        this->mapClassAttributesDates = orig.mapClassAttributesDates;
        this->mapClassAttributesInts = orig.mapClassAttributesInts;
        this->mapClassAttributesIntsNn = orig.mapClassAttributesIntsNn;
        this->mapClassAttributesSerials = orig.mapClassAttributesSerials;
        this->mapClassAttributesShorts = orig.mapClassAttributesShorts;
        this->mapClassAttributesStrings = orig.mapClassAttributesStrings;
        this->mapClassAttributesStringsNn = orig.mapClassAttributesStringsNn;
    }

    Table::~Table()
    {
    }
  }
}
