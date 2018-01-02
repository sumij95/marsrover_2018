import time
import serial

def setup(port):
    global ser
    try:
      ser = serial.Serial(port, baudrate=115200)
    except:
        print('Device not found' + 'UNO OR MEGA? ')
        print("Is port address okay? ")
        exit()




def get_data():
    ser.write(b'g')
    while ser.inWaiting() > 0:
        line = str(ser.readline().decode()).strip()
        return line


# while True:
#     print(get_data())