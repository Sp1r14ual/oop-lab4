﻿#include "Empirical.h"

Empirical::Empirical(const IDistribution* D, int _n, int _k) :
	n(_n > 1 ? _n : throw invalid_argument("Некорректный аргумент")), k(_k > 2 ? _k : (int)floor(log2(_n)) + 1)
{
	x_s = D->generate_sequence(_n);
	f_s = generate_values();
}

Empirical::Empirical(const Empirical* EM) : n(EM->n > 1 ? EM->n : throw invalid_argument("Некорректный аргумент")), k(EM->k > 2 ? EM->k : (int)floor(log2(EM->n) + 1)), x_s(EM->x_s), f_s(EM->f_s)
{
	f_s = generate_values();
}

Empirical::Empirical(const int _n, const int _k) : n(_n > 1 ? _n : throw invalid_argument("Некорректный аргумент")), k(_k > 2 ? _k : (int)floor(log2(_n) + 1))
{
	x_s = generate_sequence(n);
	f_s = generate_values();
}

Empirical::Empirical(const vector<double>& x_s) : n(x_s.size()), k((int)floor(log2(x_s.size())) + 1)
{
	this->x_s = x_s;
	f_s = generate_values();
}

Empirical::Empirical(ifstream& file)
{
	load_from_file(file);
}

Empirical::~Empirical()
{
	x_s.clear();
	f_s.clear();
}

Empirical& Empirical::operator=(const Empirical& EM)
{
	if (this == &EM)
		return *this;

	x_s = EM.x_s;
	f_s = EM.f_s;
	n = EM.n;
	k = EM.k;
	return *this;
}

double Empirical::random_var() const
{
	vector<double> intervals;
	vector<double> densities;

	int k = get_k();
	double delta = (1.0 - 0.0) / (double)k;

	double point = 0.0;
	while (point < 1.0)
	{
		intervals.push_back(point);
		point += delta;
	}
	//intervals.push_back(1.0);

	for (int i = 0; i < k; i++)
		densities.push_back(delta);

	random_device rd;
	default_random_engine gen(rd());
	piecewise_constant_distribution<> d(intervals.begin(), intervals.end() - 1, densities.begin());

	return d(gen);

}

vector<double> Empirical::generate_sequence(const int n) const
{
	vector<double> result;

	for (int i = 0; i < n; i++)
		result.push_back(random_var());

	sort(result.begin(), result.end());

	return result;
}


vector<double> Empirical::generate_values() const
{
	vector<double> result;

	for (const double& x : x_s)
		result.push_back(f(x));

	return result;
}

vector<pair<double, double>> Empirical::generate_table_of_values(const int n, const vector<double>& x_s) const
{
	vector<pair<double, double >> result;

	for (int i = 0; i < n; i++)
		result.push_back(make_pair(x_s[i], f_s[i]));

	return result;
}

vector<double> Empirical::get_x_s() const
{
	return x_s;
}

vector<double> Empirical::get_f_s() const
{
	return f_s;
}

int Empirical::get_n() const
{
	return n;
}

int Empirical::get_k() const
{
	return k;
}

void Empirical::save_to_file(ofstream& file)
{
	vector<pair<double, double>> pairs = generate_table_of_values(n);

	ofstream file_sequence;
	ofstream file_values;
	ofstream file_params;
	string filename_sequence;
	string filename_values;
	string filename_params;

	cout << "Введите имя файла, куда следует записать выборку: ";
	cin >> filename_sequence;
	cout << "Введите имя файла, куда следует записать плотности распределения: ";
	cin >> filename_values;
	cout << "Введите имя файла, куда следует записать параметры распределения: ";
	cin >> filename_params;

	file_sequence.open(filename_sequence);
	file_values.open(filename_values);
	file_params.open("empirical_params.txt");

	for (const pair<double, double>& pair : pairs)
	{
		file_sequence << pair.first << endl;
		file_values << pair.second << endl;
	}

	file_params << n << k;

	file_sequence.close();
	file_values.close();
	file_params.close();

	cout << "Выборка сохранена в файл " + filename_sequence << endl;
	cout << "Значения плотности сохранены в " + filename_values << endl;
	cout << "Параметры распределения сохранены в файл " + filename_params << endl << endl;
}

void Empirical::load_from_file(ifstream& file)
{
	string filename;

	cout << "Введите имя файла с выборкой элементов эмпирического распределения: ";
	cin >> filename;

	file.open(filename);
	if (!file)
		throw runtime_error("Ошибка: не удалось открыть файл");

	double x;
	while (!file.eof())
	{
		file >> x;
		x_s.push_back(x);
	}
	file.close();

	n = x_s.size();
	k = (int)floor(log2(n)) + 1;
	f_s = generate_values();
}


double Empirical::f(const double x) const
{
	int k = (int)floor(log2((double)n)) + 1;
	double min_x = *min_element(begin(x_s), end(x_s));
	double max_x = *max_element(begin(x_s), end(x_s));
	double delta = (max_x - min_x) / (double)k;

	for (int i = 0; i < k; i++)
		if (min_x + delta * i <= x && x < min_x + delta * (i + 1))
		{
			int n_i = count_if(x_s.begin(), x_s.end(), [i, k, min_x, max_x, delta](double x) { return i == k - 1 ? min_x + delta * (double)i <= x && x <= min_x + delta * (double)(i + 1) : min_x + delta * (double)i <= x && x < min_x + delta * (double)(i + 1); });
			return n_i / (n * delta);
		}

	return 0.0;
}

double Empirical::expected_value() const
{
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += x_s[i];
	}
	return sum / (double)n;
}

double Empirical::variance() const
{
	const double expected_val = expected_value();
	double sum = 0;

	for (int i = 0; i < n; ++i)
		sum += pow(x_s[i] - expected_val, 2);

	return sum / n;
}

double Empirical::asymmetry() const
{
	const double expected_val = expected_value();
	const double variance_val = variance();
	double sum = 0;

	for (int i = 0; i < n; ++i)
		sum += pow(x_s[i] - expected_val, 3);

	return sum / (n * pow(variance_val, 3 / 2));
}

double Empirical::kurtosis() const
{
	const double expected_val = expected_value();
	const double variance_val = variance();
	double sum = 0;

	for (int i = 0; i < n; ++i) {
		sum += pow(x_s[i] - expected_val, 4);
	}
	return (sum / (n * pow(variance_val, 2))) - 3;
}