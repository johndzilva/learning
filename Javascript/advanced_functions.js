//-----------------------
// Advanced Functions
//-----------------------
// (i) Closures
// (ii) Currying
// (iii) Compose

//----------
//Closures
//----------
const first = () => {
  const greet = "Hi";
  const second = () => {
    alert(greet);
  };
  return second;
};

const newFunction = first();
newFunction();

// Result: Hi
// Even though the greet variable does not come under the scope of second()
// The child scope always has access to the parent scope

//----------
//Currying
//----------
const multiply = (a, b) => a * b;
const curriedMultiply = (a) => (b) => a * b;
const multiplyBy5 = curriedMultiply(5);

curriedMultiply(5);
// Result: (a * b)
curriedMultiply(5)(7);
// Result: 35
multiplyBy5(6);
// Result: 30

//----------
//Compose
//----------
const compose = (f, g) => (a) => f(g(a));

const sum = (num) => num + 1;

compose(sum, sum)(5);
// Result: 7
