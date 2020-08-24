//
//  _00_drone.h
//  
//
//  Created by Martin.Q on 8/19/20.
//

#ifndef __DRONE_H__
#define __DRONE_H__

#include <sys/types.h>//open
#include <sys/stat.h>//open
#include <fcntl.h>//open
#include <stdio.h>//stderr
#include <errno.h>//errno
#include <string.h>//strerror
#include <stdlib.h>//exit
#include <sys/ioctl.h>//ioctl
#include <stdint.h>//unit8_t

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringSerial.h>

#include "pca9685.h"

#define I2C_SLAVE 0x0703

typedef struct{int dummy;}i2c_t;//1
typedef struct{int dummy;}mpu6050_t;//1
typedef struct{int dummy;}gyro_raw_t;//1
typedef struct{int dummy;}gyro_offset_t;//2
typedef struct{int dummy;}gyro_adj_t;//3
typedef struct{int dummy;}gyro_rate_t;//4
typedef struct{int dummy;}dt_t;//5
typedef struct{int dummy;}gyro_angle_t;//6
typedef struct{int dummy;}target_angle_t;//7
typedef struct{int dummy;}balancing_force_t;//7
typedef struct{int dummy;}throttle_t;//8
typedef struct{int dummy;}motor_speed_t;//8
typedef struct{int dummy;}hm10_t;//9
//typedef struct{int dummy;}pca9685_t;//10
typedef struct{int dummy;}motor_t;//10

void init(i2c_t&);//1
void init(i2c_t&, mpu6050_t&);//1
void read(mpu6050_t&, gyro_raw_t&);//1
void get(mpu6050_t&, gyro_offset_t&);//2
void calc(gyro_adj_t&, gyro_raw_t&, gyro_offset_t&);//3
void calc(gyro_rate_t&, gyro_adj_t&);//4
void init(dt_t&);//5
void calc(dt_t&);//5
void calc(gyro_angle_t&, gyro_rate_t&, dt_t&);//6
void calc(balancing_force_t&, target_angle_t&, gyro_angle_t&);//7
void distribute(motor_speed_t&, throttle_t&, balancing_force_t&);//8
void init(hm10_t&);//9
void check(hm10_t&, throttle_t&, target_angle_t&);//9
void init(i2c_t&, pca9685_t&);//10
void update(pca9685_t&, motor_t&, motor_speed_t&);//10
void add(balancing_force_t&, gyro_rate_t&);//11
void add(balancing_force_t&, target_angle_t&, gyro_angle_t&, dt_t&);//12

void print(gyro_raw_t&);//1
void println(void);//1
void print(gyro_offset_t&);//2
void print(gyro_adj_t&);//3
void print(gyro_rate_t&);//4
void print(dt_t&);//5
void print(gyro_angle_t&);//6
void print(balancing_force_t&);//7
void print(motor_speed_t&);//8

#endif //__00_DRONE_H__
