<?php

if (isset($_GET['param1']) && isset($_GET['param2'])) {
    $param1 = $_GET['param1'];
    $param2 = $_GET['param2'];
    echo "Received param1: $param1, param2: $param2";
} else {
    echo "No parameters received";
}
?>
