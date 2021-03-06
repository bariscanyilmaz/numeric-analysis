#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define max 50

#define MAX 100

void gregory_newton();

float calculate_equevelent(float x, int n, float arr[]);
float fac(int i);
void graph_method();
void bisection_method();
void regular_falsi_method();
void newton_raphson_method();
void secant_method();
void inverse_of_matrix();

float determinant(float arr[][25], int n);
void cofactor(float arr[][25], int n);
void transpose(float arr[][25], float cof[][25], int n);

void gauss_jordan_method();
void gauss_elimination_method();
void gauss_siedal();

void numeric_derivative();
void simpson();
void trapez();

int main()
{
    int code = 1;

    printf("(1) Bisection \n");
    printf("(2) Regula-Falsi \n");
    printf("(3) Newton-Rapshon \n");
    printf("(4) NxN Matris Tersi \n");
    printf("(5) Gauss Elimination \n");
    printf("(6) Gauss Seidal \n");
    printf("(7) Sayisal Turev \n");
    printf("(8) Simpson \n");
    printf("(9) Trapez \n");
    printf("(10) Gregory Newton Enterpolasyonu \n");
    printf("Bir yontem seciniz \n");
    scanf("%d", &code);

    if (code == 1)
    {
        printf(" Bisection \n\n");
        bisection_method();
    }
    else if (code == 2)
    {
        printf("Regula-Falsi \n\n");
        regular_falsi_method();
    }
    else if (code == 3)
    {
        printf("Newton-Rapshon \n\n");
        newton_raphson_method();
    }
    else if (code == 4)
    {
        printf("NxN Matris Tersi \n\n");
        inverse_of_matrix();
    }
    else if (code == 5)
    {
        printf("Gauss Elimination \n\n");
        gauss_elimination_method();
    }
    else if (code == 6)
    {
        printf("Gauss Seidal \n\n");
        gauss_siedal();
    }
    else if (code == 7)
    {
        printf("Sayisal Turev \n\n");
        numeric_derivative();
    }
    else if (code == 8)
    {
        printf("Simpson \n\n");
        simpson();
    }
    else if (code == 9)
    {
        printf("Trapez \n\n");
        trapez();
    }
    else if (code == 10)
    {
        printf("Gregory Newton Enterpolasyonu \n\n");
        gregory_newton();
    }

    return 0;
}

void gregory_newton()
{

    float arr[max][max], x[max], y[max], temp = 1;
    int all_is_equal = 1;
    int cycle = 0, i, j;
    float h, n, input, result = 0;

    ///
    printf("Ornek sayisi icin N degerini giriniz:");
    scanf("%f", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d. X degerini giriniz:", i + 1);
        scanf("%f", &x[i]);
        printf("\n");
        printf("%d. degerin Y  degerini giriniz:", i + 1);
        scanf("%f", &y[i]);
        printf("\n\n");
    }

    printf("Hesaplanacak degeri giriniz:");
    scanf("%f", &input);

    h = x[1] - x[0];

    for (i = 1; i < n; i++)
    {
        arr[i - 1][0] = y[i] - y[i - 1];
    }

    for (i = 1; i < n; i++)
    {
        all_is_equal = true;
        for (j = 1; j < n - i; j++)
        {

            if (arr[j][i - 1] != arr[j - 1][i - 1])

                arr[j - 1][i] = arr[j][i - 1] - arr[j - 1][i - 1];
        }

        cycle++;
    }

  
    result += y[0];
    i = 1;

    while (i <= cycle)
    {
        temp = 1;
        for (j = 0; j < i; j++)
        {
            temp *= (input - x[j]);
        }

        temp /= pow(h, i);
        temp /= fac(i);
        temp *= arr[0][i - 1];
        i++;

        result += temp;
    }

    printf("X:%f icin sonuc:%f", input, result);

}

float fac(int i)
{
    float tmp = 1;
    while (i > 1)
        tmp *= i--;

    return tmp;
}

void trapez()
{
    int n, i, steps;
    float arr[max], h = 0.0, result, a, b;
    float k = 0;
    printf("Denklemin derecesini giriniz:");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i <= n; i++)
    {
        printf("%d dereceli bilinmeyenin kat sayisini giriniz:", i);
        scanf("%f", &arr[i]);
        printf("\n");
    }

    printf("A degeri giriniz:");
    scanf("%f", &a);

    printf("\n");

    printf("B degeri giriniz:");
    scanf("%f", &b);
    printf("\n");

    printf("Adim sayisini giriniz:");
    scanf("%d", &steps);
    printf("\n");

    h = 1.0 * (b - a) / steps;

    result = calculate_equevelent(a, n, arr) + calculate_equevelent(b, n, arr);

    for (i = 1; i <= steps - 1; i++)
    {
        k = a + i * h;

        result += 2 * calculate_equevelent(k, n, arr);
    }

    result = result * (h / 2);
    printf("\n");
    printf("Sonuc:%f", result);
}
void numeric_derivative()
{
    int n, i;
    float arr[max];
    float h, merkezi, ileri, geri, x;

    printf("Denklemin derecesini giriniz:");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i <= n; i++)
    {
        printf("%d dereceli bilinmeyenin kat sayisini giriniz:", i);
        scanf("%f", &arr[i]);
        printf("\n");
    }
    printf("X degerini giriniz:");
    scanf("%f", &x);
    printf("\n");
    //merkezi,ileri,geri
    printf("Fark degerini giriniz:");
    scanf("%f", &h);

    ileri = (calculate_equevelent((x + h), n, arr) - calculate_equevelent(x, n, arr)) / h;
    geri = (calculate_equevelent((x), n, arr) - calculate_equevelent(x - h, n, arr)) / h;
    merkezi = (calculate_equevelent((x + h), n, arr) - calculate_equevelent(x - h, n, arr)) / 2 * h;

    printf("\n");
    printf("Merkezi Fark:%f", merkezi);
    printf("\n");
    printf("Ileri Fark:%f", ileri);
    printf("\n");
    printf("Geri Fark:%f", geri);
    printf("\n");
}

float integral(float x, int n, float arr[])
{
    float result = 0;
    int j;

    for (j = 1; j <= n; j++)
    {
        result += ((arr[j]) * (pow(x, j + 1)) / (j + 1));
    }

    return result;
}

void simpson()
{
    int n, i, steps;
    float arr[max], h = 0.0, result, a, b;
    float k = 0;
    printf("Denklemin derecesini giriniz:");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i <= n; i++)
    {
        printf("%d dereceli bilinmeyenin kat sayisini giriniz:", i);
        scanf("%f", &arr[i]);
        printf("\n");
    }

    printf("A degeri giriniz:");
    scanf("%f", &a);

    printf("\n");

    printf("B degeri giriniz:");
    scanf("%f", &b);
    printf("\n");

    printf("Adim sayisini giriniz:");
    scanf("%d", &steps);
    printf("\n");

    h = 1.0 * (b - a) / steps;

    result = calculate_equevelent(a, n, arr) + calculate_equevelent(b, n, arr);

    for (i = 1; i <= steps - 1; i++)
    {
        k = a + i * h;
        if (i % 2 == 0)
        {
            result += 2 * calculate_equevelent(k, n, arr);
        }
        else
        {
            result += 4 * calculate_equevelent(k, n, arr);
        }
    }

    result = result * (h / 3);
    printf("\n");
    printf("Sonuc:%f", result);
}

void gauss_siedal()
{
    float arr[max][max + 1] = {0};
    float x[max] = {0}, b[max] = {0}, xn[max] = {0}, c = 0, total = 0, epsilon = 0, init = 0, tmp = 0, error = 0;
    int n, i, j, k, row;

    printf("Denklem Sayisini giriniz:");
    scanf("%d", &n);
    printf("\n");

    printf("Epsilon degerini giriniz:");
    scanf("%f", &epsilon);
    printf("\n");

    printf("Baslangic degerini giriniz:");
    scanf("%f", &init);
    printf("\n");

    printf("Denklemleri girerken lutfen diagonellerinin carpimi maksimum olacak sirada giriniz!");
    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (j == n)
            {

                printf("%d. denklemin Cevabini giriniz:", i + 1);
                scanf("%f", &b[i]);
                printf("\n");
            }
            else
            {
                printf("A[%d][%d]  Elemani Giriniz:", i + 1, j + 1);
                scanf("%f", &arr[i][j]);
                printf("\n");
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        x[i] = init;
    }

    do
    {
        for (i = 0; i < n; i++)
        {
            total = b[i];
            for (j = 0; j < n; j++)
            {
                if (j != i)
                {
                    total -= arr[i][j] * x[j];
                }
            }

            xn[i] = total / arr[i][i];
        }
        c = 0; 
        for (i = 0; i < n; i++)
        {
            error = fabs(x[i] - xn[i]);
            if (error > epsilon)
            {
                c = 1;
            }
        }

        if (c == 1)
        {
            for (i = 0; i < n; i++)
            {
                x[i] = xn[i];
            }
        }

    } while (c == 1);

    printf("Cevaplar \n\n");

    for (i = 0; i < n; i++)
    {
        printf("\nX[%d]:%f", i, xn[i]);
    }

    printf("\n");
}

void gauss_jordan_method() 
{
    float arr[max][max] = {0};
    float x[max][max] = {0};
    int n, i, j, k;

    printf("NxN matrisin icin N degerini giriniz:");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d]:", i, j);
            scanf("%f", &arr[i][j]);
            printf("\n");

            if (i == j)
            {
                x[i][j] = 1;
            }
        }
    }
    float ratio;

    for (i = n - 1; i > 0; i--)
    {

        if (arr[i - 1][0] < arr[i][0])
        {
            for (j = 0; j < n; j++)
            {
                ratio = arr[i][j];
                arr[i][j] = arr[i - 1][j];
                arr[i - 1][j] = ratio;

                ratio = x[i][j];
                x[i][j] = x[i - 1][j];
                x[i - 1][j] = ratio;
            }
        }
    }

    //
    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            if (i != j)
            {

                ratio = arr[j][i] / arr[i][i];
                for (k = 0; k < n; k++)
                {
                    arr[j][k] -= arr[i][k] * ratio;
                    x[j][k] -= x[i][k] * ratio;
                }
            }
        }
    }

    //
    for (i = 0; i < n; i++)
    {
        ratio = arr[i][i];
        for (j = 0; j < n; j++)
        {

            arr[i][j] /= ratio;
            x[i][j] /= ratio;
        }
    }

    //
    printf("\nMatris\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrisin Tersi \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%f ", x[i][j]);
        }
        printf("\n");
    }
}

void gauss_elimination_method()
{
    float arr[max][max + 1] = {0};
    float x[max] = {0}, c = 0, total = 0;
    int n, i, j, k, row;

    printf("Denklem sayisini giriniz:");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (j == n)
            {

                printf("%d. denklemin Cevabini giriniz:", i + 1);
                scanf("%f", &arr[i][j]);
                printf("\n");
            }
            else
            {
                printf("A[%d][%d]  Elemani Giriniz:", i + 1, j + 1);
                scanf("%f", &arr[i][j]);
                printf("\n");
            }
        }
    }

    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (i > j)
            {
                c = arr[i][j] / arr[j][j];
                for (k = 0; k <= n; k++)
                {
                    arr[i][k] = arr[i][k] - c * arr[j][k];
                }
            }
        }
    }

    x[n - 1] = (arr[n - 1][n]) / (arr[n - 1][n - 1]);

    for (i = n - 1; i >= 0; i--)
    {
        total = 0;
        for (j = i + 1; j <= n - 1; j++)
        {
            total += arr[i][j] * x[j];
        }
        x[i] = (arr[i][n] - total) / arr[i][i];
    }

    printf("Cevaplar \n\n");

    for (i = 0; i < n; i++)
    {
        printf("x%d %f", i + 1, x[i]);
        printf("\n");
    }
}

void inverse_of_matrix()
{

    gauss_jordan_method();

    
}
void cofactor(float arr[][25], int k)
{

    float b[25][25], fac[25][25];
    int p, q, m, n, i, j;
    for (q = 0; q < k; q++)
    {
        for (p = 0; p < k; p++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < k; i++)
            {
                for (j = 0; j < k; j++)
                {
                    if (i != q && j != p)
                    {
                        b[m][n] = arr[i][j];
                        if (n < (k - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant(b, k - 1);
        }
    }

    transpose(arr, fac, k);
}

float determinant(float arr[][25], int k)
{
    float s = 1, det = 0, tmp[25][25];
    int i, j, m, n, c;
    if (k == 1)
    {
        return (arr[0][0]);
    }
    else
    {
        det = 0;
        for (c = 0; c < k; c++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < k; i++)
            {
                for (j = 0; j < k; j++)
                {
                    tmp[i][j] = 0;
                    if (i != 0 && j != c)
                    {
                        tmp[m][n] = arr[i][j];
                        if (n < (k - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            det += s * (arr[0][c] * determinant(tmp, k - 1));
            s = -1 * s;
        }
    }

    return det;
}

void transpose(float arr[][25], float cof[][25], int n)
{

    int i, j;
    float d = determinant(arr, n), tmp = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            tmp = cof[i][j] / d;
            cof[i][j] = cof[j][i] / d;
            cof[j][i] = tmp;
        }
    }

    printf("\nMatirisin Tersi:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%f ", cof[i][j]);
        }
        printf("\n");
    }
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
                printf("Kok c %f", c);
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
        printf("Belirtilen aralikta kok bulunmamaktad??r.");
        printf("\n");
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
                printf("Kok c %f", c);
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
        printf("Belirtilen aralikta kok bulunmamaktad??r.");
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

                
                printf("Kok 1 %f:\n", x);
                printf("Kok 2 %f:\n", x + delta);
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
        derivative_result = derivative(a, degree_of_equevelent, arr_of_multipiliers);

        //c=xn
        //b=xn+1;
        b = a - (result / derivative_result);
        if (is_real_root && fabs(real_root - c) < epsilon)
        {
            is_finish = true;
            printf("\nGercek Kok:%f", real_root);
            printf("\nKok:%f", c);
        }
        else if (!is_real_root && fabs(b - a) < epsilon)
        {
            is_finish = true;
            printf("\n Kok 0:%f", a);
            printf("\n Kok 1:%f", b);
            printf("\n");
        }
        else
        {
            a = b;
        }

    } while (!is_finish && derivative_result != 0);
}

void secant_method()
{
    bool is_finish = false, is_root_exist;
    float arr_of_multipiliers[MAX], result = 0, epsilon, a, b, c, real_root = 0;

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
        result = calculate_equevelent(b, degree_of_equevelent, arr_of_multipiliers);
        c = b - result * (a - b) / (calculate_equevelent(a, degree_of_equevelent, arr_of_multipiliers) - result);

        if (is_real_root && fabs(real_root - c) < epsilon)
        {
            is_finish = true;
            printf("\nGercek Kok:%f", real_root);
            printf("\nKok:%f", c);
        }
        else if (!is_real_root && fabs(c - b) < epsilon)
        {
            is_finish = true;
            printf("\n Kok 0:%f", a);
            printf("\n Kok 1:%f", b);
            printf("\n Kok :%f", c);
        }
        else
        {
            a = b;
            b = c;
        }

    } while (!is_finish);

    printf("Kirisden cik");
}