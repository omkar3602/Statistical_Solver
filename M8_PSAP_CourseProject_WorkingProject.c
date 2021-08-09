#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double sum,temp,answer=0,num1,num2;
int i,j,k,N,min,count,tempcount,choice,choice1;
char ch,ch1;

void SimpleCalculator();

void StatisticalCalculator();
void printData(double arr[],int N);
double* SelectionSort(double arr[],int N);
double ArithmeticMean(double arr[],int N);
void GeometricMean(double arr[],int N);
void HarmonicMean(double arr[],int N);
void Median(double arr[],int N);
void Mode(double arr[],int N);
void Range(double arr[],int N);
double Variance(double arr[],int N);
void StandardDeviation(double arr[],int N);

void CurveFitting();

void CorelationCoefficient();

void mainmenu();

int main()
{
        printf("\n\t\t\t\t\t\tWELCOME TO STATISTICAL SOLVER\n");
        printf("\nSelect the domain of operations:\n1.Simple Calculator\n2.Statistical Calculator\n3.Curve Fitting\n4.Coefficient of Correlation \n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
             SimpleCalculator();
             break;
        case 2:
             StatisticalCalculator();
             break;
        case 3:
            CurveFitting();
            break;
        case 4:
            CorelationCoefficient();
            break;
        default:
            printf("\n\nEnter correct choice.\n");
        }
        mainmenu();
        return 0;
}

void SimpleCalculator()
{
    system("cls");
    printf("\n\t\t\t\t\t\tSIMPLE CALCULATOR\n\n");
    printf("\nEnter first number:");
    scanf("%lf",&num1);
    printf("Enter operation (+,-,*,/,%%,^):");// "%%" used as % is used as a format specifier
    scanf(" %c",&ch);                //**VERY IMP Space before %c
    printf("Enter second number:");
    scanf("%lf",&num2);

    switch(ch)
    {
    case '+':
        printf("\n\n%.2lf %c %.2lf = %.2lf\n",num1,ch,num2,num1+num2);
        break;
    case '-':
        printf("\n\n%.2lf %c %.2lf = %.2lf\n",num1,ch,num2,num1-num2);
        break;
    case '*':
        printf("\n\n%.2lf %c %.2lf = %.2lf\n",num1,ch,num2,num1*num2);
        break;
    case '/':
        if(num2==0)
        {
            printf("\n\nCannot divide by 0.\n");
        }
        else
        {
            printf("\n\n%.2lf %c %.2lf = %.2lf\n",num1,ch,num2,num1/num2);
        }
        break;
    case '%':
        if(num2==0)
        {
            printf("\n\nCannot find remainder as cannot divide by 0.\n");
        }
        else
        {
            printf("\n\n%.2lf %c %.2lf = %.2lf\n",num1,ch,num2,fmod(num1,num2));//learn more about fmod() function
        }
        break;
    case '^':
        printf("\n\n%.2lf %c %.2lf = %.2lf\n",num1,ch,num2,pow(num1,num2));
        break;
    default:
        printf("\n\nEnter correct operator\n");
        break;
    }
}
void printData(double arr[],int N)
{
    printf("\n");
    for(i=0;i<N;i++)
    {
        printf("%.2lf ",arr[i]);
    }
    printf("\n");
}
double* SelectionSort(double arr[],int N)
{
    for(i=0;i<N-1;i++)
    {
        min=i;
        for(j=i+1;j<N;j++)
        {
            if(arr[j]<arr[min])
            {
            min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    return arr;
}
double ArithmeticMean(double arr[],int N)//double used instead of void because we need
 {                                       //ArithmeticMean in Variance function
    sum=0;
    for(i=0;i<N;i++)
    {
        sum+=arr[i];
    }
    answer=sum/N;
    return answer;
}
void GeometricMean(double arr[],int N)
{
    sum=1;
    for(i=0;i<N;i++)
    {
        sum*=arr[i];
    }
    answer=pow(sum,(1/(double)N));//** Typecasting int N into double
    printf("\n\nGeometric Mean=%.2lf\n",answer);
}
void HarmonicMean(double arr[],int N)
{
    sum=0;
    for(i=0;i<N;i++)
    {
        sum+=(1/arr[i]);
    }
    printf("%lf",sum);
    answer=N/sum;
    printf("\n\nHarmonic Mean=%.2lf\n",answer);
}
void Median(double arr[],int N)
{
    if(N%2!=0)
    {
        i=(N/2);
        answer=arr[i];
    }
    else
    {
        i=(N/2)-1;
        j=(N/2);
        answer=(arr[i]+arr[j])/2;
    }
    printf("\n\nMedian=%.2lf\n",answer);
}
void Mode(double arr[],int N)
{//**IMP Mode when same no of occurances Eg (5,5,1,2,2) Mode= 2, 5
    count=0,tempcount=0,k=0;
    double modearr[N];
    for(i=0;i<N-1;i++)
    {
        tempcount=0;
        for(j=i+1;j<N;j++)
        {
            if(arr[i]==arr[j])
            {
            tempcount++;
            }

        }
        if(tempcount>count && tempcount!=0)
        {
            k=0;
            count=tempcount;
            modearr[k]=arr[i];
            k++;
        }
        else if(tempcount==count)
        {
            modearr[k]=arr[i];
            k++;
        }
    }
    j=1;
    for(i=0;i<N;i++)
    {
        if(arr[i]==modearr[i])
        {
            j++;
        }
    }
    if(j==N)
    {
        printf("\n\nNo value is repeated in the above data.\nThere is no mode.\n");
    }
    else
    {
        printf("\n\nMode=");
        printData(modearr,k);
    }
}
void Range(double arr[],int N)
{
    answer=arr[N-1]-arr[0];
    printf("\n\nRange=%.2lf\n",answer);
}
double Variance(double arr[],int N)//double used instead of void because we need
{                                  //Variance in StandardDeviation function

    temp=ArithmeticMean(arr,N);
    sum=0;
    for(i=0;i<N;i++)
    {
        arr[i]-=temp;
        arr[i]=pow(arr[i],2);
        sum+=arr[i];
    }
    answer=sum/N;
    return answer;
}
void StandardDeviation(double arr[],int N)
{
    answer=sqrt(Variance(arr,N));
    printf("\n\nStandard Deviation=%.2lf\n",answer);
}
void StatisticalCalculator()
{
    system("cls");
    printf("\n\t\t\t\t\t\tSTATISTICAL SOLVER\n\n");
    printf("\nSelect Operation:\n\n1.ArithmeticMean\n2.GeometricMean\n3.HarmonicMean\n4.Median\n5.Mode\n6.Range\n7.Variance\n8.Standard Deviation\n\n");
    scanf("%d",&choice1);
    if(choice1>8||choice1<1)
    {
        printf("\n\nEnter correct choice.\n");
    }
    else
    {
        printf("Enter number of terms:");
        scanf("%d",&N);
        double arr[N];
        for(i=0;i<N;i++)
        {
            printf("Enter element %d:",i+1);
            scanf("%lf",&arr[i]);
        }
        printf("\nYou Entered the following data:");
        printData(arr,N);

        SelectionSort(arr,N);
        printf("\nData in ascending order:");
        printData(arr,N);

        switch(choice1)
        {
            case 1:
                answer=ArithmeticMean(arr,N);
                printf("\n\nArithmetic Mean=%.2lf\n",answer);
                break;
            case 2:
                GeometricMean(arr,N);
                break;
            case 3:
                HarmonicMean(arr,N);
                break;
            case 4:
                Median(arr,N);
                break;
            case 5:
                Mode(arr,N);
                break;
            case 6:
                Range(arr,N);
                break;
            case 7:
                answer=Variance(arr,N);
                printf("\n\nVariance=%.2lf\n",answer);
                break;
            case 8:
                StandardDeviation(arr,N);
                break;
        }
    }
}
void CurveFitting()
{
    int n,i;
    float a,b,c,x[20],y[20],sumx=0,sumy=0,sumxy=0,sumx2=0,sumx3=0,sumx2y=0,sumx4=0,Y[20],X[20];

    system("cls");
    printf("\n\t\t\t\t\t\tCURVE FITTING\n\n");
    printf("\n Select Curve to Fit the data\n\n");
    printf(" 1. Straight line (y= a+bx)\n");
    printf(" 2. Parabolic curve (y= a+bx+ c(x^2)\n");
    printf(" 3. Exponential curve (y= a(e)^(bx))\n");
    printf(" 4. Exponential curve (y= a(x)^(b))\n");


    printf("\n\n Enter your choice:");
    scanf("%d",&choice1);
    switch(choice1)
    {
    case 1:
        printf("\n\nLinear Curve Fitting \n ");
        printf("\n Enter the value of number of terms n:");
        scanf("%d",&n);
        printf("\n Enter the values of x-axis:\n");
        for(i=0;i<=n-1;i++)
        {
            scanf(" %f",&x[i]);
        }
        printf("\n Enter the values of y-axis:\n");
        for(i=0;i<=n-1;i++)
            {
                scanf("%f",&y[i]);
            }
        for(i=0;i<=n-1;i++)
        {
            sumx=sumx +x[i];
            sumx2=sumx2 +x[i]*x[i];
            sumy=sumy +y[i];
            sumxy=sumxy +x[i]*y[i];
        }
        if((n*(sumx2) - (sumx*sumx)) != 0)
        {
            a=((sumx2*sumy )-(sumx*sumxy))/((n*sumx2)-(sumx*sumx));   //Values of a and b are calculated to
            b=((n*sumxy)-(sumx*sumy))/((n*sumx2)-(sumx*sumx));        //find the y-intercept and the slope respectively for a straight line
            printf("\n\nThe line is Y=%.2f +(%.2f) X",a,b);           //which shows minimum errors for all given points
        }
        else
        {
            printf("\n\nThe line is UNDEFINED.\n");
        }
        break;
    case 2:
        printf("\n\nParabola Curve Fitting \n ");
        printf("\n Enter the value of number of terms n:");
        scanf("%d",&n);
        printf("\n Enter the values of x-axis:\n");
        for(i=0;i<=n-1;i++)
        {
            scanf(" %f",&x[i]);
        }
        printf("\n Enter the values of y-axis:\n");
        for(i=0;i<=n-1;i++)
        {
            scanf("%f",&y[i]);
        }
        for(i=0;i<=n-1;i++)
        {
            sumx=sumx +x[i];
            sumx2=sumx2 +x[i]*x[i];
            sumy=sumy +y[i];
            sumxy=sumxy +x[i]*y[i];
            sumx3=sumx3 +x[i]*x[i]*x[i];
            sumx2y=sumx2y +x[i]*x[i]*y[i];
            sumx4=sumx4 +x[i]*x[i]*x[i]*x[i];
        }

        if((n*(sumx2*sumx4) +2*(sumx*sumx2*sumx3) -n*(sumx3*sumx3) -(sumx*sumx*sumx4) -(sumx2*sumx2*sumx2)) != 0)
        {
            a= ((sumy*sumx2*sumx4) -(sumy*sumx3*sumx3) -(sumx*sumxy*sumx4) +(sumx*sumx3*sumx2y) +(sumx2*sumxy*sumx3) -(sumx2*sumx2*sumx2y))/  (n*(sumx2*sumx4) +2*(sumx*sumx2*sumx3) -n*(sumx3*sumx3) -(sumx*sumx*sumx4) -(sumx2*sumx2*sumx2));
            b= ((n*sumxy*sumx4) -(n*sumx3*sumx2y) -(sumx*sumy*sumx4) +(sumy*sumx2*sumx3) +(sumx*sumx2*sumx2y) -(sumx2*sumx2*sumxy))/(n*(sumx2*sumx4) +2*(sumx*sumx2*sumx3) -n*(sumx3*sumx3) -(sumx*sumx*sumx4) -(sumx2*sumx2*sumx2));
            c= ((n*sumx2*sumx2y) -(n*sumxy*sumx3) -(sumx*sumx*sumx2y) +(sumx*sumx2*sumxy) +(sumx*sumy*sumx3) -(sumy*sumx2*sumx2))/(n*(sumx2*sumx4) +2*(sumx*sumx2*sumx3) -n*(sumx3*sumx3) -(sumx*sumx*sumx4) -(sumx2*sumx2*sumx2));

            printf("\n\nThe parabola is Y=%.2f +(%.2f )X +(%.2f) (X^2)",a,b,c);

        }
        else
        {
            printf("\n\nThe parabola is UNDEFINED.\n");
        }
        break;
    case 3:
        printf("\n\nExponential (y= a*e^(bx)) Curve Fitting \n ");
        printf("\n Enter the value of number of terms n:");
        scanf("%d",&n);
        printf("\n Enter the values of x-axis:\n");
        for(i=0;i<=n-1;i++)
        {
            scanf(" %f",&x[i]);
        }
        printf("\n Enter the values of y-axis:\n");
        for(i=0;i<=n-1;i++)
        {
            scanf("%f",&y[i]);
        }
        for(i=0;i<=n-1;i++)
        {
            Y[i]= log(y[i]);
        }
        for(i=0;i<=n-1;i++)
        {
            sumx=sumx +x[i];
            sumx2=sumx2 +x[i]*x[i];
            sumy=sumy +Y[i];
            sumxy=sumxy +x[i]*Y[i];
        }

        if((n*(sumx2) - (sumx*sumx)) != 0)
        {
            c=((sumx2*sumy) -(sumx*sumxy))/((n*sumx2)-(sumx*sumx));
            b=((n*sumxy)-(sumx*sumy))/((n*sumx2)-(sumx*sumx));
            a=exp(c);
            printf("\n\nThe exponential is y= %.2f e^(%.2f)x",a,b);
        }
        else
        {
            printf("\n\nThe curve is UNDEFINED.\n");
        }
        break;
    case 4:
        printf("\n\nExponential (y= a*x^(b)) Curve Fitting \n ");
        printf("\n Enter the value of number of terms n:");
        scanf("%d",&n);
        printf("\n Enter the values of x-axis:\n");
        for(i=0;i<=n-1;i++)
        {
            scanf(" %f",&x[i]);
        }
        printf("\n Enter the values of y-axis:\n");
        for(i=0;i<=n-1;i++)
        {
            scanf("%f",&y[i]);
        }
        for(i=0;i<=n-1;i++)
        {
            X[i]= log(x[i]);
            Y[i]= log(y[i]);
        }
        for(i=0;i<=n-1;i++)
        {
            sumx=sumx +X[i];
            sumx2=sumx2 +X[i]*X[i];
            sumy=sumy +Y[i];
            sumxy=sumxy +X[i]*Y[i];
        }

        if((n*(sumx2) - (sumx*sumx)) != 0)
        {
            c=((sumx2*sumy) -(sumx*sumxy))/((n*sumx2)-(sumx*sumx));
            b=((n*sumxy)-(sumx*sumy))/((n*sumx2)-(sumx*sumx));
            a=exp(c);

            printf("\n\nThe exponential is y= %.2f x^(%.2f)",a,b);

        }
        else
        {
            printf("\n\nThe curve is UNDEFINED.\n");
        }
        break;
    default:
        printf("\nEnter correct choice.");
    }
}
void CorelationCoefficient()
//coefficient of correlation={sumof[(xi-xmean)(yi-ymean)]}/{sqrt[((sumof(xi-xmean))^2*(sumof(yi-ymean)^2)]}
{
    system("cls");
    printf("\n\t\t\t\t\t\tCOEFFICIENT OF CORELATION\n\n");
    float xm=0,ym=0,a=0,b=0,c=0,r;
    printf("\n\nEnter number of points: ");
    scanf("%d",&N);
    float *x;
    float *y;
    x=(float *)calloc(N,sizeof(float));
    y=(float *)calloc(N,sizeof(float));
    while(N<=1)
    {
        printf("\nERROR! Enter valid numbers of points: ");
        scanf("%d",&N);
    }
    for(i=0;i<N;i++)
    {
        printf("\nEnter co-ordinates of point %d:\n",i+1);
        scanf("%f %f",&x[i],&y[i]);
        xm=(xm+x[i]);
        ym=(ym+y[i]);
    }
    xm=xm/(double)N;
    ym=ym/(double)N;
    for(i=0;i<N;i++)
    {
        a=a+(x[i]-xm)*(y[i]-ym);
        b=b+pow(x[i]-xm,2);
        c=c+pow(y[i]-ym,2);
    }
    r=a/(sqrt(b*c));
    printf("\nCoefficient of correlation: %.2f",r);
    free(x);
    free(y);
}
void mainmenu()
{
    printf("\n\nDo you want to continue?(y/n)");
    printf("\nPress 'Y' to go to main menu or 'N' to exit:");
    scanf(" %c",&ch1);
    if(ch1=='y'|| ch1=='Y')
    {
            system("cls");
            main();
    }
    else if(ch1=='n'||ch1=='N')
    {
        return;
    }
    else
    {
        printf("\nEnter correct choice.");
        mainmenu();
    }
}

