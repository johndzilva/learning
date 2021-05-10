const array = [2, 3, 4, 5];

const arr = array.forEach((num) => {
  return num * 2;
});

//------------------------------------------------
// Map 
// Map array maps to a new variable
// Restriction: Map expects the function to return
// Prevents from function side effects. As it returns value
//------------------------------------------------
const mapArray = array.map((num) => {
    return num * 2;
});

//(or)
const mapArray = array.map(num => num * 2);

console.log(mapArray); 
//Result: [4,6,8,10]


//------------------------------------------------
// Filter
//------------------------------------------------
console filterArray = array.filter(num => num > 4);

//Result: [5]



//------------------------------------------------
// Reduce
// accumulator is like a temp variable
//------------------------------------------------
const reduceArray = array.reduce((accumulator, num) => {
    return accumulator + num;
}, 0);
