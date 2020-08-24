//
//  _06_print.cpp
//  
//
//  Created by Martin.Q on 8/19/20.
//

#include "_00_drone.h"

void print(gyro_raw_t& gyro_raw){
    printf("#RAW(X,Y,Z): %6d, %6d, %6d\n", gyro_raw.x, gyro_raw.y, gyro_raw.z);
}//1
void println(void){}//1
void print(gyro_offset_t& gyro_offset){
    printf("#OFF(X,Y,Z): %6d, %6d, %6d\n", gyro_offset.x, gyro_offset.y, gyro_offset.z);
}//2
void print(gyro_adj_t&){}//3
void print(gyro_rate_t&){}//4
void print(dt_t&){}//5
void print(gyro_angle_t&){}//6
void print(balancing_force_t&){}//7
void print(motor_speed_t&){}//8
