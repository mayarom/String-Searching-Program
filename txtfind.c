
// Description: This program gets a string and print all the lines that contain the string

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Max characters per line. */
#define MAX_LINE_LENGTH 256

/* Max characters per word. */
#define MAX_WORD_LENGTH 30

int get_line(char s[]); // gets a string (char after char) from thestandart input
// and save it in s,return the number of characters in s

int getword(char w[]); // gets a string and save it in w,return the number of characters in w

int substring(char *str1, char *str2); // gets two strings and check if str2 is a substring of str1

int similar(char *s, char *t, int n); // gets two strings and n number ,check if s and t are similar until n changes

void print_lines(char *str); // gets a string and print all the lines that contain the string

void print_similar_words(char *str); // gets a string and print all the words
// that are similar to the string by similar function

int main()
{
    char choice; // char to get the choice from the user
    char c;
    char word[MAX_WORD_LENGTH];          // char to get the word from the user
    scanf("%s %c%c", word, &choice, &c); // get the word and the choice from the user

    switch (choice)
    {
    case 'a':
        print_lines(word);
        break;
    case 'b':
        print_similar_words(word);
        break;
    default: // if the user enter a char that is not a or b , scan again
        printf("Invalid choice, please try again");
        break;
    }
    // while (1)        // loop for the menu
    // {
    //     scanf("%s %c%c", word, &choice, &c); // get the word and the choice from the user

    //     switch (choice)
    //     {
    //     case 'a':
    //         print_lines(word);
    //         break;
    //     case 'b':
    //         print_similar_word(word);
    //         break;
    //     default: // if the user enter a char that is not a or b , scan again
    //         printf("Invalid choice, please try again");
    //         break;
    //     }
    // }

    return 0;
}

/**
 * Reads a line of input from the standard input (keyboard) and saves it in the
 * provided array. The line is terminated with a null character.
 *
 * @param s Array to store the input line. The array must be large enough to
 *          hold the line and the terminating null character.
 * @return The number of characters in the input line (not including the null
 *         character).
 */
int get_line(char s[])
{ // gets a string (char after char) from thestandart input
    int i = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n')
    { // get char from standart input
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

/**
 * Reads a word of input from the standard input  and saves it in the
 * provided array. The word is terminated with a null character.
 *
 * @param w Array to store the input word. The array must be large enough to
 *          hold the word and the terminating null character.
 * @return The number of characters in the input word (not including the null
 *         character).
 */

int getword(char w[]) // gets a string and save it in w,return the number of characters in w
{
    int c, i = 0;

    while (isspace(c = getchar()))
        ; // skip leading whitespace

    while (c != EOF && !isspace(c) && i < MAX_WORD_LENGTH - 1)
    {
        w[i++] = c;
        c = getchar();
    }

    w[i] = '\0';

    return i;
}

/**
 * Determines whether a string is a substring of another string.
 *
 * @param str1 The string to search in.
 * @param str2 The string to search for.
 * @return 1 if str2 is a substring of str1, 0 otherwise.
 */
int substring(char *str1, char *str2)
{
    int pointer1; // pointer to str1
    int pointer2; // pointer to str2

    for (pointer1 = 0; str1[pointer1] != '\0'; pointer1++) // go over str1
    {
        for (pointer2 = 0; str2[pointer2] != '\0'; pointer2++) // go over str2
        {
            if (str1[pointer1 + pointer2] != str2[pointer2]) // if the chars are not equal -break and ret
            {
                break;
            }
        }
        if (str2[pointer2] == '\0')
        {
            return 1; // if we got here, str2 is a substring of str1
        }
    }
    return 0; // if we got here, str2 is not a substring of str1
}

/**
 * Determines whether two strings are similar.
 *
 * @param s The first string.
 * @param t The second string.
 * @param n The maximum number of changes allowed.
 * @return 1 if s and t are similar, 0 otherwise.
 */
int similar(char *s, char *t, int n)
{
    int i;
    for (i = 0; s[i] != '\0' && t[i] != '\0'; i++)
    { // go over the strings
        if (s[i] != t[i])
        {
            n = n - 1;
            if (n < 0)
            { // if n is negative, return 0
                return 0;
            }
        }
    }
    return 1; // if we got here, the strings are similar
}

/**
 * Reads lines from the standard input and prints any lines that contain the
 * specified string.
 *
 * @param str The string to search for in the input lines.
 */
void print_lines(char *str)
{
    char myline[MAX_LINE_LENGTH];
    do
    {
        fgets(myline, MAX_LINE_LENGTH, stdin);
        if (strstr(myline, str) != NULL)
        {
            printf("%s", myline);
        }
    } while (myline[0] != '\0');
}

/**
 * Reads words from the standard input and prints any words that are similar to
 * the specified string.
 *
 * @param str The string to search for in the input words.
 */

void print_similar_words(char *str)
{
    char myline[MAX_LINE_LENGTH];

    while (fgets(myline, MAX_LINE_LENGTH, stdin) != NULL)
    {
        char *myword = strtok(myline, " \t\n"); // split the line to words

        while (myword != NULL)
        {
            if (similar(myword, str, 1)) // check if the word is similar to str using "similar function"
            {
                printf("%s\n", myword);
            }
            myword = strtok(NULL, " \t\n"); // get the next word
        }
    }
}
