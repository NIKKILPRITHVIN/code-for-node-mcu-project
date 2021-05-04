#include <ESP8266WiFi.h>

const char* ssid = "Redmi";
const char* password = "nikkil2008";


const char* host = "maker.ifttt.com";

void setup() 
{
    Serial.begin(115200);
    Serial.println("Email from Node Mcu");
    delay(100);
    delay(1000);

   connectWiFi(); 

}

void loop() 
{                  
      WiFiClient client; 
      const int httpPort = 80;  
      if (!client.connect(host, httpPort)) 
      {  
         Serial.println("connection failed");  
         return;
      } 
      if(Serial.available())
      {           
         char a=Serial.read();           
        
         
         if (a=='y')
        {    
            String url = "/trigger/Nikkil/with/key/n4rkQDomkF2R56YWSmS5UgZjkZ--kVxWlGssBZyMAyk"; 
            Serial.print("Requesting URL: ");
            Serial.println(url);                 
            client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");    
         }                     
          else
          {
            Serial.println("Correct character not pressed.Try again");            
          }
       }          
       delay(1000);  
    while((!(WiFi.status() == WL_CONNECTED)))
    {
      connectWiFi();
    }              
}

void connectWiFi()
{ 
  int i=0;
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while((!(WiFi.status() == WL_CONNECTED)))
  {
    Serial.println(" - "); 
    i++;
    delay(300);
    if( i>10 )    
    { 
     connectWiFi();
    }
   }  
   Serial.println("");
   Serial.println("WiFi connected");
}
