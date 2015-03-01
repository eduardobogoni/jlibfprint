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
CND_CONF=Default
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/jlibfprint_JlibFprint.o  \
	${OBJECTDIR}/jlibfprint_Device.o       \
	${OBJECTDIR}/jlibfprint_DiscoveredDevice.o  \
	${OBJECTDIR}/jlibfprint_DiscoveredDeviceList.o  \
	${OBJECTDIR}/jlibfprint_PrintData.o   \
	${OBJECTDIR}/jlibfprint_Driver.o     \
	${OBJECTDIR}/jlibfprint_EnrollResult.o      \
	${OBJECTDIR}/jlibfprint_Exceptions.o  \
	${OBJECTDIR}/JniUtils.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=$(ADD_INCLUDES)
CXXFLAGS=$(ADD_INCLUDES)

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs libfprint`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libJlibFprint_jni.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libJlibFprint_jni.so: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libJlibFprint_jni.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 


${OBJECTDIR}/jlibfprint_DiscoveredDevice.o: jlibfprint_DiscoveredDevice.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libfprint`    -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/jlibfprint_DiscoveredDevice.o jlibfprint_DiscoveredDevice.cpp


${OBJECTDIR}/jlibfprint_DiscoveredDeviceList.o: jlibfprint_DiscoveredDeviceList.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libfprint`    -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/jlibfprint_DiscoveredDeviceList.o jlibfprint_DiscoveredDeviceList.cpp


${OBJECTDIR}/jlibfprint_PrintData.o: jlibfprint_PrintData.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libfprint`    -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/jlibfprint_PrintData.o jlibfprint_PrintData.cpp


${OBJECTDIR}/jlibfprint_Driver.o: jlibfprint_Driver.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libfprint`    -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/jlibfprint_Driver.o jlibfprint_Driver.cpp


${OBJECTDIR}/jlibfprint_EnrollResult.o: jlibfprint_EnrollResult.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libfprint`    -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/jlibfprint_EnrollResult.o jlibfprint_EnrollResult.cpp


${OBJECTDIR}/jlibfprint_Exceptions.o: jlibfprint_Exceptions.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libfprint`    -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/jlibfprint_Exceptions.o jlibfprint_Exceptions.cpp


${OBJECTDIR}/JniUtils.o: JniUtils.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libfprint`    -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/JniUtils.o JniUtils.cpp

${OBJECTDIR}/jlibfprint_Device.o: jlibfprint_Device.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 `pkg-config --cflags libfprint`    -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/jlibfprint_Device.o jlibfprint_Device.cpp


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libJlibFprint_jni.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
