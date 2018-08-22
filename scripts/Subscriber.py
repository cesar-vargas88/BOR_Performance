import rospy
from std_msgs.msg import String
from performance_tests.msg import SuperAwesome

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "%s", data.data)
 
def listener():
    rospy.init_node('Subscriber_Python', anonymous=True)
    rospy.Subscriber("SuperAwesome_Topic", SuperAwesome, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()