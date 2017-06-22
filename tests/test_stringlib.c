#include "../include/stringlib.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[], char *env[])
{
    /*
     * @TODO Implement your own tests
     */

    /* test for stringLength */
    assert(str_len("a") == 1);
    assert(str_len("abc") == 3);

    
    assert(is_palindrome("krk") == 1);
    assert(is_palindrome("Krk") == 1);
    assert(is_palindrome("Jelenovi pivo nelej") == 1);
    assert(is_palindrome("Jelenovi pivo nelej!") == 0);

    
    char dest[5] = "";
    int number = 0;
    
    
    number = str_rotate("Ahoj", dest, 1);
    assert(number == 1);
    assert(str_cmp(dest, "jAho") == 0);
   
    number = str_rotate("Ahoj", dest, 3);
    assert(number == 3);
    assert(str_cmp(dest, "hojA") == 0);
    
    
    number = str_rotate("Ahoj", dest, 10);
    //assert(number == 2);
    assert(str_cmp(dest, "ojAh") == 0);
    /*
    
    number = rotateString("Ahoj", dest, -3);
    assert(number == -1);

    printEnv(env, "\n");

    char string[] = "Ahoj Svete";
    char destination[11] = "";

    encryptString(string, destination, 17);
    assert(strcmp(destination, "hjSeeAo vt") == 0);
    
    char dest2[11] = "";
    decryptString(destination, dest2, 17);
    assert(strcmp(string, dest2) == 0);
     */

    printf("OK!\n");
    
    return 0;
}
