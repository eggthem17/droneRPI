//
//  _02_gyro.cpp
//  
//
//  Created by Martin.Q on 8/19/20.
//

#include "_00_drone.h"

void init(i2c_t&){}//1
void init(i2c_t&, mpu6050_t&){}//1
void read(mpu6050_t&, gyro_raw_t&){}//1
void get(mpu6050_t&, gyro_offset_t&){}//2
void calc(gyro_adj_t&, gyro_raw_t&, gyro_offset_t&){}//3
void calc(gyro_rate_t&, gyro_adj_t&){}//4
void init(dt_t&){}//5
void calc(dt_t&){}//5
void calc(gyro_angle_t&, gyro_rate_t&, dt_t&){}//6
