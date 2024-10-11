#include <stdio.h>
int main()
{
    float t[100] = {10, 15, 18, 22, 30}, v[100] = {22, 26, 35, 48, 68};
    float a;         // Value of the t to find the respective value of v(t)
    scanf("%f", &a); // This will be taken from test cases
    float k = 0;

    for (int j = 0; j < 5; j++)
    {
        float temp_divd = 1, temp_divs = 1;
        for (int i = 0; i < 5; i++)
        {
            if (i != j)
            {
                temp_divd *= (a - t[i]);
            }
        }
        for (int i = 0; i < 5; i++)
        {
            if (i != j)
            {
                temp_divs *= (t[j] - t[i]);
            }
        }
        k += (temp_divd / temp_divs) * v[j];
    }
    
    printf("The respective value of the variable v is: %.2f", k);
    return 0;
}