<?php
session_start();
if($_SESSION['user_role'])
{
if($_SESSION['user_role']=='admin')
echo "hey admin!";
else
echo "Access denied!";
}
else
echo "u need to log in first";
?>