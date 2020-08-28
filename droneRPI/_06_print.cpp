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
    printf("#DT: %6.6f\n", dt.t_period);
}//5

void print(gyro_angle_t& gyro_angle){
    printf("#ANGLE(P,R,Y): %6.1f, %6.1f, %6.1f\n", gyro_angle.pitch, gyro_angle.roll, gyro_angle.yaw);
}//6
void print(balancing_force_t& balancing_force){
    printf("#FORCE(P,R,Y): %6.1f, %6.1f, %6.1f\n", balancing_force.pitch, balancing_force.roll, balancing_force.yaw);
}//7
void print(motor_speed_t& motor_speed){
    printf("#SPEED(A,B,C,D): %6.1f, %6.1f, %6.1f, %6.1f\n", motor_speed.a, motor_speed.b, motor_speed.c, motor_speed.d);
}//8
