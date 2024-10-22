#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
# AC_CONFIG_SRCDIR([src/main.c], [src/argparse.c], [src/MC_Config.c], [src/MC33886.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([subdir-objects])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdint.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_CHECK_FUNCS([memmove memset strtol])
# AC_CHECK_LIB([libbcm2835], [bcm2835_init])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
