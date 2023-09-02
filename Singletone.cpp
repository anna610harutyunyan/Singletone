#include <iostream>

class Singletone
{
public:
	static Singletone& get_data()
	{
		static Singletone a;
		return *data;
	}
	static void set_data(Singletone& newData)
	{
		data = &newData;
	}

	void function()
	{
		std::cout << "Our singletone " << std::endl;
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
	static Singletone* data;



};
Singletone*  Singletone::data=nullptr;

int main(int argc, char** argv)
{
	Singletone& data1=Singletone::get_data();

	Singletone::set_data(data1);
	data1.function();

	Singletone& data2 = Singletone::get_data();
	data2.function();



	return 0;
}