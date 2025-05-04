//Program to calculate the area of different shapes
#include<iostream>

class Area{
    int leng,bre,height;
public:
    Area(){
        leng=1;
        bre=1;
        height=1;
    }

    Area(int l,int b,int h){
        leng=l;
        bre=b;
        height=h;
    }

    void setleng(int l);
    void setbre(int b);
    void setheight(int h);

    int square(){
        return leng*leng;
    }

    int rectangle(){
        return leng*bre;
    }

    int cube(){
        int ans=6*leng*leng;
        return ans;
    }

    int cuboid(){
        int calc=(leng*bre)+(bre*height)+(leng*height);
        int ans=2*calc;
        return ans;
    }
};



int main(){

    Area obj1;
    int length,breadth,height;
    int choice;
    printf("Enter the length:");
    scanf("%d",&length);

    printf("\nEnter the breadth:");
    scanf("%d",&breadth);

    printf("\nEnter the height:");
    scanf("%d",&height);
    
    
    while(1){
        // printf("Enter the length:");
        // scanf("%d",&length);

        // printf("\nEnter the breadth:");
        // scanf("%d",&breadth);

        // printf("\nEnter the height:");
        // scanf("%d",&height);

        printf("Enter 1.To calculate area of square,2.For cuboid,3.For rectangle,4.For cube,5.To change the dimensions:,6.To exit\n");
        scanf("%d",&choice);

        if(choice==1){
            obj1.setleng(length);
            printf("The area of a square is %d\n",obj1.square());


        }

        else if(choice==2){
            obj1.setleng(length);
            obj1.setbre(breadth);
            obj1.setheight(height);
            printf("The area of the cuboid is %d\n",obj1.cuboid());
        }

        else if(choice==3){
            obj1.setleng(length);
            obj1.setbre(breadth);
            printf("The area of the rectangle is %d\n",obj1.rectangle());
        }

        else if(choice==4){
            obj1.setleng(length);
            printf("The area of the square is %d\n",obj1.square());
        }

        else if(choice==5){
            printf("Enter the length:");
            scanf("%d",&length);

            printf("\nEnter the breadth:");
            scanf("%d",&breadth);

            printf("\nEnter the height:");
            scanf("%d",&height);
        }

        else if(choice==6){
            break;
        }
        else{
            printf("Invalid choice.Please try again");
        }
    }
    
    
    
    return 0;
}

void Area::setleng(int l){
    leng=l;
}

void Area::setbre(int b){
    bre=b;
}

void Area::setheight(int h){
    height=h;
}