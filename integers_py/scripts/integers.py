#!/usr/bin/env python 
# license removed for brevity 

import rospy 
from std_msgs.msg import Int16

def pedir_enteros():
    pub = rospy.Publisher('chatter', Int16, queue_size=10)
    rospy.init_node('talker', anonymous=True) 
    
    while not rospy.is_shutdown():
        entero = int(input("Escribe un entero por teclado: "))
        
        rospy.loginfo(entero)
        pub.publish(entero) 

if __name__ == '__main__': 
    try: 
        pedir_enteros() 
    except rospy.ROSInterruptException: 
        pass 



