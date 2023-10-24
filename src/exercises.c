#include <stdio.h>
#include <stdbool.h>
#include "exercises.h"

/*
Exercise 1:

Write a C program that continuously asks for a string of text input from the keyboard.
The output of this program should give the amount of characters, words and lines in the text.
Implement the function using a while loop, and use if-else statements to branch your code.
Read single characters from an input stream using the getchar() function.

- Assume that words can only be separated by spaces ‘ ‘ or tabs ‘\t’.
- All characters should be counted apart from space ‘ ‘, tabs ‘\t’ or new lines ‘\n’.
- An empty input has 0 characters, 0 words and 0 lines.
- Any non-empty input has at least 1 line.

*/
void exercise_1()
{
    int characters, words, lines;
    characters = words = lines = 0;
    char c;
    bool in_word = false;
    bool non_empty = false;

    printf("Type some text to analyse, press ctrl+D/ctrl+Z to stop:\n\n");

    while ((c = getchar()) != EOF)
    {
        non_empty = true;
        if (c == '\n')
        {
            ++lines;
            in_word = false;
        }
        else if (c == ' ' || c == '\t')
        {
            in_word = false;
        }
        else
        {
            if (!in_word)
            {
                ++words;
                in_word = true;
            }
            ++characters;
        }
    }

    // If the file is not empty we count the initial line
    if (non_empty)
        ++lines;

    printf("\nNumber of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);
}

/*
Exercise 2:
Implement the same function from exercise 1 using a do-while loop instead of a while loop. 
Make sure the functionality has not changed.
*/
void exercise_2()
{
    int characters, words, lines;
    characters = words = lines = 0;
    char c;
    bool in_word = false;
    bool non_empty = false;

    printf("Type some text to analyse, press ctrl+D/ctrl+Z to stop:\n\n");

    do
    {
        c = getchar();

        if (c == EOF)
            break;
        
        non_empty = true;

        if (c == '\n')
        {
            ++lines;
            in_word = false;
        }
        else if (c == ' ' || c == '\t')
        {
            in_word = false;
        }
        else
        {
            if (!in_word)
            {
                ++words;
                in_word = true;
            }
            ++characters;
        }
    } while (true);

    // If the file is not empty we count the initial line
    if (non_empty)
        ++lines;

    printf("\nNumber of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);
}

/*
Exercise 3:
Implement a switch statement in your program from Exercise 1 to replace the branching with if-else statements.
Make sure the functionality has not changed.
*/
void exercise_3()
{
    int characters, words, lines;
    characters = words = lines = 0;
    char c;
    bool in_word = false;
    bool non_empty = false;

    printf("Type some text to analyse, press ctrl+D/ctrl+Z to stop:\n\n");

    while ((c = getchar()) != EOF)
    {
        non_empty = true;
        switch (c)
        {
        case '\n':
            ++lines;
            in_word = false;
            break;
        case ' ':
        case '\t':
            in_word = false;
            break;
        default:
            if (!in_word)
            {
                ++words;
                in_word = true;
            }
            ++characters;
            break;
        };
    }

    // If the file is not empty we count the initial line
    if (non_empty)
        ++lines;

    printf("\nNumber of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);
}

/*
Exercise 4:
Write a C function that prints two columns on the screen with the temperature in degrees Fahrenheit (left column)
and the equivalent temperature in Celsius (right column).
The number of steps (rows to print), step-size (fahrenheit) and start-temperature (fahrenheit) are given as inputs to the function.
Temperatures should be formatted to contain space for 10 digits, with 1 of the digits after the decimal point.

Use a while loop to implement the function.

*/
void exercise_4(unsigned int number_of_steps, double step_size, double lower_lim)
{
    double upper_lim = step_size * (number_of_steps - 1) + lower_lim;

    printf("%10s %10s\n", "Fahrenheit", "Celsius");

    double fahrenheit = lower_lim;

    while (fahrenheit <= upper_lim)
    {
        printf("%10.1f %10.1f\n", fahrenheit, 5.0 / 9.0 * (fahrenheit - 32.0));
        fahrenheit += step_size;
    }
}

/*
Exercise 5:

Write the same function as in exercise 4, but use a for loop instead of a while loop.

*/
void exercise_5(unsigned int number_of_steps, double step_size, double lower_lim)
{
    double fahrenheit = lower_lim;

    printf("%10s %10s\n", "Fahrenheit", "Celsius");

    for (unsigned int i = 0; i <= number_of_steps - 1; ++i, fahrenheit += step_size)
    {
        printf("%10.1f %10.1f\n", fahrenheit, 5.0 / 9.0 * (fahrenheit - 32.0));
    }
}

/*
Exercise 6:
Write a C function which reads any string from the console using getchar().
When the return key is pressed, the program should print the sum of all the
positive single-digit numbers from the string if there are any, and then exit.

For example:
Input: "123"
Prints: "Sum of the numbers is: 6"

Input: "abc123"
Prints: "Sum of the numbers is: 6"

Input: "I have one thing to say"
Prints: "Sum of the numbers is: 0"

Input: "I have 1 thing to say"
Prints: "Sum of the numbers is: 1"

Hint: Use an ascii table to identify the range of characters that represent 
single digit numbers.

*/
void exercise_6()
{
    int total = 0;
    char c;
    unsigned char possible_number;

    printf("Type some numbers to add up:\n");

    while ((c = getchar()) != '\n')
    {
        possible_number = (unsigned char)(c - 48);
        if (possible_number < 10)
            total += possible_number;
    }

    printf("Sum of the numbers is: %d\n", total);
}
