#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

using namespace std;
int* dist;
int* dist_2;
int* visited;
int** graph;			// ���������� ���������������
int** graph_2;			// ���������� �����������������
queue<int>Q;
queue<int>QQ;
int start, start_2;
int N, N_2, j, i, R;

void BFSD(int v, int N, int** graph) {

	Q.push(v);
	dist[v] = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int i = 0; i < N; i++) {
			if ((graph[v][i] > 0) && (dist[i] == -1)) {
				Q.push(i);
				dist[i] = dist[v] + graph[v][i];
			}
		}
	}
}


int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("������ ������ �������  ");
	scanf_s("%d", &N_2);
	srand(time(NULL));
	graph_2 = new int* [N_2];
	dist_2 = new int[N_2];
	visited = new int[N_2];

	for (int i = 0; i < N_2; i++)
	{
		graph_2[i] = new int[N_2];
	}
	for (int i = 0; i < N_2; i++)
	{
		dist_2[i] = -1;
	}

	printf("\n ������� ��������� ��� ����������� ������������������ ����� \n\n");

	for (i = 0; i < N_2; i++)
	{
		for (j = i; j < N_2; ++j)
		{
			graph_2[i][j] = graph_2[j][i] = rand() % 10;
			graph_2[i][i] = graph_2[j][j] = 0; // ����� �����(����) �� �����������
		}

	}
	printf("   ");
	for (j = 0; j < N_2; j++)
	{
		printf("%4d  ", j + 1); //��������
	}
	printf("\n\n");
	for (i = 0; i < N_2; i++) {

		printf(" %d ", i + 1); // ������

		for (j = 0; j < N_2; j++)
		{
			printf("%4d  ", graph_2[i][j]);
		}
		printf("\n\n");
	}
	for (i = 0; i < N_2; i++)
	{
		printf("\n �� ������� %d ���� ������ � ", i + 1);
		for (j = 0; j < N_2; j++)
		{
			if (graph_2[i][j] >= 1)
				printf("%d ", j + 1);

		}
	}

	printf("\n\n ������� ��������� ������� ");
	scanf("%d", &start_2);
	//BFSD_2(start_2 - 1, N_2, graph_2);
	dist = new int[N_2];
	for (int i = 0; i < N_2; i++)
	{
		dist[i] = -1;
	}
	BFSD(start_2 - 1, N_2, graph_2);
	printf("\n\n �������      ");
	for (int i = 1; i <= N_2; i++) {
		printf("|%3d ", i);
	}
	printf("\n ����������   ");
	for (int i = 0; i < N_2; i++) {
		printf("|%3d ", dist[i]);
	}
	printf("\n\n");


	printf("������ ������ �������  ");
	scanf_s("%d", &N);
	graph = new int* [N];
	dist = new int[N];
	for (int i = 0; i < N; i++)
	{
		graph[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		dist[i] = -1;
	}
	printf("\n ������� ��������� ��� ����������� ���������������� �����\n\n");

	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; ++j)
		{

			R = rand() % 100;
			if (R > 30)
			{
				graph[i][j] = rand() % 10;
				graph[j][i] = 0;
				graph[i][i] = graph[j][j] = 0; // ����� �����(����) �� �����������
			}

			else
				graph[i][j] = graph[j][i] = rand() % 10;
			graph[i][i] = graph[j][j] = 0; // ����� �����(����) �� �����������
		}

	}
	printf("   ");
	for (j = 0; j < N; j++)
	{
		printf("%4d  ", j + 1); //��������
	}
	printf("\n\n");
	for (i = 0; i < N; i++) {

		printf(" %d ", i + 1); // ������

		for (j = 0; j < N; j++)
		{
			printf("%4d  ", graph[i][j]);
		}
		printf("\n\n");
	}
	for (i = 0; i < N; i++)
	{
		printf("\n �� ������� %d ���� ������ � ", i + 1);
		for (j = 0; j < N; j++)
		{
			if (graph[i][j] >= 1)
				printf("%d ", j + 1);

		}
	}

	printf("\n\n ������� ��������� ������� ");
	scanf("%d", &start);
	BFSD(start - 1, N, graph);
	printf("\n\n �������      ");
	for (int i = 1; i <= N; i++) {
		printf("|%3d ", i);
	}
	printf("\n ����������   ");
	for (int i = 0; i < N; i++) {
		printf("|%3d ", dist[i]);
	}
	printf("\n\n");

}
