#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "MIRACLE-";
const char* pass = "ganjuranrt1";

String IPAddr = "192.168.100.202";

WiFiServer server(80);
WiFiClient NodeMCU;

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
  // if (!NodeMCU.connect(IPAddr , 80))
  // {
  //   Serial.println(" Gagal terhubung ke web server");
  //   return;
  // }

  Tanah = analogRead(SensorPin);
  int Convert = map(Tanah,0,4095,0,1023);
  float voltage = Convert * (5.0/1023.0);
  Serial.print("VOLT : ");
  Serial.println(voltage);
  Serial.print("ADC : ");
  Serial.println(Convert);
  Serial.print("Kondisi Tanah : ");
  if (Convert > 500){
    Serial.println("Kering");
  }
  else {
    Serial.println("Basah");
  }
  delay(1000);

  //kirim data 
  HTTPClient http;
  String url = "http://"+IPAddr+"/monitoringtanah/kirimdata.php?sensor=" + String(Convert);

  //ekseskusi link
  http.begin(NodeMCU,url);
  
  //mode GET
  http.GET();
  //akhir proses
  http.end();

}
