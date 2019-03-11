/*
Name: Carter Brezinski
SID:200391111
Date: 3/12/2019
Assignment:
Purpose:
*/

#include <iostream>
#include "UnsortedType.h"
#include <fstream>

using namespace std;

int main() {

	//Declare the required
	//variables.

	int class_id;
	int no_boxes;
	char ch = 'y';

	UnsortedType obj;

	//Run the loop to get
	//the input from the user.

	while (ch == 'y')
	{
		cout << "Enter the id of the class: ";

		cin >> class_id;

		cout << "Enter the boxes sold by the class: ";

		cin >> no_boxes;

		ItemType obj1(no_boxes);

		obj.InsertItem(obj1, class_id);

		cout << "Do you wish to add more boxes(y/n)?: ";

		cin >> ch;

	}

	//Open the file to
	//write the output.
	/*
	FILE * outfile;
	outfile = fopen("boxes.txt", "w");

	//Print the data to the file.

	fprintf(outfile, "Class ID   Number of Boxes Sold ");
	for (int i = 0; i < 10; i++)
	{
		fprintf(outfile, "Class %2d   %2d ", i + 1, obj.Get_no_of_boxes(i + 1));
	}

	fprintf(outfile, " The Winner is Class %d ", obj.getWinner());

	//Close the file.
	fclose(outfile);
	*/

	ofstream myfile;
	myfile.open("boxes.txt");
	myfile << "Class ID   Number of Boxes Sold " << endl;

	for (int i = 0; i < 10; i++)
	{
		myfile << "Class   " << i + 1 << "   " << obj.Get_no_of_boxes(i + 1) << endl;
	}

	myfile << " The Winner is Class " << obj.getWinner() << endl;

	myfile.close();
	return 0;
}