#include <ch552.h>
#include <usb.h>
#include <usb_desc.h>

__xdata uint8_t recv_buf[64];
__xdata uint8_t send_buf[64];

void main() {
    CfgFsys();          // Clock config
    mDelaymS(10);
    P3_DIR_PU &= ~(1 << 4);  // Set P3.4 as push-pull output
    P3_MOD_OC &= ~(1 << 4);

    USBDeviceInit();    // Init USB device
    USBDeviceEnable();  // Enable USB interrupts
    EA = 1;             // Enable global interrupts

    while (1) {
        if (USBReceived) {
            USBReceived = 0;

            if (recv_buf[0] == 0x01) {
                P3 |= (1 << 4);   // Set P3.4 HIGH
            } else if (recv_buf[0] == 0x00) {
                P3 &= ~(1 << 4);  // Set P3.4 LOW
            }

            send_buf[0] = 0xAA; // ACK
            USB_EP1_IN_Transfer(send_buf, 1);
        }
    }
}
