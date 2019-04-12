```js
// hex = prompt("enter value(ff909f): ");
// value = prompt("\nfor hex: #ff909f \nfor RGB: 233,01,255\nenter value: ");
hex = "#ff9 ff";
// console.log(hex);
// console.log("parsed ", parseInt(hex, 16));
var h = []+[]; // "" hahah
var len = -0;

var hexToDec = hex => {
//   var len = hex.length;
  
  if (!hex.startsWith("#")) // .find
    console.info("RGB");
  
  hex = hex.replace(/#/i, "").toLowerCase().trim();
  len = hex.length;
  let spaceRegex = /[g-z\s]/g;
  if(hex.match(spaceRegex)) 
    return console.error("mission to mars");
  
 if (len === 3) {
   for(let i of hex) {
     h += conversion(i);
     h += "... ";
   }
   return h;
 } //if
  else if(len === 6) {
    for (let i = 0; i < len; i += 2){
      h += conversion(hex.substring(i, i+2));
        h += ", ";
    }
    return h;
  }
  else 
    console.log("Invalid length or character");
};

var conversion = function(hex2) {
//   console.log("parsed ", parseInt(hex2, 16))
  if (len === 3) { // one value
    for(let item of hex2){
//       return item === "0" ? "00"
//         : (item >= "0" && item <= "f") ? helpme(item += item) 
//         : null;
      if(item === "0")
          return "00";
        else if((item >= "0") && (item <= "f")) {
          return helpme(item += item);
        }
    }
  }
  else // 6
    return helpme(hex2);// split into array first?
};

var helpme = hex3 => {
  let ss = -0;//, s = [];
  let h = 'abcdef';//["a","b","c","d","e","f"];

    for (let i = hex3.length-1, j=0; i >= 0; i--,j++) {
      h.includes(hex3[j]) ? ss += (h.indexOf(hex3[j]) + 10) * 16**i :ss += hex3[j] * 16 **i
    }
//   console.log(ss);
//   if(!isNaN(ss))
  if(isNumeric(ss))
    return ss;
  return console.error("BADASS"); // '_'
};


function isNumeric(n) {
  return !isNaN(parseFloat(n)) && isFinite(n);
}

console.log(hexToDec(hex));
```
