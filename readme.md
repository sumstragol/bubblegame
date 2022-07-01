# Bubble game

## Showcase video (click the picture)
[![Watch the video](https://img.youtube.com/vi/TPAKyW2colg/maxresdefault.jpg)](https://youtu.be/TPAKyW2colg)

## Rules and game mechanics

### Controls
A - move left
D - move right
LPM - shoot a bullet
ESC - pause

### Levels
- each level is unlocked by first completing the previous one (you have to finish 1st level to play 2nd etc.)
- completed levels are marked with red font color
- buttons of levels that can't be enterned don't light up after moving mouse cursor on it
- arrow buttons allow for moving between level pages 

### Game
- at the beginning player is located in the middle of the screen
- for each level things such as time for completing the level or balls placement are defined and stay the same
- you win if
    - you shot down all the balls in given time
- you lose if
    - ball hit you
    - time elapsed
- after losing every live game exits to the menu and stats resets (have to start again from level 1)
- balls mechanics
    - balls move left and right 
    - the size of the balls define how strongly they bounce of the ground
    - if bullet hits a ball it splits into two smaller balls
    - if bullet hits a green ball (the smallest one) it finally dissapears (doesn't split anymore)
- pistol (bullet) mechanis
    - at the time only one bullet can be in the visible game field
    - you can shoot a bullet if there is no bullet yet or you hit a ball (after hitting a ball - bullet dissapears)

## Adding levels
Game is easily expandable. Each level is loaded from the file, where all data is specified.
If we want to add a new level all we do is prepare file and then in levels_state.cpp Level_State::init_levels_path() insert a path to just created level.

### File example
```
1          // number that will be displayed on the scoreboard indicating level's number
medium     // ball type
1          // how many balls of that type will be created
100 100    // specify n placementes for n balls (coordinates)
small      /// 
2          /// 
200 200    ///  more balls 
300 200    ///    
time       // specify the time (how quickly the timer moves)
0.5        // float (bigger the number quicker the timer moves)
end        // end of the level file
```
## Requirements
- C++ 17
- SFML library (graphics, system, window)