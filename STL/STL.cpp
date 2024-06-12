////////////////////////////////////////////////////////////////////////////////////////////////////
//     
// 14주 1일쨰
// 
// 
// STL Alogrithm  => non modifying   / modifying   /  sort and realated 
// non modifying: copy(src,dest) :
//
//
// distacne 구현
// tag dispatching
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <ranges>
#include <array>
#include "Mystring.h"
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <thread>
#include <forward_list>

using namespace std;




int main()
{	

	list<int> li{ 1,2,3 };

	/*sort(li.begin(), li.end());*/

	ranges::sort(li.begin(), li.end());


	li.sort();

	//save("STL.cpp");
}