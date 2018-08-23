import rospy
from performance_tests.msg import SuperAwesome
from performance_tests.srv import Rate

Counter     = 0
LoopRate    = 1

def Rate_Callback(req):
    global LoopRate
    global Counter 
    LoopRate = req.data
    Counter = 0
    print "Loop rate: %d" %(LoopRate)    
    return True

def talker():
    rospy.init_node('Publisher_Python', anonymous=True)
    SuperAwesome_Publisher  = rospy.Publisher('SuperAwesome_Topic', SuperAwesome, queue_size=10)
    Rate_Server             = rospy.Service('Change_Rate_Service', Rate, Rate_Callback)
    rate = rospy.Rate(1) 

    while not rospy.is_shutdown():
        global LoopRate
        global Counter 
        Counter += 1
        hello_str = str(Counter)
        rospy.loginfo(hello_str)
        SuperAwesome_Publisher.publish(hello_str)
        rate = rospy.Rate(LoopRate) 
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass