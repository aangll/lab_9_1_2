#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec { COMPUTERSCIENCE, IT, ECONOMY, PHYSICS, ART };

string specStr[] = { "комп'ютерні науки", "інформатика", "математика та економіка", "фізика та інформатика", "трудове навчання" };
struct Student
{
	string prizv;
	unsigned kurs;
	Spec spec;
	unsigned physicsGrades;
	unsigned mathsGrades;
	union
	{
		unsigned programGrades;
		unsigned methodGrades;;
		unsigned pedagogGrades;
	};
};

void Create(Student* s, const int N);
void Sort(Student* s, const int N);
void Print(Student* s, const int N);
int Count(Student* s, const int N);
void LowestAverage(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* s = new Student[N];
	Create(s, N);
	Sort(s, N);
	Print(s, N);
	cout << "Кількість студентів, середній бал яких менший за 4: " << Count(s, N) << endl;
	LowestAverage(s, N);
	return 0;
}

void Create(Student* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " прізвище: "; getline(cin, s[i].prizv);
		cout << " курс: "; cin >> s[i].kurs;
		cout << " спеціальність (0 - комп'ютерні науки, 1 - інформатика, 2 - математика та економіка, 3 - фізика та інформатика, 4 - трудове навчання): ";
		cin >> spec;
		cout << " оцінки з фізики: "; cin >> s[i].physicsGrades;
		cout << " оцінки з математики: "; cin >> s[i].mathsGrades;
		s[i].spec = (Spec)spec;
		switch (s[i].spec)
		{
		case COMPUTERSCIENCE:
			cout << " оцінки з програмування: "; cin >> s[i].programGrades;
			break;
		case IT:
			cout << " оцінки з чисельних методів: "; cin >> s[i].methodGrades;
			break;
		case ECONOMY:
			cout << " оцінки з педагогіки: "; cin >> s[i].pedagogGrades;
			break;
		case ART:
			cout << " оцінки з педагогіки: "; cin >> s[i].pedagogGrades;
			break;
		case PHYSICS:
			cout << " оцінки з педагогіки: "; cin >> s[i].pedagogGrades;
			break;	
		}

		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "======================================================================================================================================================================="
		<< endl;
	cout << "| №  | Прізвище    | курс| спеціальність          | оцінка з фізики | оцінка з математики | оцінка з програмування | оцінка з чисельних методів | оцінка з педагогіки |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(12) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << " "
			<< "| " << setw(23) << left << specStr[s[i].spec]
			<< "| " << setw(15) << right << s[i].physicsGrades << " "
			<< "| " << setw(19) << right << s[i].mathsGrades << " ";

			switch (s[i].spec)
			{
			case COMPUTERSCIENCE:
				cout << "| " << setw(22) << right << s[i].programGrades << " |                            |" << "                     |"
					<< endl;
				break;
			case IT:
				cout << "|                        | " << setw(26) << s[i].methodGrades << " |                     |"
				<< endl;
				break;
			case ECONOMY:
				cout << "|                        |                            | " << setw(19) << s[i].pedagogGrades << " |"
					<< endl;
				break;
			case ART:
				cout << "|                        |                            | " << setw(19) << s[i].pedagogGrades << " |"
					<< endl;
				break;
			case PHYSICS:
				cout << "|                        |                            | " << setw(19) << s[i].pedagogGrades << " |"
					<< endl;
				break;
			}
	}
	cout << "======================================================================================================================================================================="
		<< endl;
	cout << endl;
}

void Sort(Student* s, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (s[i1].prizv > s[i1 + 1].prizv)
			{
				tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}
}

int Count(Student* s, const int N)
{
	int k = 0;


	for (int i = 0; i < N; i++) {

		if (s[i].spec == 0)
			if (((s[i].mathsGrades + s[i].programGrades + s[i].physicsGrades) / 3) < 4)
			{
				k++;
			}

		if (s[i].spec == 1)
			if (((s[i].mathsGrades + s[i].methodGrades + s[i].physicsGrades) / 3) < 4)
			{
				k++;
			}

		if (s[i].spec == 2 || s[i].spec == 3 || s[i].spec == 4)
			if (((s[i].mathsGrades + s[i].pedagogGrades + s[i].physicsGrades) / 3) < 4)
			{
				k++;
			}
	}

	return k;
}

void LowestAverage(Student* s, const int N)
{
	double MathsAv;
	double ProgramAv;
	double PhysicsAv;
	double PedagogAv;
	double MethodAv;

	int m = 0;
	int p = 0;
	int t = 0;
	int h = 0;
	int g = 0;

	for (int i = 0; i < N; i++) {

		m += s[i].mathsGrades;
		p += s[i].physicsGrades;
		t += s[i].programGrades;
		h += s[i].methodGrades;
		g += s[i].pedagogGrades;
	}

	MathsAv = m / N;
	PhysicsAv = p / N;
	ProgramAv = t / N;
	MethodAv = h / N;
	PedagogAv = g / N;

	double min;
	if (PhysicsAv < MathsAv && PhysicsAv < ProgramAv && PhysicsAv < PedagogAv && PhysicsAv < MethodAv) {

		min = PhysicsAv;
		cout << "мінімальний середній бал з фізики, він дорівнює " << min;

	}

	else if (ProgramAv < MathsAv && ProgramAv < PhysicsAv && ProgramAv < MethodAv && ProgramAv < PedagogAv) {

		min = ProgramAv;
		cout << "мінімальний середній бал з програмування, він дорівнює " << min;

	}

	if (MethodAv < MathsAv && MethodAv < ProgramAv && MethodAv < PedagogAv && MethodAv < PhysicsAv) {

		min = MethodAv;
		cout << "мінімальний середній бал з чисельних методів, він дорівнює " << min;

	}

	if (PedagogAv < MathsAv && PedagogAv < ProgramAv && PedagogAv < MethodAv && PedagogAv < PhysicsAv) {

		min = PedagogAv;
		cout << "мінімальний середній бал з педагогіки, він дорівнює " << min;

	}

	else {

		min = MathsAv;
		cout << "мінімальний середній бал з математики, він дорівнює " << min;

	}
}