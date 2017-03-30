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
	
</head>
<body>
<form method="post" action="changepassword.php">
<label>New Password</label>
<input type="password" name="newPassword">
<label>Confirm Password</label>
<input type="password" name="confirmPassword">
<input type="hidden" name="user" value="<?php echo $_SESSION['login_user']; ?>">
<input type="submit" name="submit" value="Submit">
</form>
</body>
</html>
