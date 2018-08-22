import rospy
from std_msgs.msg import String
from performance_tests.msg import SuperAwesome

def talker():
    pub = rospy.Publisher('SuperAwesome_Topic', SuperAwesome, queue_size=10)
    rospy.init_node('Publisher_Python', anonymous=True)
    rate = rospy.Rate(10) 

    while not rospy.is_shutdown():
        hello_str = "hello world"
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass