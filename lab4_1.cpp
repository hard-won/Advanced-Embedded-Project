#include "mbed.h"
#include "TextLCD.h"
#include "mbed2/299/drivers/BusIn.h"

TextLCD lcd (p15, p16, p17, p18, p19, p20);

BusOut rows(p26, p25, p24);
BusIn cols(p14, p13, p12, p11);

char Keytable[] = { 
    'F', 'E', 'D', 'C',
    '3', '6', '9', 'B', 
    '2', '5', '8', '0',
    '1', '4', '7', 'A',
    };


char getKey(){
    int i, j;
    char ch = ' ';

    // i-row  j-cols
    for (i = 0; i <= 3; i++){
        rows = 1;
        for (j = 0; j <= 3; j++){
            if ((cols ^ 0x00FF) & (0x0001<<j)){
                ch = Keytable[(i*4)+j];
            }
        }
    }

}

int main() {
    char b = ' ';
    lcd.cls();
    
    while (1){
        b = getKey();
        if(b != ' '){
            lcd.locate(1, 1);
            lcd.printf("Key:%c\n",b);
        }

    }
}
