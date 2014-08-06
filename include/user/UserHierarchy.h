///* 
// * Header of User Hierarchy Table
// * @author ECHOES Technologies (TSA)
// * @date 18/04/2012
// * 
// * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
// * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
// * COMPANY AUTHORIZATION.
// * 
// * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
// * 
// */
//
//#ifndef USERHIERARCHY_H
//#define USERHIERARCHY_H
//
//#include <Wt/Dbo/Dbo>
//#include <Wt/Dbo/WtSqlTraits>
//
//#include "tools/MainIncludeFile.h"
//
//#include "primaryKeys/UserHierarchyId.h"
//
//namespace Echoes
//{
//  namespace Dbo
//  {
//    class UserHierarchy : public Table
//    {
//        public:
//            UserHierarchy();
//            virtual ~UserHierarchy();
//
//            static std::string TRIGRAM;
//
//            Wt::Dbo::ptr<User> user;
//
//            template<class Action>
//            void persist(Action& a) {
//
//                Table::fieldFiller(a, *this);
//                Wt::Dbo::belongsTo(a, hiid.parent, TRIGRAM_USER_HIERARCHY SEP "UPA");
//            }
//        protected:
//        private:
//    };
//  }
//}
//
//#endif // USERHIERARCHY_H
//
