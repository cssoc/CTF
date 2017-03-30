<?php  /*  
$servername = "localhost";
$dbusername = "challenger"; 
$dbpassword = "eirnhei";
$db = "db";
$conn = new mysqli($servername, $dbusername, $dbpassword, $db);

    $username = $_POST['username'];
    $password = $_POST['password'];
  
    $query = "SELECT * FROM users WHERE username='".$_POST['username']."'";
    $result = $conn->query($query);

    if ($result->num_rows >0)
    {
        header("location:failregister.php");
        exit;
    }

    $names=file('names.txt');
    $supername = array_pop($names);
    $supername = trim($supername);
    $string = implode("", $names);
    
    file_put_contents('names.txt', $string);

    $addSuper = "INSERT INTO `users` (username, password, privilege, supervisor) VALUES ('$supername', 'sldkvslsd', 1, null )";
    
    $addUser = "INSERT INTO `users` (username, password, privilege, supervisor) VALUES ('$username', '$password', 0, '$supername' )";
    if($conn->query($addSuper) && $conn->query($addUser))
    {
        header("location:registered.php");
        exit;
    }
    else
    {
        header("location:failregister.php");
        exit;
    }
    mysql_close($conn); */
?>
<?php    
$servername = "localhost";
$dbusername = "challenger"; 
$dbpassword = "eirnhei";
$db = "db";
$conn = new mysqli($servername, $dbusername, $dbpassword, $db);

$username = $_POST['username'];
$password = $_POST['password'];

if(!ctype_alnum($_POST['username']))
{
    echo 'Please use only letters and digits.';
}
else
{   
    $stmt = $conn->prepare("SELECT id FROM `users` WHERE username=?");
    $stmt->bind_param("s", $username);
    $stmt->execute();
     /* Store the result (to get properties) */
   $stmt->store_result();

   /* Get the number of rows */
   $num_of_rows = $stmt->num_rows;
   if($num_of_rows!=0)
   {
        header("location:failregister.php");
        exit;
   }
    //$query = "SELECT * FROM users WHERE username='".$_POST['username']."'";

    $authorised = 1;
    $unauthorised = 0;
    $superpass = 'sldkvslsd';
    $none = 'none';

    $names=file('names.txt');
    $supername = array_pop($names);
    $supername = trim($supername);
    $string = implode("", $names);
    
    file_put_contents('names.txt', $string);
    /*ini_set('display_startup_errors', 1);
    ini_set('display_errors', 1);
    error_reporting(-1);
    $addSuper = "INSERT INTO `users` (username, password, privilege, supervisor) VALUES ('$supername', 'sldkvslsd', 1, null )";*/
    $stmt2 = $conn->prepare("INSERT INTO `users` (username, password, privilege, supervisor) VALUES (?,?,?,?)");
    $stmt2->bind_param("ssis", $supername, $superpass, $authorised, $none);
    $stmt3 = $conn->prepare("INSERT INTO `users` (username, password, privilege, supervisor) VALUES (?,?,?,?)");
    $stmt3->bind_param("ssis", $username, $password, $unauthorised, $supername);

    //$addUser = "INSERT INTO `users` (username, password, privilege, supervisor) VALUES ('$username', '$password', 0, '$supername' )";
    if($stmt2->execute() && $stmt3->execute())
    {
        header("location:registered.php");
        exit;
    }
    else
    {
        echo "Registration failed.";
    }
    mysql_close($conn); 
} 
?>
