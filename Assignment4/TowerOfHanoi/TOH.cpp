#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

const int MAX = 999;

struct pole1
{
	int data1;
	pole1 *next1;
}
*topPole1 = NULL,
*node1 = NULL,
*pole1node = NULL;
/*
QQQ
This is an error that I've faced, the statements above for topPole, node, and pole1node are all technically their declaration statements
Potentially moving them to a seperate file causes an error, as it works just fine if this is one file.
The prompt only asks us to create one game file, could I technically comment this file out and give it as it is if this doesn't have any issues with it?
Let me know.
*/
struct pole2
{
	int data2;
	pole2 *next2;
}
*topPole2 = NULL,
*node2 = NULL,
*pole2node = NULL;

struct pole3
{
	int data3;
	pole3 *next3;
}
*topPole3 = NULL,
*node3 = NULL,
*pole3node = NULL;

void place1(int data)
{
	pole1node = new pole1;
	pole1node->data1 = data;
	pole1node->next1 = NULL;
	if (topPole1 == NULL)
	{
		topPole1 = pole1node;
	}
	else
	{
		pole1node->next1 = topPole1;
		topPole1 = pole1node;
	}
}

void place2(int data)
{
	pole2node = new pole2;
	pole2node->data2 = data;
	pole2node->next2 = NULL;
	if (topPole2 == NULL)
	{
		topPole2 = pole2node;
	}
	else
	{
		pole2node->next2 = topPole2;
		topPole2 = pole2node;
	}
}

void place3(int data)
{
	pole3node = new pole3;
	pole3node->data3 = data;
	pole3node->next3 = NULL;
	if (topPole3 == NULL)
	{
		topPole3 = pole3node;
	}
	else
	{
		pole3node->next3 = topPole3;
		topPole3 = pole3node;
	}
}

int getDisk1()
{
	int bottom = MAX;
	if (topPole1 == NULL)
	{
		return bottom;
	}
	else
	{
		node1 = topPole1;
		topPole1 = topPole1->next1;
		return(node1->data1);
		delete(node1);
	}
}

int getDisk2()
{
	int bottom = MAX;
	if (topPole2 == NULL)
	{
		return bottom;
	}
	else
	{
		node2 = topPole2;
		topPole2 = topPole2->next2;
		return(node2->data2);
		delete(node2);
	}
}

int getDisk3()
{
	int bottom = MAX;
	if (topPole3 == NULL)
	{
		return bottom;
	}
	else
	{
		node3 = topPole3;
		topPole3 = topPole3->next3;
		return(node3->data3);
		delete(node3);
	}
}

void print1()
{
	cout << endl;
	pole1 *node1;
	node1 = topPole1;
	cout << "Tower1:  " << " ";
	while (node1 != NULL)
	{
		cout << node1->data1 << " ";
		node1 = node1->next1;
	}
	cout << endl;
}

void print2()
{
	pole2 *node2;
	node2 = topPole2;
	cout << "Tower2:  " << " ";
	while (node2 != NULL)
	{
		cout << node2->data2 << " ";
		node2 = node2->next2;
	}
	cout << endl;
}

void print3()
{
	pole3 *node3;
	node3 = topPole3;
	cout << "Tower3:  " << " ";
	while (node3 != NULL)
	{
		cout << node3->data3 << " ";
		node3 = node3->next3;
	}
	cout << endl;
	cout << endl;
}

int topStack()
{
	if (topPole1 != NULL && topPole1->data1 == 1)
	{
		return 1;
	}
	else if (topPole2 != NULL && topPole2->data2 == 1)
	{
		return 2;
	}
	else if (topPole3 != NULL && topPole3->data3 == 1)
	{
		return 3;
	}
}

void towerOfHanoi(int n)
{
	int i, top, a, b;
	for (i = 0; i < (pow(2, n)); i++)
	{
		print1();
		print2();
		print3();
		top = topStack();
		if (i % 2 == 0)
		{
			if (top == 1)
			{
				place3(getDisk1());
			}
			else if (top == 2)
			{
				place1(getDisk2());
			}
			else if (top == 3)
			{
				place2(getDisk3());
			}
		}
		else
		{
			if (top == 1)
			{
				a = getDisk2();
				b = getDisk3();
				if (a < b && b != MAX)
				{
					place3(b);
					place3(a);
				}
				else if (a > b && a != MAX)
				{
					place2(a);
					place2(b);
				}
				else if (b == MAX)
				{
					place3(a);
				}
				else if (a == MAX)
				{
					place2(b);
				}
			}
			else if (top == 2)
			{
				a = getDisk1();
				b = getDisk3();
				if (a < b && b != MAX)
				{
					place3(b);
					place3(a);
				}
				else if (a > b && a != MAX)
				{
					place1(a);
					place1(b);
				}
				else if (b == MAX)
				{
					place3(a);
				}
				else if (a == MAX)
				{
					place1(b);
				}
			}
			else if (top == 3)
			{
				a = getDisk1();
				b = getDisk2();
				if (a < b && b != MAX)
				{
					place2(b);
					place2(a);
				}
				else if (a > b && a != MAX)
				{
					place1(a);
					place1(b);
				}
				else if (b == MAX)
				{
					place2(a);
				}
				else if (a == MAX)
				{
					place1(b);
				}
			}
		}
	}
}

int main()
{
	int n, i;
	cout << "Enter the number of disks in the game: ";
	cin >> n;
	cout << "\n \n      For reference on the posts: " << "\n \n      Top:   Bottom:" << "\n          |        |";
	for (i = n; i >= 1; i--)
	{
		place1(i);			//places the disks on the first pole
	}
	towerOfHanoi(n);		//
	return 0;
}