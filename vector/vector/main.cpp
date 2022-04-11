#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stdint.h>
//template<class T>
//struct my_data
//{
//	T data1;
//	T data2;
//};
//my_data<uint8_t> data_1[3] = { {0x11,0x22},{0x33,0x44},{0x55,0x66} };
//my_data<uint16_t> data_2[2] = { {0x7788,0x99AA},{0xBBCC,0xDDEE} };
class people
{
protected:
	const char* name;
	int age;
public:
	people()
	{
		this->name = "";
		this->age = 0U;
	}
	people(const char* name, int age)
	{
		this->name = name;
		this->age = age;
	}
	const char* get_name(void)
	{
		return this->name;
	}
	void set_name(const char* name)
	{
		this->name = name;
	}
	int get_age(void)
	{
		return this->age;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	virtual void show_infor(void);
};
void people::show_infor(void)
{
	std::cout << "my name is :" << this->name << std::endl;
	std::cout << "my age is :" << this->age << std::endl;
}
people operator + (people p1, people p2)
{
	people tmp;
	tmp.set_name(p2.get_name());
	tmp.set_age(p1.get_age() + p2.get_age());
	return tmp;
}
class sinhvien : public people
{
private:
	long student_card;
public:
	static int count;
	sinhvien() : people()
	{
		count++;
		this->student_card = 0;
	}
	sinhvien(const char* name, int age, long student_card) :people(name, age)
	{
		count++;
		this->name = name;
		this->age = age;
		this->student_card = student_card;
	}
	long get_student_card(void)
	{
		return this->student_card;
	}
	void set_student_card(long student_card)
	{
		this->student_card = student_card;
	}
	void show_infor(void);
};
void sinhvien::show_infor()
{
	std::cout << "my name is :" << this->name << std::endl;
	std::cout << "my age is :" << this->age << std::endl;
	std::cout << "my student card is :" << this->student_card << std::endl;
}
int sinhvien::count = 0;
#pragma pack(1)
template<class T1, class T2>
struct pair
{
	T1 first;
	T2 second;
};
#pragma pack()
int str_len(const char* s)
{
	static int dem = 0;
	while (*s != '\0')
	{
		s++;
		dem++;
	}
	return dem;
}
#define max_size 100
struct my_string
{
	int size_chain;
	char** str;
};
my_string* my_split(const char* s, const char c)
{
	int lenth_chain = str_len(s);
	static my_string* my_string_cop = new my_string();
	static char str[max_size] = "";
	for (int dem = 0; dem < lenth_chain; dem++)
	{
		*(str + dem) = *(s + dem);
	}
	*(str + lenth_chain) = '\0';
	int count_char = 0U;
	for (int dem = 0; dem < lenth_chain; dem++)
	{
		if (*(s + dem) == c)
		{
			count_char++;
		}
	}
	my_string_cop->size_chain = count_char;
	++count_char;
	static char** chain = new char* [count_char];
	--count_char;
	for (int dem = lenth_chain; dem >= 0; dem--)
	{
		if (c == *(str + dem))
		{
			*(chain + count_char) = str + dem + 1;
			--count_char;
			*(str + dem) = '\0';
		}
		if (count_char == 0)
		{
			break;
		}
	}
	*(chain + 0) = str + 0;
	my_string_cop->str = chain;
	return my_string_cop;
}
void swap(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
	int a = *it1;
	*it1 = *it2;
	*it2 = a;
}
int get_dev(std::vector<int>* my_vector, int low,int high)
{
	int pivot = *(my_vector->begin() + low);
	int left_index = low;
	int right_index = high;
	std::vector<int>::iterator left = my_vector->begin() + left_index;
	std::vector<int>::iterator right = my_vector->begin() + right_index;
	while (true)
	{
		while (left_index < right_index && *right > pivot)
		{
			right_index--;
			right = my_vector->begin() + right_index;
		}
		if (left_index == right_index) break;
		swap(left, right);
		left_index++;
		left = my_vector->begin() + left_index;
		while (left_index < right_index && *left < pivot)
		{
			left_index++;
			left = my_vector->begin() + left_index;
		}
		if (left_index == right_index) break;
		swap(left, right);
		right_index--;
		right = my_vector->begin() + right_index;
	}
	return left_index;
}
void quick_sort(std::vector<int>* my_vector, int low, int high)
{
	if (low < high)
	{
		int p = get_dev(my_vector, low, high);
		quick_sort(my_vector, low, p - 1);
		quick_sort(my_vector, p + 1,high);
	}
}
bool compare(sinhvien sv1, sinhvien sv2)
{
	return (sv1.get_age() > sv2.get_age());
}
int main()
{
	//std::vector<int> my_vector = { 18,7,5,3,2,9,2,16,10};
	//std::vector<int>::iterator it = my_vector.begin() + 2;
	//quick_sort(&my_vector, 0, my_vector.size() - 1);
	//for (it = my_vector.begin(); it != my_vector.end(); it++)
	//{
	//	std::cout << *it << " ";
	//}
	//std::cout << my_split("[thai[van[sang", '[')->str[2] << std::endl;
	//delete[] &my_split("[thai[van[sang", '[')->str[0];
	sinhvien* sv = new sinhvien[3];
	((sinhvien*)(sv + 0))->set_name("thai van sang1");
	((sinhvien*)(sv + 1))->set_name("thai van sang2");
	((sinhvien*)(sv + 2))->set_name("thai van sang3");
	((sinhvien*)(sv + 0))->set_age(22);
	((sinhvien*)(sv + 1))->set_age(28);
	((sinhvien*)(sv + 2))->set_age(24);
	((sinhvien*)(sv + 0))->set_student_card(100);
	((sinhvien*)(sv + 1))->set_student_card(101);
	((sinhvien*)(sv + 2))->set_student_card(102);
	
	std::map<const char*, sinhvien*> my_map_student;
	my_map_student["101180262"] = (sinhvien*)&sv[0];
	my_map_student.insert(std::pair<const char*,sinhvien*>("101180288", &sv[1]));
	my_map_student.insert(std::pair<const char*, sinhvien*>("101180888", &sv[2]));
	std::map<const char*, sinhvien*>::iterator it = my_map_student.begin();
	//std::sort(my_map_student.begin(), my_map_student.end(), compare);
	std::cout << ((sinhvien*)(it->second))->get_name() << std::endl;
	//std::cout << ((sinhvien*)(it->second))->get_age() << std::endl;
	//std::cout << ((sinhvien*)(it->second))->get_student_card() << std::endl;
    delete[] sv;
	//pair<pair<int, double>, double> my_pair= { {12,6.5},8.6 };
	//std::cout << *(double*)((int*)((pair<int, double>*)((pair<pair<int, double>, double>*) & my_pair) + 0) + 1);
	//people* p1 = new people("sang", 22);
	//people p2("sang2", 33);
	//people p3 = *p1 + p2;
	//std::cout << p3.get_age() << std::endl;
	//sinhvien* sv = new sinhvien[3];
	//((sinhvien*)(sv + 0))->set_name("thai van sang1");
	//((sinhvien*)(sv + 1))->set_name("thai van sang2");
	//((sinhvien*)(sv + 2))->set_name("thai van sang3");
	//((sinhvien*)(sv + 0))->set_age(20);
	//((sinhvien*)(sv + 1))->set_age(21);
	//((sinhvien*)(sv + 2))->set_age(22);
	//((sinhvien*)(sv + 0))->set_student_card(100);
	//((sinhvien*)(sv + 1))->set_student_card(101);
	//((sinhvien*)(sv + 2))->set_student_card(102);
	//std::map<const char*, sinhvien*> my_map;
	//my_map["ID_01"] = sv + 0;
	//my_map["ID_02"] = sv + 1;
	//my_map.insert(std::pair<const char*, sinhvien*>("ID_03", sv + 2));
	//std::map<const char*, sinhvien*>::iterator it = my_map.begin();
	//std::cout << it->first << std::endl;
	//std::cout << ((sinhvien*)(it->second))->get_name() << std::endl;
	//std::cout << ((sinhvien*)(it->second))->get_age() << std::endl;
	//std::cout << ((sinhvien*)(it->second))->get_student_card() << std::endl;
	//std::cout << sinhvien::count << std::endl;
	////std::map<const char, sinhvien*> my_vector;

	//delete[] sv;

	//std::map<const char, my_data<uint8_t>*> my_map;
	//my_map['1'] = &data_1[0];
	//my_map.insert(std::pair<const char, my_data<uint8_t>*>('2',&data_1[1]));
	//my_map.insert(std::pair<const char, my_data<uint8_t>*>('3', &data_1[2]));
	//std::map<const char, my_data<uint8_t>*>::iterator it = my_map.begin();
	//it++;
	//std::cout << it->first<< std::endl;
	//printf("%x\n", *((uint8_t*)((my_data<uint8_t>*)(it->second)) + 1));
	//uint8_t a = 0x11;
	//std::vector<my_data<uint8_t>*> my_vector = { &data_1[0],&data_1[1],&data_1[2] };
	//std::vector<my_data<uint8_t>*>::iterator it = my_vector.begin();
	//printf("convert hex :%x\n", *((uint8_t*)((my_data<uint8_t>*)(*(it + 1)) + 0)));
	//std::cout << c << std::endl;
	system("pause");
	return 0;
}