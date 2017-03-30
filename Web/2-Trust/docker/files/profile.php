
<?php
session_start();
if(!isset($_SESSION['login_user']))
{
	header("Location: index.php");
	exit;
}

$servername = "localhost";
$dbusername = "challenger"; 
$dbpassword = "eirnhei";
$db = "db";
$conn = new mysqli($servername, $dbusername, $dbpassword, $db);

$query = "SELECT * FROM `users` WHERE username = '".$_SESSION['login_user']."'";
$result = $conn->query($query);
$row = $result ->fetch_assoc();
?>

<!DOCTYPE html>
<html>
<head>
<title>Your Home Page</title>
    <link rel="stylesheet" type="text/css" href="profile.css">
   
</head>
<body>
<center>
    <h1><b>Welcome, <i><?php echo $_SESSION['login_user'] ?></i></b></br>
<b>Your supervisor is <i><?php echo $row['supervisor'] ?></i></b></h1> </br>
<b><a href="logout.php">Log Out</a></b></br>
<b><a href="newpassword.php">Change password</a></b>
</center>
</body>
</html>