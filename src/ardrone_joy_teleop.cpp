#include "ardrone_joy_teleop.hpp"

Ardrone_ps3_con::Ardrone_ps3_con(){
    joy_sub_ = nh_.subscribe("joy",10,&Ardrone_ps3_con::joy_cb_,this);
    take_off_pub_ = nh_.advertise<std_msgs::Empty>("/ardrone/takeoff",10);
    landing_pub_ = nh_.advertise<std_msgs::Empty>("/ardrone/land",10);
    twist_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel",10);

    ros::NodeHandle pnh_("~");
    linear_x_axis_ = 0;
    linear_y_axis_ = 1;
    linear_z_axis_ = 2;
    angular_z_axis_ = 3;
    linear_x_axis_reverse_ = false;
    linear_y_axis_reverse_ = false;
    linear_z_axis_reverse_ = false;
    angular_z_axis_reverse_ = false;
    takeoff_button_ = 0; 
    landing_button_ = 1;

    pnh_.getParam("/linear_x_axis", linear_x_axis_);
    pnh_.getParam("/linear_y_axis", linear_y_axis_);
    pnh_.getParam("/linear_z_axis", linear_z_axis_);
    pnh_.getParam("/angular_z_axis", angular_z_axis_);
    pnh_.getParam("/linear_x_axis_reverse", linear_x_axis_reverse_);
    pnh_.getParam("/linear_y_axis_reverse", linear_y_axis_reverse_);
    pnh_.getParam("/linear_z_axis_reverse", linear_z_axis_reverse_);
    pnh_.getParam("/angular_z_axis_reverse", angular_z_axis_reverse_);
    pnh_.getParam("/takeoff_button", takeoff_button_);
    pnh_.getParam("/landing_button", landing_button_);
    
}

void Ardrone_ps3_con::joy_cb_(sensor_msgs::Joy data){
    std_msgs::Empty e;
    geometry_msgs::Twist t;
    if(data.buttons[takeoff_button_]){
        take_off_pub_.publish(e);
    }
    if(data.buttons[landing_button_]){
        landing_pub_.publish(e);
    }
    t.linear.x = linear_x_axis_reverse_ ? -1.0 * data.axes[linear_x_axis_] : data.axes[linear_x_axis_];
    t.linear.y = linear_y_axis_reverse_ ? -1.0 * data.axes[linear_y_axis_] : data.axes[linear_y_axis_];
    t.linear.z = linear_z_axis_reverse_ ? -1.0 * data.axes[linear_z_axis_] : data.axes[linear_z_axis_];

    t.angular.z = angular_z_axis_reverse_ ? -1.0 * data.axes[angular_z_axis_] : data.axes[angular_z_axis_];
    
    twist_pub_.publish(t);
}