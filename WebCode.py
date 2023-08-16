
from tkinter import Tk
from tkinter.filedialog import askopenfilename
import urllib.request
import serial
import time
def send_Data(Number):
    try:
        myserial.write(bytes(Number.encode(encoding="utf-8")))
    except:
        print("Serial error")
root = Tk()
root.withdraw()
try:
    myserial = serial.Serial(port="COM4", baudrate=115200, bytesize=8, timeout=3, parity="N", stopbits=1)
except:
    print("Serial error")
else:
    print("Serial opened")
url = "http://ota.freevar.com/status.txt"
x=0
while True:
    with urllib.request.urlopen(url) as file:
        contents = file.read().decode('utf-8')
    if x != contents :
        send_Data(contents)
    x=contents
    print(contents)
    time.sleep(2)