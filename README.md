# Advent Of Code 2023

My solutions and approaches for the Advent of Code 2023 in C++

----
### Day 1
**[Problem description](https://adventofcode.com/2023/day/1)**

**Related Topics:** String, Two Pointers

##### Star 1
1. Loop throughe all the lines
2. For each line use a left pointer to find the first digit and a right pointer to find the last digit

##### Star 2
1. Create an array containing all the numbers as strings
2. Loop throughe all the lines
3. For the left pointer check if you can find any of the number string from (0, L), if not check if L is a number. Do the same for the right pointer just from the end of the string



----
### Day 2
**[Problem description](https://adventofcode.com/2023/day/2)**

**Related Topics:** String

##### Star 1
1. Loop throughe all the lines
2. Parse the line into sections for each turn of the game
3. Check if the amounts of all the colors are valid

##### Star 2
1. Loop throughe all the lines
2. Parse the line into sections for each turn of the game
3. Check if the used colors in this turn are bigger then before and if so set the new max values
