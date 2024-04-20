#include "save.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void save(string_view fileName)
{
	// 1. fileName �� �б������ ����.
	// 2. ������ ������ ���ٿ� ���� ���� ����.
	// 3.���� ������ ������ �о� �� ���Ͽ� �� ���δ�. 


		// 1. fileName �� �б������ ����.
		ifstream in{ fileName.data() }; //RAII

		if (!in)
		{
			cout << fileName << " ���� ����" << endl;
			exit(0);
		}

		//cout << sizeof(in) << endl;
		//cout << addressof(in) << endl;
		//cout << typeid(in).name() << endl;



		// 2. ������ ������ ���ٿ� ���� ���� ����.

		ofstream out{ "2024 1�б� STL ���� ����.txt", ios::app };



		// 3.���� ������ ������ �о� �� ���Ͽ� �� ���δ�. 
		//STL �ڷᱸ���� �˰����� �̿��Ͽ� ����Ѵ� ( ������ �ƴϴ�.)

		vector<char> v{ istreambuf_iterator<char>{in},{} };

		// ====================�ð� ����ϴ� ���=========================//
		// 1.���� time_point �� ��´�.
		auto now = chrono::system_clock::now(); // epoch ���κ��� �帥 tick
		// 2.UTC �ð��������� ��ȯ
		auto utc_time = chrono::system_clock::to_time_t(now);
		// 3.���� �ð����� �ٲ۴�.
		auto lt = localtime(&utc_time);
		// 4.�ѱ� �������� ����Ѵ�. (��½�Ʈ���� ������ ��ȯ�Ѵ�.)
		auto old = out.imbue(locale("ko_KR"));
		// 5.�ð��� ����Ѵ�.
		out << endl << endl;
		out << "=============================================== " << endl;
		out << fileName << " " << put_time(lt, "%x %A %X") << endl;
		out << "=============================================== " << endl;
		// 6.�ٽ� ���󺹱��Ѵ�.
		out.imbue(locale(old));
		// ===================================================//
		out << endl;
		copy(v.begin(), v.end(), ostreambuf_iterator<char>{out});
}