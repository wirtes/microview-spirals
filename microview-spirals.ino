/******************************************************************************
microview-spirals.ino
Pretty, random spirals drawn on the MicroView Display
Al Wirtes, wirtes@gmail.com

This sketch draws random spirals on the MicroView display.

This software is as-is without warranty.
******************************************************************************/
#include <MicroView.h>
int SCREEN_WIDTH = uView.getLCDWidth();
int SCREEN_HEIGHT = uView.getLCDHeight();
int x = 0;
int y = 0;
char color = 'BLACK';
// Play with these values to change the design
// These are overwritten with random numbers, but these values
// display a nice, loose spiral effect. 
long density = 2;
int draw_speed = 20;
int iterations = 40 * density;
int cent_x = SCREEN_WIDTH/2;
int cent_y = SCREEN_HEIGHT/2;

void setup() {
    uView.begin();
    uView.clear(PAGE);      // clear the page buffer 
    randomSeed(analogRead(0)); // Pin 0 is unconnected. This seeds the random function with random data.
}

void loop() {
  cent_x = (int) random(SCREEN_WIDTH/2 - 15, SCREEN_WIDTH/2 + 15);
  cent_y = (int) random(SCREEN_HEIGHT/2 - 10, SCREEN_HEIGHT/2 + 10);
  density = random(1,12);
  draw_speed = (int) random(3,15);
  iterations = 40 * density;
  drawSpiral(WHITE, density, draw_speed, iterations);
  drawSpiral(BLACK, density, draw_speed, iterations);
}

void drawSpiral(char clr, long density, int draw_speed, int iterations) 
{
  
  for (int i=0; i<iterations; i++)
  {
    delay(draw_speed);
      x = (i * cos(i)/density + cent_x);
      y = (i * sin(i)/density + cent_y);
    if (x > 0 && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT) 
    {
      uView.pixel(x,y,clr,NORM);
      uView.display(); 
    }     
  }
}
