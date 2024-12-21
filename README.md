# SK-S7G2
This repository describes three simple projects implemented on the SK-S7G2 Starter Kit board.


## Game 1: **LEDs in line**

### Game description
This little game basically shows infinitely how to light up led1, led2 and led3 in a line.
It's a simple little game.

### Video
At this [link](https://youtube.com/shorts/yT4yn-zjtw4) you can see how the game 1 works.

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
At this [link](https://www.youtube.com/shorts/PJK3ZkpNz_I) you can see how the game 2 works.

## Game 3: **Simon says**

### Game description
This game is more complex.

The game has as its physical base on the board two buttons: button1 and button2 and 2 LEDs: led1 and led2. <br>
The game has 5 difficulty levels: level 1, level 2, level 3, level 4 and level 5. <br>
At each level, a random sequence of 5 elements is generated, each element in the sequence can be either led1 or led2. <br>

### Rules

#### Rule 1
- button1 corresponds to led1, and button2 corresponds to led2.

#### Rule 2
- the user must follow the sequence, if led1 lights up, he must press button1 and the sequence continues, if led2 appears, he must press button2 and the sequence continues, if he presses the wrong button the sequence is reset.

#### Rule 3
- each level is composed of a sequence of 5 LEDs

#### Rule 4
- when a level starts, initially only one LED in the sequence is shown, if the user presses the button corresponding to the LED then the sequence is incremented, that is, it goes to element 2 in the sequence, if the user does not press the correct button, then the sequence is reset and the game starts again from the beginning. The sequence is as follows: a LED in the sequence is displayed, if the user has pressed the button correctly then it goes to the next element in the randomly generated sequence and the first element()LED and the second element(LED) in the sequence are displayed. Now the user must correctly press both buttons corresponding to the displayed LEDs to move on, if they press both correctly then it iterates through the sequence and the first two elements(LEDs) are displayed together with the third element(LED) in the sequence. If the user mistakenly presses a button that does not correspond to the sequence, the sequence is reset from element 1. This process is continued until the element (LED) with number 5 in the sequence is reached, the user is shown element (LED) 1 to 5 in the sequence and if the user presses all the buttons corresponding to the LEDs displayed in the sequence then it means that he has managed to finish a level and will move on to the next level

#### Rule 5
- when the user manages to finish a level, a light show will be shown

#### Rule 6
- if the user makes a mistake in the sequence, a light show corresponding to the loss will be shown

#### Rule 7
- if the user manages to pass a level, then the next level will be more difficult. For example, for level 1, the delay between displaying the LEDs in the sequence is 500 ms, for level 2 it is 400 ms, and for level 1 it is 100 ms.

#### Rule 8
- for each level, the step from rule 4 is resumed, another sequence will be shown, starting with the first LED generated in the sequence and the process from rule 4 continues until the user manages to finish the level, only that each level has its own difficulty, that is, the delay between displaying the LEDs in the sequence decreases as the level increases

#### Rule 9
- if the user makes a mistake at any time in the game, whether it is at level 1 or 4, the game will reset from level 1

#### Rule 10
- if the user manages to complete all levels successfully and also completes level 5, then a very special light show will be shown and the game will reset from level 1.

### Video
At this [link]([https://www.youtube.com/shorts/PJK3ZkpNz_I](https://youtu.be/Gh948Cs0SxA)) you can see how the game 3 works.
