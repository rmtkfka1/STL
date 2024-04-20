#include "save.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void save(string_view fileName)
{
	// 1. fileName 을 읽기용으로 연다.
	// 2. 저장할 파일을 덧붙여 쓰기 모드로 연다.
	// 3.읽을 파일의 내용을 읽어 쓸 파일에 덧 붙인다. 


		// 1. fileName 을 읽기용으로 연다.
		ifstream in{ fileName.data() }; //RAII

		if (!in)
		{
			cout << fileName << " 열기 실패" << endl;
			exit(0);
		}

		//cout << sizeof(in) << endl;
		//cout << addressof(in) << endl;
		//cout << typeid(in).name() << endl;



		// 2. 저장할 파일을 덧붙여 쓰기 모드로 연다.

		ofstream out{ "2024 1학기 STL 강의 저장.txt", ios::app };



		// 3.읽을 파일의 내용을 읽어 쓸 파일에 덧 붙인다. 
		//STL 자료구조와 알고리즘을 이용하여 기록한다 ( 좋은건 아니다.)

		vector<char> v{ istreambuf_iterator<char>{in},{} };

		// ====================시간 출력하는 방법=========================//
		// 1.현재 time_point 를 얻는다.
		auto now = chrono::system_clock::now(); // epoch 으로부터 흐른 tick
		// 2.UTC 시간형식으로 변환
		auto utc_time = chrono::system_clock::to_time_t(now);
		// 3.현지 시간으로 바꾼다.
		auto lt = localtime(&utc_time);
		// 4.한국 형식으로 출력한다. (출력스트림의 지역을 변환한다.)
		auto old = out.imbue(locale("ko_KR"));
		// 5.시간을 출력한다.
		out << endl << endl;
		out << "=============================================== " << endl;
		out << fileName << " " << put_time(lt, "%x %A %X") << endl;
		out << "=============================================== " << endl;
		// 6.다시 원상복구한다.
		out.imbue(locale(old));
		// ===================================================//
		out << endl;
		copy(v.begin(), v.end(), ostreambuf_iterator<char>{out});
}