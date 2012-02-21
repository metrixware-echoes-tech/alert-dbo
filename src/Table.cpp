#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include "Table.h"

using namespace std;

string Table::SEP = "_";
string Table::TABLE_PREFIX = "T";

Table::Table()
{
    //ctor
}

Table::~Table()
{
    //dtor
}

string Table::formatColumnName(string value)
{
    return TRIGRAM + SEP + value;
}

string Table::getName()
{
    return Table::FULL_NAME;
}


