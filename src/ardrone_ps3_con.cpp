#include "ardrone_ps3_con.hpp"

Ardrone_ps3_con::Ardrone_ps3_con(){
    joy_sub_ = nh_.subscribe("joy",10,&Ardrone_ps3_con::joy_cb_,this);
    take_off_pub_ = nh_.advertise<std_msgs::Empty>("/ardrone/takeoff",10);
    landing_pub_ = nh_.advertise<std_msgs::Empty>("/ardrone/land",10);
    twist_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel",10);
}

void Ardrone_ps3_con::joy_cb_(sensor_msgs::Joy data){
    std_msgs::Empty e;
    geometry_msgs::Twist t;
    if(data.buttons[PS3_BUTTON_START]){
        take_off_pub_.publish(e);
    }
    if(data.buttons[PS3_BUTTON_SELECT]){
        landing_pub_.publish(e);
    }
    t.linear.x = data.axes[PS3_AXIS_STICK_LEFT_UPWARDS];
    t.linear.y = data.axes[PS3_AXIS_STICK_LEFT_LEFTWARDS];
    t.linear.z = data.axes[PS3_AXIS_STICK_RIGHT_UPWARDS];

    t.angular.z = data.axes[PS3_AXIS_STICK_RIGHT_LEFTWARDS];
    
    twist_pub_.publish(t);
}