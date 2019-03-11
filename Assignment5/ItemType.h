//Define the class
//ItemType to be used in
//the class Unsorted Type.

class ItemType

{
	int x;

public:
	ItemType()
	{
		x = 0;
	}

	ItemType(int y)
	{
		x = y;
	}

	int CompareTo(ItemType obj)
	{
		if (x < obj.x)
		{
			return -1;
		}
		else if (x > obj.x)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int GetValue()
	{
		return x;
	}

	void setValue(int y)
	{
		x = y;
	}

	void addValue(int y)
	{
		x += y;
	}

};
