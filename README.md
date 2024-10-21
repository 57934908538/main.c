# main.c
The code starts by including the specific board so it understands what I'm referencing.
I also define alternate names for parts of the locations in the registor memory to improve readability.
Then I stop the watchdog clock and set the LEDs to off.
I also set the buttons to off and enable them to pull up/down resistors so they are either on or off.
Then there is a line to disable the "high-impedance" mode, but we didn't go over that part much.
Then, on an endless loop for red and green, it checks whether the button was pressed and uses xor 
to toggle the light on or off. And I'm not fully sure why there is the while with no statement.
Maybe to add some delay/wait for the user to let go of the button?
