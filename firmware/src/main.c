#include <ch554.h>
#include "usb.h"
#include "usb_descr.h"

__xdata uint8_t recv_buf[64];
__xdata uint8_t send_buf[64];

void main() {
    CfgFsys();
    mDelaymS(10);

    // Set P3.4 as push-pull output
    P3_DIR_PU &= ~(1 << 4);
    P3_MOD_OC &= ~(1 << 4);

    USBDeviceInit();
    USBDeviceEnable();
    EA = 1;

    while (1) {
        if (USBReceived) {
            USBReceived = 0;
            for (uint8_t i = 0; i < 64; i++) {
                recv_buf[i] = Ep1Buffer[i];
            }

            if (recv_buf[0] == 0x10) {
                // Command: set GPIO pin
                if (recv_buf[1] == 4) {
                    if (recv_buf[2])
                        P3 |= (1 << 4);
                    else
                        P3 &= ~(1 << 4);
                }
                send_buf[0] = 0xAA;  // ACK
                USB_EP1_IN_Transfer(send_buf, 1);
            }
        }
    }
}
