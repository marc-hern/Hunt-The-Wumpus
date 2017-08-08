# Hunt-The-Wumpus
### Setup
* The size of the grid representing the cave network must be 7 x 7 and must be represented internally by a
2D array.
* Each cell on the grid represents a room in the cave and adjacent rooms are connected through doors
which open North, South, East, or West. NOTE: These directions are only valid as long as the player is
trying to move to an adjacent room, NOT off the edge of the grid.
* The map should be randomly populated with the following items and no two items can occupy the same
room:
◦ 2 Bats
◦ 2 Bottomless Pits
◦ 1 Wumpus
◦ 2 Extra Arrows
* The player should be randomly dropped into any empty room to start the game, and has an initial arrow
capacity of 5.
* The map is hidden from the player initially.

### The Items
* The player is able to detect hazards that are adjacent to the room he/she currently occupies. The player
will report certain messages based on the hazards.
* Bats: If a room with a bat is adjacent to the player, the game should report the message "You hear
flapping nearby". If the player walks into a room with a Bat, the bat will pick up the player and
randomly drop them into any room. Bats always go back to the room they initially spawned in.
* Bottomless Pits: If a room with a bottomless pit is adjacent to the player, the game should report the
message "You feel a breeze nearby." If the player walks into a room with a bottomless pit, the
unfortunate player falls to their doom and the game is immediately over.
* Wumpus: If a room with the Wumpus is adjacent to the player, the game should report the message 
"You smell a foul stench nearby." If the player walks into the room with the Wumpus, the player gets
eaten and the game is over!
* Arrows: If the player walks into a room with an arrow lying on the ground, the game should report "You
found a magical Wumpus-Killing arrow!" and increase the player's arrow inventory by 1.
