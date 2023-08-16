<?php
	$myfile = fopen("status.txt", "w");
	$password1 = $_POST['password1'];
	$password1 = trim($_POST['password1']);
	
	$password2 = $_POST['password2'];
	$password2 = trim($_POST['password2']);
	
	$password3 = $_POST['password3'];
	$password3 = trim($_POST['password3']);
	
	$password4 = $_POST['password4'];
	$password4 = trim($_POST['password4']);
	
	// Check the password against a predefined password
	$correct_password1 = "amgad";
	$correct_password2= "fawzy";
	$correct_password3= "amr";
	$correct_password4= "gamal";
	
	if ($password1 == $correct_password1) 
	{
		fwrite($myfile, '1');
		/*write signed in*/
		header("Location: index_Amgad.html");
	}
	else if ($password2 == $correct_password2)
	{
		fwrite($myfile, '2');
		/*write signed in*/
		header("Location: index_Fawzy.html");
	}
	else if ($password3 == $correct_password3)
	{
		fwrite($myfile, '3');
		/*write signed in*/
		header("Location: index_Amr.html");
	}
	else if ($password4 == $correct_password4)
	{
		fwrite($myfile, '4');
		/*write signed in*/
		header("Location: index_Gamal.html");
	}
	
	else 
	{
		echo "Password is incorrect!";
	}
	/*close file*/
	fclose($myfile);
?>