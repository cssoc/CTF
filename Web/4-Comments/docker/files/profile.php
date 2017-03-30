<?php
session_start();
if(!isset($_SESSION['login_user']))
{
	header("Location: index.php");
	exit;
}
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">

<head>
  <title>ARaynorDesign Template</title>
  <meta name="description" content="free website template" />
  <meta name="keywords" content="enter your keywords here" />
  <meta http-equiv="content-type" content="text/html; charset=utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=9" />
  <link rel="stylesheet" type="text/css" href="css/style.css" />
  <script type="text/javascript" src="js/jquery.min.js"></script>
  <script type="text/javascript" src="js/image_slide.js"></script>
</head>

<body>
  <div id="main">
    <div id="header">
	  <div id="banner">
	    <div id="welcome">
	      <h1>Welcome To Leather &amp; Coffee</h1>
	    </div><!--close welcome-->
	    <div id="menubar">
          <ul id="menu">
            <li><a href="index.php">Home</a></li>
            <li><a href="ourwork.html">Our Work</a></li>
            <li><a href="testimonials.html">Testimonials</a></li>
            <li><a href="projects.html">Projects</a></li>
            <li><a href="contact.html">Contact Us</a></li>
            <li class="current"><a href="profile.php">Profile</a></li>
            <li><a href="logout.php">Logout</a></li>
			<li><a href="flag.php">Prize</a></li>
          </ul>
        </div><!--close menubar-->	  
	  </div><!--close banner-->	
    </div><!--close header-->	
	
	<div id="site_content">	
	
      <div class="slideshow">  
		<ul class="slideshow">
          <li class="show"><img width="900" height="350" src="images/home_1.jpg" alt="&quot;Enter your caption here&quot;" /></li>
          <li><img width="900" height="350" src="images/home_2.jpg" alt="&quot;Enter your caption here&quot;" /></li>
        </ul> 
      </div><!--close slideshow-->	 	
	
      <div id="content">
        <div class="content_item">
        </div><!--close content_item-->
      </div><!--close content-->   
	
	</div><!--close site_content--> 

	<div id="content_cream">
	  <div class="content_cream_container_box">
		<h4>Latest Blog Post</h4>
	    <p> Phasellus laoreet feugiat risus. Ut tincidunt, ante vel fermentum iaculis.</p>
		<div class="readmore">
		  <a href="#">Read more</a>
		</div><!--close readmore-->
	  </div><!--close content_cream_container_box-->
      <div class="content_cream_container_box">
       <h4>Latest News</h4>
	    <p> Phasellus laoreet feugiat risus. Ut tincidunt, ante vel fermentum iaculis.</p>
	    <div class="readmore">
		  <a href="#">Read more</a>
		</div><!--close readmore-->
	  </div><!--close content_cream_container_box-->
      <div class="content_cream_container_boxl">
		<h4>Contact Us</h4>
	    <p> Phasellus laoreet feugiat risus. Ut tincidunt, ante vel fermentum iaculis.</p>
	    <div class="readmore">
		  <a href="#">Read more</a>
		</div><!--close readmore-->	  
	  </div><!--close content_cream_container_box1-->      
	  <br style="clear:both"/>
    </div><!--close content_cream-->    
 
  </div><!--close main-->
  
  <div id="footer_container">
    <div id="footer">
	  <a href="http://validator.w3.org/check?uri=referer">Valid XHTML</a> | <a href="http://fotogrph.com/">Images</a> | Heart Internet <a href="http://www.heartinternet.co.uk/web-hosting/">web hosting</a> | website template by <a href="http://www.araynordesign.co.uk">ARaynorDesign</a>
    </div><!--close footer-->  
  </div><!--close footer_container--> 	
  
</body>
</html>
