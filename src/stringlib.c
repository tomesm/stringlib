#include <stdio.h>
#include "../include/stringlib.h"


unsigned int str_len(const char source[])
{
    if (source == NULL)
        return 0;
    unsigned int ret = 0;
    while (*(source + ret) != '\0')
        ret++;
    return ret;
}


int is_palindrome(const char input[])
{
    int len = str_len(input);
    const char *first = input;
    const char *last = input + len - 1;
    
    while (first < last) {
        // comparing alpha characters only
        if (is_space(*first)){
            first++;
        } else if (is_space(*last)){
            last--;
        } else if (to_lower(*first) == to_lower(*last)) {
            first++;
            last--;
        } else {
            return 0;
        }
    }
    return 1;
}


int str_rotate(const char source[], char destination[], int number)
{
    if (number < 0)
        return -1;
    
    int len = str_len(source);
    if (len == 0)
        return 0;
    
    char first = source[0];
    char *string = (char *) malloc(len);
    str_cp(string, (char *) source);
    
    for (int i = 0; i < number; i++) {
        // put last source into first dest position
        destination[0] = string[len - 1];
        for (int j = 0; j < len - 1; j++) {
            destination[j + 1] = string[j];
        }
        if (number > 1)
            str_cp(string, destination);
    }
    destination[len] = '\0';
    
    for (int j = 0; j < len; j++) {
        if (first == destination[j])
            return j;
    }

    return -1;
}


char *str_cp(char *result, char *origin)
{
    if (origin == NULL)
        return 0;
    char *ret = result;
    while ((*result++ = *origin++) != '\0')
        ;
    return ret;
}


size_t str_cchr(const char *string, char ch)
{
    if (string == NULL)
        return 0;
    int count = 0;
    while (*string != '\0')
        if (*string++ == ch)
            count++;
    return count;
}



int str_cmp(const char *first, const char *second)
{
    if (first == NULL )
        return 0;
    if (second == NULL )
        return 0;
    while(*first && (*first == *second))
        first++, second++;
    return *(const unsigned char*) first - *(const unsigned char*) second;
}


int str_cmpn(const char *first, const char *second, size_t n)
{
    if (first == NULL )
        return 0;
    if (second == NULL )
        return 0;
    while (n--) {
        if (*first++ != *second++)
            return *(unsigned char*) (first-1) - *(unsigned char*) (second-1);
    }
    return 0;
}


size_t str_count_substr(const char *original, const char *substring)
{
    if (original == NULL )
        return 0;
    if (substring == NULL )
        return 0;
    size_t count = 0;
    int origlen = str_len(original);
    int sublen = str_len(substring);
    for (int i = 0; i < origlen; i++) {
        if (str_cmpn(original + i, substring, sublen) == 0)
            count++;
    }
    return count;
}


const char *str_find_chr(const char *original, const char ch)
{
    int len = str_len(original);
    for (int i = 0; i < len; i++) {
        if (*(original + i) == ch) return original + i;
    }
    return NULL;
}

const char *str_find_substr(const char *orig, const char *sub)
{
    if (orig == NULL )
        return 0;
    if (sub == NULL )
        return 0;
    int origlen = str_len(orig);
    int sublen = str_len(sub);
    for (int i = 0; i < origlen; i++) {
        if (str_cmpn(orig + i, sub, sublen) == 0)
            return orig + i;
    }
    return NULL;
}

char *str_to_upper(const char *origin, char *result)
{
    if (origin == NULL )
        return NULL;
    if (result == NULL )
        return NULL;
    for(int i = 0; *(origin + i) != '\0'; i++) {
        if (!is_alpha(*(origin + i))) {
            result[i] = *(origin +i);
        } else {
            if (is_upper(*(origin + i)))
                result[i] = *(origin +i);
            else
                result[i] = to_upper(*(origin +i));
        }
    }
    return result;
}

char *str_to_lower(const char *origin, char *result)
{
    if (origin == NULL )
        return NULL;

    for(int i = 0; *(origin + i) != '\0'; i++) {
        if (!is_alpha(*(origin + i))) {
            result[i] = *(origin +i);
        } else {
            if (is_lower(*(origin + i)))
                result[i] = *(origin +i);
            else
                result[i] = to_lower(*(origin +i));
        }
    }
    return result;
}

void str_ins_sort(char *string, int (*cmp)(char a, char b))
{
    if (string == NULL)
        return;
    if (cmp== NULL)
        return;
    int strlen = str_len(string);
    int i = 0;
    int j = 0;
    char key;
    for (i = 1; i < strlen; i++) {
        key = string[i];
        j = i-1;
        while (j >= 0 && cmp(string[j], key)){
            string[j+1] = string[j];
            j = j-1;
        }
        string[j+1] = key;
    }
}

// some of my clibs

int is_lower(char c)
{
    return (c >= 'a' && c<= 'z');
}

int is_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int to_lower(char c)
{
    if(c >= 65 && c <= 90){
        return c + 32;
    }
    return c;
}

int to_upper(char c)
{
    if(c >= 97 && c <= 122){
        return c - 32;
    }
    return c;
}

int is_alpha(char c )
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int is_space(int c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
