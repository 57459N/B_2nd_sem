#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <tuple>
#include <stdexcept>
#include <memory>

#ifdef _WIN32
#include <windows.h>
#else
#include <locale.h>
#endif

#include <iostream>

using namespace std;

template <typename T>
class BTree_oop {
private:

	struct Branch {
		T data;
		Branch* parent = nullptr;
		Branch* child1 = nullptr;
		Branch* child2 = nullptr;

		Branch(int d, Branch* p = nullptr, Branch* c1 = nullptr, Branch* c2 = nullptr) {

			this->data = d;
			this->parent = p;
			this->child1 = c1;
			this->child2 = c2;
		}
	};

	inline	static Branch* _head = nullptr;

	Branch* find_place(Branch* top, const T& el) {
		if (top == nullptr) {
			return nullptr;
		}

		Branch* p;
		if (el < top->data) {
			p = find_place(top->child1, el);
		}
		else {
			p = find_place(top->child2, el);
		}

		if (p != nullptr) {
			return p;
		}
		return top;
	}

	void get_all(const Branch* top, T* arr, int& cur_size) {
		arr[cur_size] = top->data;
		if(top->child1 != nullptr && top->child2 != nullptr){
			get_all(top->child1, arr, cur_size++);
			get_all(top->child2, arr, cur_size++);
		}
	}

	

public:

	BTree_oop() = default;
	BTree_oop(const T* elems, int size) {
		for (int i = 0; i < size; i++) {
			this->pushback(elems[i]);
		}
	}
	BTree_oop(const T& tree) {
		T* arr = new T[1000]{};
		int size = 0;
		get_all(_head, arr, size);

		for (int i = 0; i < size; i++) {
			this->pushback(arr[i]);
		}
	}
	~BTree_oop() {
		wipe(_head);
	}

	void wipe(Branch* top) {
		if (top == nullptr)
			return;

		if (top->child1 != nullptr) {
			wipe(top->child1);
		}
		if (top->child2 != nullptr) {
			wipe(top->child2);
		}
		del_el(top->data);
	}

	void wipe() {
		wipe(_head);
	}

	void head_init(const T& el) {
		Branch* newEl = new Branch(el);
		_head = newEl;
	}

	void pushback(const T& el) {
				
		if (_head == nullptr) {
			head_init(el);
		}
		else {
			Branch* to_ins = find_place(_head, el);
			Branch* newEl = new Branch(el, to_ins);

			if (el < to_ins->data) {
				to_ins->child1 = newEl;
			}
			else {
				to_ins->child2 = newEl;
			}
		}
	}

	void complete(Branch* top) {
		if (top->child1 == nullptr && top->child2 == nullptr) {
			return;
		}
		if (top->child1 == nullptr) {
			top->child1 = new Branch(top->data, top);
		}
		if (top->child2 == nullptr) {
			top->child2 = new Branch(top->data, top);
		}

		complete(top->child1);
		complete(top->child2);
	}

	void complete() {
		complete(_head);
	}

	void del_el(const T& key) {
		Branch* to_del = find_el(key);
		if (to_del && to_del->child1 == nullptr && to_del->child2 == nullptr) {
			if (to_del-> parent){
				if (to_del->parent->child1 && to_del->parent->child1->data == key) {
					to_del->parent->child1 = nullptr;
				}
				else {
					to_del->parent->child2 = nullptr;
				}
			}
			else{
				_head = nullptr;
			}
		}
	}	

	Branch* find_el(const T& key, Branch* top = _head) {
		Branch* found = nullptr;

		if (top->child2 != nullptr && top->data < key) {
			found = find_el(key, top->child2);
		}
		else if (top->child1 != nullptr) {
			found = find_el(key, top->child1);
		}		
	

		if (!found) {
			if (top->data == key){
				return top;
			}
			if (top == _head){
				cout << "No such element in this tree" << endl;
			}
		}
		

		return found;

	}

	void show(Branch* parent) {

		if (parent == nullptr) {
			return;
		}

		if (parent->child1 == nullptr && parent->child2 == nullptr) {
			cout << parent->data;
			return;
		}
		else {
			show(parent->child1);
			cout << parent->data;
			show(parent->child2);
		}
	}

	void show() {
		show(_head);
		Branch* h = _head;
		cout << endl;
	}

	#define LN { std::cout << __LINE__ << std::endl; }
	inline	static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";
	void show_beautiful(const Branch* node) {
		#define _MAX(x, y) ((x) > (y) ? (x) : (y))
		#define _MIN(x, y) ((x) < (y) ? (x) : (y))

		auto RepStr = [](std::string const& s, size_t cnt) {
			if (ptrdiff_t(cnt) < 0)
				throw std::runtime_error("RepStr: Bad value " + std::to_string(ptrdiff_t(cnt)) + "!");
			std::string r;
			for (size_t i = 0; i < cnt; ++i)
				r += s;
			return r;
		};

		std::function<std::tuple<std::vector<std::string>, size_t, size_t>(const Branch * node, bool)> Rec;
		Rec = [&RepStr, &Rec](const Branch* node, bool child1) {
			std::vector<std::string> lines;
			if (!node)
				return std::make_tuple(lines, size_t(0), size_t(0));
			auto sval = std::to_string(node->data);
			//if (sval.size() % 2 != 1) sval += " ";
			auto resl = Rec(node->child1, true), resr = Rec(node->child2, false);
			auto const& vl = std::get<0>(resl);
			auto const& vr = std::get<0>(resr);
			auto cl = std::get<1>(resl), cr = std::get<1>(resr), lss = std::get<2>(resl), rss = std::get<2>(resr);
			size_t lv = sval.size();
			size_t ls = vl.size() > 0 ? lss : size_t(0);
			size_t rs = vr.size() > 0 ? rss : size_t(0);
			size_t lis = ls == 0 ? lv / 2 : _MAX(int(lv / 2 + 1 - (ls - cl)), 0);
			size_t ris = rs == 0 ? (lv + 1) / 2 : _MAX(int((lv + 1) / 2 - cr), (lis > 0 ? 0 : 1));
			size_t dashls = (ls == 0 ? 0 : ls - cl - 1 + lis - lv / 2), dashrs = (rs == 0 ? 0 : cr + ris - (lv + 1) / 2);
			//DEB(node->value); DEB(lv); DEB(ls); DEB(rs); DEB(cl); DEB(cr); DEB(lis); DEB(ris); DEB(dashls); DEB(dashrs); std::cout << std::endl;
			lines.push_back(
				(ls == 0 ? "" : (RepStr(" ", cl) + ch_ddia + RepStr(ch_hor, dashls))) +
				sval + (rs == 0 ? "" : (RepStr(ch_hor, dashrs) + ch_rddia + RepStr(" ", rs - cr - 1)))
			);
			//if (lines.back().size() != ls + lis + ris + rs)
			//    throw std::runtime_error("Dump: First line wrong size, got " + std::to_string(lines.back().size()) + ", expected " + std::to_string(ls + lis + ris + rs));
			for (size_t i = 0; i < _MAX(vl.size(), vr.size()); ++i) {
				std::string sl = RepStr(" ", ls), sr = RepStr(" ", rs);
				if (i < vl.size()) sl = vl[i];
				if (i < vr.size()) sr = vr[i];
				sl = sl + RepStr(" ", lis);
				sr = RepStr(" ", ris) + sr;
				lines.push_back(sl + sr);
			}
			return std::make_tuple(lines, (left || ls + lis == 0 || lv % 2 == 1) ? ls + lis : ls + lis - 1, ls + lis + ris + rs);
		};
		auto v = std::get<0>(Rec(node, true));
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << std::endl;

	#undef _MAX
	#undef _MIN
	}

	void show_beautiful() {
		show_beautiful(_head);
	}
};


int oop25() {

	BTree_oop<int> tree;
	tree.pushback(2);
	for (int i = 0; i < 5; i++) {
		if (i == 2) continue;
		tree.pushback(i);
	}
	tree.complete();
	tree.show_beautiful();

	tree.del_el(2);
	tree.show_beautiful();

	tree.del_el(0);
	tree.del_el(3);
	tree.show_beautiful();

	tree.wipe();
	tree.show_beautiful();

	return 0;
}