#pragma once
#include <iostream>
using namespace std;
namespace study_list {
	// 定义节点结构体模板
	template <class T>
	    struct __list_node {
		__list_node<T>* prev;
		// 指向前一个节点
		__list_node<T>* next;
		// 指向下一个节点
		T _data;
		// 存储节点的数据
		__list_node(const T& data = T()) : prev(nullptr), next(nullptr), _data(data) {
			;
		}
	}
	;
	// 迭代器模板
	template <class T, class Ref, class Ptr>
	    struct __list_iterator {
		typedef __list_node<T> Node;
		// 为节点类型定义别名
		Node* _node;
		// 当前迭代器指向的节点
		typedef __list_iterator<T, Ref, Ptr> self;
		// 迭代器构造函数
		__list_iterator(Node* node) : _node(node) {
		}
		// 解引用运算符，返回节点数据
		Ref operator*() {
			return _node->_data;
		}
		// 成员访问运算符，返回节点数据指针
		Ptr operator->() {
			return &(_node->_data);
		}
		// 前置++运算符，移动到下一个节点
		self& operator++() {
			_node = _node->next;
			return *this;
		}
		// 后置++运算符，移动到下一个节点
		self operator++(int) {
			self tmp = *this;
			_node = _node->next;
			return tmp;
		}
		// 前置--运算符，移动到前一个节点
		self& operator--() {
			_node = _node->prev;
			return *this;
		}
		// 不等于运算符，判断迭代器是否指向相同的节点
		bool operator!=(const self& it) const {
			return _node != it._node;
		}
		// 等于运算符，判断迭代器是否指向相同的节点
		bool operator==(const self& it) const {
			return _node == it._node;
		}
	}
	;
	// 定义双向循环链表类模板
	template <class T>
	    class list {
		public:
		        typedef __list_node<T> Node;
		// 为节点类型定义别名
		typedef __list_iterator<T, T&, T*> iterator;
		// 定义迭代器类型
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		// 定义常量迭代器类型
		// 构造函数，初始化带头双向循环链表
		list() {
			_head = new Node();
			_head->next = _head;
			// 初始化头节点的next指向自己
			_head->prev = _head;
			// 初始化头节点的prev指向自己
		}
		list(const list<T>& lt)
		{
			_head = new Node;
			_head -> next = _head;
			_head -> prev = _head;

			// const_iterator it = lt.begin();
			// while(it != lt.end())
			// {
			// 	push_back(*it);
			// 	++it;
			// }
			for(auto e:lt)
			{
				push_back(e);
			}
		}
		// 析构函数，清空链表并释放头节点
		~list() {
			clear();
			// 清空链表中的所有节点
			delete _head;
			// 释放头节点
		}
		// 在链表末尾插入元素
		void push_back(const T& data) {
			Node* tail = _head->prev;
			// 找到当前尾节点
			Node* new_node = new Node(data);
			// 创建新节点
			tail->next = new_node;
			// 尾节点的next指向新节点
			new_node->prev = tail;
			// 新节点的prev指向尾节点
			new_node->next = _head;
			// 新节点的next指向头节点
			_head->prev = new_node;
			// 头节点的prev指向新节点
		}
		// 返回指向链表第一个元素的迭代器
		iterator begin() {
			return iterator(_head->next);
		}
		// 返回指向链表尾节点后的迭代器（即头节点）
		iterator end() {
			return iterator(_head);
		}
		// 返回指向链表第一个元素的常量迭代器
		const_iterator begin() const {
			return const_iterator(_head->next);
		}
		// 返回指向链表尾节点后的常量迭代器（即头节点）
		const_iterator end() const {
			return const_iterator(_head);
		}
		// list<T>& operator=(const list<T>&lt)
		// {
		// 	if(this != &lt)
		// 	{
		// 		clear();
		// 		for(auto e : lt)
		// 		{
		// 			push_back(e);
		// 		}
		// 	}
		// 	return *this;
		// }
		list<T>& operator=(list<T> lt)
		{
			swap(_head,lt._head);
			return *this;
		}
		// 打印链表内容
		void print_list() const {
			const_iterator it = begin();
			while (it != end()) {
				cout << *it << " ";
				// 输出节点数据
				++it;
				// 需要递增迭代器，避免无限循环
			}
			cout << endl;
		}
		// 清空链表，删除所有节点
		void clear() {
			iterator it = begin();
			while (it != end()) {
				erase(it++);
				// 删除当前节点，并将迭代器移到下一个节点
			}
		}
		// 删除指定位置的节点
		void erase(iterator it) {

			Node* node_to_delete = it._node;
			// 取得要删除的节点
			node_to_delete->prev->next = node_to_delete->next;
			// 连接前后节点
			node_to_delete->next->prev = node_to_delete->prev;
			delete node_to_delete;
			// 删除节点
		}
		void pop_back()
		{
			erase(end()--);
		}
		void pop_front()
		{
			erase(begin());
		}
		// 在指定位置插入节点
		void insert(iterator pos, const T& data) {
			Node* node_to_insert = new Node(data);
			// 创建新节点
			Node* cur = pos._node;
			// 获取当前节点
			Node* prev = cur->prev;
			// 获取前驱节点
			prev->next = node_to_insert;
			// 连接前驱节点与新节点
			node_to_insert->prev = prev;
			// 新节点的prev指向前驱节点
			node_to_insert->next = cur;
			// 新节点的next指向当前节点
			cur->prev = node_to_insert;
			// 当前节点的prev指向新节点
		}
		private:
		        Node* _head;
		// 头节点（哨兵节点）
	}
	;
	// 测试函数1：插入并遍历整数链表
	void test_list1() {
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		// 通过迭代器遍历链表
		list<int>::iterator it = lt.begin();
		while (it != lt.end()) {
			std::cout << *it << " ";
			// 输出节点数据
			++it;
			// 移动到下一个节点
		}
		std::cout << std::endl;
	}
	// 定义数据结构用于测试
	struct Data {
		int _year = 0;
		int _month = 1;
		int _day = 1;
	}
	;
	// 测试函数2：插入并遍历自定义数据类型链表
	void test_list2() {
		list<Data> lt;
		lt.push_back(Data());
		lt.push_back(Data());
		// 遍历链表，输出结构体数据
		list<Data>::iterator it = lt.begin();
		while (it != lt.end()) {
			std::cout << "Year: " << it->_year << " "
			                      << "Month: " << it->_month << " "
			                      << "Day: " << it->_day << std::endl;
			++it;
		}
	}
	// 测试函数3：打印链表内容
	void test_list3() {
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		list<int> lt2(lt);
		lt2.print_list();
		// 打印链表内容
	}
	//栈都是后定义先析构
}

//Node* cur 和 iterator it 两者都指向同一个节点，物理内存上指向相同,但是他们的类型不同，意义不一样
//类型是不同的解释方式
//类型决定对空间的解释权


//1.vector和list的区别、
//2.vector和list底层是如何实现的
//3.vector是如何增容的
//4.什么是迭代器失效

//1.vector是一个可动他增长的数组，有点，可以随机访问 operator[] ->很好的支持 排序，二分查找，堆算法等等
//缺点 头部或者中间的插入删除效率很低
//需要增容 性能消耗较大

//2.list是一个带头双向循环的链表
//优点:任意位置插入删除数据的效率高
//缺点:不支持随机访问
//总结:vector和list是两个相辅相成，互补的两个容器