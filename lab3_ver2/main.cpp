#include "Header.h"

int main() {
	setlocale(LC_ALL, "Russian");

	tree a;
	int var;
	int data;
	cout << " ��������� ��������:" << endl;
	cout << " 1)����� �������� � ������ �� �����" << endl;
	cout << " 2)���������� �������� � ������ �� �����" << endl;
	cout << " 3)�������� � ������ �� �����" << endl;
	cout << " 4)����������� ������ � ������" << endl;
	cout << " 5)����������� ������ � �������" << endl;
	cout << " 6)��������� ������ � �������" << endl;

	while (1) {
		cout << "�������� ��������: ";
		cin >> var;
		cout << endl;
		if (var == 1) {
			cout << "������� ����: ";
			cin >> data;
			cout << endl;
			if (a.contains(data) == 1) {
				cout << "�������� ���� � ������" << endl;
			}
			else {
				cout << "�������� ��� � ������" << endl;
			}
		}

		if (var == 2) {
			cout << "������� ����: ";
			cin >> data;
			cout << endl;
			a.insert(data);
		}

		if (var == 3) {
			cout << "������� ����: ";
			cin >> data;
			if (a.contains(data)) {
				a.remove(data);
			}
			else {
				cout << "�������� ����, �������� ����������";
			}

		}
		if (var == 4) {
			cout << "������� ����������� � ������: ";
			iteratorS* a_iteratorS = a.create_iteratorS();
			while (a_iteratorS->has_next()) {
				cout << a_iteratorS->next() << " ";
			}
			cout << endl << endl;
		}
		if (var == 5) {
			cout << "������� ����������� � �������: ";
			iteratorG* a_iteratorG = a.create_iteratorG();
			int ii = 1;
			while (ii <= a.size) {
				cout << a_iteratorG->Next() << " ";
				ii++;
			}
			cout << endl << endl;
		}
		if (var == 6) {
			return 0;
		}
	}

}