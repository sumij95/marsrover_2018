import arduinoSerial
import time 
def setupSerial():
    global arduino
    arduino=arduinoSerial.Arduino(115200,'*',0)

def run():
    while True:
        print("Getting Data")
        arduino.serWrite('g')
        a =arduino.serRead()
        print(a)
        time.sleep(.5)

	
if __name__ == "__main__":
    setupSerial()
    run()


	
