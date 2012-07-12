#ifndef ALERTHISTO_H
#define ALERTHISTO_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "tools/MainIncludeFile.h"

class Alert;
class User;

class AlertAcknowledge : public Table
{
    public:
        AlertAcknowledge();
        virtual ~AlertAcknowledge();
        Wt::Dbo::ptr<Alert> alert;
        Wt::Dbo::ptr<User> user;
        
        std::string ackState;
        std::string isLast;
        
        static std::string TRIGRAM;
        
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["STATE"]=this->ackState;
            mapClassAttributesStrings["IS_LAST"]=this->isLast;
            FIELD_FILLER();
            Wt::Dbo::belongsTo(a, alert, "ACK_ALE");
            Wt::Dbo::belongsTo(a, user, "ACK_USR");
        }
        
    protected:
    private:
};

#endif // ALERTHISTO_H
