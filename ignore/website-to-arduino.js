var http = require('http');
var fs = require('fs');
//this is the html page that triggers the arduino data
var website = fs.readFileSync( '../arduino/website-to-arduino.html');

//--------arduino stuff---------------//

var SerialPort = require('serialport');
const parsers = SerialPort.parsers;

const parser = new parsers.Readline({
    delimiter: '\r\n'
});

//specify location of the serial port! 
var port = new SerialPort('/dev/tty.wchusbserialfa1410',{ 
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
});

port.pipe(parser);

//run server
var app = http.createServer(function(req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end(website);
});

var io = require('socket.io').listen(app);

io.on('connection', function(socket) {
    
    console.log('Node is listening to port');
    //lights is the name of the message specified on the html page
    socket.on('lights',function(data){
        
        console.log( data );
        //data.status is the string that is being passed to the arduino
        port.write( data.status );
    
    });
    
});

app.listen(3000);


//References
//https://designswow.blogspot.com/p/reading-data-from-serial-port-with_15.html
//https://www.youtube.com/watch?v=hFBFju_ZSYs&ab_channel=AdamThomas

