#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
char auth[] = "";    // Write your Blynk project key here
WidgetLED led1(V1);   // Virtual LED to show status on App
WidgetLED led2(V2);
WidgetLED led3(V3);
int sensor1 = 2;      // IR Sensors
int sensor2 = 3;
int sensor3 = 4;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);         // Starting Blynk server and connecting to the cloud
  
  pinMode(sensor3,INPUT);    // Setting sensors to input
  
  pinMode(sensor2,INPUT);
  
  pinMode(sensor1,INPUT);

  while (Blynk.connect() == false) {
    // Wait until connected
  }
}
 void loop() {  
   int sensorval1 = digitalRead(sensor1); // Saving Values os sensors
   int sensorval2 = digitalRead(sensor2);
   int sensorval3 = digitalRead(sensor3);
   Serial.println(sensorval1);            // printing values 
   Serial.println(sensorval2);
   Serial.println(sensorval3);
   delay(1000);
   if (sensorval1 == 1)
   {
led1.on();                                 // Setting virtual led on the app
}
   if (sensorval2 == 1)
   {
led2.on();
}
   if (sensorval3 == 1)
   {

led3.on();}
    if (sensorval1 == 0)
   {

led1.off();
}
   if (sensorval2 == 0)
   {
led2.off();
}
   if (sensorval3 == 0)
   {
led3.off();
}   
    
    Blynk.run();
    
     }
