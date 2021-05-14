//-----------------
//Instantiation
//-----------------

class PokemonGame {
  constructor(name, type){
    this.name = name;
    this.type = type;
  }

  introduce() {
    console.log(`I'm ${this.name} and ${this.type}`);
  }
}

class Pokemon extends PokemonGame {
  constructor(name, type) {
    //The super keyword is used to access and call functions on an object's parent.
    //In this case we are calling the parent constructor
    //To access pokemon class parent constructor needs to be initialized
    super(name, type);  
  }

  play() {
    console.log(`I'm a ${this.type} pokemon`);
  }
}

const pokemon1 = new Pokemon('pikachu', 'electric');
const pokemon2 = new Pokemon('onyx', 'rock');
