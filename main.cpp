#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(p15, p16, p17, p18, p19, p20);

BusOut rows(p26, p25, p24);
BusOut cols(p14, p13, p12, p11);

int main() {
    lcd.cls();

  while(1) {
      rows = 4;
      int switches = cols;
      rows = 5;
      switches = switches*16 +cols;
      lcd.cls();
      lcd.locate(1, 1);
      lcd.printf("Switches = %d\n", switches);
      wait_ms(100);
  }
}
