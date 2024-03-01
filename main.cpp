#include "MyDoublyList.cpp"
#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void header()
{
	setColor(4);
	cout << "\n\t\t\t---------------------------" << endl;
	cout << "\t\t\t|      Media Player      |" << endl;
	cout << "\t\t\t---------------------------" << endl;
	setColor(7);
}

void show(node* &curr)
{
	setColor(4);
	cout << "\n\t\t\t    [  Now Playing  ]" << endl;
	setColor(7);
	setColor(10);
	cout << "\t\t \t   Title: " << curr->data << endl;
	setColor(7);
}

int menu()
{
	char option = '\0';
	setColor(11);
	cout << "\nPrevious-R | Play-P | Next-N | Stop-S | Quit-Q | Show playlists-L | Random Play-D\n" << endl;
	cin >> option;
	setColor(7);
	return option;
}

void showPlaylists(MyDoublyList &List)
{
	setColor(3);
	cout << "\n\t\t\t -------- Playlists -------" << endl;
	List.displayList();
	setColor(7);
}

void music_player(MyDoublyList &List)
{
	int option = 0;
	node* curr = List.head;

	header();
	showPlaylists(List);

	do
	{
		option = menu();
		system("cls");
		if (option == 'p' || option == 'P')
		{
			header();
			showPlaylists(List);
			show(curr);
			PlaySound(curr->data, NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (option == 'n' || option == 'N')
		{
			if (curr->next == nullptr)
			{
				curr = List.head;
			}
			else
			{
				curr = curr->next;
			}

			header();
			showPlaylists(List);
			show(curr);
			PlaySound(curr->data, NULL, SND_FILENAME | SND_ASYNC);

		}
		else if (option == 'r' || option == 'R')
		{
			if (curr->prev == nullptr)
			{
				while (curr->next != nullptr)
				{
					curr = curr->next;
				}
			}
			else
			{
				curr = curr->prev;
			}
			header();
			showPlaylists(List);
			show(curr);
			PlaySound(curr->data, NULL, SND_FILENAME | SND_ASYNC);

		}
		else if (option == 's' || option == 'S')
		{
			header();
			showPlaylists(List);
			PlaySound(NULL, 0, 0);
		}
		else if (option == 'q')
		{
			PlaySound(NULL, 0, 0);
			cout << "\nQuitting..." << endl;
		}
		else if (option == 'l' || option == 'L')
		{
			header();
			showPlaylists(List);
		}
		else if (option == 'd' || option == 'D')
		{
			int randomIndex = rand() % List.sizeOfList();
			curr = List.getNodeAtIndex(randomIndex);

			header();
			showPlaylists(List);
			show(curr);
			PlaySound(curr->data, NULL, SND_FILENAME | SND_ASYNC);
		}
		else
		{
			header();
			cout << "\nInvalid Selection" << endl;
		}
	} while (option != 'q');
}

int main()
{
	ifstream fin;

	fin.open("songs.txt");

	if (!fin.is_open())
	{
		cout << "File Not Found" << endl;
	}
	else
	{
		MyDoublyList List;
		char* title = new char[50];

		while (!fin.eof())
		{
			fin.getline(title, 50);
			List.insertAtEnd(title);
		}

		music_player(List);
	}

	fin.close();
	system("pause");
	return 0;
}
