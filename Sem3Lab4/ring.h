#pragma once

#include <iostream>
#include <string>
#include "ring_node.h"

using namespace std;

template <typename T>
class Ring
{
private:
	RingNode<T>* head;
	RingNode<T>* tail;
	int size;

public:
	Ring();
	~Ring();

	// Геттеры
	RingNode<T>* get_head() const;
	RingNode<T>* get_tail() const;
	int get_size() const;

	// Сеттеры
	void set_head(RingNode<T>* new_head);
	void set_tail(RingNode<T>* new_tail);
	void set_size(int new_size);
	
	// Добавить элемент
	void add_element(T value); // или void add_front(T value);
	// void add_rear(T value);

	// Удалить элемент
	void delete_element(); // или void delete_front();
	// void delete_rear();

	// Поиск по полям
	RingNode<T>* find_by_surname(string surname) const;
	RingNode<T>* find_by_year(int year) const;

	void print() const;
};

template <typename T>
Ring<T>::Ring() :
	head(nullptr), tail(nullptr), size(0)
{}

template <typename T>
Ring<T>::~Ring()
{
	while (head != nullptr)
		this->delete_element();
}

template <typename T>
RingNode<T>* Ring<T>::get_head() const
{
	return this->head;
}

template <typename T>
RingNode<T>* Ring<T>::get_tail() const
{
	return this->tail;
}

template <typename T>
int Ring<T>::get_size() const
{
	return this->size;
}

template <typename T>
void Ring<T>::set_head(RingNode<T>* new_head)
{
	this->head = new_head;
}

template <typename T>
void Ring<T>::set_tail(RingNode<T>* new_tail)
{
	this->tail = new_tail;
}

template <typename T>
void Ring<T>::set_size(int new_size)
{
	this->size = new_size;
}

template <typename T>
void Ring<T>::add_element(T value)
{
	RingNode<T>* new_node = new RingNode<T>(value);

	if (head == nullptr)
	{
		new_node->set_next(new_node);
		new_node->set_prev(new_node);

		this->set_head(new_node);
		this->set_tail(new_node);
	}
	else
	{
		new_node->set_next(this->get_head());
		new_node->set_prev(this->get_tail());

		this->get_head()->set_prev(new_node);
		this->get_tail()->set_next(new_node);

		this->set_head(new_node);
	}

	this->set_size(this->get_size() + 1);
}

//template <typename T>
//void Ring<T>::add_rear(T value)
//{
//	RingNode<T>* new_node = new RingNode<T>(value);
//
//	if (head == nullptr)
//	{
//		new_node->set_next(new_node);
//		new_node->set_prev(new_node);
//
//		this->set_head(new_node);
//		this->set_tail(new_node);
//	}
//	else
//	{
//		new_node->set_next(this->get_head());
//		new_node->set_prev(this->get_tail());
//
//		this->get_head()->set_prev(new_node);
//		this->get_tail()->set_next(new_node);
//
//		this->set_tail(new_node);
//	}
// 
//  this->set_size(this->get_size() + 1);
//}

template <typename T>
void Ring<T>::delete_element()
{
	if (head == nullptr) return;
	
	if (head == tail)
	{
		delete this->get_head();

		this->set_head(nullptr);
		this->set_tail(nullptr);

		this->set_size(0);

		return;
	}

	this->set_head(this->get_head()->get_next());
	
	delete this->get_tail()->get_next();

	this->get_tail()->set_next(this->get_head());
	this->get_head()->set_prev(this->get_tail());

	this->set_size(this->get_size() - 1);
}

//template <typename T>
//void Ring<T>::delete_rear()
//{
//	if (head == nullptr) return;
//
//	if (head == tail)
//	{
//		delete this->get_head();
//
//		this->set_head(nullptr);
//		this->set_tail(nullptr);
//
//		this->set_size(0);
//
//		return;
//	}
//
//	this->set_rear(this->get_rear()->get_prev());
//
//	delete this->get_next()->get_prev();
//
//	this->get_head()->set_prev(this->get_tail());
//	this->get_tail()->set_next(this->get_head());
//
//	this->set_size(this->get_size() - 1);
//}

template <typename T>
RingNode<T>* Ring<T>::find_by_surname(string surname) const
{
	RingNode<T>* temp = this->get_head();

	// Кольцо замкнуто, поэтому идём ровно size шагов (а не до nullptr)
	for (int i = 0; i < this->get_size(); i++)
	{
		if (temp->get_value().get_surname() == surname)
			return temp;

		temp = temp->get_next();
	}

	return nullptr;
}

template <typename T>
RingNode<T>* Ring<T>::find_by_year(int year) const
{
	RingNode<T>* temp = this->get_head();

	for (int i = 0; i < this->get_size(); i++)
	{
		if (temp->get_value().get_year() == year)
			return temp;

		temp = temp->get_next();
	}

	return nullptr;
}

template <typename T>
void Ring<T>::print() const
{
	if (head == nullptr)
	{
		cout << "Ring is empty." << endl;
		return;
	}

	cout << "Ring, size = " << size << " (from head to tail, then head again)";

	// Шапка таблицы один раз
	head->get_value().print();

	RingNode<T>* temp = this->get_head();
	for (int i = 0; i < this->get_size(); i++)
	{
		cout << temp->get_value();
		temp = temp->get_next();
	}
}