<!DOCTYPE html>
<html lang="en">
	<head>

		<title>Prize</title>

	    <!-- Bootstrap core CSS -->
		<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
		
	</head>

	<body>
	
	<?php
		session_start();
	
		if(isset($_SESSION['flag'])){
	?>

		<div class="container">
			<div class="page-header">
				<h1>Congratulations!!</h1>
			</div>

			<div class="jumbotron">
				<h1>Here's the flag</h1> 
				<p><?php echo $_SESSION['flag']; ?></p>
    		</div>

		</div> <!-- /container -->
		
	<?php
		}else{
	?>

		<div class="container">
			<div class="page-header">
				<h1>Hmmmm.......</h1>
				<p>Try again</p>
			</div>
		</div> <!-- /container -->
	
	<?php
			session_destroy();
		}
	?>

	</body>
</html>

