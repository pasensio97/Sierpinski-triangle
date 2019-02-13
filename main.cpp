/*
	Author: Pablo Asensio Martínez
	GitHub: https://github.com/pasensio97
*/
#include <iostream>
#include <list>
#include <cmath>

class Pascal_pyramid
{
public:
	Pascal_pyramid(){
		std::cout << "Set, between 1 to max int, rows' number of Pascal Pyramid" << '\n';
		std::cin >> number_rows_;
		if (number_rows_ < 1) {
			std::cerr << "Incorrect number. Rows' number setted to 1." << '\n'; // try catch sould be better;
			number_rows_ = 1;
		}
		make_pyramid();
	}

	void set_number_rows(int rows) {number_rows_ = rows;}
	int get_number_rows() const {return number_rows_;}

	void make_pyramid() {
		for (int i = 1; i <= number_rows_; i++) {
			if (i == 1){
				std::list<int> l{1};
				block_.push_back(l);
			}else if (i == 2){
				std::list<int> l{1,1};
				block_.push_back(l);
			}else{
				std::list<std::list<int>>::iterator itr;

				for(){
					;
				}
			}
		}
	}

	void display(){
		std::list<std::list<int>>::iterator itr;
		for (itr=block_.begin(); itr != block_.end(); itr++)
		{
		   std::list<int>tl =* itr;
		   std::list<int>::iterator it;
		   for (it = tl.begin(); it != tl.end(); it++)
		   {
		       std::cout << *it << " ";
		   }
		   std::cout << '\n';
	   	}
	}

private:
	int number_rows_;
	std::list<std::list<int>> block_; //contains all rows with their numbers
};

int main(int argc, char const *argv[]) {

	Pascal_pyramid pyramid;
	pyramid.display();

	return 0;
}
