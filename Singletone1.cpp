#include <iostream>
#include <vector>

class Singletone
{
public:
	static Singletone& get_data()
	{
		static Singletone data;
		return data;
	}


	void function()
	{
		std::cout << "Our singletone " << std::endl;
		for (auto& num : vec)
		{
			std::cout << num << ' ';
		}
		std::cout << std::endl;
	}
private:
	Singletone()
	{
		std::cout << "Call constructor " << std::endl;
	}
	Singletone(const Singletone& obj) = delete;
	Singletone& operator =(const Singletone& obj) = delete;
	~Singletone()
	{
		std::cout << "Call destructor " << std::endl;
	}
	std::vector<int>vec = { 1,2,3,4,5,6 };



};

int main(int argc, char** argv)
{
	Singletone& data1 = Singletone::get_data();

	data1.function();

	Singletone& data2 = Singletone::get_data();
	data2.function();

	Singletone& data3 = Singletone::get_data();

	data3.function();

	return 0;
}