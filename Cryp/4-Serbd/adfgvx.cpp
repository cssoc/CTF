#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include<ctype.h>
using namespace std;
int n,i,j,a,b,aa,keySize,nrLetters,row,column,checkTrans[100],appearance[100],app2[100],app3[100];
double percentage[30];
char c,cc,flag[100100],solution[100100],checkGrid[20][20],s[100100],t[100100][3],ch[100100],grid[1010][1010],sortedGrid[1010][1010];
char cypher[100][3] = {{'g', 'a'},{'f', 'a'},{'x', 'd'},{'x', 'g'},{'a', 'd'},{'x', 'x'},{'v', 'g'},{'d', 'a'},{'a', 'g'},{'g', 'f'},{'f', 'f'},{'d', 'x'},{'x', 'v'},{'v', 'v'},{'a', 'a'},{'x', 'a'},{'v', 'x'},{'f', 'v'},{'d', 'g'},{'f', 'd'},{'g', 'x'},{'f', 'x'},{'v', 'f'},{'f', 'g'},{'a', 'f'},{'g', 'd'}};

char grid2[1010][1010];
char sortedGrid2[1010][1010];

FILE *f,*g;
int main(){
    f = fopen("adfgvx.in","r");
    g = fopen("adfgvx.out","w");
    char letterList[7] = {'a','d','f','g','v','x'};
    srand(time(0));
    //first we have to generate the adfgvx substitution for each letter
    //we can do this by using 2 randoms, one for the first letter and
    //one for the second one, then using the cypherGrid to check if the
    //current random combination has been used before
    /*b = rand() % 500;
    while(b--){
        for(i=0;i<6;i++){
            for(j=0;j<6;j++){
                checkGrid[i][j] = 0;
            }
        }
        for(i=0;i<26;i++){
            a = rand() % 6;
            aa = rand() % 6;
            while(checkGrid[a][aa]){
                a = rand() % 6;
                aa = rand() % 6;
            }
            checkGrid[a][aa] = 1;
            cypher[i][0] = letterList[a];
            cypher[i][1] = letterList[aa];
        }
    }*/
    for(i=0;i<26;i++){
        fprintf(g,"{'%c', '%c'},",cypher[i][0],cypher[i][1]);
    }
    fprintf(g,"\n\n\n\n");
    keySize = 7;
    char transKey[7] = {2,1,6,0,3,4,5};
    //we randomly generate the key for the transposition, with the mention that
    // it is 7 characters long also, for ease of programming I will only
    //generate the positions that will be use to encode the text rather than
    //generate a word and then convert the letters to digits to do the same
    //things after running the randomizing code below for a random number of
    //times what we get is at the top of the comments
    /*b = rand() % 500;
    while(b--){
        for(i=0;i<7;i++){
            checkTrans[i] = 0;
        }
        for(i=0;i<7;i++){
            a = rand() % 7;
            while( checkTrans[a] ){
                a = rand() % 7;
            }
            checkTrans[a] = 1;
            transKey[i] = a ;
        }
    }*/
    for(i=0;i<7;i++){
        fprintf(g,"%d,",transKey[i]);
    }
    fprintf(g,"\n\n\n\n");

    //Now we have to encode the flag, first we have to encode it by substituting
    //all the letters in the alphabet with the ones we define; then we have to
    //do the transposition
    //However, for safety, let us encode the big text first by substitution

    //Now, let us check the letter distribution
    n  = nrLetters = 0;
    fscanf(f,"%c",&s[n]);
    while( s[n] != '0' ){
        if( s[n] >= 'A' && s[n] <= 'Z' )
            s[n] = s[n] + 'a' - 'A';
        if( s[n] >= 'a' && s[n] <= 'z' ){
            appearance[ s[n] - 'a' ]++;
            nrLetters ++;
        }
        fscanf(f,"%c",&s[++n]);
    }
     //now we compute the percentages to see if they are close to those
    //that I have seen on the wikipedia page:
    //https://en.wikipedia.org/wiki/Letter_frequency

    for(i=0;i<26;i++){
        percentage[i] = ( 1.0 * appearance[i] ) / ( 1.0 * nrLetters ) * 100;
        fprintf(g,"%c: %.5lf\n",i + 'a', percentage[i]);
    }
    fprintf(g,"\n\n\n\n");
    //I think it is not bad
    //Now for the encoding
    for(i=0;i<n;i++){
        t[i][0] = s[i];
        if( s[i] >= 'A' && s[i] <= 'Z' )
	    s[i] = s[i] + 'a' - 'A';
	if( s[i] >= 'a' && s[i] <= 'z' )
	{
            t[i][0] = cypher[ s[i] - 'a' ][0];
            t[i][1] = cypher[ s[i] - 'a' ][1];
            fprintf(g,"%c%c",toupper(t[i][0]),toupper(t[i][1]));
        }
        else
            fprintf(g,"%c",t[i][0]);
    }
    fprintf(g,"\n\n\n\n");
    //Now, let us check if the encoding is done correctly
     for(i=0;i<n;i++){
        if( t[i][1] != 0 ){
            for(j=0;j<26;j++){
                if(t[i][0] == cypher[j][0]   && t[i][1] == cypher[j][1]){
                    ch[i] = j + 'a';
                    app2[j]++;
                    break;
                }
            }
            fprintf(g,"%c",ch[i]);
        }
        else
            fprintf(g,"%c",t[i][0]);
    }
    int ok = 1;
    for(i=0;i<26;i++){
        if( app2[i] != appearance[i] ){
            ok = 0;
            fprintf(g,"You screwed up bro\n");
        }
    }
    if(ok)
        fprintf(g,"It WORKS!\n");
    fprintf(g,"\n\n\n\n");

    //parts that dragos missed
    //mostly just copy paste

    int keySize2 = 5;
    char transKey2[5] = {1, 2, 3, 4, 0};

    row = column = 0;
    for(i = 0; i < n - 1; i++)
    {
	if(t[i][0] >= 'a' && t[i][0] <= 'z')
	{
		for(j = 0; j < 2; j++)
		{
			if(column == keySize2)
			{
				column = 0;
				grid2[++row][column++] = t[i][j] - 'a' + 'A';
			}
			else
				grid2[row][column++] = t[i][j] - 'a' + 'A';
		}
	}
    }

    for(i = 0; i <= row; i++)
    {
	    for(j = 0; j < keySize2; j++)
	    {
		    if(grid2[i][j])
			    fprintf(g,"%c", grid2[i][j]);
	    }
    	fprintf(g, "\n");
    }
    fprintf(g, "\n\n\n\n");

    for(i = 0; i < keySize2; i++)
    {
	column = transKey2[i];
	for(j = 0; j <= row; j++)
	{
		if(grid2[j][column])
			sortedGrid2[j][i] = grid2[j][column];
	}
    }

    for(i = 0; i <= row; i++)
    {
	    for(j = 0; j < keySize2; j++)
	    {
		    if(sortedGrid2[i][j])
			    fprintf(g, "%c", sortedGrid2[i][j]);
		    else
			    fprintf(g, " ");
	    }
	    fprintf(g, "\n");
    }
        for(i=0;i<=row;i++){
        for(j=0;j<keySize2;j++){
            if(grid2[i][j] >= 'A' && grid2[i][j] <= 'Z')
                app3[ grid2[i][j] - 'A' ] ++;
            if(sortedGrid2[i][j] >= 'A' && sortedGrid2[i][j] <= 'Z')
                app3[ sortedGrid2[i][j] - 'A' ] --;
        }
    }
    ok = 1;
    for(i=0;i<26;i++){
        if(app3[i] != 0){
            ok = 0;
            fprintf(g,"WROOOOOOOOOOOOOOOOONG!");
            break;
        }
    }
    if(ok)
        fprintf(g,"NICE, IT WORKS!");
    fprintf(g,"\n\n\n\n");


    int currentBlockSize = -1;
    int flagSize = 0;
    for(j=0;j<keySize2;j++){
        for(i=0;i<=row;i++){
            if(sortedGrid2[i][j])
                if(currentBlockSize == 4){
                    fprintf(g," %c",sortedGrid2[i][j]);
                    flag[++flagSize] = ' ';
                    flag[++flagSize] = sortedGrid2[i][j];
                    currentBlockSize = 0;
                }
                else{
                    fprintf(g,"%c",sortedGrid2[i][j]);
                    flag[++flagSize] = sortedGrid2[i][j];
                    currentBlockSize++;
                }
        }
    }

    //Nice, it apparently works, now let's get on with the real encoding
    //of the flag. The flag is "The wall is completely useless"
    n  = nrLetters = 0;
    fscanf(f,"%c",&s[n]);
    while( s[n] != '0' ){
        t[n][0] = s[n];
        if( s[n] >= 'A' && s[n] <= 'Z' )
            s[n] = s[n] + 'a' - 'A';
        if( s[n] >= 'a' && s[n] <= 'z' ){
            t[n][0] = cypher[ s[n] - 'a' ][0];
            t[n][1] = cypher[ s[n] - 'a' ][1];
            fprintf(g,"%c%c",t[n][0],t[n][1]);
        }
        else
            fprintf(g,"%c",t[n][0]);
        fscanf(f,"%c",&s[++n]);
    }
    t[++n][0] = 0;
    fprintf(g,"\n\n\n\n");

    //Now we finally have the text encoded via substitution and need to
    //encode it via transition based on the transition key

    row = column = 0;
    for(i=0;i<n-1;i++){
        if( t[i][0] >= 'a' && t[i][0] <= 'z' ){
            for(j=0;j<2;j++){
                if( column ==  keySize ){
                    column = 0;
                    grid[++row][column++] = t[i][j] - 'a' + 'A';
                }
                else
                    grid[row][column++] = t[i][j] - 'a' + 'A';
            }
        }
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
        column = transKey[i];
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
                app3[ grid[i][j] - 'A' ] ++;
            if(sortedGrid[i][j] >= 'A' && sortedGrid[i][j] <= 'Z')
                app3[ sortedGrid[i][j] - 'A' ] --;
        }
    }
    ok = 1;
    for(i=0;i<26;i++){
        if(app3[i] != 0){
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
    currentBlockSize = -1;
    flagSize = 0;
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
