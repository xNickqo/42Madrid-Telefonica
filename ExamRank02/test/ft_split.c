/*

Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_space(char c) {
    if (c == ' ' || (c >= 9 && c <= 13))
        return 1;
    return 0;
}

char **free_split(char **split){
    int i = 0;
    while (split && split[i]){
        free(split[i]);
        i++;
    }
    free(split);
    return NULL;
}

int count_words(char *str){
    int i = 0;
    int in_word = 0;
    int word = 0;
    while (str[i]){
        if(in_word == 0 && !is_space(str[i]))
        {
            word++;
            in_word = 1;
        }
        else if (is_space(str[i]) && in_word == 1) {
            in_word = 0;
        }
        i++;
    }
    return word;
}

int word_length(char *str, int start){
    int len = 0;

    while(!is_space(str[start]) && str[start]){
        start++;
        len++;
    }
    
    return len;
}

void ft_strlcpy(char *dest, char *src, int len){
    int i = 0;
    while(src[i] && i < len){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char    **ft_split(char *str){
    int words = count_words(str);
    //printf("count_words: %d\n", words);

    char **split = (char **)malloc((words + 1) * sizeof(char *));
    if(!split)
        return NULL;
    
    int i = 0;
    int j = 0;
    while(i < words){
        while(str[j] && is_space(str[j]))
            j++;
        
        int len = word_length(str, j);
        //printf("word_lenght: %d\n", len);

        split[i] = (char *)malloc(len + 1);
        if(!split[i]) 
            return free_split(split);

        ft_strlcpy(split[i], &str[j], len);

        j += len;

        i++;
    }
    split[i] = NULL;
    return split;
}

int main(){
    char *str = "   Hola    mundo 12    34      ";

    char **split = ft_split(str);
    int i = 0;
    while(split[i]){
        printf("    %s\n", split[i]);
        free(split[i]);
        i++;
    }
    free(split);
}