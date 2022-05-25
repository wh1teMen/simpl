#include<iostream>
#include<string.h>
using namespace std;
class String{
public:
	String()
		:data(nullptr),
		size(0),
		capacity(0)
	{
		/*data = nullptr;
		size = 0;
		capacity = 0;*/
		cout<<this<< " Base object created\n";
	};
	String(std::string str) :String() {
		size = str.size();
		capacity = size;
		data = new char[size]{};
		for (int i = 0; i < size; i++) {
			data[i]=str[i];
		}
	}
	bool operator== (const String &&other) {
		if (this->size != other.size) return false;
		if (this->size == other.size) {
			for (int i = 0; i < this->size; i++) {
				if (this->data[i] != other.data[i]) return false;
			}
			 return true;
			
		}
	}
	bool operator!= (const String &&other) {
		if (this->size == other.size) return false;
		if (this->size == other.size) {
			for (int i = 0; i < this->size; i++) {
				if (this->data[i] == other.data[i]) return false;
			}
			return true;
		}
	}
	

	friend String operator+=(String a, String b) {
		String result(a.size + b.size);
		::memcpy(result.data, a.data, a.size);
		::memcpy(result.data + a.size, b.data, b.size);
		result.size = a.size + b.size;
		return result;
	}



	//	if ( capcity= other.size) {
	//		for (int i = 0; i < size; i++) {
	//			data[i] = '\0';
	//		}
	//	}
	//	else
	//	{
	//		if (data) {
	//			delete[]data;
	//		}
	//		data=new char[other.size + 1];
	//		capacity = other.size + 1;
	//	}
	//	size = other.size;
	//	::memcpy(data, other.data, size);
	//	//процесс копирования
	//	return *this;


	
	
	explicit String(int lenght) :String() {
		capacity = lenght;
		data = new char[lenght] {};// {} - чтобы заполниь нулями
		//size = 0;
	}
	String(const char *str) {
		size=::strlen(str)+1;
		capacity = size;
		data = new char[size] {};
		::memcpy(data, str, size);
	}
	
	//конструктор копирования
	String(const String &other) {
		size = other.size;
		capacity = other.capacity;
		data = new char[other.size]{};
		::memcpy(data, other.data, size);
		cout << this;
		cout << this << " Base object created by copy\n";
	}
	String(String && other):String() {
		swap(data, other.data);
		size = other.size;
		other.size = 0;
		swap(capacity, other.capacity);
	}

	~String() {
		if (data) {
			delete[]data;
		}
		cout << this << " Base object destroyed\n";
	};

	const String &operator = (const String & other){
		if (capacity >= other.size) {
			for (int i = 0; i < size; i++) {
				data[i] = '\0';
			}
		}
		else
		{
			if (data) {
				delete[]data;
			}
			data=new char[other.size + 1];
			capacity = other.size + 1;
		}
		size = other.size;
		::memcpy(data, other.data, size);
		//процесс копирования
		return *this;


	}
	
	void setString(const char *str) {
		(*this) = String(str);
	}
	friend String operator+(String a, String b);



	

private:
	char *data;
	int size;
	int capacity;
};
void Foo(String obj) {

}

String operator+(String a, String b) {
	String result(a.size + b.size);
	::memcpy(result.data, a.data, a.size);
	::memcpy(result.data + a.size, b.data, b.size);
	result.size = a.size + b.size;
	return result;
}
String operator+=(String a, String b) {
	String result(a.size + b.size);
	::memcpy(result.data, a.data, a.size);
	::memcpy(result.data + a.size, b.data, b.size);
	result.size = a.size + b.size;
	return result;
}

 


int main() {
	setlocale(LC_ALL, "ru");
	String a;
	String b(5);
	//Base();//анонимный объект
	String *point = new String;
	Foo(static_cast<String>(8));
	delete point;
	double r = (1 / double(6));
	double e;
	e = r = 5.6;

	system("pause>null");
	return 0;
}
 