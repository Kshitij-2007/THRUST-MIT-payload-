# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
int main(){
    int count=0,ncount=0,ans;
    char name[100];
    typedef struct{
        char questions[200];
        char options[4][200];
        int correct;
    } question;
    question quiz[50];
    FILE *fptr;
    fptr=fopen("quiz.txt","r");
    if(fptr==NULL)
    printf("file doesnt exist");
    while(fgets(quiz[count].questions,200,fptr)){
        quiz[count].questions[strcspn(quiz[count].questions, "\n")] = '\0';
        for (int i=0;i<4;i++){
            fgets(quiz[count].options[i],200,fptr);
            quiz[count].options[i][strcspn(quiz[count].options[i], "\n")] = '\0';
            
        }
    char temp[50];
    fgets(temp, 50, fptr);
    temp[strcspn(temp, "\n")] = '\0';
    quiz[count].correct = atoi(temp);
    count++;
    }
    fclose(fptr);
printf("//*******!!quiz time!!*******//\n");
printf("enter your name\n");
fgets(name,100,stdin);
name[strcspn(name, "\n")] = '\0';
int num;
srand(time(0));
int used[15] = {0};
for(int l=0;l<15;l++){
    do{
        num=rand()%15;
    }while(used[num] == 1);
    used[num] = 1;
    printf("%s\n",quiz[num].questions);
    for(int i=0;i<4;i++){
        printf("%d) %s\n", i+1, quiz[num].options[i]);
    }
    printf("the answer is :");
    scanf("%d",&ans);
    if (ans==quiz[num].correct){
        ncount++;
    }
}
printf("the score is %d",ncount);
FILE *fiptr ;
fiptr=fopen("scoreboard.txt","a");
fprintf(fiptr, "%s - %d\n", name, ncount);
fclose(fiptr);
return 0;
} 
