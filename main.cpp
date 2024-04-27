#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

/*1. Создайте структуру, описывающую точку в двумерной системе координат (x, y). С помощью этой структуры задайте две точки. Будет ли прямая, проходящая через эти точки,
параллельна оси ординат или оси абсцисс?*/
struct tochka
{
	int x;
	int y;
};

void OXY(tochka* A, tochka* B)
{
	cout << "Введите координаты точки А: ";
	cin >> A->x >> A->y;
	cout << "Введите координаты точки B: ";
	cin >> B->x >> B->y;
	//формула наклона прямой m = (y2-y1)(x2-x1)
	if (B->y - A->y == 0) cout << "Прямая параллельна оси Х.";
	else if (B->x - A->x == 0) cout << "Прямая параллельна оси Y.";
	else cout << "Прямая не параллельна ни одной из осей.";
}

//2.Создать структуру, описывающую прямоугольник. Написать функцию для определения попадания произвольной точки в данный прямоугольник. Точка также должна описываться структурой.
struct rectangle
{
	int a;
	int b;
};

void within_rectangle(rectangle* figure, tochka* A)
{
	cout << "Введите стороны прямоугольника: ";
	cin >> figure->a >> figure->b;
	cout << "Введите координаты точки А: ";
	cin >> A->x >> A->y;
	if (A->x > figure->a || A->x<0 || A->y>figure->b || A->y < 0) cout << "Точка не принадлежит прямоугольнику.";
	else cout << "Точка принадлежит прямоугольнику.";
}

//3. Создать структуру, описывающую человека. Создать функции для работы с этой структурой (например, заполнение объекта и распечатка данных объекта).
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
	cout << "\tЗаполнение анкеты личных данных\n";
	cout << "Введите имя: "; cin >> person->name;
	cout << "Введите фамилию: "; cin >> person->surname;
	cout << "Введите возраст: "; cin >> person->age;
	cout << "Введите год рождения: "; cin >> person->birth_year;
	cout << "Введите пол: "; cin >> person->gender;
	cin.ignore();
	cout << "Введите номер телефона: "; gets_s(person->telephone); //почему нельзя вводить с пробелами?
	cout << "Введите страну проживания: "; cin >> person->country;
	cout << "Введите национальность: "; cin >> person->nationality;
	cout << "Введите профессию: "; cin >> person->occupation;
}

void human_data_choice(human person)
{
	cout << "Хотите узнать личные данные человека? (д/н) ";
	char answer;
	cin >> answer;
	while (answer == 'д') //почему с кирилицей не работает?
	{
		cout << "Какие данные Вы хотите узнать?\n";
		cout << "1. Фамилия\n2. Имя\n3. Возраст\n4. Год рождения\n5. Пол\n6. Страна проживания\n7. Национальность\n8. Профессия\n9. Номер телефона\n";
		cin >> answer;
		while (answer < '1' && answer > '9')
		{
			cout << "Некорректный номер данных. Введите еще раз. ";
			cin >> answer;
		}
		switch (answer) //почему вместо кирилицы выводит непонятные символы
		{
		case '1':
			cout << "Фамилия: " << person.surname; break;
		case '2':
			cout << "Имя: " << person.name; break;
		case '3':
			cout << "Возраст: " << person.age; break;
		case '4':
			cout << "Год рождения: " << person.birth_year; break;
		case '5':
			cout << "Пол: " << person.gender; break;
		case '6':
			cout << "Страна проживания: " << person.country; break;
		case '7':
			cout << "Национальность: " << person.nationality; break;
		case '8':
			cout << "Профессия: " << person.occupation; break;
		case '9':
			cout << "Номер телефона: " << person.telephone; break;
		}
		cout << "\nХотите узнать дополнительные личные данные человека? (д/н) ";
		cin >> answer;
	}
}

//4. Создать структуру, описывающую прямоугольник. Написать функции для работы с этой структурой (например, перемещение прямоугольника, изменение размера прямоугольника и т.д.).
void show_figure(rectangle* figure)
{
	cout << "Введите стороны прямоугольника для вывода: ";
	cin >> figure->a >> figure->b;
	for (int i = 0; i < figure->a; i++)
	{
		for (int j = 0; j < figure->b; j++) cout << "*";
		cout << endl;
	}
	cout << "Любопытный факт: ";
	if (figure->a == figure->b) cout << "прямоугольник является квадратом.";
	else if (figure->a > figure->b) cout << "прямоугольник стоит.";
	else cout << "прямоугольник лежит.";
}

void no_main_diagonal(rectangle figure)
{
	cout << "\n\nПрямоугольник без главной диагонали:\n";
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
	cout << "\n\nПрямоугольник без побочной диагонали:\n";
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
	cout << "\nКакую из " << figure.a << " строк Вы хотите удалить? ";
	int num;
	cin >> num;
	while (num<0 || num>figure.a)
	{
		cout << "Некорректный номер строки. Введите еще раз.";
		cin >> num;
	}
	cout << "Прямоугольник без " << num << "-й строки:\n";
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
	cout << "\nКакой из " << figure.b << " столбцов Вы хотите удалить? ";
	int num;
	cin >> num;
	while (num<0 || num>figure.b)
	{
		cout << "Некорректный номер столбца. Введите еще раз.";
		cin >> num;
	}
	cout << "Прямоугольник без " << num << "-го столбца:\n";
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
	cout << "\nВведите новые стороны фигуры: ";
	cin >> figure->a >> figure->b;
	cout << "Стороны фигуры успешно поменяны.\n";
}

void figure_operations(rectangle figure)
{
	char agreement = 'д';
	while (agreement == 'д')
	{
		cout << "Какую операцию Вы хотите выполнить над прямоугольником?";
		cout << "\n1. Убрать главную диагональ\n2. Убрать побочную диагональ\n3. Убрать строку\n4. Убрать столбец\n5. Изменить размер\n";
		cout << "Операция №";
		int answer;
		cin >> answer;
		while (answer < 0 || answer>5)
		{
			cout << "\nНекорректный номер операции. Введите еще раз.\n";
			cout << "Операция №";
			cin >> answer;
		}
		switch (answer)
		{
		case 1:
			if (figure.a != figure.b)
			{
				while (figure.a != figure.b)
				{
					cout << "\nФигура не является квадратом. Надо поменять размер.";
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
					cout << "\nФигура не является квадратом. Надо поменять размер.";
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
		cout << "\nХотите выполнить еще какую-нибудь операцию? (д/н) ";
		cin >> agreement;
	}
}

//5. Создать структуру, описывающую обычную дробь. Написать функции, реализующие операции сложения, вычитания, умножения и деления дробей.
struct drob
{
	double drobovoe;
	double number;
	int tseloe;
};

void init_drob(drob* num)
{
	cout << "Введите целую часть числа: "; cin >> num->tseloe;
	cout << "Введите дробную часть числа: "; cin >> num->drobovoe;
	int drob_part = num->drobovoe;
	int size = 1;
	while (drob_part > 9)
	{
		drob_part /= 10;
		size++;
	}
	num->number = num->tseloe + num->drobovoe / pow(10, size);
	cout << "Дробное число = " << num->number;
}

void drob_operations(drob num1, drob num2)
{
	char agreement = 'д';
	while (agreement == 'д')
	{
		cout << "Какую операцию Вы хотите выполнить над дробями?";
		cout << "\n1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление\n";
		cout << "Операция №";
		int answer;
		cin >> answer;
		while (answer < 0 || answer>4)
		{
			cout << "\nНекорректный номер операции. Введите еще раз.\n";
			cout << "Операция №";
			cin >> answer;
		}
		switch (answer)
		{
		case 1:
			cout << "\nСумма дробей = " << num1.number + num2.number;
			break;
		case 2:
			cout << "\nРазница дробей = " << num1.number - num2.number;
			break;
		case 3:
			cout << "\nРезультат умножения дробей = " << num1.number * num2.number;
			break;
		case 4:
			cout << "\nРезультат деления дробей = " << num1.number / num2.number;
			break;
		}
		cout << "\nХотите выполнить еще какую-нибудь операцию? (д/н) ";
		cin >> agreement;
	}
}

/*6. Написать программу, реализующую журнал академической группы с произвольным количеством студентов. Программа должна предоставлять возможность добавления
студента в группу, удаления студента из группы, редактирования данных о студенте, вывода информации о студентах на экран.*/
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
	cout << "Хотите добавить нового студента в список? (д/н) ";
	char answer;
	cin >> answer;
	while (answer =='д')
	{
		cout << "Введите данные о студенте:\n";

		cout << "Имя: "; cin >> stud.name;
		cout << "Фамилия: "; cin >> stud.surname;
		cout << "Курс: "; cin >> stud.course;
		cout << "Номер группы: "; cin >> stud.group;
		cin.ignore();
		cout << "Специальность: "; gets_s(stud.speciality);
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
		cout << "Студент добавлен в список.\n";

		cout << "Хотите добавить еще одного студента в список? (д/н) ";
		cin >> answer;
	}
}

void delete_student(student** group, int& size)
{
	cout << "Хотите удалить студента из списка? (д/н) ";
	char answer;
	cin >> answer;
	if (size == 0) { cout << "В списке нет студентов. "; return; }
	while (answer == 'д')
	{
		if (size == 0) { cout << "В списке нет студентов. "; return; }
		cout << "Кого из студентов Вы хотите удалить?\n";
		for (int i = 0, num = 1; i < size; i++, num++)
		{
			cout << num << ". " << (*group)[i].surname << "\n";
		}
		int del_num;
		cin >> del_num;
		while (del_num < 1 || del_num > size)
		{
			cout << "\nНекорректный номер. Введите еще раз. ";
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
		cout << "Студент удалён из списка.\n";

		cout << "Хотите удалить еще одного студента из списка? (д/н) ";
		cin >> answer;
	}
}

void change_info(student** group, int size)
{
	cout << "Хотите изменить информацию про какого-то студента из списка? (д/н) ";
	char answer;
	cin >> answer;
	while (answer == 'д')
	{
		cout << "Информацию про какого студента Вы хотите изменить?\n";
		for (int i = 0, num = 1; i < size; i++, num++)
		{
			cout << num << ". " << (*group)[i].surname << "\n";
		}
		int stud_num;
		cin >> stud_num;
		while (stud_num < 1 || stud_num > size)
		{
			cout << "\nНекорректный номер. Введите еще раз. ";
			cin >> stud_num;
		}
		cout << "Какую именно информацию Вы хотите изменить?\n";
		cout << "1. Имя\n2. Фамилия\n3. Курс\n4. Группа\n5. Специальность\n";
		int info_num;
		cin >> info_num;
		while (info_num < 1 || info_num > 5)
		{
			cout << "\nНекорректный номер. Введите еще раз. ";
			cin >> info_num;
		}
		cout << "Введите новую информацию: \n";
		switch (info_num)
		{
		case 1:
			cout << "Новое имя студента: ";
			cin >> (*group)[stud_num - 1].name; break;
		case 2:
			cout << "Новая фамилия студента: ";
			cin >> (*group)[stud_num - 1].surname; break;
		case 3:
			cout << "Новый курс, на котором учится студент: ";
			cin >> (*group)[stud_num - 1].course;  break;
		case 4:
			cout << "Новая группа, в которой состоит студент: ";
			cin >> (*group)[stud_num - 1].group; break;
		case 5:
			cout << "Новая специальность студента: ";
			cin.ignore();
			gets_s((*group)[stud_num - 1].speciality); break;
		}
		cout << "Данные изменены.\n";

		cout << "Хотите изменить информацию про какого-то студента из списка? (д/н) ";
		cin >> answer;
	}
}

void show_info(student** group, int size)
{
	cout << "Хотите узнать информацию про какого-то студента из списка? (д/н) ";
	char answer;
	cin >> answer;
	while (answer == 'д')
	{
		cout << "Информацию про какого студента Вы хотите узнать?\n";
		for (int i = 0, num = 1; i < size; i++, num++)
		{
			cout << num << ". " << (*group)[i].surname << "\n";
		}
		int stud_num;
		cin >> stud_num;
		while (stud_num < 1 || stud_num > size)
		{
			cout << "\nНекорректный номер. Введите еще раз. ";
			cin >> stud_num;
		}
		cout << "Имя: " << (*group)[stud_num - 1].name << "\n";
		cout << "Фамилия: " << (*group)[stud_num - 1].surname << "\n";
		cout << "Курс: " << (*group)[stud_num - 1].course << "\n";
		cout << "Группа: " << (*group)[stud_num - 1].group << "\n";
		cout << "Специальность: " << (*group)[stud_num - 1].speciality << "\n";

		cout << "Хотите узнать данные про еще одного студента? (д/н) ";
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