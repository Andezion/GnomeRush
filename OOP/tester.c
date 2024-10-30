#include <string.h>
#include <stdio.h>
#include "tester.h"

char *test1 = "This is";
char *test2 = " sentence.";
char *result1 = "This is sentence.";

char *test3 = "Hey bro, ";
char *test4 = "nice code";
char *result2 = "Hey bro, nice code";

char *test5 = "Damn, it's ";
char *test6 = "working!";
char *result3 = "Damn, it's working!";

void strcat_checker()
{
    int correct = 0;
    int counter = 0;

    if(my_strcat(NULL,test1) == NULL)
    {
        correct++;
    }
    counter++;
    if(my_strcat(test1,NULL) == NULL)
    {
        correct++;
    }
    counter++;
    if(my_strcat(NULL,NULL) == NULL)
    {
        correct++;
    }
    counter++;
    if(my_strcmp("This is sentence.", my_strcat(test1,test2)) == 0)
    {
        correct++;
    }
    counter++;
    if(my_strcmp("Hey bro, nice code", my_strcat(test3,test4)) == 0)
    {
        correct++;
    }
    counter++;
    if(my_strcmp("Damn, it's working!", my_strcat(test5,test6)) == 0)
    {
        correct++;
    }
    counter++;
    if(my_strcmp("This isHey bro, ", my_strcat(test1,test3)) == 0)
    {
        correct++;
    }
    counter++;
    if(strcmp("This isHey bro, ", my_strcat(test1,test3)) == 0 &&
            my_strcmp("This isHey bro, ", my_strcat(test1,test3)) == 0)
    {
        correct++;
    }
    counter++;
    if(my_strcmp("Damn, it's working!", my_strcat(test5,test6)) == 0 &&
            strcmp("Damn, it's working!", my_strcat(test5,test6)) == 0)
    {
        correct++;
    }
    counter++;

    printf("my_strcat passed %i%% tests\n",correct / counter * 100);
}

void strcmp_checker()
{
    int correct = 0;
    int counter = 0;

    if(my_strcmp("asda","assa") == 2)
    {
        correct++;
    }
    counter++;
    if(my_strcmp("asd","a") == 1)
    {
        correct++;
    }
    counter++;
    if(my_strcmp("asd","aasfs") == -1)
    {
        correct++;
    }
    counter++;
    if(my_strcmp(NULL,"This is") == 2)
    {
        correct++;
    }
    counter++;
    if(my_strcmp("This is", NULL) == 2)
    {
        correct++;
    }
    counter++;
    if(my_strcmp(NULL, NULL) == 2)
    {
        correct++;
    }
    counter++;
    if(my_strcmp(test1,"This is") == strcmp(test1,"This is"))
    {
        correct++;
    }
    counter++;
    if(my_strcmp(test2," sentence.") == strcmp(test2," sentence."))
    {
        correct++;
    }
    counter++;
    if(my_strcmp(test3,"Hey bro, ") == strcmp(test3,"Hey bro, "))
    {
        correct++;
    }
    counter++;
    if(my_strcmp(test4,"nice code") == strcmp(test4,"nice code"))
    {
        correct++;
    }
    counter++;
    if(my_strcmp(test5,"Damn, it's ") == strcmp(test5,"Damn, it's "))
    {
        correct++;
    }
    counter++;
    if(my_strcmp(test6,"working!") == strcmp(test6,"working!"))
    {
        correct++;
    }
    counter++;
    if(my_strcmp(result1,"This is sentence.") == strcmp(result1,"This is sentence."))
    {
        correct++;
    }
    counter++;
    if(my_strcmp(result2,"Hey bro, nice code") == strcmp(result2,"Hey bro, nice code"))
    {
        correct++;
    }
    counter++;
    if(my_strcmp(result3,"Damn, it's working!") == strcmp(result3,"Damn, it's working!"))
    {
        correct++;
    }
    counter++;

    printf("my_strcmp passed %i%% tests\n",correct / counter * 100);
}

void strlen_checker()
{
    int correct = 0;
    int counter = 0;

    if(my_strlen(NULL) == 0)
    {
        correct++;
    }
    counter++;
    if(strlen(test5) == my_strlen(test5))
    {
        correct++;
    }
    counter++;
    if(strlen(test6) == my_strlen(test6))
    {
        correct++;
    }
    counter++;
    if(strlen(result3) == my_strlen(result3))
    {
        correct++;
    }
    counter++;
    if(strlen(test1) == my_strlen(test1))
    {
        correct++;
    }
    counter++;
    if(strlen(test2) == my_strlen(test2))
    {
        correct++;
    }
    counter++;
    if(strlen(result1) == my_strlen(result1))
    {
        correct++;
    }
    counter++;
    if(strlen(test3) == my_strlen(test3))
    {
        correct++;
    }
    counter++;
    if(strlen(test4) == my_strlen(test4))
    {
        correct++;
    }
    counter++;
    if(strlen(result2) == my_strlen(result2))
    {
        correct++;
    }
    counter++;

    printf("my_strlen passed %i%% tests\n",correct / counter * 100);
}