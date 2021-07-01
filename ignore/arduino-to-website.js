var http = require('http');
var fs = require('fs');
//this is the html page that displays the arduino data
var website = fs.readFileSync( '../arduino/arduino-to-website.html'); 

//--------getting the data from arduino---------------//
var SerialPort = require('serialport');
const parsers = SerialPort.parsers;

const parser = new parsers.Readline({
    delimiter: '\r\n'
});

//specify location of the serial port! 
var port = new SerialPort('PORTLOCATION',{ 
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
});

port.pipe(parser);

parser.on('data', function(data) {
    
    console.log('Received data from port: ' + data);
    io.emit('data', data);
    
});

//--------launching the server to receive the data---------------//

//starting the server
var app = http.createServer(function(req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end(website);
});

var io = require('socket.io').listen(app);

io.on('connection', function(socket) {
    
    console.log('Node is listening to port');
    
});

//html page is displayed at localhost:3000
app.listen(3000);


//References
//https://designswow.blogspot.com/p/reading-data-from-serial-port-with_15.html
//https://www.youtube.com/watch?v=gQYsUjT-IBo&ab_channel=AdamThomas

