/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: honghu069@163.com											 |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_mysqlstr.h"
#include "lib/ctype-utf8.c"

/* If you declare any globals in php_mysqlstr.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(mysqlstr)
*/

/* True global resources - no need for thread safety here */
static int le_mysqlstr;

/* {{{ mysqlstr_functions[]
 *
 * Every user visible function must have an entry in mysqlstr_functions[].
 */
const zend_function_entry mysqlstr_functions[] = {
	PHP_FE(strtoupper_utf8_ext,	NULL)
	PHP_FE(strtolower_utf8_ext,	NULL)
	PHP_FE_END	/* Must be the last line in mysqlstr_functions[] */
};
/* }}} */

/* {{{ mysqlstr_module_entry
 */
zend_module_entry mysqlstr_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"mysqlstr",
	mysqlstr_functions,
	PHP_MINIT(mysqlstr),
	PHP_MSHUTDOWN(mysqlstr),
	PHP_RINIT(mysqlstr),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(mysqlstr),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(mysqlstr),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_MYSQLSTR_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_MYSQLSTR
ZEND_GET_MODULE(mysqlstr)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("mysqlstr.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_mysqlstr_globals, mysqlstr_globals)
    STD_PHP_INI_ENTRY("mysqlstr.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_mysqlstr_globals, mysqlstr_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_mysqlstr_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_mysqlstr_init_globals(zend_mysqlstr_globals *mysqlstr_globals)
{
	mysqlstr_globals->global_value = 0;
	mysqlstr_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(mysqlstr)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(mysqlstr)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(mysqlstr)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(mysqlstr)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(mysqlstr)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "mysqlstr support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */



/* {{{ proto string strtoupper_utf8_ext(string str)
    */
PHP_FUNCTION(strtoupper_utf8_ext)
{
	char *str = NULL;
	int str_len;
	char *dest;
	int dest_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
		return;
	}

	if (str_len <= 0) {
		RETURN_EMPTY_STRING();
		return;
	}

	dest = (char *) safe_emalloc(str_len + 1, sizeof(char), 1);
	dest_len  = str_len;
	dest_len = my_caseup_utf8_ex(str, str_len, dest, dest_len);
	dest[dest_len] = 0;
	RETURN_STRINGL(dest, dest_len, 0);
}
/* }}} */


/* {{{ proto string strtoupper_utf8_ext(string str)
    */
PHP_FUNCTION(strtolower_utf8_ext)
{
	char *str = NULL;
	int str_len;
	char *dest;
	int dest_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
		return;
	}
    
	if (str_len <= 0) {
		RETURN_EMPTY_STRING();
		return;
	}

	dest = (char *) safe_emalloc(str_len + 1, sizeof(char), 1);
	dest_len  = str_len;
	dest_len = my_casedn_utf8_ex(str, str_len, dest, dest_len);
	dest[dest_len] = 0;
	RETURN_STRINGL(dest, dest_len, 0);
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
