#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

/*1. �������� ���������, ����������� ����� � ��������� ������� ��������� (x, y). � ������� ���� ��������� ������� ��� �����. ����� �� ������, ���������� ����� ��� �����,
����������� ��� ������� ��� ��� �������?*/
struct tochka
{
	int x;
	int y;
};

void OXY(tochka* A, tochka* B)
{
	cout << "������� ���������� ����� �: ";
	cin >> A->x >> A->y;
	cout << "������� ���������� ����� B: ";
	cin >> B->x >> B->y;
	//������� ������� ������ m = (y2-y1)(x2-x1)
	if (B->y - A->y == 0) cout << "������ ����������� ��� �.";
	else if (B->x - A->x == 0) cout << "������ ����������� ��� Y.";
	else cout << "������ �� ����������� �� ����� �� ����.";
}

//2.������� ���������, ����������� �������������. �������� ������� ��� ����������� ��������� ������������ ����� � ������ �������������. ����� ����� ������ ����������� ����������.
struct rectangle
{
	int a;
	int b;
};

void within_rectangle(rectangle* figure, tochka* A)
{
	cout << "������� ������� ��������������: ";
	cin >> figure->a >> figure->b;
	cout << "������� ���������� ����� �: ";
	cin >> A->x >> A->y;
	if (A->x > figure->a || A->x<0 || A->y>figure->b || A->y < 0) cout << "����� �� ����������� ��������������.";
	else cout << "����� ����������� ��������������.";
}

//3. ������� ���������, ����������� ��������. ������� ������� ��� ������ � ���� ���������� (��������, ���������� ������� � ���������� ������ �������).
struct human
{
	int age;
	int birth_year;
	char surname[15];
	char name[10];
	char gender[7];
	char country[15];
	char nationality[15];
	char telephone[20];
	char occupation[50];
};

void info_cin(human* person)
{
	cout << "\t���������� ������ ������ ������\n";
	cout << "������� ���: "; cin >> person->name;
	cout << "������� �������: "; cin >> person->surname;
	cout << "������� �������: "; cin >> person->age;
	cout << "������� ��� ��������: "; cin >> person->birth_year;
	cout << "������� ���: "; cin >> person->gender;
	cin.ignore();
	cout << "������� ����� ��������: "; gets_s(person->telephone); //������ ������ ������� � ���������?
	cout << "������� ������ ����������: "; cin >> person->country;
	cout << "������� ��������������: "; cin >> person->nationality;
	cout << "������� ���������: "; cin >> person->occupation;
}

void human_data_choice(human person)
{
	cout << "������ ������ ������ ������ ��������? (�/�) ";
	char answer;
	cin >> answer;
	while (answer == '�') //������ � ��������� �� ��������?
	{
		cout << "����� ������ �� ������ ������?\n";
		cout << "1. �������\n2. ���\n3. �������\n4. ��� ��������\n5. ���\n6. ������ ����������\n7. ��������������\n8. ���������\n9. ����� ��������\n";
		cin >> answer;
		while (answer < '1' && answer > '9')
		{
			cout << "������������ ����� ������. ������� ��� ���. ";
			cin >> answer;
		}
		switch (answer) //������ ������ �������� ������� ���������� �������
		{
		case '1':
			cout << "�������: " << person.surname; break;
		case '2':
			cout << "���: " << person.name; break;
		case '3':
			cout << "�������: " << person.age; break;
		case '4':
			cout << "��� ��������: " << person.birth_year; break;
		case '5':
			cout << "���: " << person.gender; break;
		case '6':
			cout << "������ ����������: " << person.country; break;
		case '7':
			cout << "��������������: " << person.nationality; break;
		case '8':
			cout << "���������: " << person.occupation; break;
		case '9':
			cout << "����� ��������: " << person.telephone; break;
		}
		cout << "\n������ ������ �������������� ������ ������ ��������? (�/�) ";
		cin >> answer;
	}
}

//4. ������� ���������, ����������� �������������. �������� ������� ��� ������ � ���� ���������� (��������, ����������� ��������������, ��������� ������� �������������� � �.�.).
void show_figure(rectangle* figure)
{
	cout << "������� ������� �������������� ��� ������: ";
	cin >> figure->a >> figure->b;
	for (int i = 0; i < figure->a; i++)
	{
		for (int j = 0; j < figure->b; j++) cout << "*";
		cout << endl;
	}
	cout << "���������� ����: ";
	if (figure->a == figure->b) cout << "������������� �������� ���������.";
	else if (figure->a > figure->b) cout << "������������� �����.";
	else cout << "������������� �����.";
}

void no_main_diagonal(rectangle figure)
{
	cout << "\n\n������������� ��� ������� ���������:\n";
	for (int i = 0; i < figure.a; i++)
	{
		for (int j = 0; j < figure.a; j++)
		{
			if (i == j) cout << " ";
			else cout << "*";
		}
		cout << endl;
	}
}

void no_side_diagonal(rectangle figure)
{
	cout << "\n\n������������� ��� �������� ���������:\n";
	for (int i = 0; i < figure.a; i++)
	{
		for (int j = 0; j < figure.a; j++)
		{
			if (i + j == figure.a - 1) cout << " ";
			else cout << "*";
		}
		cout << endl;
	}
}

void no_stroka(rectangle figure)
{
	cout << "\n����� �� " << figure.a << " ����� �� ������ �������? ";
	int num;
	cin >> num;
	while (num<0 || num>figure.a)
	{
		cout << "������������ ����� ������. ������� ��� ���.";
		cin >> num;
	}
	cout << "������������� ��� " << num << "-� ������:\n";
	for (int i = 0; i < figure.a; i++)
	{
		for (int j = 0; j < figure.a; j++)
		{
			if (i == num - 1) cout << " ";
			else cout << "*";
		}
		cout << endl;
	}
}

void no_stolb(rectangle figure)
{
	cout << "\n����� �� " << figure.b << " �������� �� ������ �������? ";
	int num;
	cin >> num;
	while (num<0 || num>figure.b)
	{
		cout << "������������ ����� �������. ������� ��� ���.";
		cin >> num;
	}
	cout << "������������� ��� " << num << "-�� �������:\n";
	for (int i = 0; i < figure.b; i++)
	{
		for (int j = 0; j < figure.b; j++)
		{
			if (j == num - 1) cout << " ";
			else cout << "*";
		}
		cout << endl;
	}
}

void change_figure_size(rectangle* figure)
{
	cout << "\n������� ����� ������� ������: ";
	cin >> figure->a >> figure->b;
	cout << "������� ������ ������� ��������.\n";
}

void figure_operations(rectangle figure)
{
	char agreement = '�';
	while (agreement == '�')
	{
		cout << "����� �������� �� ������ ��������� ��� ���������������?";
		cout << "\n1. ������ ������� ���������\n2. ������ �������� ���������\n3. ������ ������\n4. ������ �������\n5. �������� ������\n";
		cout << "�������� �";
		int answer;
		cin >> answer;
		while (answer < 0 || answer>5)
		{
			cout << "\n������������ ����� ��������. ������� ��� ���.\n";
			cout << "�������� �";
			cin >> answer;
		}
		switch (answer)
		{
		case 1:
			if (figure.a != figure.b)
			{
				while (figure.a != figure.b)
				{
					cout << "\n������ �� �������� ���������. ���� �������� ������.";
					change_figure_size(&figure);
				}
				no_main_diagonal(figure);
			}
			else no_main_diagonal(figure);
			break;
		case 2:
			if (figure.a != figure.b)
			{
				while (figure.a != figure.b)
				{
					cout << "\n������ �� �������� ���������. ���� �������� ������.";
					change_figure_size(&figure);
				}
				no_side_diagonal(figure);
			}
			else no_side_diagonal(figure);
			break;
		case 3:
			no_stroka(figure); break;
		case 4:
			no_stolb(figure); break;
		case 5:
			change_figure_size(&figure); break;
		}
		cout << "\n������ ��������� ��� �����-������ ��������? (�/�) ";
		cin >> agreement;
	}
}

//5. ������� ���������, ����������� ������� �����. �������� �������, ����������� �������� ��������, ���������, ��������� � ������� ������.
struct drob
{
	double drobovoe;
	double number;
	int tseloe;
};

void init_drob(drob* num)
{
	cout << "������� ����� ����� �����: "; cin >> num->tseloe;
	cout << "������� ������� ����� �����: "; cin >> num->drobovoe;
	int drob_part = num->drobovoe;
	int size = 1;
	while (drob_part > 9)
	{
		drob_part /= 10;
		size++;
	}
	num->number = num->tseloe + num->drobovoe / pow(10, size);
	cout << "������� ����� = " << num->number;
}

void drob_operations(drob num1, drob num2)
{
	char agreement = '�';
	while (agreement == '�')
	{
		cout << "����� �������� �� ������ ��������� ��� �������?";
		cout << "\n1. ��������\n2. ���������\n3. ���������\n4. �������\n";
		cout << "�������� �";
		int answer;
		cin >> answer;
		while (answer < 0 || answer>4)
		{
			cout << "\n������������ ����� ��������. ������� ��� ���.\n";
			cout << "�������� �";
			cin >> answer;
		}
		switch (answer)
		{
		case 1:
			cout << "\n����� ������ = " << num1.number + num2.number;
			break;
		case 2:
			cout << "\n������� ������ = " << num1.number - num2.number;
			break;
		case 3:
			cout << "\n��������� ��������� ������ = " << num1.number * num2.number;
			break;
		case 4:
			cout << "\n��������� ������� ������ = " << num1.number / num2.number;
			break;
		}
		cout << "\n������ ��������� ��� �����-������ ��������? (�/�) ";
		cin >> agreement;
	}
}

/*6. �������� ���������, ����������� ������ ������������� ������ � ������������ ����������� ���������. ��������� ������ ������������� ����������� ����������
�������� � ������, �������� �������� �� ������, �������������� ������ � ��������, ������ ���������� � ��������� �� �����.*/
struct student
{
	int group;
	int course;
	char speciality[50];
	char surname[20];
	char name[10];
};

void add_student(student** group, int& size)
{
	student stud;
	cout << "������ �������� ������ �������� � ������? (�/�) ";
	char answer;
	cin >> answer;
	while (answer =='�')
	{
		cout << "������� ������ � ��������:\n";

		cout << "���: "; cin >> stud.name;
		cout << "�������: "; cin >> stud.surname;
		cout << "����: "; cin >> stud.course;
		cout << "����� ������: "; cin >> stud.group;
		cin.ignore();
		cout << "�������������: "; gets_s(stud.speciality);
		size++;
		student* group2 = new student[size];
		for (int i = 0; i < size - 1; i++)
		{
			strcpy(group2[i].name, group[i]->name);
			strcpy(group2[i].surname, group[i]->surname);
			group2[i].course = group[i]->course;
			group2[i].group = group[i]->group;
			strcpy(group2[i].speciality, group[i]->speciality);
		}
		strcpy(group2[size - 1].name, stud.name);
		strcpy(group2[size - 1].surname, stud.surname);
		group2[size - 1].course = stud.course;
		group2[size - 1].group = stud.group;
		strcpy(group2[size - 1].speciality, stud.speciality);

		delete[](*group);
		(*group) = group2;
		cout << "������� �������� � ������.\n";

		cout << "������ �������� ��� ������ �������� � ������? (�/�) ";
		cin >> answer;
	}
}

void delete_student(student** group, int& size)
{
	cout << "������ ������� �������� �� ������? (�/�) ";
	char answer;
	cin >> answer;
	if (size == 0) { cout << "� ������ ��� ���������. "; return; }
	while (answer == '�')
	{
		if (size == 0) { cout << "� ������ ��� ���������. "; return; }
		cout << "���� �� ��������� �� ������ �������?\n";
		for (int i = 0, num = 1; i < size; i++, num++)
		{
			cout << num << ". " << (*group)[i].surname << "\n";
		}
		int del_num;
		cin >> del_num;
		while (del_num < 1 || del_num > size)
		{
			cout << "\n������������ �����. ������� ��� ���. ";
			cin >> del_num;
		}
		int new_size = size - 1;
		student* new_group = new student[new_size];
		for (int i = 0, ind = 0; i < size; i++)
		{
			if (i != (del_num - 1))
			{
				strcpy(new_group[ind].name, (*group)[i].name);
				strcpy(new_group[ind].surname, (*group)[i].surname);
				new_group[ind].course = (*group)[i].course;
				new_group[ind].group = (*group)[i].group;
				strcpy(new_group[ind].speciality, (*group)[i].speciality);
				ind++;
			}
		}
		size--;
		delete[](*group);
		(*group) = new_group;
		cout << "������� ����� �� ������.\n";

		cout << "������ ������� ��� ������ �������� �� ������? (�/�) ";
		cin >> answer;
	}
}

void change_info(student** group, int size)
{
	cout << "������ �������� ���������� ��� ������-�� �������� �� ������? (�/�) ";
	char answer;
	cin >> answer;
	while (answer == '�')
	{
		cout << "���������� ��� ������ �������� �� ������ ��������?\n";
		for (int i = 0, num = 1; i < size; i++, num++)
		{
			cout << num << ". " << (*group)[i].surname << "\n";
		}
		int stud_num;
		cin >> stud_num;
		while (stud_num < 1 || stud_num > size)
		{
			cout << "\n������������ �����. ������� ��� ���. ";
			cin >> stud_num;
		}
		cout << "����� ������ ���������� �� ������ ��������?\n";
		cout << "1. ���\n2. �������\n3. ����\n4. ������\n5. �������������\n";
		int info_num;
		cin >> info_num;
		while (info_num < 1 || info_num > 5)
		{
			cout << "\n������������ �����. ������� ��� ���. ";
			cin >> info_num;
		}
		cout << "������� ����� ����������: \n";
		switch (info_num)
		{
		case 1:
			cout << "����� ��� ��������: ";
			cin >> (*group)[stud_num - 1].name; break;
		case 2:
			cout << "����� ������� ��������: ";
			cin >> (*group)[stud_num - 1].surname; break;
		case 3:
			cout << "����� ����, �� ������� ������ �������: ";
			cin >> (*group)[stud_num - 1].course;  break;
		case 4:
			cout << "����� ������, � ������� ������� �������: ";
			cin >> (*group)[stud_num - 1].group; break;
		case 5:
			cout << "����� ������������� ��������: ";
			cin.ignore();
			gets_s((*group)[stud_num - 1].speciality); break;
		}
		cout << "������ ��������.\n";

		cout << "������ �������� ���������� ��� ������-�� �������� �� ������? (�/�) ";
		cin >> answer;
	}
}

void show_info(student** group, int size)
{
	cout << "������ ������ ���������� ��� ������-�� �������� �� ������? (�/�) ";
	char answer;
	cin >> answer;
	while (answer == '�')
	{
		cout << "���������� ��� ������ �������� �� ������ ������?\n";
		for (int i = 0, num = 1; i < size; i++, num++)
		{
			cout << num << ". " << (*group)[i].surname << "\n";
		}
		int stud_num;
		cin >> stud_num;
		while (stud_num < 1 || stud_num > size)
		{
			cout << "\n������������ �����. ������� ��� ���. ";
			cin >> stud_num;
		}
		cout << "���: " << (*group)[stud_num - 1].name << "\n";
		cout << "�������: " << (*group)[stud_num - 1].surname << "\n";
		cout << "����: " << (*group)[stud_num - 1].course << "\n";
		cout << "������: " << (*group)[stud_num - 1].group << "\n";
		cout << "�������������: " << (*group)[stud_num - 1].speciality << "\n";

		cout << "������ ������ ������ ��� ��� ������ ��������? (�/�) ";
		cin >> answer;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	tochka A, B;
	OXY(&A, &B);
	cout << endl << endl;
	rectangle figure;
	within_rectangle(&figure, &A);
	cout << endl << endl;
	human person1;
	info_cin(&person1);
	cout << endl;
	human_data_choice(person1);
	cout << endl;
	show_figure(&figure);
	cout << endl << endl;
	figure_operations(figure);
	cout << endl;
	drob number1, number2;
	init_drob(&number1);
	cout << endl;
	init_drob(&number2);
	cout << endl << endl;
	drob_operations(number1, number2);
	int size = 0;
	student* group = new student[size];
	add_student(&group, size);
	cout << endl;
	delete_student(&group,size);
	cout << endl;
	change_info(&group, size);
	cout << endl;
	show_info(&group, size);
}