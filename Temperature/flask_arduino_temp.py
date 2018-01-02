# import arduinoSerial
import time
import gps
from flask import Flask, request, redirect, url_for, send_from_directory

app = Flask(__name__, static_url_path='')


@app.before_first_request
def setupSerial():
    print('Seraching Arduino')
    try:
        gps.setup('COM3')
        print('Gps Setup Okay')
    except:
        print('Arduino not found')


@app.route("/")
def page():
    # if arduino.getConnStatus()==True:
    return app.send_static_file('frontend.html')


import random


@app.route('/state')
def getState():
    try:
        a = gps.get_data()
        a = a.strip().split();
        a = a[1] + ':' + a[2] + ':' + a[0];
        print(a)
        return str(a)
    except:
        print('GPS disconnected')
        return str('gps device not connected');



# @atexit.register
# def disconnect():
# 	arduino.closePort()
# 	print('Port closed !!!')

# @app.route('/')
# def sendPage():
# 	return app.send_static_file('temp.html')

if __name__ == "__main__":
    app.run(debug=True)
