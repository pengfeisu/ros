#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

//串口相关的头文件  
#include<stdio.h>      /*标准输入输出定义*/  
#include<stdlib.h>     /*标准函数库定义*/  
#include<unistd.h>     /*Unix 标准函数定义*/  
#include<sys/types.h>   
#include<sys/stat.h>     
#include<fcntl.h>      /*文件控制定义*/  
#include<termios.h>    /*PPSIX 终端控制定义*/  
#include<errno.h>      /*错误号定义*/  
#include<string.h>  
   
   
//宏定义  
#define FALSE  -1  
#define TRUE   0

/******************************************************************* 
* 名称：            UART0_Open 
* 功能：            打开串口并返回串口设备文件描述 
* 入口参数：        fd :文件描述符    port :串口号(ttyS0,ttyS1,ttyS2) 
* 出口参数：        正确返回为1，错误返回为0 
*******************************************************************/  
int UART0_Open(int fd,const char* port)  
{
    fd = open( port, O_RDWR|O_NOCTTY|O_NDELAY);  
    if (FALSE == fd)  
    {  
        perror("Can't Open Serial Port");  
        return FALSE;  
    }  
    //恢复串口为阻塞状态                                 
    if(fcntl(fd, F_SETFL, 0) < 0)  
    {
        printf("fcntl failed!\n");  
        return FALSE;  
    }       
    else  
    {
        printf("fcntl=%d\n",fcntl(fd, F_SETFL,0));  
    }  
    //测试是否为终端设备      
    if(0 == isatty(STDIN_FILENO))
    {
        printf("standard input is not a terminal device\n");  
        return FALSE;  
    }  
    else  
    {
        printf("isatty success!\n");  
    }                
    printf("fd->open=%d\n",fd);  
    return fd;  
}  
/******************************************************************* 
* 名称：            UART0_Close 
* 功能：            关闭串口并返回串口设备文件描述 
* 入口参数：        fd:文件描述符   port:串口号(ttyS0,ttyS1,ttyS2) 
* 出口参数：        void 
*******************************************************************/  
   
void UART0_Close(int fd)  
{  
    close(fd);  
}  
   
/******************************************************************* 
* 名称：           UART0_Set 
* 功能：           设置串口数据位，停止位和效验位 
* 入口参数：        fd      串口文件描述符 
*                  speed     串口速度 
*                  flow_ctrl   数据流控制 
*                  databits   数据位   取值为 7 或者8 
*                  stopbits   停止位   取值为 1 或者2 
*                  parity     效验类型 取值为N,E,O,S 
*出口参数：        正确返回为1，错误返回为0 
*******************************************************************/  
int UART0_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity)  
{
    int i;  
    int status;  
    int speed_arr[] = { B115200, B19200, B9600, B4800, B2400, B1200, B300};  
    int name_arr[] = {115200,  19200,  9600,  4800,  2400,  1200,  300};  
           
    struct termios options;  
     
    /*tcgetattr(fd,&options)得到与fd指向对象的相关参数，并将它们保存于options,该函数还可以测试配置是否正确，该串口是否可用等。若调用成功，函数返回值为0，若调用失败，函数返回值为1. 
    */  
    if( tcgetattr( fd,&options)!=  0)  
    {  
        perror("SetupSerial 1");      
        return(FALSE);   
    } 
     
    //设置串口输入波特率和输出波特率  
    for ( i= 0;  i < sizeof(speed_arr) / sizeof(int);  i++)  
    {
        if  (speed == name_arr[i])  
        {               
            cfsetispeed(&options, speed_arr[i]);   
            cfsetospeed(&options, speed_arr[i]);    
        }  
    }       
     
    //修改控制模式，保证程序不会占用串口  
    options.c_cflag |= CLOCAL;  
    //修改控制模式，使得能够从串口中读取输入数据  
    options.c_cflag |= CREAD;  
    
    //设置数据流控制  
    switch(flow_ctrl)  
    {  
        case 0:   //不使用流控制  
                options.c_cflag &= ~CRTSCTS;  
                break;     
        
        case 1:   //使用硬件流控制  
                options.c_cflag |= CRTSCTS;  
                break;  
        case 2:   //使用软件流控制  
                options.c_cflag |= IXON | IXOFF | IXANY;  
                break;  
    }
      
    //设置数据位  
    //屏蔽其他标志位  
    options.c_cflag &= ~CSIZE;  
    switch (databits)  
    {    
       case 5:  
                options.c_cflag |= CS5;  
                break;  
       case 6:  
                options.c_cflag |= CS6;  
                break;  
       case 7:      
                options.c_cflag |= CS7;  
                break;  
       case 8:      
                options.c_cflag |= CS8;  
                break;    
       default:     
                fprintf(stderr,"Unsupported data size\n");  
                return (FALSE);   
    } 
     
    //设置校验位  
    switch (parity)  
    {    
       case 'n':  
       case 'N': //无奇偶校验位  
                 options.c_cflag &= ~PARENB;   
                 options.c_iflag &= ~INPCK;      
                 break;   
       case 'o':    
       case 'O'://设置为奇校验      
                 options.c_cflag |= (PARODD | PARENB);   
                 options.c_iflag |= INPCK;               
                 break;   
       case 'e':   
       case 'E'://设置为偶校验    
                 options.c_cflag |= PARENB;         
                 options.c_cflag &= ~PARODD;         
                 options.c_iflag |= INPCK;        
                 break;  
       case 's':  
       case 'S': //设置为空格   
                 options.c_cflag &= ~PARENB;  
                 options.c_cflag &= ~CSTOPB;  
                 break;   
        default:    
                 fprintf(stderr,"Unsupported parity\n");      
                 return (FALSE);   
    }   
    // 设置停止位   
    switch (stopbits)  
    {    
       case 1:     
                 options.c_cflag &= ~CSTOPB; break;   
       case 2:     
                 options.c_cflag |= CSTOPB; break;  
       default:     
                 fprintf(stderr,"Unsupported stop bits\n");   
                 return (FALSE);  
    }  
     
    //修改输出模式，原始数据输出  
    options.c_oflag &= ~OPOST;   
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  
     
    //options.c_lflag &= ~(ISIG | ICANON);  
     
    //设置等待时间和最小接收字符  
    options.c_cc[VTIME] = 1; /* 读取一个字符等待1*(1/10)s */    
    options.c_cc[VMIN] = 1; /* 读取字符的最少个数为1 */  
     
    //如果发生数据溢出，接收数据，但是不再读取 刷新收到的数据但是不读  
    tcflush(fd,TCIFLUSH);  
     
    //激活配置 (将修改后的termios数据设置到串口中）  
    if (tcsetattr(fd,TCSANOW,&options) != 0)    
    {  
        perror("com set error!\n");    
        return (FALSE);   
    }  
    return (TRUE);   
}  
/******************************************************************* 
* 名称：                UART0_Init() 
* 功能：                串口初始化 
* 入口参数：            fd:  文件描述符    
*                       speed:  串口速度 
*                       flow_ctrl  数据流控制 
*                       databits   数据位   取值为 7 或者8 
*                       stopbits   停止位   取值为 1 或者2 
*                       parity     效验类型 取值为N,E,O,,S 
* 出口参数：            正确返回为1，错误返回为0 
*******************************************************************/  
int UART0_Init(int fd, int speed,int flow_ctrl,int databits,int stopbits,int parity)  
{  
    int err;  
    //设置串口数据帧格式  
    if (UART0_Set(fd,speed,flow_ctrl,databits,stopbits,parity) == FALSE)  
    {                                                           
        return FALSE;  
    }  
    else  
    {  
        return TRUE;  
    }  
}  
   
/******************************************************************* 
* 名称：                UART0_Recv 
* 功能：                接收串口数据 
* 入口参数：            fd:文件描述符     
*                       rcv_buf:接收串口中数据存入rcv_buf缓冲区中 
*                       data_len:一帧数据的长度 
* 出口参数：            正确返回为1，错误返回为0 
*******************************************************************/  
int UART0_Recv(int fd, char *rcv_buf,int data_len)  
{  
    int len,fs_sel;
    
    fd_set fs_read;  
     
    struct timeval time;  
     
    FD_ZERO(&fs_read);  
    FD_SET(fd,&fs_read);  
     
    time.tv_sec = 10;  
    time.tv_usec = 0;  
     
    //使用select实现串口的多路通信  
    fs_sel = select(fd+1,&fs_read,NULL,NULL,&time);
      
    if(fs_sel)  
    {  
        len = read(fd,rcv_buf,data_len);  
        //printf("I am right!(version1.2) len = %d fs_sel = %d\n",len,fs_sel);  
        return len;  
    }  
    else  
    {  
        printf("Sorry,I am wrong!");  
        return FALSE;  
    }        
}  
/******************************************************************** 
* 名称：                UART0_Send 
* 功能：                发送数据 
* 入口参数：            fd:文件描述符     
*                       send_buf:存放串口发送数据 
*                       data_len:一帧数据的个数 
* 出口参数：            正确返回为1，错误返回为0 
*******************************************************************/  
int UART0_Send(int fd, char *send_buf,int data_len)  
{  
    int len = 0;  
    len = write(fd,send_buf,data_len);  
    if (len == data_len )  
    {  
        return len;  
    }       
    else     
    {     
        tcflush(fd,TCOFLUSH);  
        return FALSE;  
    }      
}  

void sensor_data(char *rcv_data,float &heading,float &pitch,float &roll)
{
    
    //char string[50]="$PTNTHPR,-5.9,N,-0.9,N,0.8,N*2C";
     
    char *str;  
   // float heading,pitch,roll;   //角度值 
    char status[3];   //状态

    str=strchr(rcv_data,',');   //返回rcv_data中第一个','所在的位置
    ++str;
    heading=atof(str);   //航向角
    //printf("heading=%2.1f\n",heading);
    
    str=strchr(str,',');
    str++;
    status[0]=*str;     //方位角状态
    
    str=strchr(str,',');
    str++;
    pitch=atof(str);   //俯仰角
    //printf("pitch=%2.1f\n",pitch);
    
    str=strchr(str,',');
    str++;
    status[1]=*str;     //俯仰角状态
    
    str=strchr(str,',');
    str++;
    roll=atof(str);   //滚动角
    //printf("roll=%2.1f\n",roll);
    
    str=strchr(str,',');
    str++;
    status[2]=*str;     //滚动角状态
    
    /*
    for(int i=0;i<3;i++)
    {
        putchar(status[i]);
    }
     */       
} 

int main(int argc,char **argv){
    int fd;                            //文件描述符  
    int err;                           //返回调用函数的状态  
    int len;                          
      
    char rcv_buf[32];
    char rcv_data[40]={'\0'};
    fd = UART0_Open(fd,"/dev/ttyS0"); //打开串口，返回文件描述符

    do
    {  
        err = UART0_Init(fd,19200,0,8,1,'N');   //初始化串口
        printf("Set Port Exactly!\n");  
    }while(FALSE == err || FALSE == fd);
    
    ros::init(argc,argv,"hmr_pub");
    
    ros::NodeHandle nh;
    
    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);
    
    ros::Rate rate(1);
    
    int flag=1;
    while(ros::ok()){
    
        geometry_msgs::Twist msg;
        
        for(int j=0;j<5;j++)
        {
            len = UART0_Recv(fd, rcv_buf,8);   //每次读取8个字节的数据
            if(len>0)
            {
                for(int k=0;k<len;k++)
                {
                    rcv_data[j*8+k]=rcv_buf[k];
                }
            }
            else
            {
                flag=0;
                printf("cannot receive data\n"); 
                break;
            }
         }
         
         if(flag==0) 
            continue;  
        
        float heading,pitch,roll;   //角度值
        
        sensor_data(rcv_data,heading,pitch,roll);  //此处应该判断一下如果错误应该跳过当前循环
        
        ROS_INFO_STREAM("rcv_data:"<<rcv_data);
        ROS_INFO_STREAM("pitch:"<<pitch);
        if(pitch>=0)
        {
            msg.angular.z=2;
        }
        else
            msg.angular.z=-2;

           
        //msg.linear.x=double(rand())/double(RAND_MAX);
        //msg.angular.z=2*double(rand())/double(RAND_MAX)-1;
        
        pub.publish(msg);
        
        //ROS_INFO_STREAM("Sending random veolicity command:"
                        //<<"linear="<<msg.linear.x
                       // <<"angular="<<msg.angular.z);
        //rate.sleep();
    }
    UART0_Close(fd); 
}
