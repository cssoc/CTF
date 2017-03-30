
<?php
session_start();
if(!(isset($_SESSION['login_user']) and $_SESSION['priv'] == 1))
{
	header("Location: index.php");
	exit;
}
?>
<!DOCTYPE html>
<html>
<head>
<title>Your Home Page</title>
</head>
<body>

<b>Welcome, <i><?php echo $_SESSION['login_user'] ?></i></b> </br>
<b>Flag: bamboozled</b>
<b><a href="logout.php">Log Out</a></b>
<b><a href="newpassword.php">Change password</a></b>

</body>
</html>
