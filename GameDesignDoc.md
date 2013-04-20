#Game Design

##"Things"
###The Game will include several different bird characters:
1. Dead Birds, which will not move at all, but will be placed randomly throughout the scene
2. Horizontal Birds, which will fly in strait horizontal lines
3. Vertical Birds, which will be the same as horizontal birds, but will fly vertically
4. (Possibly) Zig-zag Birds, which will fly in deterministic, but strait, paths
5. Loopy Birds, which will fly in deterministic, but curved, paths
6. Random Birds which will fly in (maybe smooth) random paths

##How to control the Game
Simply use the mouse to move the cursor. Try to click on birds as they move around the screen.

##Score
Score will go up as more birds are "caught". Birds will have value according to how dificult they are to catch.
In order to survive a level, the player will need to catch enough birds in a given amount of time to meet a minimum score.
Each level will have progressively higher standards, making it more and more difficult to keep up. Either the timer wil be shortened or there will be a higher minimum score.

##Lives
In order to survive a level, the player must acheive a certain score each level.
At first, this will be very easy. Later on, though, it will become much more difficult.
The player will die after the first level that he cannot complete.

##Interface
The interface will have a very simple, clean layout, with text boxes to notify the user of the time left int eh level,
the current score, and the current level. The choice to start a game or wait will be made by pressing
a button drawn in the main game window, a QGraphicsScene.

It will look something like this:
![alt text](/home/cs102/game_meldefon/interface.jpeg "Layout")
