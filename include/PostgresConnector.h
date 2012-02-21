#ifndef POSTGRESCONNECTOR_H
#define POSTGRESCONNECTOR_H

#include <string>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>


class PostgresConnector
{
    public:
        PostgresConnector(std::string databaseName,std::string userName,std::string databaseURL,std::string databasePort,std::string userPwd);
        virtual ~PostgresConnector();
        void connect();
        Wt::Dbo::Session *getSession();
        void generateModel(bool drop);
    protected:
    private:
        std::string m_databaseName;
        std::string m_userName;
        std::string m_databaseURL;
        std::string m_databasePort;
        std::string m_userPwd;
        Wt::Dbo::Session *m_session;
        Wt::Dbo::backend::Postgres *m_pg;

};

#endif // POSTGRESCONNECTOR_H
