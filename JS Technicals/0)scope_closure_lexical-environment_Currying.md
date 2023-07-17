# Scope / Closure / Lexical Environment / Currying.

---

- We have 3 types of variable in JavaScript **var, let , const**

- var is the old one, and should not be used now in any case. As it has many issues with creating scopes
- Also there are 4 kinds of scope in Javascript - **Block Scope, Global Scope, Function Scope, Module Scope**

### Block scope & Global Scope:

- The scope is the current context of execution in which values and expressions are "visible"

#### Global Scope:

- Any variable/expression which is written outside - i.e. not inside any functions, blocks etc.

- `This is shared across files`.

  - 2 ta .js file jodi ekta html file er maddhome linked thake , tahole oy 2 ta .js file will behave as a single file.

  - So, `let` diye only 1 ta variable declare kora jabe.1 tar beshi variable thakle error hobe.

  - `i.e.` 2 linked .js can not have this variable more than once: `let abc = 20;`
  - But there will be no error if variable declared in var in 2 linked file i.e. `var abc = 20`;

#### Let

- let
  this creates a `block scope`

- `re-declaration in NOT allowed` (in same scope)

- `re-assignment is allowed`

```JS
{ // block scope
  let x = 0;
  let y = 0;
  console.log(x); // 0
  let x = 1; // Error
}
{
  let x = 1;
  let y = 1;
  x = 2;
  console.log(x);// 2
}

console.log(x); // Error in Global Scope. Because x is not declared in global scope. It is declared in LOCAL SCOPE.
```

#### Temporal Dead Zone(TDZ) :

- the area in which a variable is not accessible. Temporal because it depends on time of excution not position

```JS
{
    console.log(a);

    let a = 1;
    // Line 50,51,52 is called TDZ for variable a.
    // Because we cant use a in these lines.
}
{
  // TDZ starts
  const say = () => console.log(msg); // hi

  let msg = 'hi';
  say(); // No error. Because of time.
}
```

### const

- this creates a block scope
- `re-declaration` in NOT allowed
- `re-assignment` is NOT allowed
- **Must be assigned at declaration time**.

```JS
{
  const x; //Error
  const y=0;
}

{
  const x=1;
  x=2   // Error
}

console.log(x); // Error
```

#### Variable Shadowing

```js
let x = 0; // shadowed variable
{
  let x = 1;
  console.log(x);
}
```

### var

- it doesn't have any block scope, and can be re-declared
- it only had function scope
- var are `hoisted`, so **_they can be used before the declaration_**

`Hoisted is a concept, jeta declaration ke shobar top e niye jay.`

```js
var x = 1;
var x = 2; // valid

console.log(y); // valid but undefined
var y = 3;

z = 4;
console.log(z); // valid
var z;
```

#### Let vs Var

```js
// For every i there will be separate scope.
for (let i = 0; i < 5; i++) {
  setTimeout(() => console.log(i), 1000);
} // prints 0,1,2,3,4

//i will be declared as global scope.
//Before 1 sec loop will be run 5 times and value of i will be equal to 5.
for (var i = 0; i < 5; i++) {
  setTimeout(() => console.log(i), 1000);
} // prints 5,5,5,5,5
```

`NOTE :` You should NOT use var now ❌

### Module scope

- In modern javascript, a file can be considered as module, where we use **export** and **import** syntax to use variable across files.

```C++
// Because of type="module" these 2 linked files will behave as a module..
//Means No global scope presents among them.
<script src="index.js" type="module"></script>
<script src="test.js" type="module"></script>

//We can import and export variable like these between these files
export { someVar, someFunc};
import { someVar} from './index.js';

```

#### global Object

- The global Object is the variable` window` in case of browser.
- This helps you to use variables across the scopes. Also, it is the `this` value for global functions

  - window.alert
  - window.Promise

- In non-browser environment, window doesn't exist. but other global objects exist.
- var affects this global obejct, also function declarations.

```js
function sayHi() {
  console.log(this); // this will refer to window
}
// Strict mode can change this behaviour;
`use strict`;

function sayHi() {
  console.log(window); // this is a better way of code
}
```

#### Function Scope:

- it is created upon execution a function

```Js
function sayHi(name){
    return name;
}

sayHi() // this call will create a function scope

sayHi() // this call will create another function scope
```

### Lexical Environment

- Every variable in JavaScript (within global / block / or function) has a reference to an object-like data called Lexical enviroment.
- This object (kind of object) serves as the basis of search for value of variable.

```Js
let name = 'john'
console.log(name)
```

- Lexical Enviroment (Global variable)

  - <img src="900_0-1.PNG" height=250px>

```js
let name = "john";

function sayHi() {
  let greet = "hi";
  console.log(greet);
}

sayHi();
console.log(name, sayHi);
```

- Lexical Enviroment (functions)
  - <img src="900_0-2.png" height=350px>

```JS
let name = 'john';

function sayHi(){
  let greet = "hi"
  console.log(name)
}

sayHi()
```

- <img src="900_0-3.PNG" height=350px>

#### Hoisting

- The movement of variable declaration to top of scope - before execution

- `function declarations` are properly hoisted (value accessible)

- `var` is hoisted.

```JS
let name = 'john';

sayHi() // valid

function sayHi(){
  let greet = "hi"
  console.log(name)
}

sayHello() // error
let sayHello = function(){
   console.log(name)
}

```
