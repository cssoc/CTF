<!DOCTYPE html>
<html lang="en">
	<head>

		<title>Car Models</title>

	    <!-- Bootstrap core CSS -->
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
		
	</head>

	<body>
	
		<nav class="navbar navbar-default">
			<div class="container-fluid">
				<!-- Brand and toggle get grouped for better mobile display -->
				<div class="navbar-header">
					<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
						<span class="sr-only">Toggle navigation</span>
			        	<span class="icon-bar"></span>
    			    	<span class="icon-bar"></span>
    			    	<span class="icon-bar"></span>
    				</button>
 					<a class="navbar-brand" href="#">Brand</a>
 				</div>

				<!-- Collect the nav links, forms, and other content for toggling -->
				<div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
					<ul class="nav navbar-nav">
						<li class="active"><a href="#">Link <span class="sr-only">(current)</span></a></li>
 	       				<li><a href="#">Link</a></li>
 	       				<li class="dropdown">
	 	         			<a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">
 		         				Dropdown <span class="caret"></span>
							</a>
 		         			<ul class="dropdown-menu">
 		           				<li><a href="#">Action</a></li>
 		           				<li><a href="#">Another action</a></li>
 		           				<li><a href="#">Something else here</a></li>
 		           				<li role="separator" class="divider"></li>
 		           				<li><a href="#">Separated link</a></li>
 		           				<li role="separator" class="divider"></li>
 		           				<li><a href="#">One more separated link</a></li>
 		         			</ul>
 						</li>
					</ul>
					
					<form class="navbar-form navbar-left" action="/index.php" method="GET">
 	       				<div class="form-group">
 	         				<input name="query" type="text" class="form-control" placeholder="Search">
 	       				</div>
 	       				<button type="submit" class="btn btn-default">Search</button>
 	     			</form>
 	     
 	     			<ul class="nav navbar-nav navbar-right">
 	       				<li>
							<button type="button" class="btn btn-default btn-lg" id="myBtn" data-toggle="modal" data-target="#myModal">Login</button>
						</li>
 					</ul>
 					
				</div><!-- /.navbar-collapse -->
			</div><!-- /.container-fluid -->
		</nav>

		<div class="container">
			<div class="page-header">
				<h1>Car Company</h1>
			</div>
			
			<?php
				if($_SERVER['REQUEST_METHOD'] === 'GET' && isset($_GET['query']))
				{
					$servername = "localhost";
					$username = "challenger"; 
					$password = "eirnhei";
					$db_name = "db";
		
					$db = new mysqli($servername, $username, $password, $db_name);

					// Check connection
					if ($db->connect_error) {
						die("Connection error: (" . $db->connect_errno . ") " . $db->connect_error);
					}

					$query = "SELECT brand, value FROM Cars WHERE brand LIKE '%" . $_GET['query'] . "%';";
					$result = $db->query($query);
					
					echo "<table class=\"table\">";
					echo "<thead><tr> <td>Model</td> <td>Value</td> </tr></thead>";
					
					echo "</tbody>";
					while($row = $result->fetch_array())
					{
						echo "<tr>";
						echo "<td>".$row['brand']."</td>";
						echo "<td>".$row['value']."</td>";
						echo "</tr>";
					}
					echo "</tbody>";
					
					echo "</table>";
		
					$db->close();
				}
			?>

			<!--<form class="form-signin">
				<h2 class="form-signin-heading">Please sign in</h2>
				
				<label for="inputEmail" class="sr-only">Username</label>
				<input type="text" id="inputEmail" class="form-control" placeholder="Username" required autofocus>
				
				<label for="inputPassword" class="sr-only">Password</label>
				<input type="password" id="inputPassword" class="form-control" placeholder="Password" required>
				
				<button class="btn btn-lg btn-primary btn-block" type="submit">Sign in</button>
    		</form>-->

			<!-- Modal -->
			<div class="modal fade" id="myModal" role="dialog">
				<div class="modal-dialog">
					<!-- Modal content-->
					<div class="modal-content">
						<div class="modal-header" style="padding:35px 50px;">
							<button type="button" class="close" data-dismiss="modal">&times;</button>
							<h4><span class="glyphicon glyphicon-lock"></span> Login</h4>
						</div>
						<div class="modal-body" style="padding:40px 50px;">
							<form role="form" action="/login.php" method="POST">
								<div class="form-group">
									<label for="usrname"><span class="glyphicon glyphicon-user"></span> Username</label>
									<input name="username" type="text" class="form-control" id="usrname" placeholder="Enter username">
								</div>
								<div class="form-group">
									<label for="psw"><span class="glyphicon glyphicon-eye-open"></span> Password</label>
									<input name="password" type="text" class="form-control" id="psw" placeholder="Enter password">
								</div>
								<button type="submit" class="btn btn-success btn-block"><span class="glyphicon glyphicon-off"></span> Login</button>
							</form>
						</div>
						<div class="modal-footer">
							<button type="submit" class="btn btn-danger btn-default pull-left" data-dismiss="modal">
								<span class="glyphicon glyphicon-remove"></span> Cancel
							</button>
						</div>
					</div>
				</div>
			</div>

		</div> <!-- /container -->
		
	</body>
</html>

