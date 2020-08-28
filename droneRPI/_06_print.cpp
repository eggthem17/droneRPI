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

void print(gyro_adj_t& gyro_adj){
    printf("#ADJ(X,Y,Z): %6d, %6d, %6d\n", gyro_adj.x, gyro_adj.y, gyro_adj.z);
}//3

void print(gyro_rate_t& gyro_rate){
    printf("#RATE(P,R,Y): %6.1f, %6.1f, %6.1f\n", gyro_rate.pitch, gyro_rate.roll, gyro_rate.yaw);
}//4
void print(dt_t& dt){
    printf("#DT:%6.6f", dt.t_period);
}//5
void print(gyro_angle_t&){}//6
void print(balancing_force_t&){}//7
void print(motor_speed_t&){}//8
