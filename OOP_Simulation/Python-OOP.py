#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np

# Import the entire file
#import ride

# Import only the Ride class
#from ride import Ride

class Ride:
    pass

# Import only the Driver class
class Driver:
    pass

class Passenger:
    pass

# Two instances of the Passenger class
meryl = Passenger()
daniel = Passenger()

print(meryl)
print(daniel)

# One instance of the Driver class
flatiron_taxi = Driver()
print(flatiron_taxi)

# Two instances of the Ride class
ride_to_school = Ride()
ride_home = Ride()

print(ride_to_school)
print(ride_home)


# In[2]:


def make_a_bark():
        print('ruff ruff !!!')
        pass


# In[3]:


class Dog:
    
    def bark(self):
        return "I'm an instance method! Oh and... ruff ruff!"


# In[4]:


rex = Dog()
rex.mabark = make_a_bark
rex.mabark()
rex.bark()


# In[5]:


class newDog:
    
    def bark(self):
        return 'I am actually going to bark this time. bark!'
        
    def who_am_i(self):
        return self


# In[6]:


fido = newDog()
print("1.", fido.who_am_i()) # Check return value of method
print("2.", fido) # Comparing return of the fido instance object

# Let's create another rex
another_rex = newDog()
print("3.", fido == fido.who_am_i()) 
print("4.", another_rex == another_rex.who_am_i()) 
# again asserting that `self` is equal to the instance object on which who_am_i was called


# In[7]:


class Driver:
    
    def greeting(self):
        return "Hey, how are you?"
    
    def ask_for_destination(self):
        return "Where would you like to go today?"


# In[8]:


class Passenger:
    
    def reply_greeting(self):
        return "I am doing well!"
    
    def in_a_hurry(self):
        return "Punch it! They're on our tail!"


# In[9]:


daniel = Driver() # driver
niky = Passenger() # passenger


# In[10]:


polite_greeting = daniel.greeting()
print(polite_greeting)
no_time_to_talk = niky.in_a_hurry()
print(no_time_to_talk)


# In[11]:


# Create Lion class
class Lion:
    
    def speak(self):
        return "Roar"


# In[12]:


# Create Tiger class
class Tiger:
    
    def speak(self):
        return "Meow"


# In[13]:


# Create Elephant class
class Elephant:
    
    def speak(self):
        return "woo-I'm-an-elephant!"


# In[14]:


simba = Lion()
tony = Tiger()
dumbo = Elephant()
zoo = [simba, tony, dumbo]
for animal in zoo:
    print(animal.speak())


# In[15]:


class Driver:
    pass

class Passenger:
    pass


# In[16]:


# Assign a driver instance
driver = Driver() 

# Give the driver instance object 'miles_driven' of 100000
driver.miles_driven = 100000


# In[17]:


# Assign a passenger instance
passenger = Passenger() 

# Give the passenger instance object a 'rating' of 4.9
passenger.rating = 4.9


# In[18]:


def find_driver_by_name(drivers, name):
    # Write your code here
    for driver in drivers:
        if driver.name == name:
            return driver.name

    print(f"Sorry, we couldn't find a driver with the name, {name}! :(")
    return 'None'


# In[19]:


# Create drivers with relevant attributes
alex_driver = Driver()
alex_driver.name = "alex"
alex_driver.rating = 9.0

michelle_driver = Driver()
michelle_driver.name = "michelle"
michelle_driver.rating = 8.0

jake_driver = Driver()
jake_driver.name = "jake"
jake_driver.rating = 9.7

ashleigh_driver = Driver()
ashleigh_driver.name = "ashleigh"
ashleigh_driver.rating = 8.75

list_of_drivers = [alex_driver, michelle_driver, jake_driver, ashleigh_driver]


# In[20]:


# Find "jake"
output_1 = find_driver_by_name(list_of_drivers, "jake")
output_1


# In[21]:


# Find "michelle"
output_2 = find_driver_by_name(list_of_drivers, "michelle")
output_2


# In[22]:


# Find "allison"
output_3 = find_driver_by_name(list_of_drivers, "allison")
output_3


# In[23]:


type(output_3)


# In[24]:


# Write your function here that returns the list of 
# instance objects whose name starts with the given substring
def name_starts_with(drivers, substring):
    # Write your code here
    nList = []
    for driver in drivers:
        if driver.name.startswith(substring):
            nList.append(driver.name)

    if len(nList) > 0:
        return nList
    else:
        return 'None'


# In[25]:


# Drivers whose name start with 'a'
output_4 = name_starts_with(list_of_drivers, "a")
output_4


# In[26]:


# Write your function here that returns the driver with the highest rating
def highest_rated_driver(drivers):
    # Write your code here
    maxRating = -1e-6
    driverName = ''
    for driver in drivers:
        if driver.rating > maxRating:
            maxRating = driver.rating
            driverName = driver.name
    
    return driverName


# In[27]:


# Find the driver with the highest rating
output_5 = highest_rated_driver(list_of_drivers)
output_5


# In[28]:


class NewDriver:
    
    def passenger_names(self):
        nList = []
        for passenger in self.passengers:
            nList.append(passenger.name)
            
        return nList


# In[29]:


# Passengers 
alex_passenger = Passenger()
alex_passenger.name = "alex"

michelle_passenger = Passenger()
michelle_passenger.name = "michelle"

jake_passenger = Passenger()
jake_passenger.name = "jake"

ashleigh_passenger = Passenger()
ashleigh_passenger.name = "ashleigh"

list_of_passengers = [alex_passenger, michelle_passenger, jake_passenger, ashleigh_passenger]


# In[30]:


# Instantiate a NewDriver class object
best_driver = NewDriver() 

# Add the name attribute and assign it 'Garol'
best_driver.name = 'Garol'

# Add the car_make attribute and assign it 'toyota'
best_driver.car_make = 'toyota'

# Add the car_model attribute and assign it 'camry'
best_driver.car_model = 'camry'

# Add the age attribute and assign it 30
best_driver.age = 30

# Add the passengers attribute and assign it to list_of_passengers
best_driver.passengers = list_of_passengers

# Find the names of the passengers
names_of_passengers = best_driver.passenger_names()
print(names_of_passengers)


# In[31]:


class Person():
    
    def say_hello(self):
        return 'Hi, how are you?'
        
    def eat_breakfast(self):
        self.hungry = False
        return 'Yum that was delish!'

gail = Person()
print('1.', vars(gail))
gail.name = 'Gail'
gail.age = 29
gail.weight = 'None of your business!'
print('2.', gail.say_hello())
print('3.', gail.eat_breakfast())
print('4.', vars(gail))


# In[32]:


class Person():
    
    def introduce(self):
        return f'Hi, my name is {self.name}. It is a pleasure to meet you!'
    
    def say_hello(self):
        return 'Hi, how are you?'
        
    def eat_breakfast(self):
        self.hungry = False
        return 'Yum that was delish!'
        
gail = Person()
gail.name = 'Gail'
the_snail = Person()
the_snail.name = 'the Snail'
print('1. ', gail.introduce())
print('2. ', the_snail.introduce())


# In[33]:


def say_hello_and_weather(instance_obj, weather_pattern):
    return f"Hi, my name is {instance_obj.name}! What wildly {weather_pattern} weather we're having, right?!"

say_hello_and_weather(the_snail, 'overcast')


# In[34]:


class Person():

    def say_hello_and_weather(self, weather_pattern):
        # we are using self instead of instance_obj because we know self represents the instance object
        return f"Hi, my name is {self.name}! What wildly {weather_pattern} weather we're having, right?!"

the_snail = Person()
the_snail.name = 'the Snail'
print('1. ', the_snail.say_hello_and_weather('humid'))
# notice that we are ONLY passing in the weather pattern argument
# instance methods **implicitly** pass in the instance object as the **first** argument


# In[35]:


class Person():

    def happy_birthday(self):
        self.age += 1
        return f"Happy Birthday to {self.name} (aka ME)! Can't believe I'm {self.age}?!"

the_snail = Person()
the_snail.name = 'the Snail'
the_snail.age = 29
print('1. ', the_snail.age)
print('2. ', the_snail.happy_birthday())
print('3. ', the_snail.age)


# In[36]:


class Person():

    def eat_sandwhich(self):
        if (self.hungry):
            self.relieve_hunger()
            return "Wow, that really hit the spot! I am so full, but more importantly, I'm not hangry anymore!"
        else:
            return "Oh, I don't think I can eat another bite. Thank you, though!"
    
    def relieve_hunger(self):
        print("Hunger is being relieved")
        self.hungry = False

the_snail = Person()
the_snail.name = 'the Snail'
the_snail.hungry = True
print('1. ', the_snail.hungry)
print('2. ', the_snail.eat_sandwhich())
print('3. ', the_snail.hungry)
print('4. ', the_snail.eat_sandwhich())


# In[37]:


# Define Driver Class here with properties for each instance variable
class Driver:
    
    def greet_passenger(self):
        return f"Hello! I'll be your driver today. My name is {self.first} {self.last}."
    
# Define Driver Class here with properties for each instance variable
driver = Driver()
driver.first = 'Matthew'
driver.last = 'Mitchell'
driver.miles_driven = 100
driver.rating = 4.9

# Create an instance with the above 4 attributes and then call the greet_passenger method
print('1. ', driver.first)
print('2. ', driver.last)
print('3. ', driver.miles_driven)
print('4. ', driver.rating)
print('5. ', driver.greet_passenger())


# In[38]:


# Define Passenger Class here with properties for each instance variable
class Passenger:
    
    def yell_name(self):
        return f"!!! {self.first.upper()} {self.last.upper()} !!!"
    
# Create an instance of the passenger class with the first and last attributes. Then call the yell_name method
passenger = Passenger()
passenger.first = 'Ron'
passenger.last = 'Burgundy'

print('1. ', passenger.first)
print('2. ', passenger.last)
print('3. ', passenger.yell_name())


# In[39]:


class Person:
    
    def set_name(self, name):
        self.name = name
    def set_job(self, job):
        self.job = job
        
bob = Person()
bob.set_name('Bob')
bob.name


# In[40]:


class Person:
    
    def __init__(self, name=None, job=None):
        self.name = name
        self.job = job
        
bob = Person('Bob', 'Carpenter')
print(bob.name)
print(bob.job)

print('\n')
someone = Person()
print(someone.name)
print(someone.job)

print('\n')
governer = Person(job = 'Carpenter')
print(governer.name)
print(governer.job)

print('\n')
bob = Person('Bob', 'Carpenter')
print(bob.name)
print(bob.job)


# In[41]:


class Driver:
    
    def __init__(self, first='Dale', last='Earnhardt', occupation='driving'):
        self.first = first
        self.last = last
        self.occupation = occupation
        
dale_earnhardt = Driver() # Initialize Dale Earnhardt here
print(dale_earnhardt.first) # "Dale"
print(dale_earnhardt.last) # "Earnhardt"
print(dale_earnhardt.occupation) # "driving"


# In[42]:


class Passenger:
    
    def __init__(self, first='Jerry', last='Seinfeld', email='jerry.seinfeld@mailinator.com', rides_taken=0):
        self.first = first
        self.last = last
        self.email = email
        self.rides_taken = rides_taken
        
jerry = Passenger() # Initialize Mr. Seinfeld here
print(jerry.first) # "Jerry"
print(jerry.last) # "Seinfeld"
print(jerry.email) # "jerry.seinfeld@mailinator.com"
print(jerry.rides_taken) # 0


# In[43]:


class Business():
    
    def __init__(self, name=None, biz_type=None, city=None, customers = []):
        self.name = name
        self.biz_type = biz_type
        self.city = city
        self.customers = customers
        
    def add_customer(self, customer):
        self.customers.append(customer)
        
    def top_n_customers(self, n):
        top_n = sorted(self.customers, key = lambda x: x.total_spent, reverse=True)[:n]
        for c in top_n:
            print(c.name, c.total_spent)


# In[44]:


class Customer():
    
    def __init__(self, name=None, orders=[], location=None):
        self.name = name
        self.orders = orders
        self.location = location
        self.total_spent = sum([i['item_cost']*i['quantity'] for i in orders])
        
    def add_order(self, item_name, item_cost, quantity):
        self.orders.append({'item_name': item_name, 'item_cost':item_cost, 'quantity':quantity})
        self.total_spent += item_cost * quantity


# In[45]:


startup = Business('etsy_store2076', 'crafts')
customer1 = Customer(name='Bob', orders=[])
customer1.add_order('sweater', 24.99, 1)
print(customer1.orders)
print(customer1.total_spent)


# In[46]:


names = ['Liam',  'Emma', 'Noah','Olivia','William','Ava',
         'James','Isabella','Logan','Sophia','Benjamin','Mia','Mason',
         'Charlotte','Elijah','Amelia','Oliver','Evelyn','Jacob','Abigail']
items = [('sweater',50), ('scarf', 35), ('gloves', 20), ('hat', 20)]

for i in range(10):
    customer = Customer(name=np.random.choice(names)) # Create a customer
    n_orders = np.random.randint(1, 5) # Create an order or two, or three, or four, or five!
    for order_n in range(n_orders):
        idx = np.random.choice(len(items)) # np.random.choice doesn't work with nested lists; workaround
        item = items[idx]
        item_name = item[0]
        item_price = item[1]
        quantity = np.random.randint(1, 4)
        customer.add_order(item_name, item_price, quantity)
    # Add the customer to our business
    startup.add_customer(customer)


# In[47]:


startup.top_n_customers(5)
startup.top_n_customers(50)


# In[48]:


class School:
    
    def __init__(self, name, roster={}):
        self.name = name
        self.roster = roster
        
    def add_student(self, name, grade):
        if grade not in self.roster.keys():
            self.roster[grade] = [name]
        else:    
            self.roster[grade].append(name)
            
    def grade(self, grade):
        return self.roster[grade]
    
    def sort_roster(self):
        new_dict = self.roster
        for k in new_dict.keys():
            new_dict[k].sort()
            
        return new_dict


# In[49]:


school = School('Middletown High School')
print(school.roster) 
school.add_student("Peter Piper", 12)
print(school.roster) # {"12": ["Peter Piper"]}
school.add_student("Kelly Slater", 9)
school.add_student("Tony Hawk", 10)
school.add_student("Ryan Sheckler", 10)
school.add_student("Bethany Hamilton", 11)
print(school.roster) # {9: ["Kelly Slater"], 10: ["Tony Hawk", "Ryan Sheckler"], 11: ["Bethany Hamilton"], 12: ["Peter Piper"]}
print(school.grade(10)) # ["Tony Hawk", "Ryan Sheckler"]
print(school.grade(12)) # ["Peter Piper"]
print(school.sort_roster())


# In[50]:


class ShoppingCart:
    
    def __init__(self, emp_discount=None):
        self.total = 0
        self.emp_discount = emp_discount
        self.items = []
    
    def add_item(self, name, price, quantity=1):
        self.total += price * quantity
        self.items.append({"name":name, "price":price, "quantity":quantity})
        return self.total
    
    def mean_item_price(self):
        total_items = [q["quantity"] for q in self.items]
        return self.total/sum(total_items)
    
    def median_item_price(self):
        pList = [item['price'] for item in self.items for n in range(0, item['quantity'])]
        spList = sorted(pList)
        return self.find_median(spList)
    
    def find_median(self, pList):
        if len(pList) % 2 != 0:
            return pList[len(pList)//2]
        else:
            return (pList[len(pList)//2] + pList[len(pList)//2-1])/2
    
    def apply_discount(self):
        if self.emp_discount == None:
            return "Sorry, there is no discount to apply to your cart :("
        else:
            return self.total * (1 - self.emp_discount * 0.01) 
    
    def void_last_item(self):
        if self.items[-1] != None:
            self.total = sum([item['price'] * item['quantity'] for item in self.items[:-1]])
            self.total += sum([item['price'] * (item['quantity'] - 1 ) for item in self.items[-1:]])
            return self.total
        else:
            return "There are no items in your cart!"


# In[51]:


shopping_cart = ShoppingCart()
print(shopping_cart.total)
print(shopping_cart.emp_discount)
print(shopping_cart.items)
print(shopping_cart.add_item("rainbow sandals", 45.99)) # 45.99
print(shopping_cart.add_item("agyle socks", 10.50)) # 56.49
print(shopping_cart.add_item("jeans", 50.00, 3)) # 206.49
print(shopping_cart.mean_item_price()) # 41.29
print(shopping_cart.median_item_price()) # 50.00


# In[52]:


discount_shopping_cart = ShoppingCart(20)
print(discount_shopping_cart.add_item("rainbow sandals", 45.00)) # 45.00
print(discount_shopping_cart.add_item("agyle socks", 15.00)) # 60.00
print(discount_shopping_cart.apply_discount()) # 48.00
print(discount_shopping_cart.add_item("macbook air", 1000.00)) # 1060.00
print(discount_shopping_cart.apply_discount()) # 848.00
print(shopping_cart.apply_discount()) # Sorry, there is no discount to apply to your cart :(


# In[53]:


print(shopping_cart.void_last_item())
shopping_cart.total # 156.49


# In[54]:


class Drummer(object):

    def __init__(self):
        self.name = "Ringo"
        self.role = "Drummer"

    def tune_instrument(self):
        pass

    def practice(self):
        pass

    def perform(self):
        pass

class Singer(object):

    def __init__(self):
        self.name = "John"
        self.role = "Singer"

    def tune_instrument(self):
        pass

    def practice(self):
        pass

    def perform(self):
        pass

class Guitarist(object):
    
    def __init__(self):
        self.name = 'George'
        self.role = 'Guitarist'
        self.instrument_type = 'Stringed Instrument'
        
    def tune_instrument(self):
        print('Tune the strings!')
        
    def practice(self):
        print('Strumming the old 6 string!')
        
    def perform(self):
        print('Hello, New  York!')

class Bass_Guitarist(Guitarist):
    
    def __init__(self):
        super().__init__()
        self.name = 'Paul'
        self.role = 'Guitarist'
        
    def practice(self):
        print('I play the Seinfeld Theme Song when I get bored')
        
    def perform(self):
        super().perform()
        print('Thanks for coming out!')


# In[55]:


george = Guitarist()
paul = Bass_Guitarist()
print(george.instrument_type)
print(paul.instrument_type)
george.tune_instrument()
paul.tune_instrument()
george.practice()
paul.practice()
george.perform()
paul.perform()


# In[56]:


class Musician(object):
    
    def __init__(self, name): # We'll set name at instantiation time to demonstrate passing in arguments to super().__init__()
        self.name = name
        self.band = "The Beatles"
    
    def tune_instrument(self):
        print("Tuning Instrument!")
    
    def practice(self):
        print("Practicing!")
        
    def perform(self):
        print("Hello New York!")
        
class Singer(Musician):
    
    def __init__(self, name):
        super().__init__(name)  # Notice how we pass in name argument from init to the super().__init() method, because it expects it
        self.role = "Singer"
        
    def tune_instrument(self):
        print("No tuning needed -- I'm a singer!")
    
class Guitarist(Musician):
    
    def __init__(self, name):
        super().__init__(name)
        self.role = "Guitarist"
        
    def practice(self):
        print("Strumming the old 6 string!")
        
class Bass_Guitarist(Guitarist):
    
    def __init__(self, name):
        super().__init__(name)
        self.role = "Bass Guitarist"
        
    def practice(self):
        print("I play the Seinfeld Theme Song when I get bored")
        
    def perform(self):
        super().perform()
        print("Thanks for coming out!")
        
class Drummer(Musician):
    
    def __init__(self, name):
        super().__init__(name)
        self.role = "Drummer"
        
    def tune_instrument(self):
        print('Where did I put those drum sticks?')
        
    def practice(self):
        print('Why does my chair still say "Pete Best"?')    


# In[57]:


john = Singer('John Lennon')
paul = Bass_Guitarist('Paul McCartney')
ringo = Drummer('Ringo Starr')
george = Guitarist('George Harrison')

the_beatles = [john, ringo, george, paul]

for musician in the_beatles:
    print('{} is the {}!'.format(musician.name, musician.role))
    
for musician in the_beatles:
    musician.tune_instrument()
    
for musician in the_beatles:
    musician.perform()
    
for musician in the_beatles:
    musician.perform()


# In[58]:


class Animal(object):
    
    def __init__(self, name, weight):
        self.name = name
        self.size = None
        self.weight = weight
        self.species = None
        self.food_type = None
        self.nocturnal = False
        
    def sleep(self):
        if self.nocturnal:
            print(f"the animal: {self.name} sleeps during day")
        else:
            print(f"the animal: {self.name} sleeps during night")
            
    def eat(self, food):
        if food == 'plants':
            if self.food_type == 'herbivore' or self.food_type == 'omnivore':
                print(f"the animal: {self.name} ({self.species}) thinks {food} is yummy!")
            else:
                print("I don't eat this!")
        elif food == 'meat':
            if self.food_type == 'carnivore' or self.food_type == 'omnivore':
                print(f"the animal: {self.name} ({self.species}) thinks {food} is yummy!")
            else:
                print("I don't eat this!")
        else:
            if self.food_type == 'omnivore':
                print(f"the animal: {self.name} ({self.species}) thinks {food} is yummy!")
            else:
                print("I don't eat this!")
                
class Elephant(Animal):
    
    def __init__(self, name, weight):
        super().__init__(name, weight)
        self.species = 'elephant'
        self.size = 'enormous'
        self.food_type = 'herbivore'
        self.nocturnal = False
        
class Tiger(Animal):
    
    def __init__(self, name, weight):
        super().__init__(name, weight)
        self.species = 'tiger'
        self.size = 'large'
        self.food_type = 'carnivore'
        self.nocturnal = True
        
class Raccoon(Animal):
    
    def __init__(self, name, weight):
        super().__init__(name, weight)
        self.species = 'raccoon'
        self.size = 'small'
        self.food_type = 'omnivore'
        self.nocturnal = True
        
class Gorilla(Animal):
    
     def __init__(self, name, weight):
        super().__init__(name, weight)
        self.species = 'gorilla'
        self.size = 'large'
        self.food_type = 'herbivore'
        self.nocturnal = False    


# In[59]:


def add_animal_to_zoo(zoo, animal_type, name, weight):
    
    animal = None
    
    if animal_type == 'Gorilla':
        animal = Gorilla(name, weight)
    elif animal_type == 'Raccoon':
        animal = Raccoon(name, weight)
    elif animal_type == 'Tiger':
        animal = Tiger(name, weight)
    else:
        animal = Elephant(name, weight)
        
    zoo.append(animal)
    
    return zoo


# In[60]:


animal_list = ['Elephant', 'Elephant', 'Raccoon', 'Raccoon', 'Gorilla', 'Tiger', 'Tiger', 'Tiger']

zoo = []

for animal in animal_list:
    zoo = add_animal_to_zoo(zoo, animal, 'name', 250)

zoo


# In[61]:


def feed_animals(zoo, time='Day'):
    
    for animal in zoo:
        if time == 'Day':
            if animal.nocturnal == False:
                if animal.food_type == 'carnivore':
                    animal.eat('meat')
                else:
                    animal.eat('plants')
        else:
             if animal.nocturnal == True:
                if animal.food_type == 'carnivore':
                    animal.eat('meat')
                else:
                    animal.eat('plants')


# In[62]:


feed_animals(zoo)


# In[63]:


feed_animals(zoo, 'Night')


# In[ ]:




