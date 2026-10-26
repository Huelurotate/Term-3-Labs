#pragma once

template <typename T>
class RingNode
{
private:
	T value;

	RingNode<T>* next;
	RingNode<T>* prev;
public:
	RingNode(T value = 0, RingNode<T>* next = nullptr, RingNode<T>* prev = nullptr);

	T get_value() const;
	RingNode<T>* get_next() const;
	RingNode<T>* get_prev() const;

	void set_value(T new_value);
	void set_next(RingNode<T>* new_next);
	void set_prev(RingNode<T>* new_prev);
};

template <typename T>
RingNode<T>::RingNode(T value, RingNode<T>* next, RingNode<T>* prev) :
	value(value), next(next), prev(prev)
{}

template <typename T>
T RingNode<T>::get_value() const
{
	return this->value;
}

template <typename T>
RingNode<T>* RingNode<T>::get_next() const
{
	return this->next;
}

template <typename T>
RingNode<T>* RingNode<T>::get_prev() const
{
	return this->prev;
}

template <typename T>
void RingNode<T>::set_value(T new_value)
{
	this->value = new_value;
}

template <typename T>
void RingNode<T>::set_next(RingNode<T>* new_next)
{
	this->next = new_next;
}

template <typename T>
void RingNode<T>::set_prev(RingNode<T>* new_prev)
{
	this->prev = new_prev;
}