<?php
    //koneksi ke database
    $koneksi = mysqli_connect("localhost","root","","monitoringtanah");

    //baca tb_sensor
    $sql = mysqli_query($koneksi,"SELECT * FROM tb_sensor" );

    //ambil nilai dari tb_sensor
    $data = mysqli_fetch_array($sql);
    //ambil nilai field sensdor
    $nilai_sensor = $data['sensor'];

    //uji nilai
    $voltage = $nilai_sensor * (5/1023);
    $angkaformat = number_format($voltage,2,".");
?>

<h1 style = "font-size:30px;" ><?php echo $angkaformat;?> </h1>
