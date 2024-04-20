//-------------------------------------------------------------------------------------------------------
//                          2024. 1학기 STL 4월 18일 목요일  (7 주 2)                                   //
//
// 4월 25일 (8주 2일) - 중간시험
// STL container - Sequence - deque
// 덱-> 벡터와 리스트의 짬뽕
// push_back , push_front => o(1) 알고리즘
// 리스트의 단점: 메모리를 많이먹는다 ,  순회속도가 느리다.
//-------------------------------------------------------------------------------------------------------

#include <iostream>
#include "save.h"
#include <array>
#include "Mystring.h"
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;




int main()
{
	관찰 = false;

	vector<shared_ptr<String>> a;
	관찰 = true;

	a.push_back(make_shared<String>("hello world"));
	a.push_back(make_shared<String>("wafawfaw"));
	a.push_back(make_shared<String>("15454823"));

	관찰 = false;
	//for (String& s : a)
	//{
	//	cout << s << endl;
	//}

	//관찰 = true;
	std::sort(a.begin(), a.end(), [](const auto& a, const auto& b)
		{
			return a->GetLen() < b->GetLen();
		});
	관찰 = false;

	for (const auto& s : a)
	{
		sort(s->GetPtr(), s->GetPtr() + s->GetLen());
	}


	//[문제] a의 각 string 이 관리하는 글자를 오름차순으로 정렬하라.

	for (const auto& s: a)
	{
		cout << *s << endl;
	}

	//save("STL.cpp");
}


