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
  <title>Your Homepage</title>
  <meta name="description" content="website description" />
  <meta name="keywords" content="website keywords, website keywords" />
  <meta http-equiv="content-type" content="text/html; charset=windows-1252" />
  <link rel="stylesheet" type="text/css" href="css/style.css" />
  <!-- modernizr enables HTML5 elements and feature detects -->
  <script type="text/javascript" src="js/modernizr-1.5.min.js"></script>
</head>

<body>
  <div id="main">
	
    <header>
	  <div id="strapline">
	    <div id="welcome_slogan">
	      <h3>Welcome To Free HTML5 <span>Streets</span></h3>
	    </div><!--close welcome_slogan-->
      </div><!--close strapline-->	  
	  <nav>
	    <div id="menubar">
          <ul id="nav">
            <li><a href="index.php">Home</a></li>
            <li><a href="ourwork.html">Our Work</a></li>
            <li><a href="testimonials.html">Testimonials</a></li>
            <li><a href="projects.html">Projects</a></li>
            <li><a href="contact.html">Contact Us</a></li>
            <li class="current"><a href="profile.php">Profile</a></li>
            <li><a href="logout.php">Log out</a></li>
          </ul>
        </div><!--close menubar-->	
      </nav>
    </header>
	
    <div id="slideshow_container">  
	  <div class="slideshow">
	    <ul class="slideshow">
          <li class="show"><img width="940" height="250" src="images/home_1.jpg" alt="&quot;Enter your caption here&quot;" /></li>
          <li><img width="940" height="250" src="images/home_2.jpg" alt="&quot;Enter your caption here&quot;" /></li>
        </ul> 
	  </div><!--close slideshow-->  	
	</div><!--close slideshow_container-->  	
    
	<div id="site_content">

	  <div class="sidebar_container">       
		<div class="sidebar">
          <div class="sidebar_item">
            <h2>New Website</h2>
            <p>Welcome to our new website. Please have a look around, any feedback is much appreciated.</p>
          </div><!--close sidebar_item--> 
        </div><!--close sidebar-->     		
		<div class="sidebar">
          <div class="sidebar_item">
            <h2>Latest Update</h2>
            <h3>March 2013</h3>
            <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque cursus tempor enim.</p>         
		  </div><!--close sidebar_item--> 
        </div><!--close sidebar-->
		<div class="sidebar">
          <div class="sidebar_item">
            <h3>February 2013</h3>
            <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque cursus tempor enim.</p>         
		  </div><!--close sidebar_item--> 
        </div><!--close sidebar-->  		
        <div class="sidebar">
          <div class="sidebar_item">
            <h2>Contact</h2>
            <p>Phone: +44 (0)1234 567891</p>
            <p>Email: <a href="mailto:info@youremail.co.uk">info@youremail.co.uk</a></p>
          </div><!--close sidebar_item--> 
        </div><!--close sidebar-->
       </div><!--close sidebar_container-->   
	 <div id="content">
        <div class="content_item">
          <b>Welcome, <i><?php echo $_SESSION['login_user'] ?></i></b> </br>
          <p>Your bank account is <?php echo $row['account'];?> and your balance is <?php echo $row['balance'];?></p>
          <p><b>Send a message to a friend</b></p>
          <form action="answer.php" method="post">
          User name:<input type="text" name="user"></br>
          Message:<input type="textarea" rows="4" name="url"></br>
          <input type="submit" value="Send">
          </form>
          <a href="transferform.php"><p>Make a transfer</p></a>
	    </div><!--close content_item-->
      </div><!--close content-->   
	</div><!--close site_content-->  	
    <footer>
	  <a href="index.html">Home</a> | <a href="ourwork.html">Our Work</a> | <a href="testimonials.html">Testimonials</a> | <a href="projects.html">Projects</a> | <a href="contact.html">Contact</a><br/><br/>
	  <a href="http://fotogrph.com">Images</a> |  <a href="http://www.heartinternet.co.uk/vps/">Virtual Server</a>  | website template by <a href="http://www.freehtml5templates.co.uk">Free HTML5 Templates</a>
    </footer>
  </div><!--close main-->
  
  <!-- javascript at the bottom for fast page loading -->
  <script type="text/javascript" src="js/jquery.min.js"></script>
  <script type="text/javascript" src="js/image_slide.js"></script>
  
</body>
</html>
