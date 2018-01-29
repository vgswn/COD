#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()  {
    char input[100],*l,*r,*temp,tempprod[20],productions[25][50];
    int i=0,j=0,flag=0;
    printf("Enter the production: ");
    scanf("%s",input);
    l = strtok(input,"->");
    r = strtok(NULL,"->");
    temp = strtok(r,"|");

    while (temp){
        strcpy(productions[i++] , temp);
        temp = strtok(NULL,"|");
    }

    char prod1[100], prod2[100];
    char spl[2];
    spl[0]=productions[0][0];
    spl[1]='\0';
    strcat(prod1,l);
    strcat(prod1,"->");
    strcat(prod1,spl);
    strcat(prod1,l);
    strcat(prod1,"'");



    strcat(prod2,l);
    strcat(prod2,"'");
    strcat(prod2,"->");

    for(j=0; j < i; j++){
        if (productions[j][0] == productions[0][0]){
            strcat(prod2,"|");
            char a[10];
            int xx = 1;
            while(productions[j][xx]!='\0'){
                a[xx-1] = productions[j][xx];
                xx++;
            }
            a[xx-1]='\0';
            strcat(prod2, a);

        } else {
            strcat(prod1,"|");
            strcat(prod1,productions[j]);
        }
    }
    printf("%s\n",prod1);
    printf("%s\n",prod2);

}
