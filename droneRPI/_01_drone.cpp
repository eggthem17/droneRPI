//
//  _01_drone.cpp
//  
//
//  Created by Martin.Q on 8/19/20.
//

#include "_00_drone.h"

//declare variable
i2c_t i2c;//1
mpu6050_t mpu6050 = {
    .i2c_addr = 0x68,
    .PWR_MGMT_1 = 0x6b,
    .GYRO_XOUT_H = 0x43,
};//1
gyro_raw_t gyro_raw;//1
gyro_offset_t gyro_offset;//2
gyro_adj_t gyro_adj;//3
gyro_rate_t gyro_rate;//4
dt_t dt;//5
gyro_angle_t gyro_angle;//6
target_angle_t target_angle;//7
balancing_force_t balancing_force;//7
throttle_t throttle;//8
motor_speed_t motor_speed;//8
hm10_t hm10;//9
pca9685_t pca9685;//10
motor_t motor;//10

//make whole code
int main(){
    wiringPiSetup();
    init(i2c);
    init(i2c, mpu6050);
    get(mpu6050, gyro_offset);
    init(dt);
    init(hm10);
    init(i2c, pca9685);
    
    while(true){
        read(mpu6050, gyro_raw);//1
        calc(gyro_adj, gyro_raw, gyro_offset);//3
        calc(gyro_rate, gyro_adj);//4
        calc(dt);//5
        calc(gyro_angle, gyro_rate, dt);//6
        calc(balancing_force, target_angle, gyro_angle);//7
        add(balancing_force, gyro_rate);//11
        add(balancing_force, target_angle, gyro_angle, dt);//12
        distribute(motor_speed, throttle, balancing_force);//8
        check(hm10, throttle, target_angle);//9
        update(pca9685, motor, motor_speed);//10
        
        static int cnt;
        cnt++;
        if(cnt%100 != 0)
            continue;
        
        //print(gyro_raw);//1
        //print(gyro_offset);//2
        //print(gyro_adj);//3
        print(gyro_rate);//4
        print(dt);//5
        print(gyro_angle);//6
        print(balancing_force);//7
        print(motor_speed);//8
        println();//1
    }
}
