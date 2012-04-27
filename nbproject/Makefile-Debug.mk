#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/tools/Session.o \
	${OBJECTDIR}/src/tools/AuthApplication.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/user/UserProfile.o \
	${OBJECTDIR}/src/tools/PostgresConnector.o \
	${OBJECTDIR}/src/user/UserAction.o \
	${OBJECTDIR}/src/tools/Constants.o \
	${OBJECTDIR}/src/information/Value.o \
	${OBJECTDIR}/src/plugin/Plugin.o \
	${OBJECTDIR}/src/tools/Table.o \
	${OBJECTDIR}/src/user/UserValue.o \
	${OBJECTDIR}/src/user/UserRole.o \
	${OBJECTDIR}/src/user/User.o \
	${OBJECTDIR}/src/user/UserField.o \
	${OBJECTDIR}/src/user/HistoricalAction.o \
	${OBJECTDIR}/src/information/Information.o \
	${OBJECTDIR}/src/user/Hierarchy.o \
	${OBJECTDIR}/src/information/HistoricalValue.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lwt -lwtdbo -lwtdbopostgres -lwthttp

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dbo

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dbo: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dbo ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/tools/Session.o: src/tools/Session.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tools
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/tools/Session.o src/tools/Session.cpp

${OBJECTDIR}/src/tools/AuthApplication.o: src/tools/AuthApplication.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tools
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/tools/AuthApplication.o src/tools/AuthApplication.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/user/UserProfile.o: src/user/UserProfile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/user
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/user/UserProfile.o src/user/UserProfile.cpp

${OBJECTDIR}/src/tools/PostgresConnector.o: src/tools/PostgresConnector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tools
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/tools/PostgresConnector.o src/tools/PostgresConnector.cpp

${OBJECTDIR}/src/user/UserAction.o: src/user/UserAction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/user
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/user/UserAction.o src/user/UserAction.cpp

${OBJECTDIR}/src/tools/Constants.o: src/tools/Constants.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tools
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/tools/Constants.o src/tools/Constants.cpp

${OBJECTDIR}/src/information/Value.o: src/information/Value.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/information
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/information/Value.o src/information/Value.cpp

${OBJECTDIR}/src/plugin/Plugin.o: src/plugin/Plugin.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/plugin
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/plugin/Plugin.o src/plugin/Plugin.cpp

${OBJECTDIR}/src/tools/Table.o: src/tools/Table.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tools
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/tools/Table.o src/tools/Table.cpp

${OBJECTDIR}/src/user/UserValue.o: src/user/UserValue.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/user
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/user/UserValue.o src/user/UserValue.cpp

${OBJECTDIR}/src/user/UserRole.o: src/user/UserRole.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/user
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/user/UserRole.o src/user/UserRole.cpp

${OBJECTDIR}/src/user/User.o: src/user/User.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/user
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/user/User.o src/user/User.cpp

${OBJECTDIR}/src/user/UserField.o: src/user/UserField.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/user
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/user/UserField.o src/user/UserField.cpp

${OBJECTDIR}/src/user/HistoricalAction.o: src/user/HistoricalAction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/user
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/user/HistoricalAction.o src/user/HistoricalAction.cpp

${OBJECTDIR}/src/information/Information.o: src/information/Information.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/information
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/information/Information.o src/information/Information.cpp

${OBJECTDIR}/src/user/Hierarchy.o: src/user/Hierarchy.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/user
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/user/Hierarchy.o src/user/Hierarchy.cpp

${OBJECTDIR}/src/information/HistoricalValue.o: src/information/HistoricalValue.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/information
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude/widget -Iinclude/user -Iinclude/unit -Iinclude/tools -Iinclude/probe -Iinclude/plugin -Iinclude/plugin -Iinclude/pack -Iinclude/organization -Iinclude/media -Iinclude/information -Iinclude/asset -Iinclude/alert -Iinclude/addon -Iinclude/primaryKeys -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/information/HistoricalValue.o src/information/HistoricalValue.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dbo

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
