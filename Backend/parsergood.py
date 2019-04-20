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

while True:
    line = seri.readline()
    string_n = line.decode()
    string = string_n.rstrip()
    if (string != ''):
        #Revisar si es un set de datos válido
        if(string[0] == '#' and string[len(string)-1] == '#'):
            split = string.split('#')
            data = split[1] #Siempre será válido ya que la longitud de esta lista es 3
            datalist = data.split(",")
            print(datalist)
    time.sleep(0.1)
