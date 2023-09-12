# Import necessary libraries
from tkinter import *  # Import the tkinter library for GUI
import tkinter.font    # Import the tkinter font module
import RPi.GPIO as GPIO # Import the GPIO library for Raspberry Pi
from gpiozero import LED # Import LED class from gpiozero library

# Set the GPIO mode to BCM (Broadcom SOC channel)
GPIO.setmode(GPIO.BCM)

# Initialize LEDs by specifying their GPIO pins
red = LED(14) # Red LED on GPIO 14
blue = LED(15) # Blue LED on GPIO 15
green = LED(18) # Green LED on GPIO 18

# Initialize the GUI window
win = Tk()

# Set the title and window size
win.title("GUI Interface") # Set the window title
win.geometry("250x180") # Set the window size

# Create a font for the widgets
myFont = tkinter.font.Font(family='Helvetica', size=12, weight="bold")

# Create a StringVar to hold the selected radio button's value
uv = StringVar()

# Define functions for controlling LEDs
def ledRed():
    red.on() # Turn on the Red LED
    blue.off() # Turn off the Blue LED
    green.off() # Turn off the Green LED

def ledBlue():
    red.off() # Turn off the Red LED
    blue.on() # Turn on the Blue LED
    green.off()  # Turn off the Green LED

def ledGreen():
    red.off() # Turn off the Red LED
    blue.off() # Turn off the Blue LED
    green.on() # Turn on the Green LED

def allOn():
    red.on() # Turn on all LEDs
    blue.on()
    green.on()

def allOFF():
    red.off()  # Turn off all LEDs
    blue.off()
    green.off()

# Define a function to close the GUI and clean up GPIO
def close():
    GPIO.cleanup() # Cleanup and release GPIO resources
    win.destroy() # Destroy the GUI window

# Create GUI widgets and define their properties
Label(win, text="Choose an option!!", font=myFont, padx=14).pack()  # Create a label
Radiobutton(win, text="Red", font=myFont, command=ledRed, bg='red', height=1, width=27, bd=3, variable=uv, value="LED: Red").pack(anchor="w")  # Create a Red radio button
Radiobutton(win, text="Blue", font=myFont, command=ledBlue, bg='blue', height=1, width=27, bd=3, variable=uv, value="LED: Blue").pack(anchor="w")  # Create a Blue radio button
Radiobutton(win, text="Green", font=myFont, command=ledGreen, bg='green', height=1, width=27, bd=3, variable=uv, value="LED: Green").pack(anchor="w")  # Create a Green radio button
Radiobutton(win, text="All", font=myFont, command=allOn, bg='yellow', height=1, width=27, bd=3, variable=uv, value="LED: All").pack(anchor="w")  # Create an All radio button
Radiobutton(win, text="None", font=myFont, command=allOFF, bg='purple', height=1, width=27, bd=3, variable=uv, value="LED: None").pack(anchor="w")  # Create a None radio button
Button(win, text="Exit", font=myFont, command=close, bg='grey').pack(anchor="w")  # Create an Exit button

# Set a protocol for the window close button to call the 'close' function
win.protocol("WM_DELETE_WINDOW", close)

# Start the GUI main loop
win.mainloop()  # This starts the GUI's main event loop

