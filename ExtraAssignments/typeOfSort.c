#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    if(strcmp(a, b) > 0){
        return 1;
    }
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    if(strcmp(a, b) > 0){
        return 0;
    }
    return 1;
}

int counts(const char* str){
    int i, j;
    int count = 0;
    for (i = 0; i < strlen(str); i++){
    int appears = 0;
    for (int j = 0; j < i; j++){
        if (str[j] == str[i]){
            appears = 1;
                break;
            }
        }
        if (!appears){
            count++;
        }
    }
    return count;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    if(counts(a) > counts(b)){
        return 1;
    } else if (counts(a) == counts(b)){
        if(strcmp(a, b) > 0)
            return 1;
    }
    return 0;
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a) > strlen(b)){
        return 1;
    } else if (strlen(a) == strlen(b)) {
        if(strcmp(a, b) > 0)
            return 1;
    }
    return 0;
}

void swap(char *a[], char *b[]){
    char *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i, j;
    for(i=0; i<len-1; i++){
        int max = i;
        for(j=i+1; j<len; j++){
            if((*cmp_func)(arr[max] , arr[j]))
                max = j;
        }
        swap(&arr[max], &arr[i]);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
