class Animal(object):
    def __init__(self, name):
        print(name, " is an animal.")

class Mammal_super(Animal):
    def __init__(self, name):
        print(name, " is a Mammal.")
        super().__init__(name)

class Pet(object):
    def __init__(self, name):
        print(name, " is a pet")

class CannotFly_super(Mammal_super):
    def __init__(self, name):
        print(name, " cannot fly.")
        super().__init__(name)

class CannotSwim_super(Mammal_super):
    def __init__(self, name):
        print(name, " cannot swim.")
        super().__init__(name)

class Cat_super(CannotFly_super, CannotSwim_super, Pet):
    def __init__(self):
        print("I am a super cat. Meow~")
        super().__init__("Super cat")

class Mammal(Animal):
    def __init__(self, name):
        print(name, " is a Mammal.")
        Animal.__init__(self, name)

class CannotFly(Mammal):
    def __init__(self, name):
        print(name, " cannot fly.")
        Mammal.__init__(self, name)

class CannotSwim(Mammal):
    def __init__(self, name):
        print(name, " cannot swim.")
        Mammal.__init__(self, name)

class Cat_normal(CannotFly, CannotSwim, Pet):
    def __init__(self):
        print("I am a normal cat. Meow~")
        super().__init__("Normal cat")
    
class Cat(CannotFly, CannotSwim, Pet):
    def __init__(self):
        print("I am a cat. Meow~")
        CannotFly.__init__(self, "cat")
        CannotSwim.__init__(self, "cat")
        Pet.__init__(self, "cat")

class Cat_modified(CannotFly_super, CannotSwim_super, Pet):
    def __init__(self):
        print("I am a modified cat. Meow~")
        super().__init__("modified cat")
        Pet.__init__(self, "modified cat")

if __name__ == '__main__':
    # super() will find the parent class following 
    # the Method Resolution Order. 
    #
    # Normally, MRO is depth-first but when two
    # classes inherit from the same class, Python
    # will use breadth-order for these two class
    # and then back to depth-first.
    # Cat inherits from CannotFly, CannotSwim, Pet,
    # but the order of Pet is behind that of Animal.  
    

    super_cat = Cat_super()
    print("MRO :", Cat_super.__mro__)
    print("")
    # We can observe that as Animal does not use
    # super(), Python stops tracing the class after
    # Animal in MRO. This result in not calling Pet.

    normal_cat = Cat_normal()
    print("MRO :", Cat_normal.__mro__)
    print("")
    # Cat_mormal uses super(), while its parent class
    # doesn't. This result in not calling CannotSwim,
    # since the order of CannotSwim is behind of that
    # of CannotFly.

    cat = Cat()
    print("MRO :", Cat.__mro__)
    # Cat expilicitly calls all of its parent class.
    # We can observe that Mammal and Animal are called
    # twice, since they are ancestors of both CannotFly
    # and CannotSwim.

    modified_cat = Cat_modified()
    print("MRO :", Cat_modified.__mro__)