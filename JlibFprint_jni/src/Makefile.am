#######################################
# The list of libraries we are building seperated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
lib_LTLIBRARIES = libfprint_jni.la

#######################################
# Build information for each library

AUTOMAKE_OPTIONS = gnu

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs libfprint`

# whatever flags you want to pass to the C compiler & linker
AM_CFLAGS = --pedantic -Wall -std=c99 -O2
AM_LDFLAGS = -lm $(LDLIBSOPTIONS)

# Sources
libfprint_jni_la_SOURCES = \
	jlibfprint_JlibFprint.cpp   \
	jlibfprint_Device.cpp       \
	jlibfprint_DiscoveredDevice.cpp     \
	jlibfprint_DiscoveredDeviceList.cpp \
	jlibfprint_PrintData.cpp    \
	jlibfprint_Driver.cpp       \
	jlibfprint_EnrollResult.cpp \
	jlibfprint_Exceptions.cpp   \
	JniUtils.cpp

# Linker options library
libfprint_jni_la_LDFLAGS = -module -avoid-version -shared $(LDLIBSOPTIONS)


# -------------------
# Modify the includes of the project, add you jdk include directory and libfprint includes
ADD_INCLUDES=
# Example
# ADD_INCLUDES=-I/opt/jdk1.7.0_03/include -I/opt/jdk1.7.0_03/include/linux -I../../Downloads/libfprint-0.4.0 -I../../Downloads/libfprint-0.4.0/libfprint/nbis/include
#--------------------

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
libfprint_jni_la_CPPFLAGS = $(CPPFLAGS) $(ADD_INCLUDES)

