<?php
    //koneksi ke database
    $koneksi = mysqli_connect("localhost","root","","monitoringtanah");

    //baca tb_sensor
    $sql = mysqli_query($koneksi,"SELECT * FROM tb_sensor" );

    //ambil nilai dari tb_sensor
    $data = mysqli_fetch_array($sql);
    //ambil nilai field sensdor
    $nilai_sensor = $data['sensor'];
?>

<h1 style = "font-size:30px;" ><?php echo $nilai_sensor;?> </h1>