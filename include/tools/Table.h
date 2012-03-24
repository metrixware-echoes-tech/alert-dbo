#ifndef TABLE_H
#define TABLE_H

#include <string>

class Table //classe abstraite
{
    public:
        Table();
        virtual ~Table();

        static std::string SEP;
        static std::string TABLE_PREFIX;

        template<typename T>
        std::string formatColumnName(const T &x, std::string value);
    protected:

};


/**
 * Definition and implementation of template functions must be in the same file.
 * Make sure you place both between the #ifndef / #endif anchors to prevent
 * duplicates.
 */

template<typename T>
std::string Table::formatColumnName(const T &x, std::string value)
{
    return T::TRIGRAM + Table::SEP + value;
}
#endif


