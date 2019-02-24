/*
	Author: Pablo Asensio Martínez
	GitHub: https://github.com/pasensio97
*/
#include <iostream>
#include <vector>
#include <cmath>

class Pascal_pyramid
{
public:
	Pascal_pyramid(){
		std::cout << "Set, between 1 to max unsigned int, rows' number of Pascal Pyramid" << '\n';
		std::cin >> number_rows_;
		if (number_rows_ < 1) {
			std::cerr << "Incorrect number. Rows' number setted to 1." << '\n'; // try catch should be better;
			number_rows_ = 1;
		}
		make_pyramid();
	}

	void set_number_rows(unsigned int rows) {number_rows_ = rows;}
	unsigned int get_number_rows() const {return number_rows_;}

	void make_pyramid() {
		std::vector<std::vector<unsigned int>>::iterator itr_row;
		itr_row = block_.begin(); // first row
		std::cerr << itr_row.front << '\n';

		for (unsigned int i = 1; i <= number_rows_; i++) {
			if (i == 1){
				std::vector<unsigned int> l{1};
				block_.push_back(l);
			}else if (i == 2){
				std::vector<unsigned int> l{1,1};
				block_.push_back(l);
			}else{


				/*for(){
					;
				}*/
			}
		}
	}

	void display(){
		std::vector<std::vector<unsigned int>>::iterator itr;
		for (itr = block_.begin(); itr != block_.end(); itr++)
		{
		   std::vector<unsigned int> tl = *itr;
		   std::vector<unsigned int>::iterator it;
		   for (it = tl.begin(); it != tl.end(); it++)
		       std::cout << *it << " ";
		   std::cout << '\n';
	   	}
	}

private:
	unsigned int number_rows_;
	std::vector<std::vector<unsigned int>> block_; //contains all rows with their numbers
};

int main(unsigned int argc, char const *argv[]) {

	Pascal_pyramid pyramid;
	pyramid.display();

	return 0;
}
