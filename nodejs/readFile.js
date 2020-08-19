var fs  = require("fs");
var array = fs.readFileSync("location.txt").toString().split('\n')

console.log(array)
console.log(array[0])
console.log(array[1])
console.log(array[2])
