<?php
$x=$_GET['folder'];$file;
foreach(glob($x."*") as $file)
{
$file=trim($file);
$l=strlen($file);

for($i=$l-1;$i>=0;$i--)
{
if($file[$i]=='/')
break;
}
$file1="";
for($i++;$i<$l;$i++)
$file1=$file1.$file[$i];
echo "<div><div class='folder_hover' style='margin:0;padding:0;overflow-x:hidden'><span style='display:none' >$file</span><button style='overflow-x:hidden' value='0' class='scrol_but' onclick='call_dir(\"$file\",this)' onmouseover='change_onhover(this)' onmouseout='change_onout(this)'><img src='../images/close_folder.jpg'></img></button><img style='overflow-x:hidden' src='../images/folder.jpg'></img><button style='overflow-x:hidden' class='butt'onclick='select(this)' value='0'>$file1</button></div></div>";
}

//echo "<button onclick='call_dir(\"$file/..\")'>back</button><br>"; 	
?>