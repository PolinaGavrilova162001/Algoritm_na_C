#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, current;
int N[100], M[100];
char **pic[100];
void input(int cur, char *filename)
{
    FILE *F;
    char str[512], Pic[512][512];
    int i, len;
    len=0; m=0;
    F=fopen(filename, "r");
    while (fgets(str, 512, F))
    {
        n=strlen(str);
        if (str[n-1]=='\n') n--;
        len=n;
        strncpy(Pic[m], str, n);
        m++;

    }
//if (pic[cur]) freepic(cur);
pic[cur]=(char **)malloc(m*sizeof(char *));
for (i=0; i<m; i++)
{
    pic[cur][i]=(char *)malloc(n);
    strncpy(pic[cur][i], Pic[i], n);
}
N[cur]=n;
M[cur]=m;
printf("m=%d n=%d\n", m, n);
}

void clean(int num){
    if (pic[num]!=NULL){
        free(pic[num]);
        pic[num]=NULL;
        N[num]=0;
        M[num]=0;
        printf("Picture # %d has been cleaned\n", num);
    } else{
        printf("Picture # %d is already empty.\n", num);
    }
}

void inverse(int num){
    if (pic[num]!=NULL){
        for (int i=0; i<M[num]; i++){
            for (int j=0; j<N[num]; j++){
                pic[num][i][j]=pic[num][i][j]=='?';'*';' ';
            }
        }
        printf("Picture # %d has been inverted.\n", num);
    } else {
        printf("Picture # %d is empty.\n", num);
    }
}

void rotate_r(int num){
    if (pic[num]!=NULL){
        char temp[100][100];
        for (int i=0; i<N[num]; i++){
            for (int j=0; j<M[num]; j++){
                temp[i][j]=pic[num][M[num]-1-j][i];
            }
        }
        int tempN=M[num];
        M[num]=N[num];
        N[num]=tempN;
        
        for (int i=0; i<M[num]; i++){
            for (int j=0; j<N[num]; j++){
                pic[num][i][j]=temp[i][j];
            }
        }
        printf("Picture # %d has been rotated 90 degrees to the right.\n", num);
    } else {
        printf("Picture # %d is empty.\n", num);
    }
}

void rotate_l(int num){
    if (pic[num]!=NULL){
        char temp[100][100];
        for (int i=0; i<N[num]; i++){
            for (int j=0; j<M[num]; j++){
                temp[i][j]=pic[num][j][N[num]-1-i];
            }
        }
        int tempN=M[num]; M[num]=N[num]; N[num]=tempN;
        for (int i=0; i<M[num]; i++){
            for (int j=0; j<N[num]; j++){
                pic[num][i][j]=temp[i][j];
            }
        }
        printf("Picture # %d has been rotated 90 degrees to the left.\n", num);
    } else {
        printf("Picture # %d is empty.\n", num);
    }
}

void frame(int num, char c){
    if (pic[num]!=NULL){
        for (int i=0; i<M[num]; i++){
            for (int j=0; j<N[num]; j++){
                if (i==0||i==M[num]-1||j==0||j==N[num]-1){
                    pic[num][i][j]=c;
                }
            }
        }
        printf("Picture # %d has been framed with character '%c'\n", num, c);
    } else {
        printf("Picture # %d is empty.\n", num);
    }
}

void dotting(int num){
    if (pic[num]!=NULL){
        for (int i=0; i<M[num]; i++){
            for (int j=0; j<N[num]; j++){
                if (pic[num][i][j]==' ')
                    pic[num][i][j]='.';
            }
        }
        printf("Picture # %d has been dotted.\n", num);
    } else {
        printf("Picture # %d is empty.\n", num);
    }
}

void save(int num, char filename){
    FILE *F;
    F=fopen(filename, "w");
    for (int i=0; i<M[num]; i++){
        fputs(pic[num][i], F);
        fputc('\n', F);
    }
    fclose(F);
    printf("Picture # %d has been saved to %s\n", num, filename);
}

void output (int num)
{
    int n, m, i, j;
    printf("Picture # %d\n", num);
    m=M[num]; n=N[num];
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
            putchar(pic[num][i][j]);
        putchar('\n');
    }
    
}
int main(int argc, char *argv[])
{
    FILE *F, F0;
    int i;
    char filename[256]="picl.txt";
    
    char pic1_filename[256]="pic1.txt";
    char pic2_filename[256]="pic2.txt";
    char pic3_filename[256]="picB.txt";
    
    char save_pic1[256]="saved_pic1.txt";
    char save_pic2[256]="saved_pic2.txt";
    char save_pic3[256]="saved_picB.txt";
    
    for (i=0; i<100; i++) pic[i]=NULL;
    
    F=fopen(filename, "r");
    input(0, filename);
    output(0);
    
    input(1, pic1_filename);
    output(1);
    dotting(1);
    output(1);
    save(1, save_pic1);
    
    input(2, pic3_filename);
    output(2);
    frame(2, '+');
    output(2);
    save(2, save_pic2);
    
    fclose(F);
    return 0;
}
