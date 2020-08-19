
var SerialPort = require("serialport");
var express=require('express');
var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var fs  = require("fs");
var exec = require('child_process').execFile;
var location
app.use(express.static('src'));

var fun =function(){
	console.log("fun() start");
	
	exec('dummyTransferData.exe', function(err, data){
		console.log(err)
		console.log(data.toString());
	});
}

var reading = function(){
	var array = fs.readFileSync("coordinate.txt").toString().split('\n')
	location = array[0]
	console.log(location)
}

var portName = "COM4",
portConfig = {
	baudRate: 9600,
	parser: SerialPort.parsers.readline("\n")
};

var sp;
sp = new SerialPort.SerialPort(portName, portConfig);

var sending = function(){
	sp.write(location + "\n")
}

app.get('/', function(req, res){
	res.sendFile('index.html' , { root : __dirname});
});

io.on('connection', function(socket){
	console.log('a user connected');
	socket.on('disconnect', function(){
	});
	
	socket.on('chat message', function(msg){
		io.emit('chat message', msg);
		
		if(msg = "0"){
			fun();
			setTimeout(reading, 1000)
			setTimeout(sending, 1000)
		}
		else if(msg = "1"){
			fun();
			setTimeout(reading, 1000)
			setTimeout(sending, 1000)
		}
		else if(msg = "a "){
			fun();
			setTimeout(reading, 1000)
			setTimeout(sending, 1000)
		}
	
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
