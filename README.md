# Advanced-Embedded-Project
CE323


## lab3
### lab3_1
这段代码是在mbed操作系统中编写的C++代码。它定义了一个SPI（Serial Peripheral Interface）总线和一个数字输出引脚。

代码中的主函数包含了一个无限循环，在循环中执行以下操作：

通过SPI总线写入0xFFFF，即16位全1。
将数字输出引脚的值从0变成1，再从1变成0。这个数字输出引脚将作为SPI的片选信号。
等待1秒。
通过SPI总线写入0x0000，即16位全0。
将数字输出引脚的值从0变成1，再从1变成0。
等待1秒。
SPI格式设置为16位，无奇偶校验，频率设置为1000000Hz。这些设置告诉SPI总线它将如何与其他设备通信。

如果连接到8个LED，那么这段代码可以实现LED的闪烁效果。代码通过不断地写入全1和全0的值，实现了LED的开关。因为数字输出引脚的每次变化会影响SPI总线上的所有数据，所以所有LED同时闪烁。


SPI是一种外设通信协议，通常会有多个设备连接到同一个SPI总线上。片选信号（chip select signal）是一个数字信号，用于选择要与SPI总线通信的设备。

在代码中，片选信号由数字输出引脚cs控制，用于选择SPI的接收方。当片选信号为0时，SPI的接收方为某个设备；当片选信号为1时，SPI的接收方为空。在代码中，每次在SPI写入数据之前，首先将片选信号的值从0变成1，再从1变成0，这样可以保证SPI的接收方是正确的。

这是一种常见的用于SPI通信的技术，可以避免同时与多个设备通信，从而防止数据冲突。

### lab3_2
