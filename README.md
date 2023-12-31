# Advent Of Code 2023

My solutions and approaches for the Advent of Code 2023 in C++

----
### Day 1
**[Problem description](https://adventofcode.com/2023/day/1)**

**Related Topics:** String, Two Pointers

**Test input:**
```
two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
```

#### Star 1
1. Loop throughe all the lines
2. For each line use a left pointer to find the first digit and a right pointer to find the last digit

#### Star 2
1. Create an array containing all the numbers as strings
2. Loop throughe all the lines
3. For the left pointer check if you can find any of the number string from (0, L), if not check if L is a number. Do the same for the right pointer just from the end of the string



----
### Day 2
**[Problem description](https://adventofcode.com/2023/day/2)**

**Related Topics:** String

**Test input:**
```
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
```

#### Star 1
1. Loop throughe all the lines
2. Parse the line into sections for each turn of the game
3. Check if the amounts of all the colors are valid

#### Star 2
1. Loop throughe all the lines
2. Parse the line into sections for each turn of the game
3. Check if the used colors in this turn are bigger then before and if so set the new max values



----
### Day 3
**[Problem description](https://adventofcode.com/2023/day/3)**
**Related Topics:** String

**Test input:**
```
467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..
```

#### Star 1
1. Find all the special characters and save their positions
2. Loop troughe all the found characters
   1. Look for numbers around the character
   2. When a number is found check how long it is by moving to the left until you reach its end
   3. Save the start position to a set of numbers
3. Loop troughe the the saved numbers and sum them up

#### Star 2
1. Find all the gears (*)
2. Loop troughe all the found gears
   1. Look for numbers around the character
   2. When a number is found check how long it is by moving to the left until you reach its end
   3. Save the start position to a set of numbers
   4. If the set size is equal to 2, multiply the numbers and add to the total sum



----
### Day 4
**[Problem description](https://adventofcode.com/2023/day/4)**
**Related Topics:** String, Set

**Test input:**
```
```

#### Star 1

#### Star 2

```
seeds: 79 14 55 13

seed-to-soil map:
50 98 2
52 50 48

soil-to-fertilizer map:
0 15 37
37 52 2
39 0 15

fertilizer-to-water map:
49 53 8
0 11 42
42 0 7
57 7 4

water-to-light map:
88 18 7
18 25 70

light-to-temperature map:
45 77 23
81 45 19
68 64 13

temperature-to-humidity map:
0 69 1
1 0 69

humidity-to-location map:
60 56 37
56 93 4```