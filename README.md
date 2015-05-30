# mysqlstr


## Introduction

a php extension provide string processing of mysql
(strtolower && strtoupper base utf8)

把mysql里的字符串处理函数封装成php扩展，供php使用

目前只提供了utf8下的大写转小写以及小写转大写这两个功能

## Why need this php ext



-	the result of strtolower(strtoupper) is different between php and mysql
-	 efficiency

写这个扩展的目的有两个，一个是php的大小写转换函数和mysql的有一些区别，另外一个是性能问题

##Installation

    $ /path/to/phpize
	$ ./configure --with-php-config=/path/to/php-config
	$ make 
	$ make install

	add extension=mysqlstr.so in php.ini

## Interface

### strtoupper\_utf8_ext 

strtoupper\_utf8_ext - make a utf8 string uppercase

Description

	string strtoupper_utf8_ext(string str)

### strtolower\_utf8_ext 

strtolower\_utf8_ext - make a utf8 string lowercase

Description
    
	string strtolower_utf8_ext(string str)

## Example

case

    $str = "High School D×DⅡ ";

	$timeMB = microtime(true);
	$resMb = mb_strtolower( $str, "UTF-8");
	$timeMB = microtime(true) - $timeMB;

	$timeSQL = microtime(true);
	$resSQL = strtolower_utf8_ext($str);
	$timeSQL = microtime(true) - $timeSQL;

	echo "mbTime:" . sprintf("%.5f",$timeMB)." \n";
	echo "sqlTime:" . sprintf("%.5f",$timeSQL)."\n";

	echo "mbRes:" . $resMb . "\n";
	echo "sqlRes:" . $resSQL . "\n";

result

	mbTime:0.00004
	sqlTime:0.00001
	mbRes:high school d×dⅡ
	sqlRes:high school d×dⅱ

efficiency case

	$str = "High School D×DⅡ ";

	$timeMB = microtime(true);
	for($i=0;$i<30000;$i++)
    	$resMb = mb_strtolower( $str, "UTF-8");
	$timeMB = microtime(true) - $timeMB;

	$timeSQL = microtime(true);
	for($i=0;$i<30000;$i++)
    	$resSQL = strtolower_utf8_ext($str);
	$timeSQL = microtime(true) - $timeSQL;

	echo "mbTime: " . sprintf("%.5f",$timeMB)." \n";
	echo "sqlTime: " . sprintf("%.5f",$timeSQL)."\n";

result:

	mbTime: 0.18481
	sqlTime: 0.01055

## More
	
String processing of mysql base [mysql-5.1.74](https://github.com/mysql/mysql-server )

More related analysis base Chinese is [here](http://redfoxli.github.io/lower-diff-between-php-and-mysql.html)
