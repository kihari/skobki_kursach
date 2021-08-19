# define _crt_secure_no_warnings

# include <stdio.h> 
# define MAX_SIZE 100 

//�������� ������� ������������ ���������� ��������� ��������� 
void print_brackets(int pos, int n, int open, int close);


int main()
{
    int n;//������� ��������� ������������������ 
    printf("%s", "Enter the depth (N) of the parentheses: ");
    scanf_s("%d", &n);
    if (n <= 0)//������� ������������ ?
    {
        perror("Error");
    }
    else print_brackets(0, n, 0, 0);
    return 0;
}

//������� ������������ ���������� ��������� ���������
void print_brackets(int pos, int depth, int open, int close)
{
    static char str[MAX_SIZE];//������ ��� �������� ����������� ���������� ���������
    static int schet = 1;//����� ���������� ��������� 

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