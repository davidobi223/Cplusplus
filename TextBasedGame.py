# David Obi
# Sample function showing the goal of the game and move commands
def show_instructions():
    # print a main menu and the commands
    print("Cyclops Text Adventure Game")
    print("Collect 7 items to win the game, or be eaten by the dragon.")
    print("Move commands: South, North, East, West")
    print("Add to Inventory: get 'item name'")


def printStatus(current_room, inventory):
    # TODO
    print('You are in', current_room)

    for item in inventory:
        print(item)

    if 'item' in rooms[current_room]:
        print('You see a', rooms[current_room]['item'])



def pickup_item(current_room, item):
    inventory.append(rooms[current_room]["item"])
    del rooms[current_room]["item"]


# A dictionary linking a room to other rooms
rooms = {
    'Forest Entrance': {'South': 'Ghostly Hallow', 'East': 'Cave', 'item': 'Bow'},
    'Cave': {'West': 'Forest Entrance', 'item': 'Arrows'},
    'Ghostly Hallow': {'North': 'Forest Entrance', 'South': 'Meadow', 'West': 'Green Woods', 'East': 'Cyclops Lair',
                       'item': 'Axe'},
    'Cyclops Lair': {'West': 'Ghostly Hallow', 'North': 'Graveyard'},
    'Meadow': {'East': 'Mount Zeus', 'North': 'Ghostly Hallow', 'item': 'Health Potion'},
    'Green Woods': {'East': 'Ghostly Hallow', 'item': 'Horse'},
    'Graveyard': {'South': 'Cyclops Lair', 'item': 'Fire Arrows'},
    'Mount Zeus': {'West': 'Meadow', 'item': 'Lightning'}
}
inventory = []  # empty inventory

current_room = 'Forest Entrance'

show_instructions()

while current_room != "exit":
    # Game Startup 
    direction = input("Which direction do you choose? ")
    if direction == "South":
        current_room = rooms[current_room]["South"]
        printStatus(current_room, inventory)
    elif direction == "East":
        current_room = rooms[current_room]["East"]
        pickup_item(current_room)
        printStatus(current_room)

    elif direction == "West":
        current_room = rooms[current_room][direction]
        pickup_item(current_room)
        printStatus(current_room)

    elif direction == "North":
        current_room = rooms[current_room][direction]
        pickup_item(current_room)
        printStatus(current_room)
    elif len(inventory) >= 7 or current_room == "Cyclops Lair":
        print('Congrats! you have collected all items and defeated the Cyclops')
        print('Thanks for playing the game I hope you enjoyed it.')
    else:
        print("That is the road to nowhere try again")