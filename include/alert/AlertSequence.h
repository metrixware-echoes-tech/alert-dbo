/* 
 * File:   AlertSequence.h
 * Author: tsa
 *
 * Created on 15 août 2012, 15:21
 */

#ifndef ALERTSEQUENCE_H
#define	ALERTSEQUENCE_H

#include "tools/MainIncludeFile.h"
#include <Wt/Dbo/Dbo>

class AlertSequence : public Table 
{
public:
    AlertSequence();
    AlertSequence(const AlertSequence& orig);
    virtual ~AlertSequence();
    
    static std::string TRIGRAM;
    bool firstParenthesis;
    Wt::Dbo::ptr<AlertValue> alertValue;
    bool secondParenthesis;
    boost::optional<int> boolOperator;
    Wt::Dbo::weak_ptr<AlertSequence> alertSequence;
    Wt::Dbo::ptr<AlertSequence> alertSequenceBelongTo;
    
    Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
    
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesBools["FIRST_PARENTHESIS"]=&this->firstParenthesis;
        mapClassAttributesBools["SECOND_PARENTHESIS"]=&this->secondParenthesis;
        mapClassAttributesIntsNn["BOOL_OP"]=&this->boolOperator;

        FIELD_FILLER();
        
        Wt::Dbo::belongsTo(a,alertSequenceBelongTo,TRIGRAM_ALERT_SEQUENCE SEP "NXT_ID");
        Wt::Dbo::hasOne(a, alertSequence, TRIGRAM_ALERT_SEQUENCE SEP "NXT_ID");
        
        Wt::Dbo::belongsTo(a,alertValue,TRIGRAM_ALERT_SEQUENCE SEP TRIGRAM_ALERT_VALUE);
        Wt::Dbo::hasMany(a,alerts,Wt::Dbo::ManyToOne, TRIGRAM_ALERT_SEQUENCE SEP "FIRST_ID");
        
    }
    
    virtual std::string toJSON();
    
private:

};

#endif	/* ALERTSEQUENCE_H */

