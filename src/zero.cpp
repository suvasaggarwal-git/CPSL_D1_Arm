#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/ArmString_.hpp"

#define TOPIC "rt/arm_Command"

using namespace unitree::robot;
using namespace unitree::common;

extern "C" void Zero() {
    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    publisher.InitChannel();

    unitree_arm::msg::dds_::ArmString_ msg{};
    msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":2,\"data\":{\"mode\":1,\"angle0\":0.000000,\"angle1\":-85.900000,\"angle2\":87.800000,\"angle3\":0.000000,\"angle4\":-0.000000,\"angle5\":0.000000,\"angle6\":0.000000}}";
    publisher.Write(msg);
    sleep(1);
}
