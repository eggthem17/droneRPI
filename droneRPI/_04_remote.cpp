//
//  _04_remote.cpp
//  
//
//  Created by Martin.Q on 8/19/20.
//

#include "_00_drone.h"

void init(hm10_t& hm10){
    hm10.serial_port = serialOpen("/dev/ttyS0", 9600);
    
    if(hm10.serial_port<0){
        fprintf(stderr, "unable to open serial device: %s\n", strerror(errno));
        exit(-1);
    }
}//9

void check(hm10_t& hm10, throttle_t& throttle, target_angle_t& target_angle){
    static int cntMsg;
    
    if(serialDataAvail(hm10.serial_port)){
        while(serialDataAvail(hm10.serial_port)){
            char msp_data = serialGetchar(hm10.serial_port);
            if(msp_data == '$')
                cntMsg = 0;
            else
                cntMsg++;
            if(cntMsg == 8)
                throttle.value = msp_data;
        }
    }
}//9
