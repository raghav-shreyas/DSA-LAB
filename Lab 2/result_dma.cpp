#include <cstdlib>
#include <cstdio>
#include<math.h>

bool Palindrome(int *inp){
    int *org=(int *)malloc(sizeof(int));
    int *reverse=(int *)malloc(sizeof(int));
    int *rem=(int *)malloc(sizeof(int));
    (*org)=*inp;
    *reverse=0;

    while (*org != 0){
        *rem=(*org)%10;
        *reverse=(*reverse)*10+(*rem);
        (*org)/=10;
    }
    (*org)=*inp;
    return *inp==*reverse;

}

bool Armstrong(int *inp){
    int *sum=(int *)malloc(sizeof(int));
    int *rem=(int *)malloc(sizeof(int));
    int *digit=(int *)malloc(sizeof(int));
    *sum=0;
    *digit=0;

    int *temp=(int *)malloc(sizeof(int));
    *temp=*inp;
    while ((*temp) != 0){
        (*temp)/=10;
        (*digit)++;
    }

    *temp=*inp;
    while((*temp)!=0){
        *rem=(*temp)%10;
        (*sum)+=pow(*rem,*digit);
        (*temp)/=10;
    }
    return *inp==*sum;
}

bool Perfect(int *inp){
    int *sum=(int *)malloc(sizeof(int));
    int *temp=(int *)malloc(sizeof(int));
    *sum=0;
    *temp=*inp;
    for (int i=1;i<=(*temp/2);i++){
        if ((*temp)%i==0){
            (*sum)+=i;
        }
    }
    return *inp==*sum;
}

int main(){
    int *input=(int *)malloc(sizeof(int));
    printf("Enter an integer:");
    scanf("%d", input);
    int *inp=(int *)malloc(sizeof(int));
    *inp=1;
    while (inp){
        printf("Enter 1 To check for Palindrom.\n");
        printf("Enter 2 To check for Armstrong number.\n");
        printf("Enter 3 To check for Perfect number.\n");
        printf("Enter 4 To Exit.\n");
        printf("Enter operation to perform: ");
        int *in=(int *)malloc(sizeof(int));
        scanf("%d", in);

        switch (*in)
        {
            case 1:
                if (Palindrome(input)){
                    printf("The given number is a Palindrome.\n");
                }
                else{
                    printf("The given number is not a Palindrome.\n");
                }
                break;
            case 2:
                if (Armstrong(input)){
                    printf("The given number is an Armstrong number.\n");
                }
                else{
                    printf("The given number is not an Armstrong number.\n");
                }
                break;
            case 3:
                if (Perfect(input)){
                    printf("The given number is an Perfect number.\n");
                }
                else{
                    printf("The given number is not an Perfect number.\n");
                }
                break;
            case 4:
                (*inp)=0;
                break;
        }
    }

}