<?php
	$options = array("command", "key", "file");
	$secret = "a5f9ej69duzpqR0z"; //16 characters
	$request_para = array_keys($_GET);
	foreach($request_para as $para)
		if(!in_array($para, $options))
		{
			echo "Invalid Request";
			return;
		}

	if($_GET['command'] == "open")
	{
		$query = urldecode($_SERVER['QUERY_STRING']);
		$key = substr($query, 4, 64);
		$request = substr($query, 69);
		$expected = hash("sha256", $secret . $request);
		if($key != $expected)
		{
			echo "Invalid key";
			return;
		}
		else
		{
			if($_GET['file'] == "d27X")
			{
				echo "The flag is: extensionr";
			}
			elseif($_GET['file'] == "info")
			{
				echo "I've hid the information in \"d27X\". Good luck my friend.";
				echo PHP_EOL, "Remember the secret is the 16 character long one.";
			}
			else	echo "Uknown file";
		}
	}
	else
		echo "Unkown command";

?>
