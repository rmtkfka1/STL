#pragma once
///////////////////////////////////////////////////////////
// 헤더파일
// 
// 
// 4.16 이동할떄 에외가 발생하지않음을 보장 noexcept
// 4.30 llst 의 merge 에 필요한 operator<
// 5.7 begin 과 end 를 코딩
// 5.7 String_reverse_iterator 클래스 코딩
// 5.7 begin , end 의 return 값을 string_iteator 가 되도록 코딩.
// 5.9 sort 가 문제 없이 실행되도록 연산자 오버로딩 하였다.
///////////////////////////////////////////////////////////
#include <iostream>
#include "save.h"
#include <memory>
#include <cstring>
#include <string>
#include "Mystring.h"
using namespace std;
extern bool 관찰;

//반복자 어댑터
class String_reverse_iterator
{
public:
	using difference_type = int;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;
	using iterator_concept = contiguous_iterator_tag;

	String_reverse_iterator(char* p) :p(p) {};

	char operator*() {
		return *(p - 1);
	};
	char* operator++() {
		return --p;
	};

	bool operator==(String_reverse_iterator & other) {
		return this->p == other.p;
	}

private:
	char* p;

};

class String_iterator
{
public:
	/*difference_type*/   /* using difference_type = int;*/
	/*value_type          /* using value_type = char 
	pointer              /   using pointer =char*
	reference            /   using reference =char&;
	iterator_category*/ //   using iterator_category = random_access_iterator;

	using difference_type = long long; 
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = random_access_iterator_tag;
	using iterator_concept = contiguous_iterator_tag;


private:


public:

	String_iterator(char* p) :p(p) {};


	reference operator*() const{
		return *(p);
	};


	char* operator++() {
		return ++p;
	};

	bool operator==(const String_iterator& other) const{
		return this->p == other.p;
	}
		//2024 5.9 sort 되도록 요구하는 연산들추가

	difference_type operator-(const String_iterator& rhs) const {
		return p - rhs.p;
	}

	String_iterator& operator--() {
		--p;
		return *this;
	}

	bool operator<(const String_iterator& other) const{
		return p < other.p;
	}

	String_iterator operator+(const difference_type diff) const{
		return String_iterator(p + diff);
	}

	String_iterator operator-(const difference_type diff) const {
		return String_iterator(p - diff);
	}






private:
	char* p;

};
 



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

	//2024.4.30
	bool operator<(const String& other) const;

	size_t GetLen() const { return len; }
	char* GetPtr() const { return p.get(); }

	//2024 .5 .7 [ 템플릿 정신 을 계승하기위해 여기다가 몰아서 코딩]
	String_iterator  begin() const{
		return  String_iterator{ p.get() };
	};
	String_iterator  end() const {
		return String_iterator{ p.get() + len };
	};

	String_reverse_iterator rbegin() const{
		return String_reverse_iterator{ p.get() + (len) };
	}

	String_reverse_iterator rend() const {
		return String_reverse_iterator{ p.get() };
	}

	
	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& other);



private:
	size_t len{};
	std::unique_ptr<char[]> p{};
	static size_t uid;
	size_t id{};


};
