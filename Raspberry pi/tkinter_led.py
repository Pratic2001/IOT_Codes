#!/usr/bin/env python
import Tkinter as tk
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setup(13 , GPIO.OUT)
master = tk.Tk()
master.title('LED_Control1')
master.geometry("300x100")
LED_STATE = False
def onoff():
	global LED_STATE
	if LED_STATE == True:
		LED_STATE = False
	else:
		LED_STATE = True
	GPIO.output(13 , LED_STATE)
button = tk.Button(master , text = 'Press to turn on / off' , bg = 'blue' , command = onoff).pack()
master.mainloop()
