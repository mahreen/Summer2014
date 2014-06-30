 
#include <stdio.h>
#include <stdlib.h>

// This includes the /declaratinos/ of the functions that you write
// in this assignment. Including the declarations allows you to use
// the functions in this file.

#include "answer01.h"

#define BUFFER_LEN 1024

void printArray(int * array, int len)
{
    printf("{");
    int ind;
    for(ind = 0; ind < len; ++ind) {
	printf("%d", array[ind]);
	if(ind != len - 1) {
	    printf(", ");
	}
    }
    printf("}");
    // If we don't include a '\n' character, then we need to 
    // include this line to ensure that our output is printed immediately.
    fflush(stdout); 
}

void test_arraySum(int * array, int len, int expected)
{
    printArray(array, len);
    int sum = arraySum(array, len);
    printf(". sum = %d, expected = %d.", sum, expected);
    if(sum != expected)
	printf(" FAIL");
    printf("\n");
}

void test_00_arraySum()
{
    printf("Testing arraySum(...)\n");

    // Here we use "static initialization" to create an array
    int array1[] = { -4, -1, 0, 1, 5, 10, 20, 21 };
    int len1 = 8;
    int expected1 = 52;
    test_arraySum(array1, len1, expected1);

    // Our functions must always work... even on empty arrays
    int array2[] = {};
    int len2 = 0;
    int expected2 = 0;
    test_arraySum(array2, len2, expected2);

    // You can add more test-cases here
    // ...

    printf("\n"); // Tidy output is easier to use
}

void test_arrayCountNegative(int * array, int len, int expected)
{
    printArray(array, len);
    int count = arrayCountNegative(array,len); 
    printf(". count = %d, expected = %d.", count, expected);
    if(count != expected)
	printf(" FAIL");
    printf("\n");
}

void test_01_arrayCountNegative()
{
    printf("Testing arrayCountNegative(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayCountNegative(array1, len1, 1);

    int array2[] = {};
    int len2 = 0;
    test_arrayCountNegative(array2, len2, 0);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayCountNegative(array3, len3, 0);

    int array4[] = { -1, -2, -3, -4 };
    int len4 = 4;
    test_arrayCountNegative(array4, len4, 4);

    // You can add more test-cases here
    // ...

    printf("\n");
}

int main(int argc, char * * argv)
{
    printf("Welcome to ECE264, we are working on PA01.\n"
	   "\n"
	   "You are encouraged to edit this file in order to test\n"
	   "the behavior of the functions you write in answer02.c\n"
	   "\n"
	   "This file will not be marked, and should not be\n"
	   "submitted.\n"
	   "\n"
	   "Don't forget to post questions on blackboard, and ask\n"
	   "the TAs and your classmates for help.\n"
	   "\n");

    // Uncomment to run two example (incomplete) testcases.
    // test_00_arraySum();
    // test_01_arrayCountNegative();

    // Below are some testcases for the latter part of the assignment.
    // These testcases are incomplete, and are guides to get you started.

    const char * s1 = "Hello World!";
    const char * s2 = "";
    const char * s3 = "foo";

    printf("my_strlen, should be: 12, 0, and 3)\n");

    printf("my_strlen(\"%s\") = %d\n", s1, (int) my_strlen(s1));
    printf("my_strlen(\"%s\") = %d\n", s2, (int) my_strlen(s2));
    printf("my_strlen(\"%s\") = %d\n", s3, (int) my_strlen(s3));
    
    printf("---------------------------------------------------------------\n\n");

    printf("arrayRFind... haystack  = { 1, 4, -5, 4} \n");
    int haystack[] = { 1, 4, -5, 4 };
    int lenn = 4;
    int x1 = arrayIndexRFind(1, haystack, lenn); // x1 == 0
    int x2 = arrayIndexRFind(4, haystack, lenn); // x2 == 3
    int x3 = arrayIndexRFind(6, haystack, lenn); // x3 == -1

    printf(" arrayIndexRFind(1, haystack, len); // (expected x1 == 0) %d\n", x1);
    printf(" arrayIndexRFind(4, haystack, len); // (expected x2 == 3) %d\n", x2); 

    printf("---------------------------------------------------------------\n\n\n\n");


 printf("arrayFindSmallest... array = {0,1,5,3,6,-1 } array2 = {0, 1, 2, -5, -6,10}\n");
 int array[] = {0, 1, 5, 3, 6, -1};
 int array2[] = {6, 1, 2, -5, -6, 10};
    int len = 6;
    int ind1 = arrayFindSmallest(array, len); // ind1 == 0
    int ind2 = arrayFindSmallest(array2, len); // ind2 == 0
    printf("arrayFindSmallest(array,len) = %d (expected 5)\n", ind1);
    printf("arrayFindSmallest(array2, len) = %d (expected 4)\n", ind2);
    printf("---------------------------------------------------------------\n\n\n\n");

    printf("my_strchr, should be: llo World!, null, and whitespace\n");

    printf("my_strchr(\"%s\", 'W') = %s\n", s1, my_strchr(s1, 'W'));
    printf("my_strchr(\"%s\", 'o') = %s\n", s2, my_strchr(s2, 'o'));
    printf("my_strchr(\"%s\", '\\0') = %s\n", s3, my_strchr(s3, '\0'));

    printf("---------------------------------------------------------------\n\n\n\n");

    printf("my_strstr, should be: World!, Hello World!, (null)\n");

    printf("my_strstr(\"%s\", \"World\") = %s\n", s1, my_strstr(s1, "World"));
    printf("my_strstr(\"%s\", \"\") = %s\n", s1, my_strstr(s1, ""));
    printf("my_strstr(\"%s\", \"hello\") = %s\n", s1, my_strstr(s1, "hello"));

    printf("---------------------------------------------------------------\n\n\n\n");

    printf("my_strcpy. For this function you need a buffer where you copy the string to.");

    char buffer[BUFFER_LEN];
    s1 = "Hello World";
    my_strcpy(buffer, "Hello World");
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s1, buffer);
    my_strcpy(buffer, s2);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s2, buffer);
    my_strcpy(buffer, s3);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s3, buffer);

    printf("---------------------------------------------------------------\n\n\n\n");

    printf("my_strcat. You will have to do this yourself\n");

    char strcat_var[50];
    my_strcpy(strcat_var, "Hello ");
    printf("my_strcat ('Hello ', 'Zippy!') = %s\n", my_strcat(strcat_var, "Zippy!")); // prints "Hello Zippy!"

    printf("---------------------------------------------------------------\n\n\n\n");

    printf("my_isspace. You will have to do this for yourself.\n");

    printf("space = %d\n", my_isspace(' ')); // 1
    printf("slash f = %d\n",my_isspace('\f')); // 1
    printf("slash n = %d\n", my_isspace('\n')); // 1
    printf("t = %d\n)", my_isspace('t')); // 0


    my_isspace('\r'); // 1
    my_isspace('\t'); // 1
    my_isspace('\v'); // 1
    char ch;
    printf("A to Z : ");
    for(ch = 'A'; ch <= 'Z'; ++ch)
      printf("%d ", my_isspace(ch)); // always 0
    printf("\n");
    printf("---------------------------------------------------------------\n\n\n\n");

    printf("my_atoi. You will have to do this for yourself.\n");
    printf("Temp is %d\n", my_atoi("Today is blah blah blah 80 degrees"));

    printf("---------------------------------------------------------------\n\n\n\n");

    return EXIT_SUCCESS;
}


