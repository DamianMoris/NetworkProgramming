# Network Programming
## General Info
This service provides multiple functions with the theme 'randomness' in mind.  
To call on of the functions you use the 'Damian>>>' prefix with the name of the function directly behind the prefix. (example. Damian>>>coinflip) to do a coinflip.  
For the functions that require more arguments you put some '>>>' in between (example. Damian>>>deck>>>7)  
These functions return a value or string that corresponds to their utility with the prefix 'Damian<<<'  
(Full example. send: Damian>>>d20  return: Damian<<<13)  
## Functions
These are the functions this service that works via the benternet network has:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-coinflip  (flip coin)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-d4, d6, d8, d12, d20 or a d100  (dice throw)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-letter  (random letter)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-card  (random card)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-rng  (random number + requires extra argument 'value')  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-deck  (random cards from a deck + requires extra argument 'value')  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-magic8ball  (ask a yes-no question + requires extra argument 'string')  
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;WIP: spin-the-wheel (input multiple strings to choose from, outputs one of the strings)  
## Flowchart
![Flowchart](./flowchart.PNG)
