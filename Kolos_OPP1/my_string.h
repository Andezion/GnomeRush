#ifndef KOLOS_OPP1_MY_STRING_H
#define KOLOS_OPP1_MY_STRING_H

// strlen(+), strcat(+), strncat(+), strcmp(+), strncmp(+), strcpy(+), strncpy(+), strdup(+), strchr(+), strrchr(+)

int my_strlen(const char *word); // - длинна текста
char *my_strcat(char *word1, char *word2); // - из двух текстов - один
int my_strcmp(const char *word1, const char *word2); // - проверяем на идентичность
int my_strncmp(const char *word1, const char *word2, size_t counter); // - проверяем на идентичность определённое количество знаков
char *my_strncat(char *word1, char *word2, size_t size); // - из двух текстов создаём один с определённым количеством знаков
char *my_strcpy (char *where, const char *from); // - копируем из - в
char *my_strncpy( char *where, const char *from, size_t number); // - копируем определённое количество знаков
char * my_strchr(const char * str, int z); // - первое появление буквы
char *my_strrchr(const char * str, int ch); // - последнее появление буквы
char *my_strdup(const char * sTekst); // - создаём копию

#endif //KOLOS_OPP1_MY_STRING_H
