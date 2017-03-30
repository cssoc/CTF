
  <link rel="stylesheet" type="text/css" href="css/style.css" />
<?php
session_start();
if(!isset($_SESSION['login_user']))
{
	header("Location: index.php");
	exit;
}

//$account=$_GET['account'];
//$amount=$_GET['amount'];
//
//echo 'Your transfer of '.$amount.' dollars to the account '.$account.' successfully went through.';
echo "ERROR: Insufficient funds in your account";
echo 'Go back to your <a href="profile.php">homepage</a>.';
