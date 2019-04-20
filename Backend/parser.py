import serial
import time
seri = serial.Serial(port='/dev/cu.usbmodemFA131',
  baudrate=9600,
  parity=serial.PARITY_NONE,
  stopbits=serial.STOPBITS_ONE,
  bytesize=serial.EIGHTBITS,
  timeout=0
)

print("connected to: " + seri.portstr)
count = 1

while count <= 50:
    datastring = []
    ln = seri.readline()
    if(chr(ln) == '#'):
        for line in seri.readline():
            count = count + 1
            print('Data: ', count, chr(line))
            datastring.append(chr(line))
            if(chr(line) == '#'):
                #It is the end of the data message
                print(datastring)
                break
            time.sleep(0.3)
            #print(str(count) + str(': ') + chr(line))
