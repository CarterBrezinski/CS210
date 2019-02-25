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
	for (i = numDisks; i >= 1; i--)
	{
		placedisk1(i);			//places the disks on the first pole
	}
	towerOfHanoi(numDisks);		//
	return 0;
}
void towerOfHanoi(int numDisks)
{

}
class Disk
{
	int Value;
	/*
	Purpose: compare this disk against another disk, returning true if this disk is larger, returning false if it is not
	Aurguments:
	Return:
	*/
	//-------
	bool isLarger(Disk& compareDisk);
	Disk();
	Disk(int diskValue);
	Disk~;
};

class Tower
{
	string name;
	int stackSize;
	Disk[] diskStack;
	//-----
	void moveDiskToTower(Tower& toTower);
	void print;
	Tower(string name, unsigned int stackSize);
	Tower~;
};

//constructor
Disk::Disk()
{
	this.Value = NULL;
}
Disk::Disk(int diskValue)
{
	this.Value = diskValue;
}

bool Disk::isLarger(Disk& compareDisk)
{
	
}

void Tower::moveDiskToTower(Tower& toTower)
{


}
void Tower::print
{
	cout << this.name << ":";
	for (int i = 0; i < this.stackSize)
	
}
Tower::Tower(string name, unsigned int stackSize)
{

}
