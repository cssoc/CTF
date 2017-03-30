<?php
session_start();
if(!isset($_SESSION['login_user']))
{
	header("Location: index.php");
	exit;
}
?>

<!DOCTYPE html>
<html>
<head>
  <link rel="stylesheet" type="text/css" href="css/style.css" />
<title>Transfer</title>
</head>
<body>
<form action="transfer.php" method="get">
Account number:<input type="text" name="account"></br>
Amount:<input type="number" name="amount"></br>
<input type="submit" value="Make tranfer">
</form>
</body>
</html>
