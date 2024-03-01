# pragma once
class node
{
public:
	char* data;
	node* prev;
	node* next;

	node(char* value)
	{
		int length = 0;
		while (value[length] != '\0')
		{
			++length;
		}

		data = new char[length + 1];

		for (int i = 0; i <= length; ++i)
		{
			data[i] = value[i];
		}

		prev = nullptr;
		next = nullptr;
	}


	~node()
	{
	   delete[] data;
	}

};