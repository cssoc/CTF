<?php
session_start();
if(isset($_SESSION['login_user']))
{
header("Location: profile.php");
exit;
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Log in</title>
    <link rel="stylesheet" type="text/css" href="index.css">

</head>
<body>

       <div id="form1">
           <div>
            <h2>Login</h2>
                <form action="login.php" method="post">
                    <label>Username :</label>
                    <input class="input" name="username" placeholder="username" type="text"></br>
                    <label>Password <span class="point">:</span></label>
                    <input class="input" name="password" placeholder="**********" type="password"></br>
                    <input id="login" name="submit" type="submit" value="Login">
                </form>
            </br>
            </div>
            <center><h1>OR</h1></center>
            <div>
            <h2>Register</h2>
                <form action="register.php" method="post">
                    <label>Username : </label>
                    <input class="input" type="text" name="username"/><br/>
                    <label>Password <span class="point">:</span> </label>
                    <input class="input" type="password" name="password"/><br/>
                    <input id="submit" type="submit" value="Submit"/><br/>
                </form>
            </div>
   <a id="credits" href="credits.html"><button>Credits</button></a>
    <!--
    <div id="credits">
            <p>Adress: xxxxxxx</p>
            <p>Phone:xxx-xxx-xxx</p>
            <p>Special thanks:@leonardoDicaprio</p>

        </div>-->
        </div>


</body>
</html>
