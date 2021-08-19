# define _crt_secure_no_warnings

# include <stdio.h> 
# define MAX_SIZE 100 

//Прототип функции формирования правильных скобочных выражений 
void print_brackets(int pos, int n, int open, int close);


int main()
{
    int n;//Глубина скобочной последовательности 
    printf("%s", "Enter the depth (N) of the parentheses: ");
    scanf_s("%d", &n);
    if (n <= 0)//Глубина положительна ?
    {
        perror("Error");
    }
    else print_brackets(0, n, 0, 0);
    return 0;
}

//Функция формирования правильных скобочных выражений
void print_brackets(int pos, int depth, int open, int close)
{
    static char str[MAX_SIZE];//Массив для хранения правильного скобочного выражения
    static int schet = 1;//Номер скобочного выражения 

    if (close == depth)
    {
        printf("%d ", schet++);
        printf("%s \n", str);
    }
    else
    {
        if (open > close)
        {
            str[pos] = ')';
            print_brackets(pos + 1, depth, open, close + 1);
        }
        if (open < depth)
        {
            str[pos] = '(';
            print_brackets(pos + 1, depth, open + 1, close);
        }
    }
}