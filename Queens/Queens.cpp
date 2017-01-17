// Queens.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <math.h>

//��ӡ�ʺ�λ��
void  showQueens(int queenArr[], int nLen,int nSolution)
{
	printf("-----------------Queen position:%d-----------------------\n",nSolution);
	for (int i = 0; i < nLen; i++)
	{
		if (queenArr[i] == -1)
		{
			for (int j = 0; j < nLen ; j++)
			{
				printf("%c", 6);
			}
			printf("\n");
			continue;
		}
		//��ӡ�ʺ�ǰ��Ŀ���λ��
		for (int j = 0 ;j < queenArr[i]; j++)
		{
			printf("%c", 6);
		}
		//��ӡ�ʺ�ASCII���2
		printf("%c", 2); 
		//��ӡ�ʺ������ಿ��
		for (int j = 0; j < nLen - queenArr[i] - 1; j++)
		{
			printf("%c", 6);
		}
		printf("\n");
	}
	printf("----------------------------------------\n");
}
//��˷��
bool isClash(int queenArr[])
{
	for (int i = 1; i <= 8; i ++ )
	{
		for (int j = 0; j <= i - 1; j++)
		{
			if (queenArr[i] == queenArr[j])//˵����ͬһ��
			{
				return true;
			}
			if (abs(queenArr[i] - queenArr[j]) == abs( i - j))
			{
				return true;
			}
			return false;
		}
	}
}
//���˵�˼ά��ʽ��������---ö�ٷ���8^8�����ó����ֱ���֤������
void enumQueenPosition(int queenArr[],int &nSolution)
{
	for (queenArr[0] = 0; queenArr[0] < 8; queenArr[0]++)//�ѵ�һ���ʺ��������ƶ�
		for (queenArr[1] = 0; queenArr[1] < 8; queenArr[1]++)
			for (queenArr[2] = 0; queenArr[2] < 8; queenArr[2]++)
				for (queenArr[3] = 0; queenArr[3] < 8; queenArr[3]++)
					for (queenArr[4] = 0; queenArr[4] < 8; queenArr[4]++)
						for (queenArr[5] = 0; queenArr[5] < 8; queenArr[5]++)
							for (queenArr[6] = 0; queenArr[6] < 8; queenArr[6]++)
								for	(queenArr[7] = 0; queenArr[7] < 8; queenArr[7]++)
								{
									//�жϵ�ǰ�����Ƿ����ʺ���
									if (isClash(queenArr))
									{
										continue;
									}
									else
									{
										//��ǰ�������У���ӡ���
										nSolution++;
										showQueens(queenArr, 8, nSolution);
									}
								}
}
int main()
{
	int queenArr[8];//ÿ�������Ա����һ���ʺ�λ��-queenArr[0]= 4 ,�����һ���ʺ��ڵ�5��λ��
/*	for (int i = 0; i < 8; i++)
	{
		queenArr[i] = -1;
	}
	queenArr[0] = 3;
	queenArr[1] = 6;
	showQueens(queenArr, 8);*/
	int nSolution = 0;//�ⷨ����
	enumQueenPosition(queenArr, nSolution);
	printf ("Hello World!\n");
    return 0;
}

