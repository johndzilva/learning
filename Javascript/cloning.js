//-----------------
// Referencing
//-----------------

var object1 = { value: 20};
var object2 = object1; //reference of obj1 is set in obj2

object2.value = 30;

console.log(object1.value);

//Result: 30 (because pass by reference)

// Clone : to avoid pass by reference
// cloning a object
//-----------------
let obj1 = {a: 'a', b: 'b', c: 'c'};
let clone = Object.assign({}, obj1);
//another way is using spread operator
let clone2 = {...obj1};


obj1.c = 4
console.log(clone);
//Result: a: 'a', b: 'b', c: 'c' 

//cloning a array
//-----------------
let arr = [1,2,3,4,5]
let cloneArr = [].concat(arr);

cloneArr.push(66);

console.log(arr);
///Result: 1,2,3,4,5


//-----------------
//deep copy or cloning
//-----------------

let obj1 = {
            a: 'a',
            b: 'b',
            c: {
             deep: 'new deep'
            }
          };

let clone = Object.assign({}, obj1);
let clone2 = {...obj1};

obj1.c.deep = 'everything changed';

console.log(obj1);
console.log(clone);
console.log(clone2);

//Result: even though a clone is created, obj1.c.deep assignment changes
//        everything. because it was shallow copied. copying only one level

//Deep cloning
let superClone = JSON.parse(JSON.stringify(obj1));

//Note: Deep cloning is not prefered because json parsing may take
// longer time if the object is too deep
