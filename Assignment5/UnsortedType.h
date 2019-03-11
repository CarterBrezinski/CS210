#pragma once
#include "ItemType.h"

//Use the interface
//provided and define
//the required functions.

class UnsortedType
{
	//Declare the
	//required variables.

	int size;
	ItemType list[10];

public:

	//Define the required
	//member functions.

	UnsortedType()
	{
		size = 0;
	}

	bool IsFull() const
	{
		if (size == 10)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Function: Determines whether list is full.
	// Pre: List has been initialized.
	// Post: Function value = (list is full)

	int LengthIs() const

	{
		return size;
	}

	// Function: Determines the number of elements in list.
	// Pre: List has been initialized.
	// Post: Function value = number of elements in list

	void RetrieveItem(ItemType& item, bool& found)
	{
		for (int i = 0; i < size; i++)
		{
			if (item.CompareTo(list[i]) == 0)
			{
				found = true;
				item = list[i];
				return;
			}
		}
	}

	// Function: Retrieves list element whose key matches item's
	// key (if present).
	// Pre: List has been initialized.
	// Key member of item is initialized.
	// Post: If there is an element someItem whose key matches
	// item's key, then found = true and item is a copy of
	// someItem; otherwise found = false and item is unchanged.
	// List is unchanged.

	void InsertItem(ItemType item, int loc)
	{
		if (loc > 10 || loc < 1 || size == 10)
		{
			return;
		}
		else
		{
			ItemType obj(0);
			if (list[loc - 1].CompareTo(obj) == 0)
			{
				list[loc - 1].setValue(item.GetValue());
				size++;
			}
			else
			{
				list[loc - 1].addValue(item.GetValue());
			}
		}
	}

	int Get_no_of_boxes(int loc)
	{
		return list[loc - 1].GetValue();
	}

	int getWinner()
	{
		int winner = 0;
		for (int i = 0; i < size; i++)
		{
			if (list[i].CompareTo(list[winner]) > 0)
			{
				winner = i;
			}
		}
		return winner;
	}
};