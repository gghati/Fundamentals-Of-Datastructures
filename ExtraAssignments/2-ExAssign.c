/*

REFER HACKERRANK PRACTICE PROBLEM:

https://www.hackerrank.com/challenges/querying-the-document/problem?isFullScreen=false

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m)
{ 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char ** str_split(char * text, const char a_const){
    char ** new_sen;
    size_t count = 0;
    char * tmp = text; 
    char * last_word = 0;
    char delim[2] = {a_const, 0};

    while(*tmp){
        if(a_const == *tmp){
            count++;
            last_word = tmp;
        }
        tmp++;
    }
    count += last_word < (text + strlen(text) - 1);
    count++;

    new_sen = malloc(sizeof(char*) * count);

    if (new_sen){
        size_t idx  = 0;
        char* token = strtok(text, delim);

        while (token){
            assert(idx < count);
            *(new_sen + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(new_sen + idx) = 0;
    }

    return new_sen;
}

char**** get_document(char* text) {
    assert(text != NULL);
    char** para = str_split(text, '\n');
    
    int count = 0;
    while (para[count] != NULL) {
        count++;
    }
    
    char**** doc = malloc((count+1)*sizeof(char***));			// set last position to NULL for the user
    doc[count] = NULL;											// to know when the array ends. 
    
    int i = 0;
    while (para[i] != NULL) {
        char** sentences = str_split(para[i], '.');
        int nsen = 0;
        while(sentences[nsen] != NULL) {
            nsen++;
        }
        
        doc[i] = malloc((nsen+1)*sizeof(char**));
        doc[i][nsen] = NULL; 
        
        int j = 0;
        while (sentences[j] != NULL) {
            doc[i][j] = str_split(sentences[j], ' ');
            j++;
        }
        i++;
    }
    return doc;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// REFER ABOVE CODE ONLY!

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
