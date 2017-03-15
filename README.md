# PongBox
My **very first game**, made on C.

![title screen][title]

## Description
Pongbox is a _pong-like_ game with a spin, literally.

![twist demo][twist]

The game has 2 game-modes:

* Original pong game with an AI.  
  You can choose on 3 levels of difficulty.  
  It´s not the greatest A.I., but it simulates very well one. Basically it consists on a _dice_ that decides wether or not it moves so it can reach the ball, the higher the difficulty, the lower the chances of missing the ball.
* PongBox.  
  Survival challenge where you only have three lives to get the maximum score. 

Full game demo can be seen here (low gif framerate):

![game demo][demo]


## Getting it to work
This game was made on Borland C++ compiler so it is not compatible with actual systems.

In order to get this game running you need an MS-DOS emulator. [Turbo C++][TurboC] is an integrated development environment made from Borland which can be run on actual Windows systems using an emulated MS-DOS environment called [DOSBox](https://www.dosbox.com/).

If you want to get the game working just install [TurboC++][TurboC], open the file on the compiler, run it and play :video_game:.

## Notes
* The game is still buggy, I´m looking forward to repair that, but maybe starting a new version from scratch will be easier.
* Most of the code is uncommented, I was too young too undesrtand why it **must** be documented.

[TurboC]: https://turboc.codeplex.com/
[title]: https://github.com/JCastrejonE/Pongbox/blob/master/imgs/title.gif?raw=true
[twist]: https://github.com/JCastrejonE/Pongbox/blob/master/imgs/twist.gif?raw=true
[demo]: https://github.com/JCastrejonE/Pongbox/blob/master/imgs/PongBox.gif?raw=true
