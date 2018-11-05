// Sensor
#include <DHT11.h>
int pin=4;
DHT11 dht11(pin);

// LEd RGB
byte led_r = 4;
byte led_g = 5;
byte led_b = 6;

float temp, humi;

void setup()
{
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_b, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  color();
}

void color(int r, int g, int b)
{
  digitalWrite(led_r, r);
  digitalWrite(led_g, g);
  digitalWrite(led_b, b);

}

void temperatura()
{
   int err;
  temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
}

}

void muestra_temperatura()
{
 if( temp <= 10)
 {
  color(0,0,255);
 }
 else if(temp >10 && <=30)
 {
  color(125, 0, 125);
 }
 else
 {
  color(255, 0, 0);
  }

}
