# this is example-file: configure.ac

# initial information about the project
AC_INIT([libfprint_jni],[1.0])

# check if the source folder is correct
AC_CONFIG_SRCDIR([src/jlibfprint_JlibFprint.cpp])

AC_COPYRIGHT(GNU General Public License)


# Checks for programs

# check for C++ compiler and the library compiler
AC_PROG_CXX
AC_PROG_RANLIB
AC_PROG_CC

# automake initialisation (mandatory) and check for minimal automake API version 1.9
AM_INIT_AUTOMAKE([1.9])

# use the C++ compiler for the following checks
AC_LANG([C++])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([string])
AC_CHECK_HEADERS([iostream])
AC_CHECK_HEADERS([jni])
AC_CHECK_HEADERS([libfprint/fprint.h])

AX_JNI_INCLUDE_DIR
for JNI_INCLUDE_DIR in $JNI_INCLUDE_DIRS
do
      CPPFLAGS="$CPPFLAGS -I$JNI_INCLUDE_DIR"
done


LT_INIT

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

AC_CONFIG_MACRO_DIR([m4])

# distribute additional compiler and linker flags
# --> set these variables instead of CXXFLAGS or LDFLAGS
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])
AC_SUBST([LIBS])

# files to generate via autotools (.am or .in source files)
AC_CONFIG_FILES([
	Makefile
	src/Makefile
])

# generate the final Makefile etc.
AC_OUTPUT

