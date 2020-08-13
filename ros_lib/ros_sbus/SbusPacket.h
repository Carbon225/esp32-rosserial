#ifndef _ROS_ros_sbus_SbusPacket_h
#define _ROS_ros_sbus_SbusPacket_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ros_sbus
{

  class SbusPacket : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint16_t channels[16];
      typedef bool _ch17_type;
      _ch17_type ch17;
      typedef bool _ch18_type;
      _ch18_type ch18;
      typedef bool _frameLost_type;
      _frameLost_type frameLost;
      typedef bool _failsafe_type;
      _failsafe_type failsafe;

    SbusPacket():
      header(),
      channels(),
      ch17(0),
      ch18(0),
      frameLost(0),
      failsafe(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      *(outbuffer + offset + 0) = (this->channels[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channels[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->channels[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_ch17;
      u_ch17.real = this->ch17;
      *(outbuffer + offset + 0) = (u_ch17.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch17);
      union {
        bool real;
        uint8_t base;
      } u_ch18;
      u_ch18.real = this->ch18;
      *(outbuffer + offset + 0) = (u_ch18.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch18);
      union {
        bool real;
        uint8_t base;
      } u_frameLost;
      u_frameLost.real = this->frameLost;
      *(outbuffer + offset + 0) = (u_frameLost.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->frameLost);
      union {
        bool real;
        uint8_t base;
      } u_failsafe;
      u_failsafe.real = this->failsafe;
      *(outbuffer + offset + 0) = (u_failsafe.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->failsafe);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 16; i++){
      this->channels[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->channels[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->channels[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_ch17;
      u_ch17.base = 0;
      u_ch17.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch17 = u_ch17.real;
      offset += sizeof(this->ch17);
      union {
        bool real;
        uint8_t base;
      } u_ch18;
      u_ch18.base = 0;
      u_ch18.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch18 = u_ch18.real;
      offset += sizeof(this->ch18);
      union {
        bool real;
        uint8_t base;
      } u_frameLost;
      u_frameLost.base = 0;
      u_frameLost.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->frameLost = u_frameLost.real;
      offset += sizeof(this->frameLost);
      union {
        bool real;
        uint8_t base;
      } u_failsafe;
      u_failsafe.base = 0;
      u_failsafe.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->failsafe = u_failsafe.real;
      offset += sizeof(this->failsafe);
     return offset;
    }

    const char * getType(){ return "ros_sbus/SbusPacket"; };
    const char * getMD5(){ return "a4015f0786942013e802f40803790218"; };

  };

}
#endif
