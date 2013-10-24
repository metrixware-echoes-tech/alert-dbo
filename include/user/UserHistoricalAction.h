/* 
 * Header of User Historical Action Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#ifndef USERHISTORICALACTION_H
#define USERHISTORICALACTION_H

#include <string>

// include Dbo
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/WDateTime>

#include "tools/MainIncludeFile.h"

//class User;
//class UserAction;

class UserHistoricalAction : public Table
{
    public:
        UserHistoricalAction();
        virtual ~UserHistoricalAction();

        static std::string TRIGRAM;
        
	// attributes
        Wt::WDateTime dateTime;
    
        int actionBefore;
        int actionAfter;
        int actionRelative;
        Wt::WString tableObject;
        long long tableObjectId;

	// methods


	// dbo pointers (Other tables ids as foreign keys for this table)
        Wt::Dbo::ptr<User> user;
        Wt::Dbo::ptr<UserAction> userAction;

	// dbo collections (This table id as foreign key in other tables)
//        Wt::Dbo::collection<Wt::Dbo::ptr<UserAction> > userActions;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesDates["DATETIME"]=&this->dateTime;            
            mapClassAttributesInts["BEFORE"]=&this->actionBefore;
            mapClassAttributesInts["AFTER"]=&this->actionAfter;
            mapClassAttributesInts["RELATIVE"]=&this->actionRelative;
            mapClassAttributesStrings["TABLE_OBJECT"]=&this->tableObject;
            mapClassAttributesSerials["TAO_ID"]=&this->tableObjectId;
            FIELD_FILLER();
            //Other tables ids as foreign keys for user table

            Wt::Dbo::belongsTo(a, user, "UHA_USR");
            
            Wt::Dbo::belongsTo(a,userAction,"UHA_UAC");

            

        }
};





#endif // USERHISTORICALACTION_H
