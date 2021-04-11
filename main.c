#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100
void graph_method();


int main()
{
    graph_method();
    return 0;
}

float calculate_equevelent(float x, int n, float arr[])
{
    float result = 0;
    int j;
    for (j = 0; j <= n; j++)
    {
        result += (arr[j]) * (pow(x, j));
    }

    return result;
}

void graph_method()
{
    bool is_finish = false, is_root_exist = false;
    float arr_of_multipiliers[MAX], x, delta, result = 0, result2 = 0, epsilon;

    int degree_of_equevelent, i;
    printf("Denklemin derecesini giriniz:");
    scanf("%d", &degree_of_equevelent);
    printf("\n");

    for (i = 0; i <= degree_of_equevelent; i++)
    {
        printf("%d dereceli bilinmeyenin kat sayisini giriniz:", i);
        scanf("%f", &arr_of_multipiliers[i]);
        printf("\n");
    }

    printf("X icin baslangic degeri giriniz:");
    scanf("%f", &x);
    printf("\n");
    printf("Delta degeri giriniz:");
    scanf("%f", &delta);
    printf("\n");
    printf("Epsilon degeri giriniz:");
    scanf("%f", &epsilon);
    printf("\n");

    do
    {
        result = calculate_equevelent(x, degree_of_equevelent, arr_of_multipiliers);
        result2 = calculate_equevelent(x + delta, degree_of_equevelent, arr_of_multipiliers);

        if (result * result2 < 0)
        {
            delta = delta / 2;

            if (fabs(result - result2) < epsilon)
            {
                is_finish = true;

                printf("Root find\n");
                printf("Root 1 %f:\n", x);
                printf("Root 2 %f:\n", x + delta);
            }
            else
            {
                result2 = calculate_equevelent(x + delta, degree_of_equevelent, arr_of_multipiliers);
            }
        }else{
            x+=delta;
        }

    } while (!is_finish);

}