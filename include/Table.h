#ifndef TABLE_H
#define TABLE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/WtSqlTraits>
#include <Constants.h>

class Table;

class Table //classe abstraite
{
    public:
        Table();
        virtual ~Table();
        /*template<typename T>
        std::string formatColumnName(const T &x, std::string value)
        {
            return T::getTrigram();
        }*/
    protected:
        //virtual std::string getTrigram();


    private:


};



template<typename T>
void QuiSuisJe(const T & x)
{
    std::cout << "Je suis un <inconnu>" << std::endl;
}

template<typename T>
void setFields(const T & t)
{
    const T a = t;

    std::cout << a.a << std::endl;
    std::cout << a.b << std::endl;

    /*
    for (T& i : a)
    {
        std::cout << i << std::endl;
    }
    */
}

#endif // TABLE_H
