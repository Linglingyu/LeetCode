#include<list>
#include<memory>
#include<vector>
#include<string>

using namespace std;

template <typename T> class Blob
{
public:
	typedef T valueType;
	typedef typename std::vector<T>::size_type size_type;
	//构造函数
	Blob();
	Blob(std::initializer_list<T> il);
	//blob中元素的数目
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//添加和删除元素
	void push_back(const T &t){ data->push_back(t); }
	//移动版本
	void push_back(T &t){ data->push_back(std::move(t)); }
	void pop_back();
	//元素访问
	T& back();
	T& operator[](size_type i);

private:
	std::shared_ptr<std::vector<T>> data;
	//若data[i]无效，抛出msg
	void check(size_type i, const std::string &msg) const;
};


template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T> T Blob<T>::back(){
	check(0, "back on empty Blob.");
	return data->back();
}

template <typename T> T& Blob<T>::operator[](size_type i){
	//如果i太大，check会抛出异常，阻止访问一个不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T> T Blob<T>::pop_back(){
	check(0, "pop_back on empty Blob.");
	data->pop_back();
}

template <typename T> Blob<T>::Blob() :data(std::make_shared<std::vector<T>>()){}

template <typename T> Blob<T>::Blob(std::initializer_list<T> il) : 
						data(std::make_shared<std::vector<T>>(il)){}

void main(){
	Blob<int> ia;
	Blob<int> ia2 = { 0, 1, 2, 3, 4 };
	Blob<string> articles = { "a", "an", "the" };
	Blob<int> squares = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (size_t i = 0; i != squares.size(); i++){
		squares[i] = i*i;
	}
}