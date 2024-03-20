#include <stdio.h>
#include <math.h>

const double y=0.577215664901532860606512090082;
    double Ci(double x)
        {
            double Cos;
            Cos=log(x)+y-(x*x)/(2*2)+(x*x*x*x)/(4*4*3*2)-(x*x*x*x*x*x)/(6*6*5*4*3*2)+(x*x*x*x*x*x*x*x)/(8*8*7*6*5*4*3*2);
            return Cos;
        }
int main(int argc, char **argv)
{
    for (double x=0.5; x<7; x+=0.1)
printf("%lf %lf \n", x, Ci(x));
    return 0;
}
