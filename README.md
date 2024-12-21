# SK-S7G2
This repository describes three simple projects implemented on the SK-S7G2 Starter Kit board.


## Game 1: **LEDs in line**


## Game 2: "Forward & Backward**

### Game description
We have two buttons: button1 and button2 and 3 LEDs: led1, led2. led3. <br>
The game starts with all the LEDs off. <br>

#### Button 1
If button1 is pressed once, led1 is turned on. <br>
If button1 is pressed once more, led1 is turned off and led2 is turned on. <br>
If button1 is pressed once more, led2 is turned off and led3 is turned on. <br>
If button1 is pressed once more, led3 is turned off and all the LEDs are turned on. <br>
If button1 is pressed once more, all the LEDs are turned off and led1 is turned on. <br>

#### Button 2
If button2 is pressed once, all the LEDs are turned on. <br>
If button2 is pressed once more, all the LEDs are turned off and led3 is turned on. <br>
If button2 is pressed once more, led3 is turned off and led2 is turned on. <br>
If button2 is pressed once more, led2 is turned off and led1 is turned on. <br>
If button2 is pressed again, all the LEDs turn on and LED1 turns off. <br>

#### Sequence
The game continues indefinitely, from whatever state you are in, if you press button1 you will go through the sequence *LED1-LED2-LED3-AllLEDs*, if you press button2 you will go through the sequence *AllLEDs-LED3-LED2-LED1*.

#### Finit State Machine
![Game2_FSM](https://github.com/user-attachments/assets/2d1300cb-564a-4d48-9221-c715f757f5f9)

#### Video
At this [link]() you can see how the game 2 works.
