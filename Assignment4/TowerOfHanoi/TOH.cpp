#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string>

using namespace std;

const int MAX = 999;

int main()
{
	int numDisks, i;
	cout << "Enter the number of disks in the game: ";
	cin >> numDisks;
	cout << "\n \n      For reference on the posts: " << "\n \n      Top:   Bottom:" << "\n          |        |";
	Tower tower1("Tower 1", numDisks);
	Tower tower2("Tower 2", numDisks);
	Tower tower3("Tower 3", numDisks);
	
	towerOfHanoi(numDisks, tower1, tower2, tower3);		
	return 0;
}
void towerOfHanoi(int numDisks, Tower tower1, Tower tower2, Tower tower3)
{
	int i, top, a, b;
	for (i = 0; i < (pow(2,numDisks)); i++)
	{
		tower1.print();
		tower2.print();
		tower3.print();
	}
}

class Disk
{
public:
	int value;
	/*
	Purpose: compare this disk against another disk, returning true if this disk is larger, returning false if it is not
	Aurguments:
	Return:
	*/
	//-------
	//getValue function here
	bool isLarger(Disk& compareDisk);
	Disk();
	Disk(int diskValue);
	~Disk();
};

class Tower
{
public:
	string name;
	int stackSize;
	Disk diskStack[MAX];
	//-----
	void moveDiskToTower(Tower& toTower, int stackSize);

	void print();

	void initPlaceDisks(unsigned int numDisks);

	Tower(string name, unsigned int stackSize);

	int topOfTower(unsigned int stackSize);

	void addDisk(Disk givenDisk);

	void removeDisk();

	~Tower();
};

//constructor
Disk::Disk()
{
	value = NULL;
}
Disk::Disk(int diskValue)
{
	value = diskValue;
}

bool Disk::isLarger(Disk& compareDisk)
{
	if (value > compareDisk.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tower::moveDiskToTower(Tower& toTower, int towerStackSize)
{
	toTower.addDisk(diskStack[stackSize]);
	removeDisk();
}

void Tower::print()
{
	cout << name << ":";
	for (int i = 0; i < stackSize; i++)
	{
		cout << diskStack[i].value << " ";
	}
}

Tower::Tower(string towerName, unsigned int stackSize)
{
	name = towerName;

	for (int i = 0; i <= stackSize; i++)
	{
		diskStack[i].value = 0;
	}
}

void Tower::initPlaceDisks(unsigned int numDisks)
{
	int counter = 0;
	for (int i = numDisks; i >= 1; i--)
	{
		diskStack[counter].value = i;		//initial disk placement
		counter++;						
	}
}

int Tower::topOfTower(unsigned int stackSize)
{
	int topStack = diskStack[stackSize].value;
	return topStack;
}

void Tower::addDisk(Disk givenDisk)
{
	stackSize++;													//extend this Tower's length
	diskStack[stackSize] = givenDisk;
}
void Tower::removeDisk()
{
	diskStack[stackSize].value = 0;										//change current stack's top disk to 0
	stackSize--;		 																	//shorten current stack's length
}
