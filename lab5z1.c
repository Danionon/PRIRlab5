#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

double licz(double a, double b, int trapez)
 {
    double h = (b - a)/trapez;
    double sum = 0;
    
    sum = sum + ((f(a) + f(b)) / 2);
    
    for(int i = 1; i < trapez; i++){
        sum = sum + (f(a+i*h));
    }
    
    return sum * h;
}

double f(double x)
{
    return 4*x - 6*x + 5;
}

int main()
 {
    int n;

    printf("Podaj liczbe procesow: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (fork()==0) 
		{
            srand(time(NULL) ^ (getpid()<<16));

            double a = rand()%20;
            double b = rand()%20;

            while (b <= a)
                b = rand()%20;

            int trapez = (rand()%(20-1+1))+1;

            printf("a = %f, b = %f, liczba przedzialow trapezu: %d \n", a, b, trapez);
            printf("Wynik: %f \n", licz(a, b, trapez));
            exit(0);
        }
    }
    
    return 0;
}