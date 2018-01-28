#pragma once
#include <vector>
#include <iostream>

template<class T>
class List
{
public:
	List(){}
	~List(){}

	void add(T t){
		data.push_back(t);
	}

	void add(T t, int i){
		data.emplace(data.begin() + i, t);
	}

	bool remove(int i){
		data.erase(data.begin() + i);
		return true;
	}

	bool remove(T t){
		int index = std::find(data.begin(), data.end(), t);
		if (index < data.begin() || index > data.end())
			return false;
		data.erase(index);
		return true;
	}

	int size(){
		return data.size();
	}

	T get(int i) {
		return data[i];
	}

	T operator[](int i) {
		return data[i];
	}

	typename std::vector<T>::iterator begin() {
		return std::vector<T>::iterator();
	}

	typename std::vector<T>::iterator end() {
		return std::vector<T>::iterator();
	}
	
	friend std::ostream& operator<<(std::ostream &os, List<T> &l) {
		os << "[";
		int i = 0;
		for (i = 0; i < l.size() - 1; i++) {
			os << l[i] << ",";
		}
		os << l[i] << "]";
		return os;
	}


private:
	std::vector<T> data;
};

