#ifndef ARDRONE_PS3_CON_HPP
#define ARDRONE_PS3_CON_HPP
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Empty.h"
#include "sensor_msgs/Joy.h"

class Ardrone_ps3_con{
    private:
        ros::NodeHandle nh_;

        ros::Subscriber joy_sub_;
        ros::Publisher take_off_pub_;
        ros::Publisher landing_pub_;
        ros::Publisher twist_pub_;

        int linear_x_axis_,linear_y_axis_,linear_z_axis_,angular_z_axis_;
        bool linear_x_axis_reverse_,linear_y_axis_reverse_,linear_z_axis_reverse_,angular_z_axis_reverse_;
        int takeoff_button_,landing_button_;
        
        void joy_cb_(sensor_msgs::Joy);

    public:
        Ardrone_ps3_con();
};

#endif //ARDRONE_PS3_CON_HPP