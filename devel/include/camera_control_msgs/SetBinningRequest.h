// Generated by gencpp from file camera_control_msgs/SetBinningRequest.msg
// DO NOT EDIT!


#ifndef CAMERA_CONTROL_MSGS_MESSAGE_SETBINNINGREQUEST_H
#define CAMERA_CONTROL_MSGS_MESSAGE_SETBINNINGREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace camera_control_msgs
{
template <class ContainerAllocator>
struct SetBinningRequest_
{
  typedef SetBinningRequest_<ContainerAllocator> Type;

  SetBinningRequest_()
    : target_binning_x(0)
    , target_binning_y(0)  {
    }
  SetBinningRequest_(const ContainerAllocator& _alloc)
    : target_binning_x(0)
    , target_binning_y(0)  {
  (void)_alloc;
    }



   typedef uint32_t _target_binning_x_type;
  _target_binning_x_type target_binning_x;

   typedef uint32_t _target_binning_y_type;
  _target_binning_y_type target_binning_y;




  typedef boost::shared_ptr< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetBinningRequest_

typedef ::camera_control_msgs::SetBinningRequest_<std::allocator<void> > SetBinningRequest;

typedef boost::shared_ptr< ::camera_control_msgs::SetBinningRequest > SetBinningRequestPtr;
typedef boost::shared_ptr< ::camera_control_msgs::SetBinningRequest const> SetBinningRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace camera_control_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'camera_control_msgs': ['/home/llr_ic/catkin_ws/devel/share/camera_control_msgs/msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "070d3ce2d671acce3b96edb95ae60995";
  }

  static const char* value(const ::camera_control_msgs::SetBinningRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x070d3ce2d671acceULL;
  static const uint64_t static_value2 = 0x3b96edb95ae60995ULL;
};

template<class ContainerAllocator>
struct DataType< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "camera_control_msgs/SetBinningRequest";
  }

  static const char* value(const ::camera_control_msgs::SetBinningRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
uint32 target_binning_x\n\
uint32 target_binning_y\n\
\n\
";
  }

  static const char* value(const ::camera_control_msgs::SetBinningRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.target_binning_x);
      stream.next(m.target_binning_y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetBinningRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::camera_control_msgs::SetBinningRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::camera_control_msgs::SetBinningRequest_<ContainerAllocator>& v)
  {
    s << indent << "target_binning_x: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.target_binning_x);
    s << indent << "target_binning_y: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.target_binning_y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAMERA_CONTROL_MSGS_MESSAGE_SETBINNINGREQUEST_H
