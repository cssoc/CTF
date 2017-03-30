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
<title>Flag</title>
</head>
</html>
<body>
<p>Top secret information: the meme is a lie</p>
<a href="logout.php">Logout</a>
<a href="profile.php">Profile</a>
</body>
</html>