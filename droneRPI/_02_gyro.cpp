//
//  _02_gyro.cpp
//  
//
//  Created by Martin.Q on 8/19/20.
//

#include "_00_drone.h"

void init(i2c_t& i2c){
    i2c.port = open("/dev/i2c-1", O_RDWR);
    if(i2c.port<0){
        fprintf(stderr, "unable to open i2c-1 device: %s\n", strerror(errno));
        exit(-1);
    }
}//1
void init(i2c_t& i2c, mpu6050_t& mpu6050){
    mpu6050.i2c_port = i2c.port;
    ioctl(mpu6050.i2c_port, I2C_SLAVE, mpu6050.i2c_addr);
    wiringPiI2CWriteReg8(mpu6050.i2c_port, mpu6050.PWR_MGMT_1, 0);
}//1
void read(mpu6050_t& mpu6050, gyro_raw_t& gyro_raw){
    const int I2C_PORT = mpu6050.i2c_port;
    const int GYRO_XH = mpu6050.GYRO_XOUT_H;
    ioctl(I2C_PORT, I2C_SLAVE, mpu6050.i2c_addr);
    
    gyro_raw.x=(wiringPiI2CReadReg8(I2C_PORT, GYRO_XH+0)&0xFF)<<8;
    gyro_raw.x|=wiringPiI2CReadReg8(I2C_PORT, GYRO_XH+1)&0xFF;
    gyro_raw.y=(wiringPiI2CReadReg8(I2C_PORT, GYRO_XH+2)&0xFF)<<8;
    gyro_raw.y|=wiringPiI2CReadReg8(I2C_PORT, GYRO_XH+3)&0xFF;
    gyro_raw.z=(wiringPiI2CReadReg8(I2C_PORT, GYRO_XH+4)&0xFF)<<8;
    gyro_raw.z|=wiringPiI2CReadReg8(I2C_PORT, GYRO_XH+5)&0xFF;
}//1
void get(mpu6050_t&, gyro_offset_t&){}//2
void calc(gyro_adj_t&, gyro_raw_t&, gyro_offset_t&){}//3
void calc(gyro_rate_t&, gyro_adj_t&){}//4
void init(dt_t&){}//5
void calc(dt_t&){}//5
void calc(gyro_angle_t&, gyro_rate_t&, dt_t&){}//6
