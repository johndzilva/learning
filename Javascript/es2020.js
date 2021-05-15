//----------------------
// ES2020
//----------------------
// (i) BigInt 
// (ii) Optional Chaining Operator ?.
// (iii) Nullish Coalescing Operator ??

// (i) BigInt - It is used to work with numbers more than MAX_SAFE_INTEGER
typeof 5n;
//Result: 'BigInt'

// (ii) Optional Chaining Operator ?.
// *The optional chaining operator (?.) enables you to read the value
// * of a property located deep within a chain of connected objects 
// * without having to check that each reference in the chain is valid.

let will_pokemon = {
  pikachu: {
    species: 'mouse',
    height: 0.4,
    weight: 6,
    power: 'lightning'
  }
}

let andrew_pokemon = {
  pikachu: {
    species: 'mouse',
    height: 0.4,
    weight: 6,
    power: 0
  }
}

if(will_pokemon.raichu) {
  let weight = will_pokemon.raichu.weight;
}
// (Or)

let weight = will_pokemon?.raichu?.weight;

console.log(weight);
//Result: undefined (because there is raichu element)

// (iii) Nullish Coalescing Operator ??
// *The nullish coalescing operator (??) is a logical operator 
// *that returns its right-hand side operand when its left-hand
// *side operand is null or undefined

let power = andrew_pokemon?.pikachu?.power || 'no power';
console.log(power);
//Result: no power (even though the value is 0)

//Now using nullish ??
let power = andrew_pokemon?.pikachu?.power ?? 'no power';
console.log(power);
//Result: 0
