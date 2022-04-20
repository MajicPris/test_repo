#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>

using namespace std;

class worker
{
public:
	int id;
	char name[40];
	int expi;
	int hs;
	int hr;
	int salary;
	worker();
	void initWorker();
	int getSalary();
	void show();	
	int getId() const;
};

worker::worker()
{
	id = 0;
	name[0]='/0';
	expi = 0;
	hs = 0;
	hr = 0;
	salary = 0;
}

void worker::initWorker()
{
	cout << "enter id: " << endl;
	cin >> id;
	cout << "enter name: " << endl;
	cin >> name;
	cout << "enter expirience: " << endl;
	cin >> expi;
	cout << "enter hourly cash: " << endl;
	cin >> hs;
	cout << "enter hours: " << endl;
	cin >> hr;
}

int worker::getSalary()
{
	salary = hs*hr;
	return salary;
}

void worker::show()
{
	cout <<setw(4) << id << setw(12) << name << setw(12) << expi << setw(11) << hs << setw(8) << hr<<setw(8)<<salary;
}

int worker::getId() const
{
	return id;
}

class  arr
{
	vector <worker> w;
public:
	void show();
	void add(worker tmp);
	void find(int id_);
	void erase(int id_);
	void sort();
};

void arr::add(worker tmp)
{
	w.push_back(tmp);
}
void arr::show()
{
	cout << "----------------------All workers----------------------" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << setw(4)<<"Id" << setw(12) << "Name" << setw(12) << "Expiriance" << setw(12) << "Hour/cash " << setw(8) << "Hours " <<setw(8)<<"Salary "<< endl;
	for (int i = 0; i < w.size(); i++)
	{
		cout << endl;
		w[i].show();
	}
}

void arr::find(int id_)
{
	for (int i = 0; i < w.size(); i++)
	{
		if (w[i].getId() == id_)
		{
			w[i].show();
			return;
		}
	}
	cout << "No id" << endl;

}

void arr::erase(int id_)
{
	for (int i = 0; i < w.size(); i++)
	{
		if (w[i].getId() == id_)
		{
			w.erase(w.begin() + i);
			return;
		}
	}
	cout << "No id" << endl;

}

void arr::sort()
{
	worker tmp;
	for (int i = 1; i < w.size() - 1; i++)
	{
		for (int j = 0; j < w.size() - i; j++)
		{
			if (w[j].getId() < w[j + 1].getId())
			{
				/*tmp = w[j].getId();
				w[j].getId() = w[j + 1].getId();
				w[j + 1].getId() = tmp;*/
			}
		}
	}
}

int main()
{
	worker k;
	arr mas;
	char key;
	while (1)
	{
		cout << endl;
		cout << "A. Add worker" << endl;
		cout << "S. Show all workers" << endl;
		cout << "F. Find worker" << endl;
		cout << "D. Deleter worker" << endl;
		cout << "Q. Quit" << endl;
		cin >> key;
		switch (key)
		{
		case 'a':
			k.initWorker();
			k.getSalary();
			mas.add(k);
			break;
		case 's':
			//mas.sort();
			mas.show();
			break;
		case 'f':
			int i;
			cout << "enter your Id: " << endl;
			cin >> i;
			mas.find(i);
			break;
		case 'd':
			int d;
			cout << "enter your Id: " << endl;
			cin >> d;
			mas.erase(d);
			break;
		case 'q':
			exit(1);
			break;
		}
	}
	return 0;
}