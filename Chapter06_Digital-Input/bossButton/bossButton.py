## Simple demo
## Sits forever listening to serial port
## When you press button, opens website of your choosing.
## Extend this to many buttons and you'll have a physical
##  web-launcher.  
import serial
import webbrowser

SERIAL_PORT = 'COM5' 
BAUD_RATE = 9600

BOSS_SITE = "http://perplexity.com"





sp = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout = 5)
sp.flush()
print ("Boss Button")   

while(1):                       # Sit and wait forever
    response = sp.read(1)       # get one byte
    if response == "O":
        print ("Got OK Byte.  Waiting for button press.")
    elif response == b"X":
        print ("Got Boss Byte!  Alarm!")
        webbrowser.open(BOSS_SITE)
    else:
        print ("Got nothing.  Still waiting.")


