#pragma once

// ===================================================================================
// Johnny552 Board Configuration
// ===================================================================================

// --- USB Descriptors ---
#define USB_VENDOR_ID        0x16C0
#define USB_PRODUCT_ID       0x27DD
#define USB_DEVICE_VERSION   0x0100  // BCD format (1.0)

// --- Descriptor Strings ---
#define MANUFACTURER_STR     'J','o','h','n','n','y','L','a','b','s'
#define PRODUCT_STR          'J','o','h','n','n','y','5','5','2'
#define SERIAL_STR           'J','5','5','2','0','0','1'
#define INTERFACE_STR        'G','P','I','O','/','P','W','M',' ','D','e','v','i','c','e'

// --- GPIO Assignments ---
#define GPIO_PIN_0           P3_0    // PWM1
#define GPIO_PIN_1           P3_1    // PWM2
#define GPIO_PIN_2           P3_3    // INT1
#define GPIO_PIN_3           P3_4    // PWM2 / T0

#define GPIO_PWM1            P3_0
#define GPIO_PWM2            P3_1

// --- RGB LED (SK6812) ---
#define SK6812_DI_PIN        P1_5    // Data pin for SK6812 LED

// --- Temperature/Humidity Sensor (AHT21) ---
#define AHT21_SCL_PIN        P1_7    // I2C SCL
#define AHT21_SDA_PIN        P1_6    // I2C SDA

// --- Boot / Reset Pins ---
#define BOOT_PIN             P3_2
#define RESET_PIN            RST

// --- UART (optional/debug) ---
#define UART_TX              P3_1    // U0TX
#define UART_RX              P3_0    // U0RX
