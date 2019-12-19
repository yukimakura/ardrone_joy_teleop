#include "ardrone_joy_teleop.hpp"

int main(int argc , char *argv[]){
    ros::init(argc, argv, "ardrone_joy_teleop_node");
    Ardrone_ps3_con arcon;
    ros::spin();
}