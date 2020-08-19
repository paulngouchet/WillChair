var exec = require('child_process').execFile;

var fun =function(){
   console.log("fun() start");
   exec('dummyTransferData.exe', function(err, data) {
        console.log(err)
        console.log(data.toString());
    });
}
fun();

var fs  = require("fs");

var reading = function(){
  var array = fs.readFileSync("coordinate.txt").toString().split('\n')
  console.log(array[0])
  console.log(array[1])
}

setTimeout(reading, 100)
