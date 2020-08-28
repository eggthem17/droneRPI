//
//  _03_balancing.cpp
//  
//
//  Created by Martin.Q on 8/19/20.
//

#include "_00_drone.h"

void calc(balancing_force_t& balancing_force, target_angle_t& target_angle, gyro_angle_t& gyro_angle){
    double angle_error_roll = target_angle.roll - gyro_angle.roll;
    double angle_error_pitch = target_angle.pitch - gyro_angle.pitch;
    double angle_error_yaw = target_angle.yaw - gyro_angle.yaw;
    
    balancing_force.roll = 1 * angle_error_roll;
    balancing_force.pitch = 1 * angle_error_pitch;
    balancing_force.yaw = 1 * angle_error_yaw;
}//7
void distribute(motor_speed_t&, throttle_t&, balancing_force_t&){}//8
void add(balancing_force_t&, gyro_rate_t&){}//11
void add(balancing_force_t&, target_angle_t&, gyro_angle_t&, dt_t&){}//12
