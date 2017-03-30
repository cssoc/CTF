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

		$query = "SELECT * FROM `Users` WHERE `username` = ? AND `password_hash` = ?";
		
		if($stmt = $db->prepare($query)){
			$name = $_POST['username'];
			$pass = sha1($_POST['password']);

			$stmt->bind_param("ss", $name, $pass);

			$stmt->execute();
			$stmt->store_result();

			if ($stmt->num_rows <= 0){
				echo "Incorrect Username and Password combination.";
				return;
			}

				session_start();
				$_SESSION['username'] = $_POST['username'];
	
			$stmt->free_result();
			$stmt->close();
		}else{
			echo "Could not prepare statement";
			return;
		}
		
		$db->close();

		// Login was successful.
		// Enable user session and "log in"
	?>
	
	<body>
		<ul style="float:left; list-style:none; text-decoration:none;">
			<li><a href="index.php">Logout</a></li>
			<li><a href="flag.php">Prize</a><li>
		</ul>
	</body>
</html>

