<?php
$admin_name=$_GET["new_admin"];
$path=$_GET["path"];
$write=$path." ".$admin_name.PHP_EOL;
$file=fopen("admin.txt","a");
fwrite($file,$write);
fclose($file);
echo "admin successfully added !";
?>