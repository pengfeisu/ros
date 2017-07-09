#include "image_handle.h"
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
