#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int BF(char S[], char T[], char A[])//BF�㷨
{
	int i = 0, j = 0;//i���ĸ��S��j����Ӵ�T
	while (i < strlen(S) && j < strlen(A))
	{
		if (S[i] == T[j])//��ȣ�������
		{
			i++;
			j++;
		}
		else//���ȣ�ĸ������
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= strlen(A)) return 1;
	else return 0;

}
int main()
{
	char a[501], b[501];
	int n, flag = 0;
	cin >> n;//�������
	for (int i = 0; i < n; i++)
	{
		cin >> a;//���벡����
		getchar();
		cin >> b;//����DNA
		char c[1000];
		for (int i = 0; i < strlen(a); i++)//������Ϊ����������ÿ�ֿ���
		{
			int k = i;
			for (int j = 0; j < strlen(a); j++)//c��ֵΪ�ô��жϵĲ�����
			{
				c[j] = a[k++];
				if (k % strlen(a) == 0) k = 0;
			}
			if (BF(b, c, a) == 1)//��BF�㷨�жϣ�������Ϊ�Ӵ���DNAΪĸ��
			{
				flag = 1;
				break;
			}
			else
				flag = 0;
		}
		if (flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}