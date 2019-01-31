# Yam repository

A simple Yam game made for university in C programming language.

`yam` folder contains a version of the classical Yam game

`yam2` folder contains a modified version of the Yam game

## Yam2 rules

Starting points : 30

Minimum number of players : 2

Maximum number of players : 20

A game ends when only one player is left alive (with more than 0 points)

Each player plays his round this way :
- Choose a bet :
  - 12 (do 12 points or less)
  - 30 (do 30 points or more)
**Dices roll**
- Choose the dices you want to keep for your final score
- Roll dices left and keep doing this until you don't have any dices left
**Score**
- If your score is equal to your bet, you're allright
- If your score doesn't fit your bet, you loose the exceeding points
- If you went over yout bet, you can remove the exceeding points to one of your opponents

## Compile

**Yam :**
`git clone https://github.com/segFuf/yam/ && cd yam/yam && make`

**Yam2 :**
`git clone https://github.com/segFuf/yam/ && cd yam/yam2 && make`


Then, run the output executable `yam` or `yam2`



