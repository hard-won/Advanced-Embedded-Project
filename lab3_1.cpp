#include "mbed.h"
#include "mbed2/299/drivers/DigitalOut.h"
SPI sw(p5, p6, p7);
DigitalOut cs(p8);

int main() {
    cs = 0;
    sw.format(16,0);  //SPI格式设置为16位，无奇偶校验，频率设置为1000000Hz。
    sw.frequency(1000000);

    while (1) {
        sw.write(0xFFFF); //通过SPI总线写入0xFFFF，即16位全1，两个bit控制一个led，0是关，1是红，2是绿，3是黄
        cs = 1;
        cs = 0;
        wait(1); 
        sw.write(0x0000); //通过SPI总线写入0x0000，即16位全0。
        cs = 1;
        cs = 0;
        wait(1);
        
    }
}
