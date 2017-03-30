<?php
session_start(); // Starting Session
// Define $username and $password
$username=$_POST['username'];
$password=$_POST['password'];
$servername = "localhost";
$dbusername = "challenger"; 
$dbpassword = "eirnhei";
$db = "db";
$conn = new mysqli($servername, $dbusername, $dbpassword,$db);

// SQL query to fetch information of registerd users and finds user match.
$query = "SELECT * FROM users WHERE username='".$_POST['username']."' AND password='".$_POST['password']."'";
$result = $conn->query($query);
if ($result->num_rows >0)
{
	$_SESSION['login_user']=$username; // Initializing Session
	header("Location: profile.php"); // Redirecting To Other Page
	exit;
} 
else 
{
	echo "Username or Password is invalid";
}
mysql_close($conn);