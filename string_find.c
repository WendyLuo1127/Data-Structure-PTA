#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXS 30

char* search(char* s, char* t);
void ReadString(char s[]); /* �����ṩ��ϸ�ڲ��� */

int main()
{
    char s[MAXS], t[MAXS], * pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if (pos != NULL)
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
char* search(char* s, char* t)
{
    int i = 0, j = 0, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        k = i;
        j = 0;//ÿ�αȽ϶���t��ָ�ĵ�һ����ʼ�Ƚ�
        while (s[k] == t[j] && s[k] != '\0' && t[j] != '\0')
            //�ж�ʱҪ���������Ƿ�Ϊ\0�������һ����������
        {
            k++;
            j++;
        }
        if (j != 0 && t[j] == '\0')
            break;
    }
    if (s[i] != '\0')
    {
        s = i + s;      //ע���ȱȽ��ټӣ�������ܻ�����Խֵ
        return s;
    }
    return NULL;
}