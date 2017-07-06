// Generated by gencpp from file camera_control_msgs/GrabImagesResult.msg
// DO NOT EDIT!


#ifndef CAMERA_CONTROL_MSGS_MESSAGE_GRABIMAGESRESULT_H
#define CAMERA_CONTROL_MSGS_MESSAGE_GRABIMAGESRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sensor_msgs/Image.h>

namespace camera_control_msgs
{
template <class ContainerAllocator>
struct GrabImagesResult_
{
  typedef GrabImagesResult_<ContainerAllocator> Type;

  GrabImagesResult_()
    : reached_values()
    , images()
    , reached_exposure_times()
    , reached_brightness_values()
    , reached_gain_values()
    , reached_gamma_values()
    , success(false)  {
    }
  GrabImagesResult_(const ContainerAllocator& _alloc)
    : reached_values(_alloc)
    , images(_alloc)
    , reached_exposure_times(_alloc)
    , reached_brightness_values(_alloc)
    , reached_gain_values(_alloc)
    , reached_gamma_values(_alloc)
    , success(false)  {
  (void)_alloc;
    }



   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _reached_values_type;
  _reached_values_type reached_values;

   typedef std::vector< ::sensor_msgs::Image_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::sensor_msgs::Image_<ContainerAllocator> >::other >  _images_type;
  _images_type images;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _reached_exposure_times_type;
  _reached_exposure_times_type reached_exposure_times;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _reached_brightness_values_type;
  _reached_brightness_values_type reached_brightness_values;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _reached_gain_values_type;
  _reached_gain_values_type reached_gain_values;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _reached_gamma_values_type;
  _reached_gamma_values_type reached_gamma_values;

   typedef uint8_t _success_type;
  _success_type success;




  typedef boost::shared_ptr< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> const> ConstPtr;

}; // struct GrabImagesResult_

typedef ::camera_control_msgs::GrabImagesResult_<std::allocator<void> > GrabImagesResult;

typedef boost::shared_ptr< ::camera_control_msgs::GrabImagesResult > GrabImagesResultPtr;
typedef boost::shared_ptr< ::camera_control_msgs::GrabImagesResult const> GrabImagesResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace camera_control_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'camera_control_msgs': ['/home/llr_ic/catkin_ws/devel/share/camera_control_msgs/msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9064484959c52efa531a9708033fd887";
  }

  static const char* value(const ::camera_control_msgs::GrabImagesResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9064484959c52efaULL;
  static const uint64_t static_value2 = 0x531a9708033fd887ULL;
};

template<class ContainerAllocator>
struct DataType< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "camera_control_msgs/GrabImagesResult";
  }

  static const char* value(const ::camera_control_msgs::GrabImagesResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
##########################################\n\
################# RESULT #################\n\
##########################################\n\
\n\
########################################## DEPRECATED !!!\n\
# target values can not always be reached\n\
float32[] reached_values\n\
########################################## DEPRECATED !!!\n\
\n\
# The resulting images with the inquired image intensity settings.\n\
# The size of the vector equals the size of the exposure_times or the\n\
# brightness_values-vector\n\
sensor_msgs/Image[] images\n\
\n\
# The reached values of the images e.g. the values that were set to the camera\n\
# before the grab\n\
float32[] reached_exposure_times\n\
\n\
float32[] reached_brightness_values\n\
\n\
float32[] reached_gain_values\n\
\n\
float32[] reached_gamma_values\n\
\n\
# Flag which indicates the success of the grabbing action\n\
# In case of failure, the images-vector contains only the images, that could be\n\
# grabbed before the failure occurred.\n\
bool success\n\
\n\
\n\
================================================================================\n\
MSG: sensor_msgs/Image\n\
# This message contains an uncompressed image\n\
# (0, 0) is at top-left corner of image\n\
#\n\
\n\
Header header        # Header timestamp should be acquisition time of image\n\
                     # Header frame_id should be optical frame of camera\n\
                     # origin of frame should be optical center of cameara\n\
                     # +x should point to the right in the image\n\
                     # +y should point down in the image\n\
                     # +z should point into to plane of the image\n\
                     # If the frame_id here and the frame_id of the CameraInfo\n\
                     # message associated with the image conflict\n\
                     # the behavior is undefined\n\
\n\
uint32 height         # image height, that is, number of rows\n\
uint32 width          # image width, that is, number of columns\n\
\n\
# The legal values for encoding are in file src/image_encodings.cpp\n\
# If you want to standardize a new string format, join\n\
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n\
\n\
string encoding       # Encoding of pixels -- channel meaning, ordering, size\n\
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n\
\n\
uint8 is_bigendian    # is this data bigendian?\n\
uint32 step           # Full row length in bytes\n\
uint8[] data          # actual matrix data, size is (step * rows)\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::camera_control_msgs::GrabImagesResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.reached_values);
      stream.next(m.images);
      stream.next(m.reached_exposure_times);
      stream.next(m.reached_brightness_values);
      stream.next(m.reached_gain_values);
      stream.next(m.reached_gamma_values);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GrabImagesResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::camera_control_msgs::GrabImagesResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::camera_control_msgs::GrabImagesResult_<ContainerAllocator>& v)
  {
    s << indent << "reached_values[]" << std::endl;
    for (size_t i = 0; i < v.reached_values.size(); ++i)
    {
      s << indent << "  reached_values[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.reached_values[i]);
    }
    s << indent << "images[]" << std::endl;
    for (size_t i = 0; i < v.images.size(); ++i)
    {
      s << indent << "  images[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "    ", v.images[i]);
    }
    s << indent << "reached_exposure_times[]" << std::endl;
    for (size_t i = 0; i < v.reached_exposure_times.size(); ++i)
    {
      s << indent << "  reached_exposure_times[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.reached_exposure_times[i]);
    }
    s << indent << "reached_brightness_values[]" << std::endl;
    for (size_t i = 0; i < v.reached_brightness_values.size(); ++i)
    {
      s << indent << "  reached_brightness_values[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.reached_brightness_values[i]);
    }
    s << indent << "reached_gain_values[]" << std::endl;
    for (size_t i = 0; i < v.reached_gain_values.size(); ++i)
    {
      s << indent << "  reached_gain_values[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.reached_gain_values[i]);
    }
    s << indent << "reached_gamma_values[]" << std::endl;
    for (size_t i = 0; i < v.reached_gamma_values.size(); ++i)
    {
      s << indent << "  reached_gamma_values[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.reached_gamma_values[i]);
    }
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAMERA_CONTROL_MSGS_MESSAGE_GRABIMAGESRESULT_H
