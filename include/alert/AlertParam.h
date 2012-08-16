//#ifndef ALERTPARAM_H
//#define ALERTPARAM_H
//
//#include <Wt/Dbo/Dbo>
//#include <Wt/Dbo/WtSqlTraits>
//
//#include "tools/MainIncludeFile.h"
//
////class AlertValue;
//class AlertCriteria;
//
//class AlertParam : public Table
//{
//    public:
//        AlertParam();
//        virtual ~AlertParam();
//        
//        static std::string TRIGRAM;
//        
//        Wt::WString name;
//        Wt::WString format;
//        
////        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
//        Wt::Dbo::collection<Wt::Dbo::ptr<AlertCriteria> > alertCriterias;
//        
//        template<class Action>
//        void persist(Action& a)
//        {
//            mapClassAttributesStrings["NAME"]=&this->name;
//            mapClassAttributesStrings["FORMAT"]=&this->format;
//            
//            FIELD_FILLER();
//            
////            Wt::Dbo::hasMany(a,
////                             alertValues,
////                             Wt::Dbo::ManyToOne,
////                             "AVA_APA");
//            Wt::Dbo::hasMany(a,
//                             alertCriterias,
//                             Wt::Dbo::ManyToMany,
//                             "TJ_ACR_APA");
//            
//
//        }
//        
//    protected:
//    private:
//};
//
//#endif // ALERTPARAM_H
