
var SerialPort = require("serialport");
var express=require('express');
var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);

app.use(express.static('src'));

var portName = "COM4",
portConfig = {
	baudRate: 9600,
	parser: SerialPort.parsers.readline("\n")
};
var sp;
sp = new SerialPort.SerialPort(portName, portConfig);

app.get('/', function(req, res){
    res.sendFile('index.html' , { root : __dirname});
});

io.on('connection', function(socket){
  console.log('a user connected');
  socket.on('disconnect', function(){
  });

	//sp.write(Buffer([0x02]))
  socket.on('chat message', function(msg){
    io.emit('chat message', msg);
		console.log(msg)
    sp.write(msg + "\n");

  });
});

http.listen(3000, function(){
  console.log('listening on *:3000');
});

sp.on("open", function () {
  console.log('open');
  sp.on('data', function(data) {
    console.log('data received: ' + data);
    io.emit("chat message", "An XBee says: " + data);
  });
});
