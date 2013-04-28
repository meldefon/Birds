#Game Design

##"Things"
###The Game will include several different bird characters:
1. Dead Birds, which will not move at all, but will be placed randomly throughout the scene
2. Horizontal Birds, which will fly in strait horizontal lines
3. Vertical Birds, which will be the same as horizontal birds, but will fly vertically
4. Zig-zag Birds, which will fly in deterministic, but strait, paths
5. Random Birds which will fly in (maybe smooth) random paths
6. Pet, which will be selected by right clicking a bird. It will take on a new graphic, but move in the same way
as its original type. It will help the user by catching all birds it collides with. The user will have to choose which moement
style will make the best pet.

##How to control the Game
Simply use the mouse to move the cursor. Try to click on birds as they move around the screen. In later levels, there will be a powerup available that will allow the user to catch a bird as a pet by right clicking it. This
pet bird will catch all birds it collides with, helping the player to get higher scores.

##Score
Score will go up as more birds are "caught". Birds will have value according to how dificult they are to catch.
In order to survive a level, the player will need to catch enough birds in a given amount of time to meet a minimum score.
Each level will have progressively higher standards, making it more and more difficult to keep up. Both the timer is shortened and the minimum score increases.
The birds will have the following values:
* Dead Birds: 5
* Horizontal Birds: 25
* Vertical Birds: 45
* Zig-zag Birds: 75
* Random Birds: 150

##Lives
In order to survive a level, the player must acheive a certain score each level.
At first, this will be very easy. Later on, though, it will become much more difficult.
The player will die after the first level that he cannot complete.

##Interface
The interface will have a very simple, clean layout, with text boxes to notify the user of the time left int eh level,
the current score, and the current level. The choice to start a game or wait will be made by pressing
a button drawn in the main game window, a QGraphicsScene.

It will look something like this:
![alt text](https://github.com/usc-csci102-spring2013/game_meldefon/blob/master/interface.jpeg?raw=true "Layout")

UPDATE:
The interface will include start and reset buttons to start levels and games and bring the interface back to its initial configuration. There will also be a name and total score bar
displayed at the bottom of the screen, as well as an error bar directing the user. Attached are some screenshots.

![alt text](https://github.com/usc-csci102-spring2013/game_meldefon/blob/master/interface_shot.png?raw=true "Layout")

![alt text](https://github.com/usc-csci102-spring2013/game_meldefon/blob/master/game_shot.png?raw=true "Layout")

