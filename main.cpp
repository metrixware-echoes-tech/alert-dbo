/* 
 * DBO Create Table
 * @author ECHOES Technologies (FPO)
 * @date 21/04/2013
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include <Wt/WLogger>

#include "tools/SessionPool.h"

using namespace std;

SessionPool* SessionPool::instance = 0;
std::string SessionPool::credentials = "";
boost::mutex SessionPool::mutex;

int main(int argc, char** argv)
{
    Session session("hostaddr=172.16.3.202 port=5432 dbname=echoes user=echoes password=toto");
    
    try 
    {
        Wt::Dbo::Transaction transaction(session);

        Wt::log("info") << "Tables Creation";
        session.createTables();

        transaction.commit();
    }
    catch (Wt::Dbo::Exception e)
    {
        Wt::log("error") << e.what();
    }

    try 
    {
        Wt::Dbo::Transaction transaction(session);

        Wt::log("info") << "Calculate AVG IVA Function Creation";

        session.execute
        (
" CREATE OR REPLACE FUNCTION calculate_avg_iva(integer, integer, integer, integer, integer, integer, integer, integer, integer, integer, integer)\n"
"   RETURNS void AS\n"
" $BODY$\n"
"   INSERT INTO \"T_INFORMATION_VALUE_IVA\"\n"
"     (\n"
"       \"version\",\n"
"       \"IVA_VALUE\",\n"
"       \"IVA_CREA_DATE\",\n"
"       \"IVA_LINE_NUM\",\n"
"       \"IVA_LOT_NUM\",\n"
"       \"IVA_STATE\",\n"
"       \"IVA_AST_AST_ID\",\n"
"       \"IVA_SLO_SLO_ID\",\n"
"       \"SEA_ID\",\n"
"       \"SRC_ID\",\n"
"       \"PLG_ID_PLG_ID\",\n"
"       \"INF_VALUE_NUM\",\n"
"       \"INU_ID_INU_ID\"\n"
"     )\n"
"     SELECT\n"
"         0 \"version\",\n"
"         (diff_value / diff_sec) \"IVA_VALUE\",\n"
"         now() \"IVA_CREA_DATE\",\n"
"         \"IVA_LINE_NUM\",\n"
"         \"IVA_LOT_NUM\",\n"
"         0 \"IVA_STATE\",\n"
"         \"IVA_AST_AST_ID\",\n"
"         \"IVA_SLO_SLO_ID\",\n"
"         \"SEA_ID\",\n"
"         \"SRC_ID\",\n"
"         \"PLG_ID_PLG_ID\",\n"
"         \"INF_VALUE_NUM\",\n"
"         \"INU_ID_INU_ID\"\n"
"       FROM\n"
"         (\n"
"          SELECT\n"
"              \"IVA_ID\",\n"
"              \"IVA_VALUE\",\n"
"              \"SEA_ID\",\n"
"              \"SRC_ID\",\n"
"              \"PLG_ID_PLG_ID\",\n"
"              \"INF_VALUE_NUM\",\n"
"              \"INU_ID_INU_ID\",\n"
"              \"IVA_AST_AST_ID\",\n"
"              \"IVA_SLO_SLO_ID\",\n"
"              \"IVA_LINE_NUM\",\n"
"              \"IVA_LOT_NUM\",\n"
"              --first_value(\"IVA_CREA_DATE\") over(partition by \"SEA_ID\",\"SRC_ID\",\"PLG_ID_PLG_ID\",\"INF_VALUE_NUM\",\"INU_ID_INU_ID\",\"IVA_LINE_NUM\" order by \"IVA_CREA_DATE\" DESC ) max_date,\n"
"              --first_value(\"IVA_CREA_DATE\") over(partition by \"SEA_ID\",\"SRC_ID\",\"PLG_ID_PLG_ID\",\"INF_VALUE_NUM\",\"INU_ID_INU_ID\",\"IVA_LINE_NUM\" order by \"IVA_CREA_DATE\" ASC ) min_date,\n"
"              extract(epoch from (first_value(\"IVA_CREA_DATE\") over(partition by \"SEA_ID\",\"SRC_ID\",\"PLG_ID_PLG_ID\",\"INF_VALUE_NUM\",\"INU_ID_INU_ID\",\"IVA_LINE_NUM\" order by \"IVA_CREA_DATE\" DESC ) - first_value(\"IVA_CREA_DATE\") over(partition by \"SEA_ID\",\"SRC_ID\",\"PLG_ID_PLG_ID\",\"INF_VALUE_NUM\",\"INU_ID_INU_ID\",\"IVA_LINE_NUM\" order by \"IVA_CREA_DATE\" ASC ))) diff_sec,\n"
"              (CAST(first_value(\"IVA_VALUE\") over(partition by \"SEA_ID\",\"SRC_ID\",\"PLG_ID_PLG_ID\",\"INF_VALUE_NUM\",\"INU_ID_INU_ID\",\"IVA_LINE_NUM\" order by \"IVA_CREA_DATE\" DESC ) as float) - CAST(first_value(\"IVA_VALUE\") over(partition by \"SEA_ID\",\"SRC_ID\",\"PLG_ID_PLG_ID\",\"INF_VALUE_NUM\",\"INU_ID_INU_ID\",\"IVA_LINE_NUM\" order by \"IVA_CREA_DATE\" ASC ) as float)) diff_value\n"
"              --first_value(\"IVA_VALUE\") over(partition by \"SEA_ID\",\"SRC_ID\",\"PLG_ID_PLG_ID\",\"INF_VALUE_NUM\",\"INU_ID_INU_ID\",\"IVA_LINE_NUM\" order by \"IVA_CREA_DATE\" DESC ) max_value,\n"
"              --first_value(\"IVA_VALUE\") over(partition by \"SEA_ID\",\"SRC_ID\",\"PLG_ID_PLG_ID\",\"INF_VALUE_NUM\",\"INU_ID_INU_ID\",\"IVA_LINE_NUM\" order by \"IVA_CREA_DATE\" ASC ) min_value\n"
"            FROM\n"
"              (\n"
"                SELECT\n"
"                    iva.\"IVA_ID\",\n"
"                    iva.\"IVA_LINE_NUM\",\n"
"                    iva.\"IVA_CREA_DATE\",\n"
"                    iva.\"IVA_AST_AST_ID\",\n"
"                    iva.\"SEA_ID\",\n"
"                    iva.\"SRC_ID\",\n"
"                    iva.\"PLG_ID_PLG_ID\",\n"
"                    iva.\"INF_VALUE_NUM\",\n"
"                    iva.\"IVA_VALUE\",\n"
"                    iva.\"INU_ID_INU_ID\",\n"
"                    iva.\"IVA_SLO_SLO_ID\",\n"
"                    \"IVA_LOT_NUM\"\n"
"                  FROM \"T_INFORMATION_VALUE_IVA\" iva\n"
"                  WHERE\n"
"                    \"SEA_ID\" = $1\n"
"                    AND \"SRC_ID\" = $2\n"
"                    AND \"PLG_ID_PLG_ID\" = $3\n"
"                    AND \"INF_VALUE_NUM\" = $4\n"
"                    AND \"INU_ID_INU_ID\"  = $5\n"
"                    AND \"IVA_STATE\" = 1 /* $6 lot number : aucun sens pour le calcul de moyenne */\n"
"                    AND \"IVA_LINE_NUM\" = $8 /* on a besoin de savoir à quelle ligne ça appartient sinon on mélange tout, ici eth0 */\n"
"                    /*AND (\"IVA_VALUE\" ~ '^[0-9]+$')*/\n"
"                    AND \"IVA_AST_AST_ID\" = $9\n"
"                    AND \"IVA_CREA_DATE\" <= (SELECT \"IVA_CREA_DATE\" FROM \"T_INFORMATION_VALUE_IVA\" WHERE \"IVA_ID\" = $11)\n"
"                  ORDER BY \"IVA_ID\" DESC\n"
"                  LIMIT $10\n"
"              ) sr\n"
"          ) sr_sr\n"
"     WHERE diff_sec != 0\n"
"     ORDER BY \"IVA_ID\" DESC\n"
"     LIMIT 1;\n"
" $BODY$\n"
"   LANGUAGE sql VOLATILE\n"
"   COST 100;"
        );

        transaction.commit();
    }
    catch (Wt::Dbo::Exception e)
    {
        Wt::log("error") << e.what();
    }

    try 
    {
        Wt::Dbo::Transaction transaction(session);

        Wt::log("info") << "Calculate CPU IVA Function Creation";
        
        session.execute
        (
" CREATE OR REPLACE FUNCTION calculate_cpu_iva(integer, integer, integer, integer, integer, integer, integer, integer, integer, integer, integer)\n"
"   RETURNS void AS\n"
" $BODY$\n"
"   INSERT INTO \"T_INFORMATION_VALUE_IVA\"\n"
"     (\n"
"       \"version\",\n"
"       \"IVA_VALUE\",\n"
"       \"IVA_CREA_DATE\",\n"
"       \"IVA_LINE_NUM\",\n"
"       \"IVA_LOT_NUM\",\n"
"       \"IVA_STATE\",\n"
"       \"IVA_AST_AST_ID\",\n"
"       \"IVA_SLO_SLO_ID\",\n"
"       \"SEA_ID\",\n"
"       \"SRC_ID\",\n"
"       \"PLG_ID_PLG_ID\",\n"
"       \"INF_VALUE_NUM\",\n"
"       \"INU_ID_INU_ID\"\n"
"     )\n"
"     SELECT\n"
"         0 \"version\",\n"
"         (\n"
"           CAST ((\"WORK_JIFFIES\" - \"WORK_LAG_JIFFIES\")  AS FLOAT)\n"
"           /\n"
"           CAST ((\"TOTAL_JIFFIES\" - \"TOTAL_LAG_JIFFIES\") AS FLOAT)\n"
"           *\n"
"          100\n"
"         )\n"
"         \"IVA_VALUE\", -- CPU Usage\n"
"         \"IVA_CREA_DATE\",\n"
"         $8 \"IVA_LINE_NUM\",\n"
"         $6 \"IVA_LOT_NUM\",\n"
"         0 \"IVA_STATE\",\n"
"         $9 \"IVA_AST_AST_ID\",\n"
"         \"IVA_SLO_SLO_ID\",\n"
"         $1 \"SEA_ID\",\n"
"         $2 \"SRC_ID\",\n"
"         $3 \"PLG_ID_PLG_ID\",\n"
"         -1 \"INF_VALUE_NUM\",\n"
"         7 \"INU_ID_INU_ID\"\n"
"       FROM\n"
"         (\n"
"           SELECT\n"
"               (\n"
"                 CAST(\"USER\" as bigint)\n"
"                 + CAST(\"NICE\" as bigint)\n"
"                 + CAST(\"SYSTEM\" as bigint)\n"
"                 + CAST(\"IDLE\" as bigint)\n"
"                 + CAST(\"IOWAIT\" as bigint)\n"
"                 + CAST(\"IRQ\" as bigint)\n"
"                 + CAST(\"SOFT_IRQ\" as bigint)\n"
"               ) \"TOTAL_JIFFIES\",\n"
"               (\n"
"                 CAST(\"USER\" as bigint)\n"
"                 + CAST(\"NICE\" as bigint)\n"
"                 + CAST(\"SYSTEM\" as bigint)\n"
"               ) \"WORK_JIFFIES\",\n"
"               \"IVA_CREA_DATE\",\n"
"               (\n"
"                 CAST(\"LAG_USER\" as bigint)\n"
"                 + CAST(\"LAG_NICE\" as bigint)\n"
"                 + CAST(\"LAG_SYSTEM\" as bigint)\n"
"                 + CAST(\"LAG_IDLE\" as bigint)\n"
"                 + CAST(\"LAG_IOWAIT\" as bigint)\n"
"                 + CAST(\"LAG_IRQ\" as bigint)\n"
"                 + CAST(\"LAG_SOFT_IRQ\" as bigint)\n"
"               ) \"TOTAL_LAG_JIFFIES\",\n"
"               (\n"
"                 CAST(\"LAG_USER\" as bigint)\n"
"                 + CAST(\"LAG_NICE\" as bigint)\n"
"                 + CAST(\"LAG_SYSTEM\" as bigint)\n"
"               ) \"WORK_LAG_JIFFIES\",\n"
"               \"LAG_DATE\",\n"
"               \"IVA_SLO_SLO_ID\"\n"
"             FROM\n"
"               (\n"
"                 SELECT\n"
"                     \"IVA_AST_AST_ID\",\n"
"                     \"IVA_CREA_DATE\",\n"
"                     \"LAG_DATE\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 1) THEN \"IVA_VALUE\" END) AS \"INTERFACE_NAME\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 2) THEN \"IVA_VALUE\" END) AS \"USER\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 3) THEN \"IVA_VALUE\" END) AS \"NICE\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 4) THEN \"IVA_VALUE\" END) AS \"SYSTEM\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 5) THEN \"IVA_VALUE\" END) AS \"IDLE\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 6) THEN \"IVA_VALUE\" END) AS \"IOWAIT\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 7) THEN \"IVA_VALUE\" END) AS \"IRQ\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 8) THEN \"IVA_VALUE\" END) AS \"SOFT_IRQ\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 1) THEN \"LAG_VALUE\" END) AS \"LAG_INTERFACE_NAME\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 2) THEN \"LAG_VALUE\" END) AS \"LAG_USER\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 3) THEN \"LAG_VALUE\" END) AS \"LAG_NICE\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 4) THEN \"LAG_VALUE\" END) AS \"LAG_SYSTEM\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 5) THEN \"LAG_VALUE\" END) AS \"LAG_IDLE\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 6) THEN \"LAG_VALUE\" END) AS \"LAG_IOWAIT\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 7) THEN \"LAG_VALUE\" END) AS \"LAG_IRQ\",\n"
"                     max (CASE WHEN (sr_sr.\"INF_VALUE_NUM\" = 8) THEN \"LAG_VALUE\" END) AS \"LAG_SOFT_IRQ\",\n"
"                     min (\"IVA_SLO_SLO_ID\") \"IVA_SLO_SLO_ID\"\n"
"                   FROM\n"
"                     (\n"
"                       SELECT\n"
"                           \"IVA_ID\",\n"
"                           \"IVA_CREA_DATE\",\n"
"                           lag (\"IVA_CREA_DATE\") OVER (PARTITION BY \"IVA_AST_AST_ID\", \"SEA_ID\", \"SRC_ID\", \"PLG_ID_PLG_ID\", \"INF_VALUE_NUM\" ORDER BY \"IVA_ID\") \"LAG_DATE\",\n"
"                           \"IVA_VALUE\",\n"
"                           lag (\"IVA_VALUE\") OVER (PARTITION BY \"IVA_AST_AST_ID\", \"SEA_ID\", \"SRC_ID\", \"PLG_ID_PLG_ID\", \"INF_VALUE_NUM\" ORDER BY \"IVA_ID\") \"LAG_VALUE\",\n"
"                           \"SEA_ID\",\n"
"                           \"SRC_ID\",\n"
"                           \"PLG_ID_PLG_ID\",\n"
"			    \"INF_VALUE_NUM\",\n" 
"                           \"IVA_AST_AST_ID\",\n"
"                           \"IVA_LINE_NUM\",\n"
"                           \"IVA_LOT_NUM\",\n"
"                           \"IVA_SLO_SLO_ID\"\n"
"                         FROM \"T_INFORMATION_VALUE_IVA\" iva\n"
"                         WHERE\n"
"                           \"SEA_ID\" = $1\n"
"                           AND \"SRC_ID\" = $2\n"
"                           AND \"IVA_LOT_NUM\" IN\n"
"                             (\n"
"                               $6,\n"
"                               (\n"
"                                 SELECT \"IVA_LOT_NUM\"\n"
"                                   FROM \"T_INFORMATION_VALUE_IVA\"\n"
"                                   WHERE\n"
"                                     \"SEA_ID\" = $1\n"
"                                     AND \"SRC_ID\" = $2\n"
"                                     AND \"IVA_LINE_NUM\" = $8\n"
"                                     AND \"PLG_ID_PLG_ID\" = $3\n"
"                                     AND \"INF_VALUE_NUM\" = $4\n"
"                                     /*AND \"INU_ID_INU_ID\" = 0*/\n"
"                                     AND \"IVA_AST_AST_ID\" = $9\n"
"                                     AND \"IVA_CREA_DATE\" <= (SELECT \"IVA_CREA_DATE\" FROM \"T_INFORMATION_VALUE_IVA\" WHERE \"IVA_ID\" = $11)\n"
"                                   ORDER BY \"IVA_ID\" DESC\n"
"                                   LIMIT 1\n"
"                                   OFFSET 1\n"
"                               )\n"
"                             )\n"
"                           AND \"IVA_CREA_DATE\" <= (SELECT \"IVA_CREA_DATE\" FROM \"T_INFORMATION_VALUE_IVA\" WHERE \"IVA_ID\" = $11)\n"
"                           AND \"IVA_LINE_NUM\" = $8\n"
"                           AND \"PLG_ID_PLG_ID\" = $3\n"
"                           AND \"IVA_AST_AST_ID\" = $9\n"
"                         ORDER BY \"IVA_ID\" DESC\n"
"                         LIMIT 8\n"
"                     ) sr_sr\n"
"                   WHERE \"IVA_LOT_NUM\" = $6\n"
"                   GROUP BY \"IVA_AST_AST_ID\", \"IVA_CREA_DATE\", \"LAG_DATE\"\n"
"                ) sr_sr_sr\n"
"          ) sr_sr_sr_sr;\n"
" $BODY$\n"
"   LANGUAGE sql VOLATILE\n"
"   COST 100;"

        );

        transaction.commit();
    }
    catch (Wt::Dbo::Exception e)
    {
        Wt::log("error") << e.what();
    }

    return 0;
}

