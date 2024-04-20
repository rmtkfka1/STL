//-------------------------------------------------------------------------------------------------------
//                          2024. 1�б� STL 4�� 18�� �����  (7 �� 2)                                   //
//
// 4�� 25�� (8�� 2��) - �߰�����
// STL container - Sequence - deque
// ��-> ���Ϳ� ����Ʈ�� «��
// push_back , push_front => o(1) �˰���
// ����Ʈ�� ����: �޸𸮸� ���̸Դ´� ,  ��ȸ�ӵ��� ������.
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
	���� = false;

	vector<shared_ptr<String>> a;
	���� = true;

	a.push_back(make_shared<String>("hello world"));
	a.push_back(make_shared<String>("wafawfaw"));
	a.push_back(make_shared<String>("15454823"));

	���� = false;
	//for (String& s : a)
	//{
	//	cout << s << endl;
	//}

	//���� = true;
	std::sort(a.begin(), a.end(), [](const auto& a, const auto& b)
		{
			return a->GetLen() < b->GetLen();
		});
	���� = false;

	for (const auto& s : a)
	{
		sort(s->GetPtr(), s->GetPtr() + s->GetLen());
	}


	//[����] a�� �� string �� �����ϴ� ���ڸ� ������������ �����϶�.

	for (const auto& s: a)
	{
		cout << *s << endl;
	}

	//save("STL.cpp");
}


