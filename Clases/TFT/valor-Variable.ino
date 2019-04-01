#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
void setup(void) {
// Necesario pantalla Elegoo(Al menos hasta que sabemos identificador)
  Serial.begin(9600); 
  tft.begin(0x9341);
  tft.setRotation(1);


}// Setup


void loop(){
  TSPoint p = ts.getPoint();
  //p.x = Coordenadas en x
  //p.y = Cooredenadas en y
  //p.z = Presión sobre la pantalla

   if (p.z > MINPRESSURE && p.z < MAXPRESSURE) 
   {
      if(p.x <= 895 && p.y <= 140)  
      {
        // Estamos pulsando el botón
      }
   }
  
}// Loop
  

