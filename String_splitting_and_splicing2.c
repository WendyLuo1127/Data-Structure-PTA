#include <stdio.h>

// ����������볤��
#define MAX_LEN 103
#define MAX_PARTS 100  // �������ָ�Ĳ���

// �ֶ���ȡһ�����벢�����з�
void read_line(char str[], int max_len) {
    int i = 0;
    char ch;
    while (i < max_len - 1 && (ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';  // ��ӽ�����
}

// �ֶ������ַ�������
int my_strlen(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// ������ʵ���ַ�����split����
void split(char str[], char p, char result[][MAX_LEN], int* size) {
    int idx = 0, res_idx = 0, start = 0;

    while (str[idx] != '\0') {
        if (str[idx] == p) {
            // **[start, idx) �������Ϊһ���Ӵ�
            if (idx > start) {
                for (int i = start; i < idx; i++) {
                    result[res_idx][i - start] = str[i];
                }
                result[res_idx][idx - start] = '\0';  // �ֶ�����ַ���������
            }
            else {
                // ���������ķָ��ַ�������������ַ���
                result[res_idx][0] = '\0';
            }
            res_idx++;
            start = idx + 1;
        }
        idx++;
    }
    // �������һ��
    if (idx > start) {
        for (int i = start; i < idx; i++) {
            result[res_idx][i - start] = str[i];
        }
        result[res_idx][idx - start] = '\0';
    }
    else {
        result[res_idx][0] = '\0';  // ������һ���ַ��Ƿָ�����������ַ���
    }
    *size = res_idx + 1;
}

// ������ʵ���ַ��������join����
void join(char result[][MAX_LEN], int size, char join_str[], char output[]) {
    int output_idx = 0;  // ����׷��output������
    int join_len = my_strlen(join_str);  // �ֶ�����join_str�ĳ���

    for (int i = 0; i < size; i++) {
        // ����ǰ�Ӵ�������output��
        int result_len = my_strlen(result[i]);  // �ֶ����㵱ǰ�Ӵ��ĳ���
        for (int j = 0; j < result_len; j++) {
            output[output_idx++] = result[i][j];
        }

        // ����������һ���Ӵ������������ַ���
        if (i < size - 1) {
            for (int j = 0; j < join_len; j++) {
                output[output_idx++] = join_str[j];
            }
        }
    }
    output[output_idx] = '\0';  // ��ֹ����ַ���
}

int main() {
    char str[MAX_LEN], p, join_str[MAX_LEN], result[MAX_PARTS][MAX_LEN], output[10000];
    int size = 0;

    // �ֶ���ȡ����
    read_line(str, MAX_LEN);   // ��ȡ�����ַ���

    p = getchar();  // ��ȡ�ָ��ַ�
    getchar();  // �����ո�
    read_line(join_str, MAX_LEN);  // ��ȡ�����ַ���

    // ����split����
    split(str, p, result, &size);

    // ���split�������
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("\"%s\"", result[i]);
    }
    printf("]\n");

    // ����join������������
    join(result, size, join_str, output);
    printf("%s\n", output);

    return 0;
}
