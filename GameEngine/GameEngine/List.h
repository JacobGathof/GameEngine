#pragma once
#include <vector>
#include <iostream>

template<class T>
class List
{
public:
	List(){}
	~List(){}

	List(std::initializer_list<T> values) {
		data.insert(data.end(), values.begin(), values.end());
	}

	void add(T t){
		data.push_back(t);
	}

	void add(T t, int i){
		data.emplace(data.begin() + i, t);
	}

	void addAll(std::initializer_list<T> values) {
		data.insert(data.end(), values.begin(), values.end());
	}

	void addAll(List<T> &l) {
		data.insert(data.end(), l.begin(), l.end());
	}

	void clear() {
		data.clear();
	}

	bool removeIndex(int i){
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

	T& get(int i) {
		return data[i];
	}

	typename std::vector<T>::iterator begin() {
		return data.begin();
	}

	typename std::vector<T>::iterator end() {
		return data.end();
	}
	
	friend std::ostream& operator<<(std::ostream &os, List<T> &l) {
		os << "[";
		int i = 0;
		for (i = 0; i < l.size() - 1; i++) {
			os << l[i] << ",";
		}
		if (i != 0) os << l[i];
		os << "]";
		return os;
	}

	T& operator[](int i) {
		return data[i];
	}

	List<T> operator+(List<T> & l) {
		List<T> ret;
		ret.addAll(*this);
		ret.addAll(l);
		return ret;
	}

	List<T>& operator+=(List<T> & l) {
		addAll(l);
		return *this;
	}

	List<T> operator+(std::initializer_list<T> l) {
		List<T> ret;
		ret.addAll(*this);
		ret.addAll(l);
		return ret;
	}

	List<T>& operator+=(std::initializer_list<T> l) {
		addAll(l);
		return *this;
	}


private:
	std::vector<T> data;
};

