///* 
// * File:   WidgetValueId.h
// * Author: tom
// *
// * Created on 5 mai 2012, 00:35
// */
//
//#ifndef WIDGETVALUEID_H
//#define	WIDGETVALUEID_H
//
//#include <Wt/Dbo/Dbo>
//
//class Group;
//class Widget;
//class Probe;
//class Plugin;
//class Information;
//class WidgetValue;
//
//struct WidgetValueId
//{
//    Wt::Dbo::ptr<Group> group;
//    Wt::Dbo::ptr<Widget> widget;
//    Wt::Dbo::ptr<Probe> probe;
//    Wt::Dbo::ptr<Plugin> plugin;
//    Wt::Dbo::ptr<Information> information;
//
//    WidgetValueId(Wt::Dbo::ptr<Group> o, Wt::Dbo::ptr<Widget> w, Wt::Dbo::ptr<Probe> pr, Wt::Dbo::ptr<Plugin> 
//    pl, Wt::Dbo::ptr<Information> i)
//        : group(o), widget(w), probe(pr), plugin(pl), information(i) { }
//
//    WidgetValueId(){ }
//
//    bool operator== (const WidgetValueId& other) const {
//        return group == other.group && widget == other.widget && probe == other.probe 
//                && plugin == other.plugin && information == other.information;
//    }
//
//    bool operator< (const WidgetValueId& other) const {
//        if (widget < other.widget)
//            return true;
//        else
//            return false;
//    }
//};
//
//inline std::ostream& operator<< (std::ostream& o, const WidgetValueId& pk)
//{
//    return o << "(" << pk.widget << ")";
//}
//
//namespace Wt
//{
//    namespace Dbo
//    {
//        template <class Action>
//        void field(Action& a, WidgetValueId& wvid,
//                   const std::string& name, int size = -1)
//        {
//            Wt::Dbo::belongsTo(a, wvid.group, "ORG_ID");
//            Wt::Dbo::belongsTo(a, wvid.widget, "WGT_ID");
//            Wt::Dbo::belongsTo(a, wvid.probe, "PRB_ID");
//            Wt::Dbo::belongsTo(a, wvid.plugin, "PLU_ID");
//            Wt::Dbo::belongsTo(a, wvid.information, "INF_ID");
//        }
//    }
//}
//
//#endif	/* WIDGETVALUE_H */
//
