#!/usr/bin/env python
import serial
import Tkinter as tk
master = tk.Tk()
master.title('LED_Control2')
master.geometry('300x150')
ser = serial.Serial('/dev/ttyUSB0' , 9600 , timeout = 1)
ser.flush()
def onoff1():
    ser.write(b"1\n")

def onoff2():
    ser.write(b"2\n")

def onoff3():
    ser.write(b"3\n")

def onoff4():
    ser.write(b"4\n")
button1 = tk.Button(master , text = 'Press to on/off led1' , bg = 'blue' , command = onoff1).pack()
button2 = tk.Button(master , text = 'Press to on/off led2' , bg = 'blue' , command = onoff2).pack()
button3 = tk.Button(master , text = 'Press to on/off led3' , bg = 'blue' , command = onoff3).pack()
button4 = tk.Button(master , text = 'Press to on/off led4' , bg = 'blue' , command = onoff4).pack()
master.mainloop()
