/* 
 * Header of Alert Type Table
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

//#ifndef ALERTTYPE_H
//#define ALERTTYPE_H
//
//#include <Wt/Dbo/Dbo>
//
//#include "tools/MainIncludeFile.h"
//
//class Alert;
//class AlertCriteria;
//
//class AlertType : public Table
//{
//    public:
//        AlertType();
//        virtual ~AlertType();
//        
//        static std::string TRIGRAM;
//        
//        Wt::WString name;
//        
//        Wt::Dbo::collection<Wt::Dbo::ptr<Alert> > alerts;
//        Wt::Dbo::collection<Wt::Dbo::ptr<AlertCriteria> > alertCriterias;
//        
//        template<class Action>
//        void persist(Action& a)
//        {
//            mapClassAttributesStrings["NAME"]=&this->name;
//            
//            FIELD_FILLER();
//            
//            Wt::Dbo::hasMany(a,
//                             alerts,
//                             Wt::Dbo::ManyToOne,
//                             "ALE_ATY");
//            Wt::Dbo::hasMany(a,
//                             alertCriterias,
//                             Wt::Dbo::ManyToMany,
//                             "TJ_ATY_ACR");
//            
//        }
//        
//    protected:
//    private:
//};
//
//#endif // ALERTTYPE_H

