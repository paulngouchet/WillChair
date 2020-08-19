var fs  = require("fs");
var array = fs.readFileSync("coordinate.txt").toString().split('\n')
console.log(array)
console.log(array[0])
