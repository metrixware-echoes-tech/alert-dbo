#ifndef TABLE_H
#define TABLE_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/WtSqlTraits>

//template <typename U>
class Table //classe abstraite
{
    public:
        Table();
        virtual ~Table();
        static std::string getTrigram();
        static std::string getName();
        static std::string TRIGRAM;
        static std::string SEP;






    protected:
        std::string formatColumnName(std::string value);

        static std::string TABLE_PREFIX;
        static std::string SHORT_NAME;
        static std::string FULL_NAME;



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
