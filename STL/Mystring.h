#pragma once
///////////////////////////////////////////////////////////
// �������
// 
// 

///////////////////////////////////////////////////////////
#include <iostream>
#include "save.h"
#include <memory>
#include <cstring>
#include <string>
#include "Mystring.h"
using namespace std;
extern bool ����;

class String
{

public:
	/*String(const shared_ptr<String> other);*/



	String();

	~String();
	
	String(const char* s);

	//���������
	String(const String& other);
	//�����Ҵ翬����
	String& operator=(const String& rhs);

	//2024.4.4 �̵������� // �̵��Ҵ翬����
	// 2024 4.16 noexcept 
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;
	//2024 4.18 
	bool operator==(const String& other) const;

	size_t GetLen() const { return len; }
	char* GetPtr() const { return p.get(); }


	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& other);



private:
	size_t len{};
	std::unique_ptr<char[]> p{};
	static size_t uid;
	size_t id{};


};
