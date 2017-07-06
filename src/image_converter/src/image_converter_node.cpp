#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <geometry_msgs/Twist.h>
//#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>

//static const std::string OPENCV_WINDOW = "Image window";

////****自动白平衡****/////
void whiteBalance(cv::Mat &src,cv::Mat &dst){
 
    std::vector<cv::Mat> imageRGB;  
  
    //RGB三通道分离  
    split(src, imageRGB);  
  
    //求原始图像的RGB分量的均值  
    double R, G, B;  
    B = mean(imageRGB[0])[0];  
    G = mean(imageRGB[1])[0];  
    R = mean(imageRGB[2])[0];  
  
    //需要调整的RGB分量的增益  
    double KR, KG, KB;  
    KB = (R + G + B) / (3 * B);  
    KG = (R + G + B) / (3 * G);  
    KR = (R + G + B) / (3 * R);  
  
    //调整RGB三个通道各自的值  
    imageRGB[0] = imageRGB[0] * KB;  
    imageRGB[1] = imageRGB[1] * KG;  
    imageRGB[2] = imageRGB[2] * KR;  
  
    //RGB三通道图像合并  
    merge(imageRGB, dst);   
}




class ImageConverter
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_l,image_sub_r;
  
  //image_transport::Publisher image_pub_;
  
  ros::Publisher veolicity_pub;
  geometry_msgs::Twist msg;
  
public:
  ImageConverter()
    : it_(nh_)
  {
    // Subscrive to input video feed and publish output video feed
    
    image_sub_l = it_.subscribe("/pylon_camera_node_l/image_raw", 1, &ImageConverter::imageCb_l, this);
    image_sub_r = it_.subscribe("/pylon_camera_node_r/image_raw", 1, &ImageConverter::imageCb_r, this);
      
    //image_pub_ = it_.advertise("/image_converter/output_video", 1);
    
    veolicity_pub = nh_.advertise <geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
    //cv::namedWindow(OPENCV_WINDOW);
  }

  ~ImageConverter()
  {
    //cv::destroyWindow(OPENCV_WINDOW);
  }

  void publishVeolicity();

  void imageCb_l(const sensor_msgs::ImageConstPtr& msg)
  {
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    
    cv::Mat dstImage=cv_ptr->image.clone();
    whiteBalance(cv_ptr->image,dstImage);
     
    // Update GUI Window
    //cv::imshow("left image", cv_ptr->image);
    cv::imshow("left result image", dstImage);
    cv::waitKey(3);
    
    publishVeolicity();
    // Output modified video stream
    //image_pub_.publish(cv_ptr->toImageMsg());
  }
  
  
  
    void imageCb_r(const sensor_msgs::ImageConstPtr& msg)
  {
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);                           
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    
    cv::Mat dstImage=cv_ptr->image.clone();
    whiteBalance(cv_ptr->image,dstImage);
    
     
    // Update GUI Window
    //cv::imshow("right image", cv_ptr->image); 
    cv::imshow("right result image", dstImage);
    cv::waitKey(3);
    
    // Output modified video stream
   // image_pub_.publish(cv_ptr->toImageMsg());
   
  }
};


void ImageConverter::publishVeolicity(){
    msg.angular.z=1;
    veolicity_pub.publish(msg);    
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_converter");
  ImageConverter ic;
  ros::spin();
  return 0;
}
