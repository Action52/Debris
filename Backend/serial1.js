const SerialPort = require('serialport');
const port = new SerialPort('/dev/cu.usbmodemFA131', {
  baudRate: 9600
});



const Readline = require('@serialport/parser-readline')
const parser = port.pipe(new Readline({ delimiter: '\r\n' }))

// Switches the port into "flowing mode"
port.on('data', function (data) {
  console.log(data.toString('utf-8'))
})
