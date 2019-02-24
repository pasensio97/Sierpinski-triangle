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
		std::list<std::list<unsigned int>>::iterator itr_row;
		for (unsigned int i = 1; i <= number_rows_; i++) {
			if (i == 1){
				std::list<unsigned int> new_row{1};
				block_.push_back(new_row);
			}else if (i == 2){
				std::list<unsigned int> new_row{1,1};
				block_.push_back(new_row);
			}else{
				itr_row = block_.end();
				--itr_row; // itr at last info row

				std::list<unsigned int> new_row;
				std::list<unsigned int> last_row = *itr_row;
				std::list<unsigned int>::iterator it1;
				std::list<unsigned int>::iterator it2;

				it1 = last_row.begin();
				it2 = last_row.begin();
				++it2; // it2 at second row's position

				while (it2 != last_row.end()) {
					unsigned int new_value;
					new_value = *it1 + *it2;
					new_row.push_back(new_value);
					it1++;
					it2++;
				}

				new_row.push_front(1);
				new_row.push_back(1);

				block_.push_back(new_row);

			}
		}
	}

	void display(){
		std::list<std::list<unsigned int>>::iterator itr;
		for (itr = block_.begin(); itr != block_.end(); itr++)
		{
		   std::list<unsigned int> tl = *itr;
		   std::list<unsigned int>::iterator it;
		   for (it = tl.begin(); it != tl.end(); it++)
		       std::cout << *it << " ";
		   std::cout << '\n';
	   	}
	}

private:
	unsigned int number_rows_;
	std::list<std::list<unsigned int>> block_; //contains all rows with their numbers
};

int main(unsigned int argc, char const *argv[]) {

	Pascal_pyramid pyramid;
	pyramid.display();

	return 0;
}
