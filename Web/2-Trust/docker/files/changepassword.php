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

$newPassword = $_POST['newPassword'];
$confirmPassword = $_POST['confirmPassword'];
$username = $_POST['user'];

if($_POST['newPassword']!==$_POST['confirmPassword']) 
{
	echo "Passwords do not match";
}
else
{
	$stmt = $conn->prepare("UPDATE `users` SET password=? WHERE username=?");
    $stmt->bind_param("ss", $newPassword, $username);
    
	//$changepass="UPDATE `users` SET password='".$_POST['newPassword']."' WHERE username='".$_POST['user']."'";
	if($stmt->execute())
	{
		echo "Your password has been changed, " . $_POST['user']. "\n";
		echo '<a href="logout.php">Go back to login</a>';
	}
}
?>
