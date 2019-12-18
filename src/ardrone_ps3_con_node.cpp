#include "ardrone_ps3_con.hpp"

int main(int argc , char *argv[]){
    ros::init(argc, argv, "ardrone_ps3_con_node");
    Ardrone_ps3_con arcon;
    ros::spin();
}