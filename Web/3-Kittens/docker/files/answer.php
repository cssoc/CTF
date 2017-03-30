
  <link rel="stylesheet" type="text/css" href="css/style.css" />
<?php
session_start();
if(!isset($_SESSION['login_user']))
{
	header("Location:index.php");
}
$url = $_POST['url'];

$account = $_SESSION['account'];

if($_POST['user'] != "AmericanNumber1")
	fail();

$valid1 = "#<a href=\".*?transfer\.php\?amount=[1-9][0-9]{3,}&account={$account}\">Cute Kittens<\/a>#";
$valid2 = "#<a href=\".*?transfer\.php\?account={$account}&amount=[1-9][0-9]{3,}\">Cute Kittens<\/a>#";

if(preg_match($valid1, $url) or preg_match($valid2, $url))
	success();
else
	fail();

function success()
{
	echo 'Congratulations! Here\'s the flag: goosfraba';
	exit(0);
}

function fail()
{
	echo 'Message successfully sent. <a href="profile.php>Go back.</a>';
	exit(0);
}
?>
