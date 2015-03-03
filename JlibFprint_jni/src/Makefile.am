#######################################
# The list of libraries we are building seperated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
lib_LTLIBRARIES = libfprint_jni.la

#######################################
# Build information for each library

AUTOMAKE_OPTIONS          = gnu

# whatever flags you want to pass to the C compiler & linker
AM_CFLAGS = --pedantic -Wall -std=c99 -O2
AM_LDFLAGS = -lm

# Sources for libTest
libfprint_jni_la_SOURCES = \
	$(srcdir)/jlibfprint_JlibFprint.cpp   \
	$(srcdir)/jlibfprint_Device.cpp       \
	$(srcdir)/jlibfprint_DiscoveredDevice.cpp     \
	$(srcdir)/jlibfprint_DiscoveredDeviceList.cpp \
	$(srcdir)/jlibfprint_PrintData.cpp    \
	$(srcdir)/jlibfprint_Driver.cpp       \
	$(srcdir)/jlibfprint_EnrollResult.cpp \
	$(srcdir)/jlibfprint_Exceptions.cpp   \
	$(srcdir)/JniUtils.cpp

# Linker options library
libfprint_jni_la_LDFLAGS = -module -avoid-version -shared


# -------------------
# Modify the includes of the project, add you jdk include directory and libfprint includes
ADD_INCLUDES=-I/Library/Java/JavaVirtualMachines/jdk1.7.0_71.jdk/Contents/Home/include/darwin/  -I/Library/Java/JavaVirtualMachines/jdk1.7.0_71.jdk/Contents/Home/include -I/Users/kinshuk.bairagi/Documents/learn/libfprint-0.6.0
# Example
# ADD_INCLUDES=-I/opt/jdk1.7.0_03/include -I/opt/jdk1.7.0_03/include/linux -I../../Downloads/libfprint-0.4.0 -I../../Downloads/libfprint-0.4.0/libfprint/nbis/include
#--------------------

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
libfprint_jni_la_CPPFLAGS = $(ADD_INCLUDES)

