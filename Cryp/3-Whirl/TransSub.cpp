#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,i,j,a,b,row,column,keySize,check[10],appearance[30];
char solution[1001000],flag[1001000],grid[1010][1010],sortedGrid[1010][1010];
FILE *f,*g;
int main(){
    f = fopen("TransSub.in","r");
    g = fopen("TransSub.out","w");
    srand(time(0));
    keySize = 6;
    int key[10]={3,1,5,4,0,2};
    //we randomly generate the key, with the mention that it is 6 characters
    //long also, for ease of programming I will only generate the positions
    //that will be use to encode the text rather than generate a word and then
    //convert the letters to digits to do the same things
    //after running the randomizing code below for a random number of times
    //what we get is at the top of the comments
    /*b = rand() % 500;
    while(b--){
        for(i=0;i<6;i++){
            check[i] = 0;
        }
        for(i=0;i<6;i++){
            a = rand() % 6;
            while( check[a] ){
                a = rand() % 7;
            }
            check[a] = 1;
            key[i] = a ;
        }
    }
    for(i=0;i<6;i++){
        fprintf(g,"%d,",key[i]);
    }*/
    //Our flag is "Captain Phasma is a double agent", which is obviously
    //a reference to the Star Wars Franchise. Here, I simply write the flag
    //in a grid, this being the first step in the encoding
    fscanf(f,"%c",&solution[n]);
    row = column = 0;
    while( solution[n] != '0' ){
        if( solution[n] >= 'A' && solution[n] <= 'Z' )
            solution[n] = solution[n] + 'a' - 'A';
        if( solution[n] >= 'a' && solution[n] <= 'z' ){
            if( column ==  keySize ){
                column = 0;
                grid[++row][column++] = solution[n] - 'a' + 'A';
            }
            else
                grid[row][column++] = solution[n] - 'a' + 'A';
        }
        fscanf(f,"%c",&solution[++n]);
    }
    for(i=0;i<=row;i++){
        for(j=0;j<keySize;j++){
            if(grid[i][j])
                fprintf(g,"%c",grid[i][j]);
        }
        fprintf(g,"\n");
    }
    fprintf(g,"\n\n\n\n");
    //Now, we need to sort the column of the grid in the order given by the
    //key. In order to do this and to keep the original grid, we use a new
    //one
    for(i=0;i<keySize;i++){
        column = key[i];
        for(j=0;j<=row;j++){
            if(grid[j][column])
                sortedGrid[j][i] = grid[j][column];
        }
    }
     for(i=0;i<=row;i++){
        for(j=0;j<keySize;j++){
            if(sortedGrid[i][j])
                fprintf(g,"%c",sortedGrid[i][j]);
            else
                fprintf(g," ");
        }
        fprintf(g,"\n");
    }
    //Now let us check that the 2 grids have the same letters in them
    for(i=0;i<=row;i++){
        for(j=0;j<keySize;j++){
            if(grid[i][j] >= 'A' && grid[i][j] <= 'Z')
                appearance[ grid[i][j] - 'A' ] ++;
            if(sortedGrid[i][j] >= 'A' && sortedGrid[i][j] <= 'Z')
                appearance[ sortedGrid[i][j] - 'A' ] --;
        }
    }
    int ok = 1;
    for(i=0;i<26;i++){
        if(appearance[i] != 0){
            ok = 0;
            fprintf(g,"WROOOOOOOOOOOOOOOOONG!");
            break;
        }
    }
    if(ok)
        fprintf(g,"NICE, IT WORKS!");
    fprintf(g,"\n\n\n\n");

    //for the last part of the code we have to print the sortedGrid from left
    //to right in blocks of 5 characters and between them a ' ' character
    int currentBlockSize = -1;
    int flagSize = 0;
    /*for(i=0;i<=row;i++){
        for(j=0;j<keySize;j++){
            if(sortedGrid[i][j])
                if(currentBlockSize == 4){
                    fprintf(g," %c",sortedGrid[i][j]);
                    flag[++flagSize] = ' ';
                    flag[++flagSize] = sortedGrid[i][j];
                    currentBlockSize = 0;
                }
                else{
                    fprintf(g,"%c",sortedGrid[i][j]);
                    flag[++flagSize] = sortedGrid[i][j];
                    currentBlockSize++;
                }
        }
    }*/
    for(j = 0; j < keySize; j ++){
      for(i = 0; i <= row; i ++){
        if(sortedGrid[i][j])
            if(currentBlockSize == 4){
                fprintf(g," %c",sortedGrid[i][j]);
                flag[++flagSize] = ' ';
                flag[++flagSize] = sortedGrid[i][j];
                currentBlockSize = 0;
            }
            else{
                fprintf(g,"%c",sortedGrid[i][j]);
                flag[++flagSize] = sortedGrid[i][j];
                currentBlockSize++;
            }
      }
    }
    fclose(f);
    fclose(g);
    return 0;
}