--TEST--
Check for mysqlstr presence
--SKIPIF--
<?php if (!extension_loaded("mysqlstr")) print "skip"; ?>
--FILE--
<?php

$str = "High School D×DⅡ ";

var_dump(mb_strtolower($str, "UTF-8"));
var_dump(strtolower_utf8_ext($str));
var_dump(mb_strtoupper($str, "UTF-8"));
var_dump(strtoupper_utf8_ext($str));
                                                                                                                                                                                                              
$str = "High School D×Dⅱ ";

var_dump(mb_strtolower($str, "UTF-8"));
var_dump(strtolower_utf8_ext($str));
var_dump(mb_strtoupper($str, "UTF-8"));
var_dump(strtoupper_utf8_ext($str));

$str = "";

var_dump(mb_strtolower($str, "UTF-8"));
var_dump(strtolower_utf8_ext($str));
var_dump(mb_strtolower($str, "UTF-8"));
var_dump(strtolower_utf8_ext($str));

?>
--EXPECT--
string(20) "high school d×dⅡ "
string(20) "high school d×dⅱ "
string(20) "HIGH SCHOOL D×DⅡ "
string(20) "HIGH SCHOOL D×DⅡ "
string(20) "high school d×dⅱ "
string(20) "high school d×dⅱ "
string(20) "HIGH SCHOOL D×Dⅱ "
string(20) "HIGH SCHOOL D×DⅡ "
string(0) ""
string(0) ""
string(0) ""
string(0) ""
