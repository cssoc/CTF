#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,i,j,a,b,nrLetters,check[30],appearance[30],app2[30];
double percentage[30];
char s[1001000],t[1001000],ch[1001000],flag[100],flagAnswer[100];
FILE *f,*g;
int main(){
    f = fopen("MonoSub.in","r");
    g = fopen("MonoSub.out","w");
    srand(time(0));
    char cypher[30] = {'q','j','r','c','a','e','n','k','g','x','t','p','z'
                       ,'h','m','i','l','u','o','s','b','w','v','f','d','y'};
    //After running the code below for a random number of times in which I
    //randomize the letters in the alphabet, the resultant substitution
    //alphabet is the one at the top of this comment

    /*b = rand() % 500;
    while(b--){
        for(i=0;i<=26;i++){
            check[i] = 0;
        }
        for(i=0;i<26;i++){
            a = rand() % 26;
            while( check[a] ){
                a = rand() % 26;
            }
            check[a] = 1;
            cypher[i] = a + 'a';
        }
    }
    for(i=0;i<26;i++){
        fprintf(g,"%c,",cypher[i]);
    }*/

    //Now we will encode the text that is included in the MonoSub.in file and
    //and the output is in the MonoSub.out file
    //Note: the text is an excerpt from "The Winds of Winter" by GRRM

    //However, first we have to check that the text we input has the correct
    //letter distribution or something close to it
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
    //This is just the sheer number of appearances for each letter
    /*for(i=0;i<26;i++){
        fprintf(g,"%c: %d\n",i + 'a',appearance[i]);
    }*/

    //now we compute the percentages to see if they are close to those
    //that I have seen on the wikipedia page:
    //https://en.wikipedia.org/wiki/Letter_frequency

    for(i=0;i<26;i++){
        percentage[i] = ( 1.0 * appearance[i] ) / ( 1.0 * nrLetters ) * 100;
        fprintf(g,"%c: %.5lf\n",i + 'a', percentage[i]);
    }
    fprintf(g,"\n\n\n\n");

    //It seems that they are quite close, but if someone wants, you can
    //tell me to include another text that will be closer to the distribution


    //Now, let us encode it.
    //Also, should we let the text with characters such as: '.','?',';', etc;
    //as this would help the participants a little bit or write them in blocks
    //of 5 characters?
    for(i=0;i<n;i++){
        t[i] = s[i];
        if( s[i] >= 'a' && s[i] <= 'z' ){
            t[i] = cypher[ s[i] - 'a' ];
            fprintf(g,"%c",t[i]);
        }
        else
            fprintf(g,"%c",s[i]);
    }
    fprintf(g,"\n\n\n\n");

    //Now, let's decode it to check if we did any mistakes.

    for(i=0;i<n;i++){
        if( t[i] >= 'a' && t[i] <= 'z' ){
            for(j=0;j<26;j++){
                if( t[i] == cypher[j] ){
                    ch[i] = j + 'a';
                    app2[ ch[i] - 'a' ] ++;
                    break;
                }
            }
            fprintf(g,"%c",ch[i]);
        }
        else
            fprintf(g,"%c",t[i]);
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
    //Yup, it is ok

    //Now, let's create the flag and encode it
    //The flag is: Never gonna give you up. Never gonna let you down.
    n = 0;
    fscanf(f,"%c",&flagAnswer[n]);
    while(flagAnswer[n] != '0'){
        fscanf(f,"%c",&flagAnswer[++n]);
    }
    fprintf(g,"\n\n\n%s\n\n\n",flagAnswer);
    for(i=0;i<n;i++){
        flag[i] = flagAnswer[i];
        if( flagAnswer[i] >= 'A' && flagAnswer[i] <= 'Z' )
            flagAnswer[i] = flagAnswer[i] + 'a' - 'A';
        if( flagAnswer[i] >= 'a' && flagAnswer[i] <= 'z' ){
            flag[i] = cypher[ flagAnswer[i] - 'a' ];
            fprintf(g,"%c",flag[i]);
        }
        else
            fprintf(g,"%c",flagAnswer[i]);
    }
    fprintf(g,"\n\n\n\n");
    fclose(f);
    fclose(g);
    return 0;
}
