#include "Mystring.h"
#include <algorithm>
///////////////////////////////////////////////////////////
// cpp 파일 2024 .4.4 STL 동작 을 관찰하기위함
// 2024 . 4 .4  관찰 메세지 
// 2024 . 4 .16  noexcept
///////////////////////////////////////////////////////////


size_t String::uid{};
extern bool 관찰{ false };

String::String():id(++uid)
{
	if (관찰)
	{
		cout << "[" << id << "] - 디폴트 생성,갯수:" << len;
		cout << "주소 :" << static_cast<void*>(p.get()) << endl;
	}
}

String::~String()
{
	if (관찰)
	{
		cout << "[" << id << "] - 소멸자 호출,갯수:" << len;
		cout << "주소 :" << static_cast<void*>(p.get()) << endl;
	}
}

String::String(const char* s):id(++uid)
{
	len = strlen(s);
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);


	if (관찰)
	{
		cout << "[" << id << "] -생성자 생성(const char*),갯수:" << len;
		cout << "주소 :" << static_cast<void*>(p.get()) << endl;
	}
}

String::String(const String& other):id(++uid)
{
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);


	if (관찰)
	{
		cout << "[" << id << "] - 복사생성자 생성(const String& other),갯수:" << len;
		cout << "주소 :" << static_cast<void*>(p.get()) << endl;
	}
}





String& String::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;

	len = rhs.len;
	p.release();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), rhs.p.get(), len);
	if (관찰)
	{
		cout << "[" << id << "] - 복사 할당 생성,갯수:" << len;
		cout << "주소 :" << static_cast<void*>(p.get()) << endl;
	}

	return *this;
}

String::String(String&& other) noexcept
	:len(other.len),id(++uid)
{
	p.reset(other.p.get());
	other.p.release();
	other.len = 0;

	if (관찰)
	{
		cout << "[" << id << "] - 이동 생성,갯수:" << len;
		cout << "주소 :" << static_cast<void*>(p.get()) << endl;
	}
}

String& String::operator=(String&& other) noexcept
{
	if (this == &other)
		return *this;

	len = other.len;
	p.reset(other.p.release());
	other.len = 0;

	if (관찰)
	{
		cout << "[" << id << "] - 이동할당연산자 생성,갯수:" << len;
		cout << "주소 :" << static_cast<void*>(p.get()) << endl;
	}

	return *this;

}

bool String::operator==(const String& other) const
{
	if (len != other.len)
		return false;

	return std::equal(p.get(), p.get() + len, other.p.get());

}

bool String::operator<(const String& other) const
{
	return std::lexicographical_compare(p.get(), p.get() + len,
		other.p.get(), other.p.get() + other.len);
}


//입출력함수 오버로딩
std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (size_t i = 0; i < s.len; ++i)
	{
		os << s.p.get()[i];
	}

	return os;
}

std::istream& operator>>(istream& is, String& other)
{

	std::string str;
	is >> str;

	other.len = str.size();
	other.p = make_unique<char[]>(other.len);
	memcpy(other.p.get(), str.data(), other.len);

	return is;

}