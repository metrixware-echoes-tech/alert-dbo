#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

class Hierarchy;
namespace Wt
{
    namespace Dbo
    {
        template<>
        struct dbo_traits<Hierarchy> : public dbo_default_traits
        {
            static const char *surrogateIdField()
            {
                //changed to test, return0.
                //return "HRC_ID";
                return 0;
            }
            static const char *versionField()
            {
                return 0;
            }
        };
    }
}

class User;

class Hierarchy
{
    public:
        Hierarchy();
        virtual ~Hierarchy();

        Wt::Dbo::ptr<User> userParent;
        Wt::Dbo::ptr<User> userChild;

        template<class Action>
        void persist(Action& a)
        {

            Wt::Dbo::belongsTo(a, userParent, "UPA");
            Wt::Dbo::belongsTo(a, userChild, "UCH");
        }
    protected:
    private:
};

#endif // HIERARCHY_H
