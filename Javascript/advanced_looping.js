//----------------------
// Looping
//----------------------
// for, while, do, forEach(new in ECMA 5)

const basket = ['apples', 'oranges', 'mangoes']
const detailedBasket = {
  apples: 5,
  oranges: 10,
  mangoes: 100
}

basket.forEach(item => {
  console.log(tem);
})

// (i) for of (ES6)
// all it does is iterating over arrays and strings
for (item of basket) {
  console.log(item)
}
//Result: apples, oranges, mangoes

// (ii) for in (ES6)
// all it does is enumerating over objects - properties
for (item in detailedBasket) {
  console.log(item)
}

//Result: apples, oranges, mangoes
