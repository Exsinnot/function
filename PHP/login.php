<?php
  require 'conn.php';
  session_start();
  $xmlString = file_get_contents('php://input');
  $xml = json_decode($xmlString); //send from xmlHttp

  $username2 = (string) $xml->username;
  $password2 = (string) $xml->password;
  $sql2 = "SELECT * FROM `user` WHERE `user` LIKE '$username2'";
  $re = mysqli_query($conn,$sql2);
  if (mysqli_num_rows($re) > 0){
    if(mysqli_fetch_array($re)['pass'] == $password2){
        $_SESSION['username'] = $username2;
        echo "true";
    }
    else{
        echo "false";
    }
  }
  else{
    echo "not found";
  }
  
?>
