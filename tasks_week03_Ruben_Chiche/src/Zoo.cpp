#include "Zoo.h"
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

// constructor
Zoo::Zoo()
{
	_option = -1;

	create("Lion", "Simba");
	create("Lion", "Mufasa");
	create("Dog", "Toto");
	create("Shark", "Jaws");

}

// run the zoo
void Zoo::run()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);

	cout << "                               __________   ____  " << endl;
	cout << "                              |___  / __ \\ / __ \\ " << endl;
	cout << "                                 / / |  | | |  | |" << endl;
	cout << "                                / /| |  | | |  | |" << endl;
	cout << "                               / /_| |__| | |__| |" << endl;
	cout << "                              /_____\\____/ \\____/ " << endl;
	cout << "                                                  " << endl;
      
	SetConsoleTextAttribute(hConsole, 15);
	

	do
	{
		map();
		help();

		cout << "Which operation you want?" << endl;
		cout << ">> ";
		cin >> _option;

		switch (_option)
		{
		case 0:
		{
			size_t index;
			cout << "Choose an index" << endl << ">> ";
			cin >> index;
			stop(index);
		}
		break;
		case 1:
		{
			size_t index;
			cout << "Choose an index" << endl << ">> ";
			cin >> index;
			move(index);
		}
		break;
		case 2:
		{
			string type, name;
			cout << "Choose an animal" << endl << ">> ";
			cin >> type;
			cout << "Choose a name" << endl << ">> ";
			cin >> name;
			create(type, name);
		}
		break;
		case 3:
		{
			size_t index;
			cout << "Choose an index" << endl << ">> ";
			cin >> index;
			del(index);
		}
		break;
		case 4:
		{
			string type;
			cout << "Choose an animal" << endl << ">> ";
			cin >> type;
			dellAll(type);
		}
		break;
		case 5:
		{
			help();
		}
		break;
		case 6: break;
		case 7:
		{
			point();
		}
		break;
		case 8:
		{
			for (size_t i = 0; i < 10000; i++)
			{
				system("cls");
				point();
				map();
				Sleep(300);
			}		
		}
		break;
		default:
		{
			cout << "This operation was not found, please try again" << endl;
		}
		break;
		}
	} while (_option != 6);

}


// stop an animal
void Zoo::stop(size_t index) const
{
	if (index >= animals.size())
		return;

	animals[index]->stop();
}

// move an animal
void Zoo::move(size_t index) const
{
	if (index >= animals.size())
		return;

	animals[index]->move();
}

// create a new animal
void Zoo::create(string type, string name)
{
	Location randLocation((rand() % 20), (rand() % 40));
	
	if (type == "Lion")
		animals.emplace_back(make_unique<Lion>(name, randLocation));
	else if (type == "Dog")
		animals.emplace_back(make_unique<Dog>(name, randLocation));
	else if (type == "Shark")
		animals.emplace_back(make_unique<Shark>(name, randLocation));
}

// delete an animal
void Zoo::del(size_t index)
{
	if (index >= animals.size())
		return;

	animals.erase(animals.begin() + index);
}

//delete all the animals of a specific type
void Zoo::dellAll(string type)
{
	if (type != "Lion" && type != "Dog" && type != "Shark")
		return;

	
	string clType = "class " + type;

	for (auto i = animals.begin(); i != animals.end(); )
		if (*i && typeid(**i).name() == clType)
			i = animals.erase(i);
		else
			++i;

}

// print all available operations
void Zoo::help() const
{
	cout << "Available operations:" << endl;
	cout << "0  -> [stop] stop an animal, args(index_of_the_animal: int)" << endl;
	cout << "1  -> [move] if stopped, make the animal move, args(index_of_the_animal: int)" << endl;
	cout << "2  -> [create] create a new animal, args(type_of_the_animal (Lion,Dog,Shark): string, name_of_the_animal: string)" << endl;
	cout << "3  -> [del] delete an animal, args(index_of_the_animal: int)" << endl;
	cout << "4  -> [dellAll] delete all the animals of a specific type, args(type_of_the_animal (Lion,Dog,Shark): string)" << endl;
	cout << "5  -> [help] print all the available operations" << endl;
	cout << "6  -> [exit] quit the program" << endl;
	cout << "7  -> [.] make a step to all the animals" << endl;
	cout << "8  -> [BONUS] make 1000 steps" << endl;
}

// make a step to all the animals
void Zoo::point() const
{
	for (const auto& animal : animals)
		animal->step();
}

// print the map of the zoo, and the list of all the animals
void Zoo::map() const
{
	char arr[ROWS][COLUMNS]{};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			arr[i][j] = '.';
		}
	}


	for(const auto& animal : animals)
		arr[animal->getLocation()._row][ animal->getLocation()._column] = animal->getInitial();

	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			if (arr[i][j] == 'L')
			{
				SetConsoleTextAttribute(hConsole, 6);
				cout << arr[i][j] << ' ';
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (arr[i][j] == 'D')
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << arr[i][j] << ' ';
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (arr[i][j] == 'S')
			{
				SetConsoleTextAttribute(hConsole, 3);
				cout << arr[i][j] << ' ';
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
				cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;

	for (size_t i = 0; i < animals.size(); i++)
	{
		cout << i << ". ";
		animals[i]->printDetails();
		cout << endl;
	}


	cout << endl;
}
