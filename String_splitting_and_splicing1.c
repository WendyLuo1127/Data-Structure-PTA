#include <stdio.h>
#include <string.h>

int main() {
    char in[1010]="\0",split, join[1000]="\0";
    gets(in);   
    split = getchar();           // �ָ��ַ�
    getchar();// ��ȡ�����ַ����������ָ��ַ��Ϳո�
    gets(join);

    int len = strlen(in);      // ԭʼ�ַ����ĳ���
    int join_len = strlen(join); // �����ַ����ĳ���

    // 1. ���� split �ָ�
    printf("[");
    int start = 0;   // �������ÿһ���Ӵ�����ʼ
    int first_part = 1;  // ����Ƿ��ǵ�һ���Ӵ�
    for (int i = 0; i <= len; i++) {  // ע�� i <= len, ���ڴ������һ����
        if (in[i] == split || i == len) {
            // ��������ָ��ַ����ߵ����ַ���ĩβ
            if (!first_part) {
                printf(", ");
            }
            printf("\"");
            for (int j = start; j < i; j++) {
                printf("%c", in[j]);
            }
            printf("\"");
            first_part = 0;  // ��һ���Ӵ�����
            start = i + 1;   // ��һ���Ӵ�����ʼλ��
        }
    }
    printf("]\n");

    // 2. ���� join ����
    start = 0;
    first_part = 1;
    for (int i = 0; i <= len; i++) {
        if (in[i] == split || i == len) {
            // ����ÿ���Ӵ�
            if (!first_part) {
                printf("%s", join);  // ���������ַ���
            }
            for (int j = start; j < i; j++) {
                printf("%c", in[j]);
            }
            first_part = 0;  // ��һ���Ӵ�����
            start = i + 1;   // ��һ���Ӵ�����ʼλ��
        }
    }
    printf("\n");

    return 0;
}
