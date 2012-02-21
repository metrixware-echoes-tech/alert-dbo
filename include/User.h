#ifndef USER_H
#define USER_H

#include <Table.h>
#include <Wt/WDateTime>

class User : public Table
{
private:

public:
    User();
    User(std::string firstName, std::string lastName, std::string eMail, std::string password);
    virtual ~User();

    std::string firstName;
    std::string lastName;
    std::string eMail;
    std::string password;
    Wt::WDateTime deleteTag;


    /*
    int myint[] = {1,2,3,4};
    for (int& i : myint)
    {
        cout << i << endl;
    }
    */

    template<class Action>
    void persist(Action& a)
    {
        std::map <std::string,std::string> mapClassAttributesStrings;
        mapClassAttributesStrings["FIRST_NAME"]=this->firstName;
        mapClassAttributesStrings["LAST_NAME"]=this->lastName;
        mapClassAttributesStrings["MAIL"]=this->eMail;
        mapClassAttributesStrings["PWD"]=this->password;

        std::map <std::string,Wt::WDateTime> mapClassAttributesDates;
        mapClassAttributesDates["DELETE"]=this->deleteTag;

        std::map<std::string,std::string>::iterator itStrings;
        for(itStrings = mapClassAttributesStrings.begin(); itStrings != mapClassAttributesStrings.end(); ++itStrings)
        {
            Wt::Dbo::field(a, (*itStrings).second,     this->formatColumnName((*itStrings).first));
        }

        std::map<std::string,Wt::WDateTime>::iterator itDates;
        for(itDates = mapClassAttributesDates.begin(); itDates != mapClassAttributesDates.end(); ++itDates)
        {
            Wt::Dbo::field(a, (*itDates).second,     this->formatColumnName((*itDates).first));
        }


        //Wt::Dbo::field(a, this->deleteTag,     this->formatColumnName("DELETE"));
        //Wt::Dbo::field(a, password, this->formatColumnName("PASSWORD"));
    }

    void test();
};

namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<User> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                //FIXME: solve this string / char problem
                //const std::string resString = Table::TRIGRAM+Table::SEP+"ID";
                //const char * resChar = resString.c_str();
                return "USR_ID";
            }
            static const char *versionField()
            {
                return 0;
            }
        };
    }
}



#endif // USER_H
