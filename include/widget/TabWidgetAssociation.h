///* 
// * File:   TabWidgetAssociation.h
// * Author: tom
// *
// * Created on 30 avril 2012, 19:29
// */
//
//#ifndef TABWIDGETASSOCIATION_H
//#define	TABWIDGETASSOCIATION_H
//
//#include "Table.h"
//#include <Wt/Dbo/Dbo>
//#include <Wt/Dbo/WtSqlTraits>
//
//
//#include "Probe.h"
//
//#include "Tab.h"
//#include "TabVersion.h"
//
//#include "Widget.h"
//#include "WidgetType.h"
//
//#include "Unit.h"
//#include "UnitType.h"
//
//#include "Information.h"
//#include "HistoricalValue.h"
//#include "Value.h"
//
//#include "Plugin.h"
//
//#include "Organization.h"
//
//#include "Addon.h"
//
//#include "Source.h"
//#include "SourceParameter.h"
//#include "SourceParameterValue.h"
//
//#include "Asset.h"
//
//class Tab;
//class Widget;
//class TabVersion;
//
//class TabWidgetAssociation : public Table
//{
//public:
//    TabWidgetAssociation();
//    virtual ~TabWidgetAssociation();
//    Wt::Dbo::collection<Wt::Dbo::ptr<Widget> > widgets;
//    Wt::Dbo::collection<Wt::Dbo::ptr<Tab> > tabs;
//    
//    Wt::Dbo::collection<Wt::Dbo::ptr<TabVersion> > tabVersions;
//    
//    template<class Action>
//    void persist(Action& a)
//    {     
//        Wt::Dbo::hasMany(a,
//                            widgets,
//                            Wt::Dbo::ManyToOne,
//                            "TWG1");
//        Wt::Dbo::hasMany(a,
//                            tabs,
//                            Wt::Dbo::ManyToOne,
//                            "TWG2");
//        
//        //TJ
//        Wt::Dbo::hasMany(a,
//                            tabVersions,
//                            Wt::Dbo::ManyToMany,
//                            "TJ_TWG_TVS");
//    }
//private:
//
//};
//
//#endif	/* TABWIDGETASSOCIATION_H */
//
