##---------------------------------------------
# (i)   Class 
# (ii)  @classmethod and @staticmethod   
# (iii) Private vs public variable 
# (iv)  Inheritance
# (v)   Super()  
# (vi)  Dunder method
# (vii) Multiple inheritance
##---------------------------------------------


# ---------------------------------------------
# Class 
# ---------------------------------------------

class Animal:
    # Class Object Attribute - Immutable
    species = 'mammal'
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def printWho(self):
        print(f'name: {self.name}, age: {self.age}')

cat1 = Animal('Dog', 6)
cat1.printWho()

## Result:
#  name: Dog, age: 6

# ---------------------------------------------
# @classmethod and @staticmethod 
# ---------------------------------------------

class Animal:
    # Class Object Attribute - Immutable
    species = 'mammal'
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    @classmethod
    def adding_things(cls, num1, num2):
        return num1 + num2 
    
    #similar to class method but it does not have access to cls
    @staticmethod 
    def adding_things2(num1, num2):
        return num1 + num2 

cat1 = Animal('Dog', 6)
print(cat1.adding_things(2, 3))
print(Animal.adding_things(2, 6))

## Result:
#  5
#  8

# ---------------------------------------------
# Private vs public variable
#   There is no specific way to define private 
#   variable in python
# ---------------------------------------------

class Animal:
    species = 'mammal'
    def __init__(self, name, age):
        # private variable
        self._name = name
        self._age = age
    

# ---------------------------------------------
# Inheritance
# ---------------------------------------------

class User:
    def sign_in(self):
        print('logged in')

# inheriting from User class
class Wizard(User):
    def __init__(self, name, power):
        # private variable
        self._name = name
        self._power = power
    
    def attack(self):
        print(f'attacking with power {self._power}')

wizard1 = Wizard("Balbasaur", 300)
wizard1.sign_in()
wizard1.attack()

## Result:
#  logged in
#  attacking with power 300 


# ---------------------------------------------
# Super()
# ---------------------------------------------

class User:
    def __init__(self, email):
        self.email = email
    def sign_in(self):
        print('logged in')

# inheriting from User class
class Wizard(User):
    def __init__(self, name, power, email):
        super().__init__(email)
        # (or) User.__init__(self, email)
        self.name = name
        self.power = power

wizard1 = Wizard("Ogre", 300, "ogre@gmail.com")
print(wizard1.email)

## Result:
# ogre@gmail.com

# ---------------------------------------------
# Dunder methods
# ---------------------------------------------

class Toy():
  def __init__(self, color, age):
    self.color = color
    self.age = age
    self.my_dict = {
        'name':'Yoyo',
        'has_pets': False,
    }

  def __str__(self):
    return f"{self.color}"

  def __len__(self):
    return 5

  def __del__(self):
    return "deleted"

  def __call__(self):
      return('yes??')

  def __getitem__(self,i):
      return self.my_dict[i]


action_figure = Toy('red', 0)
print(action_figure.__str__())
print(str(action_figure))
print(len(action_figure))
print(action_figure())
print(action_figure['name'])

## Results:
# red
# red
# 5
# yes??
# Yoyo

# ---------------------------------------------
# Multiple Inheritance
# ---------------------------------------------

class User:
    def sign_in(self):
        print('logged in')

# inheriting from User class
class Wizard(User):
    def __init__(self, name, power):
        self.name = name
        self.power = power
    
    def attack(self):
        print(f'attacking with power {self.power}')

# inheriting from User class
class Archer(User):
    def __init__(self, name, arrow):
        self.name = name
        self.arrow = arrow
    
    def check_arrow(self):
        print(f'available arrow {self.arrow}')

class Hybrid(Wizard, Archer):
    def __init__(self, name, power, arrow):
        Wizard.__init__(self, name, power)
        Archer.__init__(self, name, arrow)

hybrid1 = Hybrid("Cyborg", 100, 5)
hybrid1.attack()
hybrid1.check_arrow()

## Results:
# attacking with power 100
# available arrow 5