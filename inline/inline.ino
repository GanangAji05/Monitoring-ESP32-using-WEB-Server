#include <WiFi.h>

const char* ssid = "MIRACLE-";
const char* pass = "ganjuranrt1";

String IPAddr = "192.168.100.202";

WiFiServer server(80);

int SensorPin = 34;
int Tanah;

void setup() {
  Serial.begin(9600);
  Serial.println("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..! ");
  Serial.print("Got IP : ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println("HTTPS server started");
}

void loop() {

  Tanah = analogRead(SensorPin);
  int Convert = map(Tanah,0,4095,0,1023);
  float voltage = Convert * (5.0/1023.0);
  Serial.print("VOLT : ");
  Serial.println(voltage);
  Serial.print("ADC : ");
  Serial.println(Convert);
  Serial.print("Kondisi Tanah : ");
  String html = "<html><body>";
  if (Convert > 500){
    html += "<h1>Kering</h1>";
    Serial.println("Kering");
  }
  else {
    html += "<h1>Basah</h1>";
    Serial.println("Basah");
  }
  delay(1000);

  WiFiClient client = server.available();
  
  if (client) {
    // Tampilkan suhu dalam halaman HTML
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Refresh: 10");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("<meta charset='utf-8'>");
    client.println("<meta name='viewport' content='width=device-width, initial-scale=1'>");
    client.println("<title>Monitoring Kelembaban Tanah</title>");
    client.println("<link href='https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css' rel='stylesheet' integrity='sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN' crossorigin='anonymous'>");
    client.println("</head>");
    client.println("<body>");
    client.println("<div class = 'container' style = 'text-align:center; margin-top:100px;' >");
    client.println("<img src='https://www.uny.ac.id/sites/default/files/inline-images/logo-uny.png' alt='logo' style = 'width:130px'>");
    client.print("<h1>");
    client.print("MONITORING KELEMBABAN TANAH ");
    client.print("<br>");
    client.print("DENGAN WEB SERVER");
    client.print("</h1>");
    client.print("<p>");
    client.print("-- Menggunakan Sensor Soil Moisture --");
    client.print("</p>");
    client.print("</div>");
    //HTML KOLOM

    //AWAL KOLOM 1
    client.print("<div class='container text-center'>");
    client.print("<div class='row align-items-start'>");
    client.print(" <div class='col'>");
    client.print(" <div class='card'>");
    client.print(" <div class='card-header' style = 'background-color:Blue; color:white;'>");
    client.print(" <h1 style = 'font-size:24px;' >");
    client.print("ADC");
    client.print("</h1>");
    client.print("</div>");
    client.print("<div class='card-body'>");
    client.print(Convert);
    client.print("</div>");
    client.print("</div>");
    client.print("</div>");
    //AKHIR KOLOM 1
    
    //AKHIR KOLOM 2
    client.print("<div class='container text-center'>");
    client.print("<div class='row align-items-start'>");
    client.print(" <div class='col'>");
    client.print(" <div class='card'>");
    client.print(" <div class='card-header' style = 'background-color:Red; color:white;'>");
    client.print(" <h1 style = 'font-size:24px;' >");
    client.print("ADC");
    client.print("</h1>");
    client.print("</div>");
    client.print("<div class='card-body'>");
    client.print(voltage);
    client.print("</div>");
    client.print("</div>");
    client.print("</div>");
    //AKHIR KOLOM 2

    //AWAL KOLOM 3
    client.print("<div class='container text-center'>");
    client.print("<div class='row align-items-start'>");
    client.print(" <div class='col'>");
    client.print(" <div class='card'>");
    client.print(" <div class='card-header' style = 'background-color:Black; color:white; '>");
    client.print(" <h1 style = 'font-size:24px;' >");
    client.print("ADC");
    client.print("</h1>");
    client.print("</div>");
    client.print("<div class='card-body'>");
    client.print(html);
    client.print("</div>");
    client.print("</div>");
    client.print("</div>");
    client.print("</div>");
    client.print("</div>");
    client.print("<script src= 'https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js' integrity='sha384-C6RzsynM9kWDrMNeT87bh95OGNyZPhcTNXj1NW7RuBCsyN/o0jlpcV8Qyq46cDfL' crossorigin='anonymous'>");
    client.print("</script>");
    client.println("</body>");
    client.println("</html>");
    //AKHIR KOLOM 3

    // Tunggu sebentar dan tutup koneksi
    delay(10);
    client.stop();
  }
  

}
