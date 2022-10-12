/*input initial x1,x2,maximum no of iterations(n)
while(you give x1,x2 such that f(x1)*f(x2)>0 )
keep asking user for x1,x2
i=1;
x= (x1*f(x2) - x2 * f(x1)) / (f(x2) - f(x1))
do{
if(f(x)*f(x1)<0)
  x2=x;
else
  x1=x;

x= (x1*f(x2) - x2 * f(x1)) / (f(x2) - f(x1))
if(abs(x3-x)<0.0001)// cheching if value of previous iteration is matching of within the threshold
  print x;
  return;
  x=x3;
  i++;
}while(i<=n);
Print x  // x is the root
*/
#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001 //3 decimal places
float findValueAt(float x)
{
   return x*x*x - 2*x -5;
}
float findX(float x1,float x2)
{
    // return (x1+x2)/2;  //for Bisection Method
      return (x1*findValueAt(x2) - x2 * findValueAt(x1)) / (findValueAt(x2) - findValueAt(x1));
}
int main()
{
    int maxIteration,i=1;
    float x1,x2,x3,x;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);
   //Finding x1 and x2
   do
   {
        printf("Enter the value of x1 and x2(starting boundary->Initial Roots)");
        scanf("%f%f",&x1,&x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
           printf("Roots are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;
        }
    } while(1);
    //find the Intermediate point
    x = findX(x1,x2);

    do
    {
      if(findValueAt(x)*findValueAt(x1)<0)
         x2=x;
      else
         x1=x;
      printf("Iterations=%d  Root=%f\n",i,x);
      x3 = findX(x1,x2);
      if(fabs(x3-x)<EPSILON)
      {
          printf("Root=%f  Total Iterations=%d",x,i);
          return 0;
      }
      x=x3;  //Important
      i++;
    }while(i<=maxIteration);
    printf("Root=%f  Total Iterations=%d",x,--i);

    return 0;
}
