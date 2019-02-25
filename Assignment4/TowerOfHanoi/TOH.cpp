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
class disk
{

	int Value;

	/*
	Purpose: compare this disk against another disk, returning true if this disk is larger, returning false if it is not
	Aurguments:
	Return:
	*/
	//-------
	bool disk::isLarger(disk& compareDisk);
	disk;
	disk~;
};

class tower
{
	string name;
	disk[] diskStack;
	//-----
	void moveDiskToTower(tower& toTower);
	void print;
	tower;
	tower~
};

