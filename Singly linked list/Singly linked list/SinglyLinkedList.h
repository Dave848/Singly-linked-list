#ifndef _SINGLYLINKEDLIST
#define _SINGLYLINKEDLIST

#include "Node.h"
#include <sstream>
#include <fstream>

template<typename T>
class SinglyLinkedList
{
	std::shared_ptr<Node<T>> head;
public:
	SinglyLinkedList() : head{ nullptr } {}

	SinglyLinkedList(const SinglyLinkedList& list) : head(nullptr)
	{
		std::shared_ptr<Node<T>> temp = list.head;
		while (temp)
		{
			insert_back(temp->data);
			temp = temp->next;
		}
	}

	SinglyLinkedList(SinglyLinkedList&& list) : head(list.head)
	{
		list.head = nullptr;
	}

	void show_list() const
	{
		std::shared_ptr<Node<T>> temp = head;
		while (temp)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	void insert_front(const T& data) 
	{
		std::shared_ptr<Node<T>> new_node{ std::make_shared<Node<T>>(data) };

		if (!head)
		{
			head = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
		}
	}

	void insert_back(const T& data)
	{
		std::shared_ptr<Node<T>> new_node{ std::make_shared<Node<T>>(data) };
		std::shared_ptr<Node<T>> temp = head;

		if (!head)
		{
			head = new_node;
			return;
		}
		while (true)
		{
			if (temp->next == nullptr)
			{
				temp->next = new_node;
				return;
			}
			temp = temp->next;
		}
	}

	std::shared_ptr<Node<T>> pop_front()
	{
		if (!head) { return nullptr; }

		std::shared_ptr<Node<T>> temp = head;
		head = head->next;
		return temp;
	}

	std::shared_ptr<Node<T>> pop_back()
	{
		if (!head) { return nullptr; }

		std::shared_ptr<Node<T>> temp = head;
		std::shared_ptr<Node<T>> previous;

		if (temp->next == nullptr)
		{
			head = nullptr;
			return temp;
		}

		while (true)
		{
			if (temp->next == nullptr)
			{
				previous->next = nullptr;
				return temp;
			}
			previous = temp;
			temp = temp->next;
		}
	}

	void remove(const T& data)
	{
		if (!head) { return; }

		std::shared_ptr<Node<T>> temp = head;
		std::shared_ptr<Node<T>> previous;

		if (temp->data == data && temp->next == nullptr)
		{
			head = nullptr;
			return;
		}
		else if(temp->data == data && temp->next != nullptr)
		{
			head = temp->next;
			return;
		}

		while (true)
		{
			if (temp->data == data)
			{
				previous->next = temp->next;
				return;
			}
			previous = temp;
			if (temp->next == nullptr) { return; }
			temp = temp->next;
		}
	}
	
	bool is_empty() const
	{
		return !head;
	}

	bool search(const T& data) const
	{
		std::shared_ptr<Node<T>> temp = head;
		while (temp)
		{
			if (temp->data == data)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	SinglyLinkedList& operator=(const SinglyLinkedList& list)
	{
		if (this == &list)
		{
			return *this;
		}

		while(!is_empty())
		{
			pop_front();
		}
		
		std::shared_ptr<Node<T>> temp = list.head;
		while(temp)
		{
			insert_back(temp->data);
			temp = temp->next;
		}
		return *this;
	}

	SinglyLinkedList& operator=(SinglyLinkedList&& list)
	{
		head = list.head;
		list.head = nullptr;
		return *this;
	}

	T& operator[](int index)
	{
		if(!good_index(index))
		{	
			std::cout << "Wrong index value, exiting";
			exit(0);
		}

		std::shared_ptr<Node<T>> temp_ptr = head;
		for (int i = 0; i < index ; i++)
		{
			temp_ptr = temp_ptr->next;
		}

		return temp_ptr->data;
	}

	bool good_index(int index)
	{
		if (index < 0) { return false; }

		std::shared_ptr<Node<T>> temp_ptr = head;
		for (int i = 0; i < index; i++)
		{
			temp_ptr = temp_ptr->next;
			if (temp_ptr == nullptr)
			{
				return false;
			}
		}
		return true;
	}

	void sort()
	{
		if (!head) { return; }

		std::shared_ptr<Node<T>> current, temp_ptr;
		current = head;
		T temp_data;

		while (current)
		{
			temp_ptr = current->next;
			while (temp_ptr)
			{
				if (current->data > temp_ptr->data)
				{
					temp_data = current->data;
					current->data = temp_ptr->data;
					temp_ptr->data = temp_data;
				}
				temp_ptr = temp_ptr->next;
			}
			current = current->next;
		}
	}

	void serialize() const
	{
		std::shared_ptr<Node<T>> temp_ptr = head;
		std::stringstream temp_ss;

		while (temp_ptr)
		{
			temp_ss << temp_ptr->data;
			temp_ptr = temp_ptr->next;
		}
	
		std::ofstream file;
		file.open("Serialized_data.txt");
		if(!file)
		{
			std::cerr << "File couldn't be opened." << std::endl;
			exit(1);
		}

		file << temp_ss.str();
	}
};

#endif