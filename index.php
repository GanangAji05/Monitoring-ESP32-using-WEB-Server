<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Monitoring Kelembaban Tanah</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
    <script type="text/javascript" src="jquery/jquery.min.js"></script>

     <!-- Proses realtime -->

        <script>
            $(document).ready(function(){
              //inverval setting
              setInterval(function(){
                $("#ADC").load("bacaADC.php");
                $("#Volt").load("bacaVolt.php");
                $("#Status").load("bacaStatus.php");
              }, 1000);
              
            });
        </script>

     <!-- Akhir realtime -->

    </head>
  <body>
    <!-- Tampilan Text -->
    <div class = "container" style = "text-align:center; margin-top:100px;" >
        <img src="img/logo-uny.png" alt="logo" style = "width:130px">
        <h1>MONITORING KELEMBABAN TANAH <br> DENGAN WEB SERVER</h1>
        <p>-- Menggunakan Sensor Soil Moisture --</p>
    </div>
    <!-- Tampilan Text -->

    <!-- Awal Kolom -->
    <div class="container text-center">
    <div class="row align-items-start">
    <!-- Tampilan Kolom 1 -->
        <div class="col">
        <div class="card">
        <div class="card-header" style = "background-color:blue; color:white; ">
            <h1 style = "font-size:24px;" > ADC </h1>
        </div>
        <div class="card-body" id = "ADC">
            
        </div>
        </div>
        </div>
    <!-- Tampilan Kolom 1 -->
    
    <!-- Tampilan Kolom 2 -->
        <div class="col">
        <div class="card">
        <div class="card-header" style = "background-color:Red; color:white;">
            <h1 style = "font-size:24px;" > Volt </h1>
        </div>
        <div class="card-body" id = "Volt">
            
        </div>
        </div>
        </div>
    <!-- Tampilan Kolom 2 -->

    <!-- Tampilan Kolom 3 -->
        <div class="col">
        <div class="card">
        <div class="card-header" style = "background-color:black; color:white; ">
            <h1 style = "font-size:24px;"> Status </h1>
        </div>
        <div class="card-body" id = "Status">
            
        </div>
        </div>
        </div>
    <!-- Tampilan Kolom 3 -->
    </div>
        <br><br>
        <h2 style = "font-size:24px;">Ganang Aji Priambodo <br> 21502241029 </h2>
    </div>
    <!-- Akhir Kolom -->

    

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-C6RzsynM9kWDrMNeT87bh95OGNyZPhcTNXj1NW7RuBCsyN/o0jlpcV8Qyq46cDfL" crossorigin="anonymous"></script>
  </body>
</html>