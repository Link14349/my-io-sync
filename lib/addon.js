let IOSync = require("./build/Release/IOSync.node");
IOSync.input = function (text, type = "String") {
    return global[type](IOSync.raw_input(text));
};
module.exports = IOSync;