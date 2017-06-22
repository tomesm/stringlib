#ifndef STRINGLIB_H
#define STRINGLIB_H

#include <stdlib.h>

/**
 * Calculates length of string
 *
 * @param source
 * 
 * @return length of source string 
 */
unsigned int str_len(const char source[]);


/**
 * Verifies that source string is palindrome
 *
 * @param source the string to be verified
 * 
 * @return 1 if source is palindrome 0 otherwise 
 */
int is_palindrome(const char source[]);


/**
 * Rotates characters in string
 *
 * @param source string to be rotated
 * @param destination place where rotated string will be stored
 * @param number offset in rotation
 *
 * @return shift of first characer of source in destination, -1 if operation fails 
 */
int str_rotate(const char source[], char destination[], int number);


/**
 * Prints array of strings to stdout
 *
 * @param env array of strings to be printed
 * @param separator string which will separate strings in stdout
 *
 * @return number of printed environment variables
 */
int print_env(const char *env[], char separator[]);


/**
 * Encrypts string by rewriting index in source array
 *
 * @param source string to be encrypted
 * @param destination place where encrypted string will be stored
 * @param cipher number which will be used to calculate new index
 *
 * @return 0 if operation succeeds -1 otherwise
 */
int str_enc(const char source[], char destination[], int cipher);


/**
 * Decrypts string previously encrypted by encryptString
 * 
 * @param source string to be decrypted
 * @param destination place where decrypted string will be stored
 * @param cipher number which will be used to calculate new index
 *
 * @return 0 if operation succeeds -1 otherwise
 */
int str_dec(const char source[], char destination[], int cipher);


/**
 * Creates the string's copy
 * @param result - Where a copy will be stored
 * @param origin - From what string you will create a copy
 * @return the pointer to copied string
 */
char *str_cp(char *result, char *origin);


/**
 * Counts chars in string
 * @param string - Input string where you will count chars
 * @param ch - Char to be count
 * @return Number of occurrences of character ch
 */
size_t str_cch(const char *string, char ch);


/**
 * Compares strings
 * @param first - First string to compare
 * @param second - Second string to compare
 * @return negative if first is "greater", zero if same, positive if sencod "greater"
 */
int str_cmp(const char *first, const char *second);


/**
 * Comares first N characters of string
 * @param first - First string to compare
 * @param second - Second string to compare
 * @param n - size of compared strings
 * @return negative if first is "greater", zero if same, positive if sencod "greater"
 */
int str_cmpn(const char *first, const char *second, size_t n);


/**
 * Counts substrings in string
 * @param original - Input string where you counting substrings
 * @param substring - Substring to be count
 * @return Number of substrings
 */
size_t str_count_substr(const char *original, const char *substring);


/**
 * Finding character in string and returns the pointer to that character
 * @param original - Input string where you are trying to find character
 * @param ch - Character you are trying to find
 * @return Pointer to first occurrence of character in string, NULL if string does not contains character
 */
const char *str_find_chr(const char *original, const char ch);


/**
 * Finding substring in string and returns the pointer to beginning of that substring
 * @param original - Input string where you are trying to find character
 * @param sub - Substring you are trying to find
 * @return Pointer to first occurrence of character in string, NULL if string does not contains character
 */
const char *str_find_substr(const char *orig, const char *sub);


/**
 * Converts all letters in string to upper
 * @param origin - Original string
 * @param result - Result of operation - must be same size or greater than original string
 * @return NULL if origin or result is NULL; pointer on the beginning of result
 */
char *str_to_upper(const char *origin, char *result);


/**
 * Converts all letters in string to lower
 * @param origin - Original string
 * @param result - Result of operation - must be same size or greater than original string
 * @return NULL if origin or result is NULL; pointer on the beginning of result
 */
char *str_to_lower(const char *origin, char *result);


// TODO: create docstrings
void str_ins_sort(char *string, int (*comparator)(char , char));

int is_lower(char c);

int is_upper(char c);

int to_lower(char c);

int to_upper(char c);

int is_alpha(char c );

int is_space(int c);

#endif /* STRINGLIB_H */
