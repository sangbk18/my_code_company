#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

class sinhvien
{
private:
	const char* name;
	int age;
	long student_card;
public:
	static long count;
	sinhvien()
	{
		this->name = "";
		this->age = 0;
		this->student_card = count;
		count++;
	}
	sinhvien(const char* name, int age)
	{
		this->name = name;
		this->age = age;
		this->student_card = count;
		count++;
	}
	void Set_name(const char* name)
	{
		this->name = name;
	}
	const char* Get_name(void)
	{
		return this->name;
	}
	void Set_age(int age)
	{
		this->age = age;
	}
	int Get_age(void)
	{
		return this->age;
	}
	void Set_student_card(long mssv)
	{
		this->student_card = mssv;
	}
	long Get_student_card(void)
	{
		return this->student_card;
	}
	void show_infor(void)
	{
		std::cout << "Your student card is : " << this->student_card << std::endl;
		std::cout << "Your name is : " << this->Get_name() << std::endl;
		std::cout << "Your age is : " << this->Get_age() << std::endl;
	}
};
long sinhvien::count = 100;
bool compare(sinhvien* sv1, sinhvien* sv2)
{
	return (sv1->Get_age() > sv2->Get_age());
}
int main(void)
{
	sinhvien* sv = new sinhvien[5];
	((sinhvien*)(sv + 0))->Set_name("Thai Van Sang");
	((sinhvien*)(sv + 1))->Set_name("Nguyen Duc Anh");
	((sinhvien*)(sv + 2))->Set_name("Chu Quoc Khanh");
	((sinhvien*)(sv + 3))->Set_name("Nguyen Duc Sy");
	((sinhvien*)(sv + 4))->Set_name("Nguyen Hoang Sy");
	((sinhvien*)(sv + 0))->Set_age(23);
	((sinhvien*)(sv + 1))->Set_age(21);
	((sinhvien*)(sv + 2))->Set_age(21);
	((sinhvien*)(sv + 3))->Set_age(19);
	((sinhvien*)(sv + 4))->Set_age(28);
	std::vector<sinhvien*> my_vector = { sv + 0,sv + 1,sv + 2,sv + 3 };
	std::vector<sinhvien*>::iterator it = my_vector.begin();
	std::cout << sinhvien::count << std::endl;
	//std::sort(my_vector.begin(), my_vector.end(), compare);
	my_vector.insert(it + 0, sv + 4);
	for (it = my_vector.begin();it != my_vector.end(); it++)
	{
		((sinhvien*)(*it))->show_infor();
    }
	//std::multimap<int, sinhvien*> my_map;
	//my_map.insert(std::pair<int, sinhvien*>(102, sv + 0));
	//my_map.insert(std::pair<int, sinhvien*>(102, sv + 1));
	//my_map.insert(std::pair<int, sinhvien*>(101, sv + 2));
	//std::multimap<int, sinhvien*>::iterator it = my_map.begin() ;
	//my_map.insert(std::pair<int, sinhvien*>(103, sv + 3));
	//for (it = my_map.begin(); it != my_map.end(); it++)
	//{
	//	std::cout << it->first << std::endl;
	//	((sinhvien*)(it->second))->show_infor();
	//}
	delete[] sv;
	return 0;
}