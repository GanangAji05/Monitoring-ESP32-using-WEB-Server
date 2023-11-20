<?php
    //koneksi ke database
    $koneksi = mysqli_connect("localhost","root","","monitoringtanah");

    $nilai_sensor = $_GET['sensor'];
    
    mysqli_query ($koneksi,"UPDATE tb_sensor SET sensor ='$nilai_sensor'");
?>