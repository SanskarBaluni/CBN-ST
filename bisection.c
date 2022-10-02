#include<stdio.h>
#include<math.h>

float findvalueat(float x)
{
    return x*x*x-2*x-5;
}

float bisect(float x1,float x2)
{
    return (x1+x2)/2;
}

int main()
{
    int iteration,i=1;
    float x1,x2,x;
    printf("Enter number of iterations\n");
    scanf("%d",&iteration);
    do
    {
        printf("Enter value of x1 and x2 starting boundary");
        scanf("%f%f",&x1,&x2);
        if(findvalueat(x1)*findvalueat(x2)>0)
        {
            printf("Roots are Invalid\n");
            continue;
        }
        else
        {
            printf("Roots lie between %f and %f\n",x1,x2);
            break;
        }
    }while(1);//infinite loop

    while(i<iteration)
    {
        x=bisect(x1,x2);
        if(findvalueat(x)*findvalueat(x1)<0)
        x2=x;
        else if(findvalueat(x)*findvalueat(x2)<0)
        x1=x;
        printf("\t iterations =%d    Roots=%f \n",i++,x);
    }
    printf("\n\tRoots =%f    Total iterations=%d\n",x,--i);
    return 0;
}
