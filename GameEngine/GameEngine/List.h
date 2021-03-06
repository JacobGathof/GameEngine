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
		auto index = std::find(data.begin(), data.end(), t);
		if (index == data.end())
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

	void swap(int a, int b) {
		T temp = data[a];
		data[a] = data[b];
		data[b] = temp;
	}

	void insert(typename std::vector<T>::iterator a, typename std::vector<T>::iterator b) {
		data.insert(data.end(), a, b);
	}

	List<T> subList(int a, int b) {
		List<T> li;
		li.insert(data.begin()+a, data.begin()+b);
		return li;
	}

	List<T> subList(int a) {
		List<T> li;
		li.insert(data.begin() + a, data.end());
		return li;
	}

	/*
	T concat() {
		T ret;
		for (int i = 0; i < data.size(); i++) {
			ret += data[i];
		}
		return ret;
	}
	*/

private:
	std::vector<T> data;
};

