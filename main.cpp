#include "mbed.h"
#include "HEPTA_COM.h"

RawSerial pc(USBTX,USBRX,9600);
HEPTA_COM com(p9,p10,9600);

int main(){
    pc.printf("Xbee communication Mode\r\n");
    int rcmd=0,cmdflag=0;
    for(int i = 0; i < 50; i++) {
        com.printf("num = %d\r\n",i);
        com.xbee_receive(&rcmd,&cmdflag);
        pc.printf("rcmd=%d, cmdflag=%d\r\n",rcmd, cmdflag);
        if (cmdflag == 1) {
            if (rcmd == 'a') {
                pc.printf("Command Get %d\r\n",rcmd);
                com.printf("HEPTA Uplink OK\r\n");
            }
            com.initialize();
        }
        wait(1.0);
    }
}