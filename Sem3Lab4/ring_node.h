#pragma once

template <typename T>
class RingNode
{
private:
	T value;

	RingNode<T>* next;
	RingNode<T>* prev;
public:
	RingNode(const T& value = T(), RingNode<T>* next = nullptr, RingNode<T>* prev = nullptr);

	const T& get_value() const;
	RingNode<T>* get_next() const;
	RingNode<T>* get_prev() const;

	void set_value(const T& new_value);
	void set_next(RingNode<T>* new_next);
	void set_prev(RingNode<T>* new_prev);
};

template <typename T>
RingNode<T>::RingNode(const T& value, RingNode<T>* next, RingNode<T>* prev) :
	value(value), next(next), prev(prev)
{}

template <typename T>
const T& RingNode<T>::get_value() const
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
void RingNode<T>::set_value(const T& new_value)
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