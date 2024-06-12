#pragma once
///////////////////////////////////////////////////////////
// �������
// 
// 
// 4.16 �̵��ҋ� ���ܰ� �߻����������� ���� noexcept
// 4.30 llst �� merge �� �ʿ��� operator<
// 5.7 begin �� end �� �ڵ�
// 5.7 String_reverse_iterator Ŭ���� �ڵ�
// 5.7 begin , end �� return ���� string_iteator �� �ǵ��� �ڵ�.
// 5.9 sort �� ���� ���� ����ǵ��� ������ �����ε� �Ͽ���.
///////////////////////////////////////////////////////////
#include <iostream>
#include "save.h"
#include <memory>
#include <cstring>
#include <string>
#include "Mystring.h"
using namespace std;
extern bool ����;

//�ݺ��� �����
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
		//2024 5.9 sort �ǵ��� �䱸�ϴ� ������߰�

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

	//2024.4.30
	bool operator<(const String& other) const;

	size_t GetLen() const { return len; }
	char* GetPtr() const { return p.get(); }

	//2024 .5 .7 [ ���ø� ���� �� ����ϱ����� ����ٰ� ���Ƽ� �ڵ�]
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
