import rospy
from performance_tests.msg import SuperAwesome

def callback(data):
    rospy.loginfo("%s", data.data)
 
def listener():
    rospy.init_node('Subscriber_Python', anonymous=True)
    rospy.Subscriber("SuperAwesome_Topic", SuperAwesome, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()