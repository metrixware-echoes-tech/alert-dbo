#include "PostgresConnector.h"

namespace odb = Wt::Dbo;
using namespace std;

PostgresConnector::PostgresConnector(string databaseName,string userName,string databaseURL,string databasePort,string userPwd) :
    m_databaseName(databaseName),
    m_userName(userName),
    m_databaseURL(databaseURL),
    m_databasePort(databasePort),
    m_userPwd(userPwd)
{
    m_session = new Session();
    this->connect();
}

PostgresConnector::~PostgresConnector()
{
    //dtor
}

/**
*/
void PostgresConnector::connect()
{
    string connectionString = "hostaddr="+m_databaseURL+" port="+m_databasePort+" dbname="+m_databaseName+" user="+m_userName+" password="+m_userPwd;
    m_pg = new odb::backend::Postgres(connectionString);
    m_pg->setProperty("show-queries", "true");
    m_session->setConnection(*m_pg);

}

/**
*/
void PostgresConnector::generateModel(bool drop)
{
    if (drop)
    {
        m_session->dropTables();
    }
    m_session->createTables();
}

Session *PostgresConnector::getSession()
{
    return m_session;
}
