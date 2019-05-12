IOSync
==========
[![npm version](https://badge.fury.io/js/my-io-sync.svg)](https://badge.fury.io/js/my-io-sync)  
This package provides sync IO method for nodejs.

Install
--------
```bash
npm install my-io-sync --save-dev
```

Usage
--------
### Import
```javascript
let {print, println, raw_input, input} = require("my-io-sync");
```
### Output
- `print(...texts)` _Print texts_
- `println(...texts)` _Print texts and line feed_
```js
let {print, println} = require("my-io-sync");
println("Hello world!");
print("Hello world!");
```
### Input
- `raw_input(...texts)` _Print texts and input(return String value)_
- `input(text, transType = "String")` _Print text and input(return (transType) value)_
```js
let {println, raw_input, input} = require("my-io-sync");
let name = raw_input("Name:");
let age = input("Age:", "Number");
println(name, age);
```

License
----------
[MIT license](LICENSE)