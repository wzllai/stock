/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 321634 2012-01-01 13:15:04Z felipe $ */

#ifndef PHP_STOCK_H
#define PHP_STOCK_H

extern zend_module_entry stock_module_entry;
#define phpext_stock_ptr &stock_module_entry

#ifdef PHP_WIN32
#	define PHP_STOCK_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_STOCK_API __attribute__ ((visibility("default")))
#else
#	define PHP_STOCK_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif
struct _stock_node{
        char *code;
        char *name;
        struct _stock_node *next;
};

typedef struct _stock_node stock;
ZEND_BEGIN_MODULE_GLOBALS(stock)
        stock *list;
ZEND_END_MODULE_GLOBALS(stock)

PHP_MINIT_FUNCTION(stock);
PHP_MSHUTDOWN_FUNCTION(stock);
PHP_RINIT_FUNCTION(stock);
PHP_RSHUTDOWN_FUNCTION(stock);
PHP_MINFO_FUNCTION(stock);

PHP_FUNCTION(stock_extract_code);
PHP_FUNCTION(stock_extract_name);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(stock)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(stock)
*/

/* In every utility function you add that needs to use variables 
   in php_stock_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as STOCK_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define STOCK_G(v) TSRMG(stock_globals_id, zend_stock_globals *, v)
#else
#define STOCK_G(v) (stock_globals.v)
#endif

#endif	/* PHP_STOCK_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
