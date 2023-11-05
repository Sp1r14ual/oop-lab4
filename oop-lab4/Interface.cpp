#include "Interface.h"

void step3_primary(Primary* HB)
{
	ofstream x_s;
	ofstream y_s;
	ofstream params;
	vector<pair<double, double>> table;
	char option;
	int n;
	double x = 0;

	cout << "��� ������ ������?" << endl;
	cout << "1. ������� ��������� ������������� �� �����" << endl;
	cout << "2. ��������� �������� ��������� ������������� � ������������ �����" << endl;
	cout << "3. �������� ������� ��� �������" << endl;
	cout << "4. ������� ��������� ������������� � ����" << endl;
	cout << "5. �����" << endl << endl;


	cin >> option;
	cout << endl;

	switch (option)
	{
	case '1':
		cout << "v = " << HB->get_v() << endl;
		cout << "K = " << HB->get_k() << endl;
		cout << "Scale = " << HB->get_scale() << endl;
		cout << "Shift = " << HB->get_shift() << endl;
		cout << "M[X] = " << HB->expected_value() << endl;
		cout << "D[X] = " << HB->variance() << endl;
		cout << "As[X] = " << HB->asymmetry() << endl;
		cout << "Kurt[X] = " << HB->kurtosis() << endl;
		cout << "P = " << HB->P() << endl;
		cout << "f(0) = " << HB->f(0) << endl << endl << endl;

		break;

	case '2':
		cout << "������� x: ";
		cin >> x;
		cout << endl << "f(" << x << ") = " << HB->f(x) << endl << endl;
		break;

	case '3':
		x_s.open("x_s.txt");
		y_s.open("y_s.txt");
		cout << "������� ����������� ������� n: ";
		cin >> n;
		table = HB->generate_table_of_values(n);
		for (const pair<double, double>& pr : table)
		{
			x_s << pr.first << endl;
			y_s << pr.second << endl;
		}

		x_s.close();
		x_s.close();

		cout << endl << "�������� ������� �������� � ����� x_s.txt � y_s.txt" << endl << endl;
		break;

	case '4':
		HB->save_to_file(params);
		cout << endl << endl;
		break;

	case '5':
		cout << endl << endl;
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;
	}
}

void step3_mixture(Mixture<Primary, Primary>* MX)
{
	ofstream x_s;
	ofstream y_s;
	ofstream params;
	vector<pair<double, double>> table;
	char option;
	int n;
	double x = 0;

	cout << "�������� �����:" << endl;
	cout << "1. ������� ��������� ����� ������������� �� �����" << endl;
	cout << "2. ��������� �������� ��������� ����� ������������� � ������������ �����" << endl;
	cout << "3. �������� ������� ��� �������" << endl;
	cout << "4. ������� ��������� ����� ������������� � ����" << endl;
	cout << "5. �����" << endl << endl;

	cin >> option;
	cout << endl;

	switch (option)
	{
	case '1':
		cout << "P = " << MX->get_p() << endl;
		cout << "V1 = " << MX->get_component1()->get_v() << endl;
		cout << "K1 = " << MX->get_component1()->get_k() << endl;
		cout << "Scale1 = " << MX->get_component1()->get_scale() << endl;
		cout << "Shift1 = " << MX->get_component1()->get_shift() << endl;
		cout << "V2 = " << MX->get_component2()->get_v() << endl;
		cout << "K2 = " << MX->get_component2()->get_k() << endl;
		cout << "Scale2 = " << MX->get_component2()->get_scale() << endl;
		cout << "Shift2 = " << MX->get_component2()->get_shift() << endl;
		cout << "M[X] = " << MX->expected_value() << endl;
		cout << "D[X] = " << MX->variance() << endl;
		cout << "As[X] = " << MX->asymmetry() << endl;
		cout << "Kurt[X] = " << MX->kurtosis() << endl;
		cout << "f(0) = " << MX->f(x) << endl << endl << endl;

		break;

	case '2':
		cout << "������� x: ";
		cin >> x;
		cout << endl << "f(" << x << ") = " << MX->f(x) << endl << endl;
		break;

	case '3':
		x_s.open("x_s.txt");
		y_s.open("y_s.txt");
		cout << "������� ����������� ������� n: ";
		cin >> n;
		table = MX->generate_table_of_values(n);
		for (const pair<double, double>& pr : table)
		{
			x_s << pr.first << endl;
			y_s << pr.second << endl;
		}

		x_s.close();
		x_s.close();

		cout << endl << "�������� ������� �������� � ����� x_s.txt � y_s.txt" << endl << endl;
		break;

	case '4':
		MX->save_to_file(params);
		cout << endl << endl;
		break;

	case '5':
		cout << endl << endl;
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl << endl;
		break;
	}

}

void step3_empirical(Empirical* EM)
{
	ofstream file;
	char option;
	double x = 0;

	cout << "�������� �����:" << endl;
	cout << "1. ������� ��������� ������������� ������������� �� �����" << endl;
	cout << "2. ��������� �������� ��������� ����� ������������� � ������������ �����" << endl;
	cout << "3. ������� ������� ��������� � ��������� ������������� ������������� � ����" << endl;
	cout << "4. �����" << endl << endl;

	cin >> option;
	cout << endl;

	switch (option)
	{
	case '1':
		cout << "n = " << EM->get_n() << endl;
		cout << "K = " << EM->get_k() << endl;
		cout << "M[X] = " << EM->expected_value() << endl;
		cout << "D[X] = " << EM->variance() << endl;
		cout << "As[X] = " << EM->asymmetry() << endl;
		cout << "Kurt[X] = " << EM->kurtosis() << endl;
		cout << "f(0) = " << EM->f(x) << endl << endl << endl;

		break;

	case '2':
		cout << "������� x: ";
		cin >> x;
		cout << endl << "f(" << x << ") = " << EM->f(x) << endl << endl;
		break;

	case '3':
		EM->save_to_file(file);
		cout << endl << endl;
		break;

	case '4':
		cout << endl << endl;
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;
	}
}

void step2_primary()
{
	char option;
	double v, scale, shift;
	Primary* HB;
	ifstream file;

	cout << "�������� �����: " << endl;
	cout << "1. ����������� ������������� �������" << endl;
	cout << "2. ������ ������������ ��������� � ����������" << endl;
	cout << "3. ������� ��������� �� �����" << endl;
	cout << "4. �����" << endl << endl;

	cin >> option;
	cout << endl;

	switch (option)
	{
	case '1':
		cout << "������� �������� v: ";
		cin >> v;
		cout << endl << endl;
		try
		{
			HB = new Primary(v);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}

		step3_primary(HB);
		break;

	case '2':
		cout << "������� v scale shift: ";
		cin >> v >> scale >> shift;
		cout << endl << endl;
		try
		{
			HB = new Primary(v, scale, shift);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}

		step3_primary(HB);
		break;

	case '3':
		try
		{
			HB = new Primary(file);
		}
		catch (exception e)
		{
			cerr << endl << e.what() << endl << endl;
			break;
		}

		step3_primary(HB);
		break;

	case '4':
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;
	}
}

void step2_mixture()
{
	char option;
	double p, v1, scale1, shift1, v2, scale2, shift2;
	Mixture<Primary, Primary>* MX;
	Primary* HB1;
	Primary* HB2;
	ifstream file;

	cout << "�������� �����: " << endl;
	cout << "1. ����������� ��������� ����� �������������" << endl;
	cout << "2. ���� � ����������" << endl;
	cout << "3. ���� �� �����" << endl;
	cout << "4. �����" << endl << endl;

	cin >> option;
	cout << endl << endl;

	switch (option)
	{
	case '1':
		MX = new Mixture<Primary, Primary>(new Primary(), new Primary(), 0.5);
		step3_mixture(MX);
		break;

	case '2':
		cout << "������� p (v1 scale1 shift1) (v2 scale2 shift2) (����� ������ ��� ����� Enter): ";
		cin >> p >> v1 >> scale1 >> shift1 >> v2 >> scale2 >> shift2;
		try
		{
			HB1 = new Primary(v1, scale1, shift1);
			HB2 = new Primary(v2, scale2, shift2);
			MX = new Mixture<Primary, Primary>(HB1, HB2, p);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}
		step3_mixture(MX);
		break;

	case '3':
		MX = new Mixture<Primary, Primary>(new Primary(), new Primary(), 0.5);
		try
		{
			MX->load_from_file(file);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}
		step3_mixture(MX);
		break;

	case '4':
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;
	}
}

void step2_empirical_from_primary()
{
	Empirical* EM;
	char option;
	double v, scale, shift;
	int n, k;
	Primary* HB;
	ifstream file;

	cout << "�������� �����: " << endl;
	cout << "1. ����������� ������������� �������" << endl;
	cout << "2. ������ ������������ ��������� � ����������" << endl;
	cout << "3. ������� ��������� �� �����" << endl;
	cout << "4. �����" << endl << endl;

	cin >> option;
	cout << endl << endl;

	switch (option)
	{
	case '1':
		cout << "������� �������� v: ";
		cin >> v;
		cout << endl << endl;
		try
		{
			HB = new Primary(v);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}
		cout << "������� n: ";
		cin >> n;
		cout << "������� k (0, ���� ������ ���������� k �� ������� ����������): ";
		cin >> k;
		cout << endl << endl;

		EM = new Empirical(HB, n, k);
		step3_empirical(EM);

		break;

	case '2':
		cout << "������� v scale shift: ";
		cin >> v >> scale >> shift;
		cout << endl << endl;
		try
		{
			HB = new Primary(v, scale, shift);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}
		cout << "������� n: ";
		cin >> n;
		cout << "������� k (0, ���� ������ ���������� k �� ������� ����������): ";
		cin >> k;
		cout << endl << endl;
		EM = new Empirical(HB, n, k);
		step3_empirical(EM);

		break;

	case '3':
		try
		{
			HB = new Primary(file);
		}
		catch (exception e)
		{
			cerr << endl << e.what() << endl;
			break;
		}

		cout << "������� n: ";
		cin >> n;
		cout << "������� k (0, ���� ������ ���������� k �� ������� ����������): ";
		cin >> k;

		EM = new Empirical(HB, n, k);
		step3_empirical(EM);
		break;

	case '4':
		cout << endl << endl;
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;
	}
}

void step2_empirical_from_mixture()
{
	Empirical* EM;
	char option;
	double p, v1, scale1, shift1, v2, scale2, shift2;
	int n, k;
	Mixture<Primary, Primary>* MX;
	Primary* HB1;
	Primary* HB2;
	ifstream file;

	cout << "�������� �����: " << endl;
	cout << "1. ����������� ��������� ����� �������������" << endl;
	cout << "2. ���� � ����������" << endl;
	cout << "3. ���� �� �����" << endl;
	cout << "4. �����" << endl << endl;

	cin >> option;
	cout << endl << endl;

	switch (option)
	{
	case '1':
		MX = new Mixture<Primary, Primary>(new Primary(), new Primary, 0.5);

		cout << "������� n: ";
		cin >> n;
		cout << "������� k (0, ���� ������ ���������� k �� ������� ����������): ";
		cin >> k;
		cout << endl << endl;

		EM = new Empirical(MX, n, k);

		step3_empirical(EM);
		break;

	case '2':
		cout << "������� p (v1 scale1 shift1) (v2 scale2 shift2) (����� ������ ��� ����� Enter): ";
		cin >> p >> v1 >> scale1 >> shift1 >> v2 >> scale2 >> shift2;
		try
		{
			HB1 = new Primary(v1, scale1, shift1);
			HB2 = new Primary(v2, scale2, shift2);
			MX = new Mixture<Primary, Primary>(HB1, HB2, p);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}
		cout << "������� n: ";
		cin >> n;
		cout << "������� k (0, ���� ������ ���������� k �� ������� ����������): ";
		cin >> k;
		cout << endl << endl;

		EM = new Empirical(MX, n, k);
		step3_empirical(EM);
		break;

	case '3':
		MX = new Mixture<Primary, Primary>(new Primary(), new Primary(), 0.5);
		try
		{
			MX->load_from_file(file);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}

		cout << "������� n: ";
		cin >> n;
		cout << "������� k (0, ���� ������ ���������� k �� ������� ����������): ";
		cin >> k;
		cout << endl << endl;

		EM = new Empirical(MX, n, k);
		step3_empirical(EM);
		break;

	case '4':
		cout << endl << endl;
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;
	}
}

void step2_empirical_from_empirical()
{
	Empirical* EM;
	char option;
	ifstream file;
	string filename;
	int n, k;

	cout << "1. ������ ��������� ������������� �� �����" << endl;
	cout << "2. �����" << endl << endl;

	cin >> option;
	cout << endl << endl;

	switch (option)
	{
	case '1':
		cout << "������� ��� ����� � ����������� �������������: ";
		cin >> filename;
		cout << endl << endl;

		file.open(filename);

		if (!file)
			throw runtime_error("������: �� ������� ������� ����");

		while (!file.eof())
			file >> n >> k;

		file.close();

		try
		{
			EM = new Empirical(n, k);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}
		cout << endl << endl;

		step3_empirical(EM);
		break;

	case '2':
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;

	}
}

void step2_empirical_from_sequence()
{
	Empirical* EM;
	char option;
	ifstream file;
	string filename;
	double x;
	vector<double> x_s;

	cout << "1. ������ ������� ��������� �� �����" << endl;
	cout << "2. �����" << endl << endl;

	cin >> option;
	cout << endl;

	switch (option)
	{
	case '1':
		cout << "������� ��� ����� � ����������� �������������: ";
		cin >> filename;
		cout << endl << endl;

		file.open(filename);

		if (!file)
			throw runtime_error("������: �� ������� ������� ����");

		while (!file.eof())
		{
			file >> x;
			x_s.push_back(x);
		}

		file.close();

		try
		{
			EM = new Empirical(x_s);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}

		cout << endl << endl;
		step3_empirical(EM);
		break;

	case '2':
		cout << endl << endl;
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;

	}

}

void step2_empirical()
{
	Empirical* EM;
	ifstream file;
	int n, k;
	char option;

	cout << "������ ����� ��������� ��� ������������� �������������?" << endl;
	cout << "1. �������� �������������" << endl;
	cout << "2. ����� �������������" << endl;
	cout << "3. �� ���� ������������� ������������� �������������" << endl;
	cout << "4. �� ���� ������������ ������� ��������� ��������� ��������" << endl;
	cout << "5. ����������� ���������" << endl;
	cout << "6. ������ ��������� �� �����" << endl;
	cout << "7. �����" << endl << endl;

	cin >> option;
	cout << endl;

	switch (option)
	{
	case '1':
		step2_empirical_from_primary();
		break;

	case '2':
		step2_empirical_from_mixture();
		break;

	case '3':
		step2_empirical_from_empirical();
		break;

	case '4':
		step2_empirical_from_sequence();
		break;

	case '5':
		cout << "������� n: ";
		cin >> n;
		cout << "������� k (0, ���� ������ ���������� k �� ������� ����������): ";
		cin >> k;
		cout << endl << endl;

		EM = new Empirical(n, k);
		step3_empirical(EM);
		break;

	case '6':
		try {
			EM = new Empirical(file);
		}
		catch (exception e)
		{
			cerr << e.what() << endl << endl;
			break;
		}
		step3_empirical(EM);
		break;

	case '7':
		break;

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;
	}
}

void step1()
{
	char option;

	cout << "�������������: " << endl;
	cout << "1. �������� �������������" << endl;
	cout << "2. ����� �������������" << endl;
	cout << "3. ������������ �������������" << endl;
	cout << "4. �����" << endl << endl;

	cin >> option;
	cout << endl << endl;

	switch (option)
	{
	case '1':
		step2_primary();
		break;

	case '2':
		step2_mixture();
		break;

	case '3':
		step2_empirical();
		break;

	case '4':
		cout << "���������� ������" << endl << endl;
		exit(0);

	default:
		cerr << endl << "������: ������������ ��������" << endl << endl;
		break;
	}
}

void start()
{
	while (true)
		step1();
}