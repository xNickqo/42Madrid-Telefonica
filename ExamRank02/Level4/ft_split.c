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

#include <stdlib.h>
#include <stdio.h>

int is_space(char c){
    return (c == ' ' || (c >= 9 && c <= 13));
}

int	count_substr(const char *str) {
	int in_word = 0;
	int substr = 0;
    int i = 0;
	while (str[i]){
		if (!is_space(str[i]) && in_word == 0){
			substr++;
			in_word = 1;
		} else if (is_space(str[i]) && in_word == 1) {
            in_word = 0;
        }
		i++;
	}
	return (substr);
}

int word_length(const char *str, int start) {
    int len = 0;
    while (str[start + len] && !is_space(str[start + len])) {
        len++;
    }
    return len;
}

char	**free_split(char **split){
	int i = 0;
	while (split && split[i]) {
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

int	ft_strlcpy(char *dest, const char *src, int size){
	int i = 0;
	if (size == 0){
		while (src[i] != '\0')
			i++;
		return (i);
	}
	
    while ((i < size - 1) && src[i]){
		dest[i] = src[i];
		i++;
	}
	
    dest[i] = '\0';
	
    i = 0;
	while (src[i] != '\0')
		i++;

	return (i);
}

char **ft_split(char *str){
    if(!*str) 
        return NULL;

    //Contamos el numero de palabras
    int count_words = count_substr(str);

    //Creamos el array que se va a devolver y verificamos que no falle
    char **split = (char **)malloc((count_words + 1) * sizeof(char *));
    if(!split)
        return NULL;
    
    //Recorremos las palabras
    int i = 0;
    int j = 0;
    while(i < count_words){
        //Mientars sea un espacio lo ignoramos
        if(str[j] && is_space(str[j]))
            j++;

        //Contamos la longitud de las palabras
        int len = word_length(str, j);
        split[i] = (char *)malloc(len + 1);
        if(!split[i]) 
            return free_split(split);

        //Copiamos el contenido de la palabra en nuestro str[i]
        ft_strlcpy(split[i], &str[j], len + 1);

        //Sumamos al str la longitud de la palabra que acabamos de introducir
		j += len;

        //Pasamos a la siguiente palabra
		i++;
    }
    split[i] = NULL;

    return split;
}

int main(){
    char *str = "Hola mundo me 1llamo Nico";

    char **split = ft_split(str);
    int i = 0;
    while(split[i]){
        printf("    %s\n", split[i]);
        free(split[i]);
        i++;
    }
    free(split);
}