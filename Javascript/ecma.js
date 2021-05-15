//---------------------
// ES7
//---------------------

// (i) includes
const pets = ['dog', 'cat', 'rabbit'];
pets.includes('dog');
//Result: True
pets.includes('mouse');
//Result: False

// (ii) exponential 

const sqaure = (x) => x**2;
sqaure(4);
//Result: 16

//---------------------
// ES8
//---------------------

//(i) string padding (space is added)

'John'.padStart(10);
//Result:"      John"
'John'.padEnd(10);
//Result:"John      "

//(ii) trailing comma

const fun = (a,b,c,d,) => {
  console.log(a);
}
fun(1,2,3,4,);
//Result: 4 ( no error ) 

//(iii) values, entries (turns object to array), keys

let obj = {
  user1: "john",
  user2: "peter",
  user3: "kennedy"
}

Object.keys(obj).forEach((key, index) => {
  console.log(key, obj[key]);
});

//Result: user1 john
//        user2 peter
//        user3 kennedy

Object.values(obj).forEach(value => {
  console.log(value);
});

//Result: john
//         peter
//         kennedy

Object.entries(obj).forEach(value => {
  console.log(value);
});

//Result: ["user1", "john"]
//        ["user2", "peter"]
//        ["user3", "kennedy"]

//---------------------
// ES10
//---------------------

// (i) flat (flattens a nested array)

const arr = [ 1, 3, [4,5], [6,8]]
arr.flat(); //if no parameter then only one layer

//Result : [1,3,4,5,6,8]

// (ii) flatMap
// (iii) trimStart, trimEnd

// (iv) fromEntries (turns array to object)

let userProfiles = [['commander', 25], ['superior', 36]]
const obj = Object.fromEntries(userProfiles);

console.log(obj);

//Result: {
//          commander: 25,
//          superior: 36
//        }


// (v) try-catch 
// ES10 does not require catch (error) parameter

try {
  true + 'Hi'
} catch {
  console.log("type mismatch")
}

//Result: type mismatch

