#include <ch552.h>
#include "usb.h"
#include "usb_descr.h"

void main() {
    CfgFsys();          // Set system clock
    mDelaymS(10);       // Small delay after power-up

    USBDeviceInit();    // Configure USB core and endpoints
    USBDeviceEnable();  // Enable USB and interrupts
    EA = 1;             // Global interrupts on

    while (1) {
        // Check if data received on EP1 OUT, process it
        // Respond via EP1 IN if needed
    }
}
