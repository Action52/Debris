// Require the serialport node module
var SerialPort = require('serialport');
// Open the port
var port = new SerialPort("/dev/cu.usbmodemFA131", {
    baudRate: 9600
});
// Read the port data
port.on("open", function () {
    console.log('open');
    port.on('data', function(data) {
      console.log(port.read(data));
    });
    port.on('readable', function (){
      console.log('Data: ', port.read());
    });
});
