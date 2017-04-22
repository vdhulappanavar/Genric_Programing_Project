template<class T>
class pairing_heap {
	public:
	pairing_heap() : root(0) {}
	~pairing_heap() 
	{
		if (root != 0) delete root;
	}
	inline const T & front() 
	{
		if (empty()) throw 31;
		return root->value;
	}
	inline bool empty() 
	{
		return (root == 0);
	}
	inline bool pop_front() 
	{
		if (empty()) return false;
		node * newroot = merge_pairs(root->sub);
		delete root;
		root = newroot;
		if (root != 0) root->parent = 0;
		return true;
	}
	class iterator 
	{
		public:
		iterator() : p(0) {}
		inline T & operator*() {
			if (p == 0) throw 34;
			return p->value;
		}
		inline T * operator->() {
			return (&(operator*()));
		}
		private:
		typename pairing_heap<T>::node * p;
		friend class pairing_heap<T>;
	};
	inline iterator insert(const T & v) 
	{
		iterator it;
		it.p = new node(v);
		root = merge(root, it.p);
		return it;
	}
	inline void on_decrease_key(const iterator & it) 
	{
		node * n = it.p;
		if (n->parent == 0) return;
		if (!erase_from_list(n, n->parent->sub)) throw 38;
		root = merge(root, n);
	}
	private:
	class node {
		public:
		node(const T & v) : value(v), parent(0) {}
		~node() {
			while (!sub.empty()) {
				delete sub.front();
				sub.pop_front();
			}
		}
		T value;
		node * parent;
		list<node *> sub;
	};
	inline bool erase_from_list(node * v, list<node *> & s) 
	{
		for (typename list<node *>::iterator it = s.begin();
			it != s.end(); ++it) {
			if (v == *it) {
				s.erase(it);
				return true;
			}
		}
		return false;
	}
	inline node * merge(node * a, node * b) 
	{
		if (a == 0) return b;
		if (b == 0) return a;
		if (a->value < b->value) {
			a->sub.push_front(b);
			b->parent = a;
			return a;
		} else {
			b->sub.push_front(a);
			node * t = a->parent;
			a->parent = b;
			b->parent = t;
			return b;
		}
		return a;
	}
	node * merge_pairs(list<node *> & s) {
		if (s.size() < 1) return 0;
		if (s.size() == 1) {
			node * ret = s.front();
			s.pop_front();
			return ret;
		}
		node * a = s.front();
		s.pop_front();
		node * b = s.front();
		s.pop_front();
		return merge(merge(a, b), merge_pairs(s));
	}
	node * root;
	pairing_heap(const pairing_heap<T> & h) {}
	void operator=(const pairing_heap<T> & h) {}
};

int main()
{
	
}
