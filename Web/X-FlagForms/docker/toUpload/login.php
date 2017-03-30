<!DOCTYPE html>
<html>
	<head>
		<title>High Tech Company INC</title>

	    <!-- Bootstrap core CSS -->
		<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
	</head>

	<?php
		$servername = "localhost";
		$username = "challenger"; 
		$password = "eirnhei";
		$db_name = "db";
		
		$db = new mysqli($servername, $username, $password, $db_name);

		// Check connection
		if ($db->connect_error) {
		    die("Connection error: (" . $db->connect_errno . ") " . $db->connect_error);
		}

		$query = "SELECT flag FROM `Users` WHERE `username` = '" . $_POST['username'] . "' AND `password_hash` = '" . sha1($_POST['password']) . "'";
		$result = $db->query($query);
		
		if ($result->num_rows <= 0){
			echo "Incorrect Username and Password combination.";
			return;
		}
		
		$row = $result->fetch_array();
		
		$db->close();

		// Login was successful.
		// Enable user session and "log in"
		
		session_start();
		$_SESSION['username'] = $_POST['username'];
		$_SESSION['flag'] = $row['flag'];
		
		// TODO Allow user to access flag somehow.
	?>
	
	<body>
		<ul style="float:left; list-style:none; text-decoration:none;">
			<li><a href="index.html">Logout</a></li>
			<li><a href="flag.php">Prize</a><li>
		</ul>
	</body>
</html>

