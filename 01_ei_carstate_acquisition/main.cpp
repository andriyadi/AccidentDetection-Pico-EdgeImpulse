#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "MPU6050.h"

#define FREQUENCY_HZ        100
#define INTERVAL_MS         (1000 / (FREQUENCY_HZ + 1))

MPU6050 mpu;

int main()
{
    stdio_init_all();

#if !defined(i2c_default) || !defined(PICO_DEFAULT_I2C_SDA_PIN) || !defined(PICO_DEFAULT_I2C_SCL_PIN)
    #warning i2c/mpu6050_i2c example requires a board with I2C pins
    puts("Default I2C pins were not defined");
#else
    printf("Hello, MPU6050! Reading acceleraction...\n");

    // This example will use I2C0 on the default SDA and SCL pins (4, 5 on a Pico)
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_4G)) {
        printf("Could not find a valid MPU6050 sensor, check wiring!\r\n");
        sleep_ms(500);
    }

    while (1) {
        Vector normAccel = mpu.readNormalizeAccel();
        //printf("Norm Acc. X = %.4f, Y = %.4f, Z = %.4f\n", normAccel.XAxis, normAccel.YAxis, normAccel.ZAxis);
        printf("%f \t", normAccel.XAxis);
        printf("%f \t", normAccel.YAxis);
        printf("%f \n", normAccel.ZAxis);
        
        sleep_ms(INTERVAL_MS);
    }
#endif
    return 0;
}
