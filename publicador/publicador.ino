#include <ros.h>
//#include <std_msgs/String.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh;
std_msgs::Int32 str_msg;
ros::Publisher chatter ("chatter",&str_msg);

const int Echo=5;
const int Trigger=6;
void setup(){
 Serial.begin(9600);
 pinMode(Trigger,OUTPUT);
 pinMode(Echo,INPUT);
 digitalWrite(Trigger,LOW);
 nh.initNode();
 nh.advertise(chatter);
}
void loop(){
 long t;
 long d;

 digitalWrite(Trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(Trigger,LOW);

 t=pulseIn(Echo,HIGH);
 d=t/59;

 Serial.print("Distancia: ");
 Serial.print(d);
 Serial.println("cm");

 str_msg.data=d;
 chatter.publish(&str_msg);
 nh.spinOnce();

 delay(100);
}



