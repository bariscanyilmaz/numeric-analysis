#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100
void graph_method();
void bisection_method();
void regular_falsi_method();
void newton_raphson_method();

int main()
{
    //graph_method();
    //bisection_method();
    //regular_falsi_method();
    newton_raphson_method();
    return 0;
}

float derivative(float x, int n, float arr[])
{

    float result = 0;
    int j;

    for (j = 1; j <= n; j++)
    {
        result += j * (arr[j]) * (pow(x, j - 1));
    }

    return result;
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

void bisection_method()
{
    bool is_finish = false, is_root_exist;
    float arr_of_multipiliers[MAX], result = 0, result2 = 0, epsilon, a, b, c;

    int degree_of_equevelent, i, iterate_count = 0;
    printf("Denklemin derecesini giriniz:");
    scanf("%d", &degree_of_equevelent);
    printf("\n");

    for (i = 0; i <= degree_of_equevelent; i++)
    {
        printf("%d dereceli bilinmeyenin kat sayisini giriniz:", i);
        scanf("%f", &arr_of_multipiliers[i]);
        printf("\n");
    }

    printf("\n");
    printf("Epsilon degeri giriniz:");
    scanf("%f", &epsilon);
    printf("\n");
    printf("Kok araligi icin a degerini giriniz:");
    scanf("%f", &a);
    printf("\n");
    printf("Kok araligi icin b degerini giriniz:");
    scanf("%f", &b);

    do
    {
        float res = 0;
        c = (a + b) / 2;
        result = calculate_equevelent(a, degree_of_equevelent, arr_of_multipiliers);
        result2 = calculate_equevelent(b, degree_of_equevelent, arr_of_multipiliers);
        if (result * result2 < 0)
        {
            is_root_exist = true;

            iterate_count++;

            res = calculate_equevelent(c, degree_of_equevelent, arr_of_multipiliers);

            if (res == 0 || ((b - a) / pow(2, iterate_count)) < epsilon)
            {
                is_finish = true;

                printf("Kok 1:%f", a);
                printf("\n");
                printf("Kok 2:%f", b);
                printf("\n");
                printf("Root c %f", c);
            }
            else if (res * result < 0)
            {
                b = c;
            }
            else if (res * result2 < 0)
            {
                a = c;
            }
        }
        else
        {
            is_root_exist = false;
        }

    } while (!is_finish && is_root_exist);

    if (!is_root_exist)
    {
        printf("Belirtilen aralikta kok bulunmamaktadır.");
    }
}

void regular_falsi_method()
{
    bool is_finish = false, is_root_exist;
    float arr_of_multipiliers[MAX], result = 0, result2 = 0, epsilon, a, b, c;

    int degree_of_equevelent, i, iterate_count = 0;
    printf("Denklemin derecesini giriniz:");
    scanf("%d", &degree_of_equevelent);
    printf("\n");

    for (i = 0; i <= degree_of_equevelent; i++)
    {
        printf("%d dereceli bilinmeyenin kat sayisini giriniz:", i);
        scanf("%f", &arr_of_multipiliers[i]);
        printf("\n");
    }

    printf("\n");
    printf("Epsilon degeri giriniz:");
    scanf("%f", &epsilon);
    printf("\n");
    printf("Kok araligi icin a degerini giriniz:");
    scanf("%f", &a);
    printf("\n");
    printf("Kok araligi icin b degerini giriniz:");
    scanf("%f", &b);

    do
    {
        float res = 0;

        result = calculate_equevelent(a, degree_of_equevelent, arr_of_multipiliers);
        result2 = calculate_equevelent(b, degree_of_equevelent, arr_of_multipiliers);

        c = (a * result2 - b * result) / (result2 - result);

        if (result * result2 < 0)
        {
            is_root_exist = true;
            res = calculate_equevelent(c, degree_of_equevelent, arr_of_multipiliers);
            iterate_count++;

            if (res == 0 || ((b - a) / pow(2, iterate_count)) < epsilon)
            {
                is_finish = true;

                printf("Kok 1:%f", a);
                printf("\n");
                printf("Kok 2:%f", b);
                printf("\n");
                printf("Root c %f", c);
                printf("\n");
            }
            else if (res * result < 0)
            {
                b = c;
            }
            else if (res * result2 < 0)
            {
                a = c;
            }
        }
        else
        {
            is_root_exist = false;
        }

    } while (!is_finish && is_root_exist);

    if (!is_root_exist)
    {
        printf("Belirtilen aralikta kok bulunmamaktadır.");
    }
}

void graph_method()
{
    bool is_finish = false;
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
        }
        else
        {
            x += delta;
        }

    } while (!is_finish);
}

void newton_raphson_method()
{
    bool is_finish = false, is_root_exist;
    float arr_of_multipiliers[MAX], result = 0, derivative_result = 0, epsilon, a, b, c, real_root = 0;

    int degree_of_equevelent, i, iterate_count = 0, is_real_root;
    printf("Denklemin derecesini giriniz:");
    scanf("%d", &degree_of_equevelent);
    printf("\n");

    for (i = 0; i <= degree_of_equevelent; i++)
    {
        printf("%d dereceli bilinmeyenin kat sayisini giriniz:", i);
        scanf("%f", &arr_of_multipiliers[i]);
        printf("\n");
    }

    printf("\n");
    printf("Epsilon degeri giriniz:");
    scanf("%f", &epsilon);
    printf("\n");
    printf("Kok araligi icin a degerini giriniz:");
    scanf("%f", &a);
    printf("\n");
    printf("Kok araligi icin b degerini giriniz:");
    scanf("%f", &b);

    printf("\n Gercek kok degeri var mi?:(1/0)");
    scanf("%d", &is_real_root);
    if (is_real_root)
    {
        printf("\n Gercek kok degerini girniz:");
        scanf("%f", &real_root);
    }

    do
    {    
        result = calculate_equevelent(a, degree_of_equevelent, arr_of_multipiliers);
        derivative_result=derivative(a,degree_of_equevelent,arr_of_multipiliers);
        
        //c=xn
        //b=xn+1;
        b=a-(result/derivative_result);
        if (is_real_root && fabs(real_root-c)<epsilon)
        {
            is_finish=true;
            printf("\nGercek Root:%f",real_root);
            printf("\nRoot:%f",c);
        }else if(!is_real_root && fabs(b-a)<epsilon){
            is_finish=true;
            printf("\n Root 0:%f",a);
            printf("\n Root 1:%f",b);
        }else{
         a=b;   
        }

    } while (!is_finish&&derivative_result!=0);

}