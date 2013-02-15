#ifndef PROBE_H
#define PROBE_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class Organization;
class InformationValue;
class InformationValue;

class Probe : public Table
{
    public:
        Probe();
        virtual ~Probe();
        
        static std::string TRIGRAM;             
        Wt::WString name;
        Wt::WString cert;
        
        Wt::Dbo::ptr<Organization> organization;
        Wt::Dbo::ptr<ProbePackageParameter> probePackageParamater;

        Wt::Dbo::collection<Wt::Dbo::ptr<Syslog> > syslogs;
        Wt::Dbo::collection<Wt::Dbo::ptr<SyslogHistory> > syslogsHistory;
        Wt::Dbo::collection<Wt::Dbo::ptr<Asset> > assets;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;            
            mapClassAttributesStrings["CERT"]=&this->cert; 
            FIELD_FILLER();
            Wt::Dbo::belongsTo(a, organization, TRIGRAM_PROBE SEP TRIGRAM_ORGANIZATION);
            Wt::Dbo::belongsTo(a, probePackageParamater, TRIGRAM_PROBE SEP TRIGRAM_PROBE_PACKAGE_PARAMETER);

            Wt::Dbo::hasMany(a,
                             syslogs,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_SYSLOG SEP TRIGRAM_PROBE);
            
            Wt::Dbo::hasMany(a,
                             syslogsHistory,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_SYSLOG_HISTORY SEP TRIGRAM_PROBE);
            
            Wt::Dbo::hasMany(a,
                             assets,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_ASSET SEP TRIGRAM_PROBE);
                         
        }
        virtual std::string toJSON();
        
    protected:
    private:
};

#endif // PROBE_H
