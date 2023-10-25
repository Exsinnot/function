<?php
    require 'conn.php';
    if ($_POST['Gender'] == "Other"){
        $gender = $_POST['GenderOther'];
    }
    else{
        $gender = $_POST['Gender'];
    }
    
    
    $sql2 = "SELECT * FROM `member` WHERE `user` LIKE '".$_POST['Username']."'";
    $re = mysqli_query($conn,$sql2);
    if (mysqli_num_rows($re) > 0){
        echo "<script>
            alert('User นี้ใช้ไปแล้ว')
            history.back()
        </script>";
    }
    $sql = "INSERT INTO member VALUES('".$_POST['Username']."','".$_POST['FirstName']."','".$_POST['LastName']."','".$gender."','".$_POST['Birthday']."','".$_POST['Gmail']."','".$_POST['Phone']."','".$_POST['rank']."','".$_POST['job']."','".$_POST['c']."','".$_POST['c++']."','".$_POST['Python']."','".$_POST['Java']."','".$_POST['JS']."','".$_POST['HTML']."','".$_POST['CSS']."','".$_POST['PHP']."')";
    mysqli_query($conn, $sql);
    header("Location:https://exsinnot.com/AddData.html");
?>