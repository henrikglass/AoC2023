#include "hgl_neat.h"
#include "aoc_util.h"

#include <stdio.h>
#include <string.h>

int main()
{

    const char *input = read_input("input/day1.txt");
    size_t input_size = strlen(input);

    int first_digit = -1;
    int last_digit = -1;
    int sum = 0;

#if 0
    for (size_t i = 0; i < input_size; i++) {
        char c = input[i];  

        /* c is new line or null byte */
        if (c == '\n' || c == '\r' || c == '\0') {
            sum += first_digit * 10 + last_digit;
            first_digit = -1;
            last_digit = -1;
            continue;
        }

        /* c is non-digit */
        if (c < '0' || c > '9') {
            continue;
        }

        /* c is digit */
        int digit = (int) (c - '0');
        if (first_digit == -1) {
            first_digit = digit;
            last_digit = first_digit;
        } else {
            last_digit = digit;
        }

    }
#else
   
    /* keep track of what digits are spelled out */
    int digit_idx[10] = {0};
    const char *digit_str[] = {
        [0] = "zero", [1] = "one", [2] = "two",   [3] = "three", [4] = "four",
        [5] = "five", [6] = "six", [7] = "seven", [8] = "eight", [9] = "nine"
    };

    for (size_t i = 0; i < input_size; i++) {
        char c = input[i]; 
        int digit = -1;

        /* c is new line or null byte */
        if (c == '\n' || c == '\r' || c == '\0') {
            sum += first_digit * 10 + last_digit;

            /* reset stuff */
            first_digit = -1;
            last_digit = -1;
            for (int j = 0; j < 10; j++) digit_idx[j] = 0;

            continue;
        }

        if (c < '0' || c > '9') /* c is non-digit */{
            
            /* update digit_str indices */
            for (int j = 0; j < 10; j++) {
                
                if (digit_str[j][digit_idx[j]] != c) {
                    digit_idx[j] = 0;

                    /* remember to check if the first character matches */
                    if (digit_str[j][digit_idx[j]] == c) {
                        digit_idx[j]++;
                    }

                    continue;
                }

                digit_idx[j]++;
                if (digit_idx[j] == (int)strlen(digit_str[j])) {
                    digit_idx[j] = 0;
                    assert(digit == -1);
                    digit = j;
                }
            }
        } else /* c is digit */ {
            assert(digit == -1);
            digit = (int) (c - '0');

            /* reset all digit indices */
            for (int j = 0; j < 10; j++) digit_idx[j] = 0;
        }

        /* we got a valid digit */
        if (digit != -1) {
            last_digit = digit;
            if (first_digit == -1) {
                first_digit = digit;
            }
        }

    }
#endif

    printf("%d\n", sum);
}
