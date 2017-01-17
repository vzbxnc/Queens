// Queens.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <math.h>

//打印皇后位置
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
		//打印皇后前面的空余位置
		for (int j = 0 ;j < queenArr[i]; j++)
		{
			printf("%c", 6);
		}
		//打印皇后，ASCII码表2
		printf("%c", 2); 
		//打印皇后后面空余部分
		for (int j = 0; j < nLen - queenArr[i] - 1; j++)
		{
			printf("%c", 6);
		}
		printf("\n");
	}
	printf("----------------------------------------\n");
}
//回朔法
bool isClash(int queenArr[])
{
	for (int i = 1; i <= 8; i ++ )
	{
		for (int j = 0; j <= i - 1; j++)
		{
			if (queenArr[i] == queenArr[j])//说明在同一列
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
//以人的思维方式来解析的---枚举法，8^8方案拿出来分别验证可行性
void enumQueenPosition(int queenArr[],int &nSolution)
{
	for (queenArr[0] = 0; queenArr[0] < 8; queenArr[0]++)//把第一个皇后逐渐往后移动
		for (queenArr[1] = 0; queenArr[1] < 8; queenArr[1]++)
			for (queenArr[2] = 0; queenArr[2] < 8; queenArr[2]++)
				for (queenArr[3] = 0; queenArr[3] < 8; queenArr[3]++)
					for (queenArr[4] = 0; queenArr[4] < 8; queenArr[4]++)
						for (queenArr[5] = 0; queenArr[5] < 8; queenArr[5]++)
							for (queenArr[6] = 0; queenArr[6] < 8; queenArr[6]++)
								for	(queenArr[7] = 0; queenArr[7] < 8; queenArr[7]++)
								{
									//判断当前方案是否避免皇后打架
									if (isClash(queenArr))
									{
										continue;
									}
									else
									{
										//当前方案可行，打印结果
										nSolution++;
										showQueens(queenArr, 8, nSolution);
									}
								}
}
int main()
{
	int queenArr[8];//每个数组成员代表一个皇后位置-queenArr[0]= 4 ,代表第一个皇后在第5个位置
/*	for (int i = 0; i < 8; i++)
	{
		queenArr[i] = -1;
	}
	queenArr[0] = 3;
	queenArr[1] = 6;
	showQueens(queenArr, 8);*/
	int nSolution = 0;//解法数量
	enumQueenPosition(queenArr, nSolution);
	printf ("Hello World!\n");
    return 0;
}

