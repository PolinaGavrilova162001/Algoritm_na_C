#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 100

struct tnode {
    int count;
    char word[MAX_WORD_SIZE];
    struct tnode *left;
    struct tnode *right;
}

int Strcmp(char *a, char *b){
    
}

struct tnode* createtnode(char *word){
    struct tnode* newtnode = (struct tnode*)malloc(sizeof(struct tnode));
    strncpy(newtnode->word,word,MAX_WORD_SIZE);
    newtnode->left = NULL;
    newtnode->right = NULL;
    newtnode->count = 1;
    return newtnode;
}

void inserttnode(struct tnode **root, char *word){
    if(*root == NULL){
        *root = createtnode(word);
    {else{
        if(Strcmp(word,(*root)->word)<0){
            inserttnode(&(*root)->left, word);
        }else{
            inserttnode(&(*root)->right, word);
        }
    }
}

void inorderTraversal(struct tnode *root, FILE *outputFile){
    if(root != NULL){
        inorderTraversal(root->left, outputFile);
        fprintf(outputFile, "%s\n", root->word);
    }
}

int main(int argc, char*argv[])
{
    struct tnode *root = NULL;
FILE *f; char S[256], *pt;
    while(--argc){
        f=fopen(argv[argc], "r");
        while(fgets(S, 256, f) != NULL){
            pt=strtok(S, " .,;:/!?()[]*\n""");
            printf("<%s>\n", pt);
        //  inserttnode(root, pt);
        //  while(pt=strtok(NULL, " .,;:/!?()[]*\"\'")!=NULL)
        
            //inserttnode(root, pt);
            printf("%s\n", S);
            
            
        }
        getchar();
        
        //root = tree_insert(root, x);
    }
}
