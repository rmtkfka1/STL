#pragma once
///////////////////////////////////////////////////////////
// 헤더파일
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
extern bool 관찰;

class String
{

public:
	/*String(const shared_ptr<String> other);*/



	String();

	~String();
	
	String(const char* s);

	//복사생성자
	String(const String& other);
	//복사할당연산자
	String& operator=(const String& rhs);

	//2024.4.4 이동생성자 // 이동할당연산자
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
