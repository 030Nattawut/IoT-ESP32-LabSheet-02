#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"                        // เพื่อการใช้งาน digital output (GPIO)

void app_main(void)
{
    gpio_reset_pin(23);                         // รีเซ็ตสถานะของขาหมายเลข 22
    gpio_set_direction(23, GPIO_MODE_OUTPUT);   // กำหนดให้ขาหมายเลข 22 เป็น digital output

    while (true)                                // while (true) = วนรอบไม่มีที่สิ้นสุด
    {
        gpio_set_level(23, 1);                  // สั่งให้ LED ติด
        usleep(500000);                               // หน่วงเวลา 1 วินาที
        gpio_set_level(23, 0);                  // สั่งให้ LED ดับ
        usleep(500000);                               // หน่วงเวลา 1 วินาที
    }
}
