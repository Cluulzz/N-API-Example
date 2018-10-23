const main = require("./build/Release/main");
try{
    console.log(main.calculate(4));
}catch (e) {
    console.log(e);
}