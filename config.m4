dnl $Id$
dnl config.m4 for extension mysqlstr

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(mysqlstr, for mysqlstr support,
dnl Make sure that the comment is aligned:
[  --with-mysqlstr             Include mysqlstr support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(mysqlstr, whether to enable mysqlstr support,
dnl Make sure that the comment is aligned:
dnl [  --enable-mysqlstr           Enable mysqlstr support])

if test "$PHP_MYSQLSTR" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-mysqlstr -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/mysqlstr.h"  # you most likely want to change this
  dnl if test -r $PHP_MYSQLSTR/$SEARCH_FOR; then # path given as parameter
  dnl   MYSQLSTR_DIR=$PHP_MYSQLSTR
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for mysqlstr files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       MYSQLSTR_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$MYSQLSTR_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the mysqlstr distribution])
  dnl fi

  dnl # --with-mysqlstr -> add include path
  dnl PHP_ADD_INCLUDE($MYSQLSTR_DIR/include)

  dnl # --with-mysqlstr -> check for lib and symbol presence
  dnl LIBNAME=mysqlstr # you may want to change this
  dnl LIBSYMBOL=mysqlstr # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $MYSQLSTR_DIR/lib, MYSQLSTR_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_MYSQLSTRLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong mysqlstr lib version or lib not found])
  dnl ],[
  dnl   -L$MYSQLSTR_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(MYSQLSTR_SHARED_LIBADD)

  PHP_NEW_EXTENSION(mysqlstr, mysqlstr.c, $ext_shared)
fi
