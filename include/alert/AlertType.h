#ifndef ALERTTYPE_H
#define ALERTTYPE_H

#include <Wt/Dbo/Dbo>


class AlertType : public Table
{
    public:
        AlertType();
        virtual ~AlertType();
        Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,
                             alerts,
                             Wt::Dbo::ManyToOne,
                             "ATY");
        }
        
    protected:
    private:
};

#endif // ALERTTYPE_H
