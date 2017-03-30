  <link rel="stylesheet" type="text/css" href="css/style.css" />

<?php
session_start();
if (empty($_POST['username']) || empty($_POST['password']) || !ctype_alnum($_POST['username']))
{
echo "Username and password cannot be empty. Also, please use only letters and numerals for your username.";
}
else
{
$servername = "localhost";
$dbusername = "challenger"; 
$dbpassword = "eirnhei";
$db = "db";
$conn = new mysqli($servername, $dbusername, $dbpassword, $db);

$username = $_POST['username'];
$password = $_POST['password'];
$stmt = $conn->prepare("SELECT id, account FROM users WHERE username=? AND password=?");
$stmt->bind_param("ss", $username, $password);
$stmt->execute();

//$query = "SELECT * FROM users WHERE username='".$_POST['username']."' AND password='".$_POST['password']."'";
$stmt->store_result();

   /* Get the number of rows */
$num_of_rows = $stmt->num_rows;
$stmt->bind_result($id, $account);
if($stmt->fetch())
	if($num_of_rows!=0)
	{
		$_SESSION['login_user']=$username; // Initializing Session
		$_SESSION['account'] = $account;
		header("Location: profile.php"); // Redirecting To Other Page
		exit;
	}
	else 
	{
		echo "Username or Password is invalid";
	}
mysql_close($conn); // Closing Connection
}

?>
