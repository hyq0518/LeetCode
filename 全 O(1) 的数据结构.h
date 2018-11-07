/*
运用两个map就可以解决
*/
class AllOne {
public:
	/** Initialize your data structure here. */
	AllOne() {

	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		if (allonekv[key] == 0)
		{
			allonevk[++allonekv[key]].insert(key);
		}
		else
		{
			allonevk[allonekv[key]].erase(key);
			if (allonevk[allonekv[key]].size() == 0)
				allonevk.erase(allonekv[key]);
			allonevk[++allonekv[key]].insert(key);
		}
	}
	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (allonekv[key] == 0)
		{
			return;
		}
		else
		{
			allonevk[allonekv[key]].erase(key);
			if (allonevk[allonekv[key]].size() == 0)
				allonevk.erase(allonekv[key]);
			if ((--allonekv[key]) == 0)
				allonekv.erase(key);
			else
				allonevk[allonekv[key]].insert(key);
		}
	}
	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (allonevk.size() == 0)
			return "";
		map<int, unordered_set<string>>::iterator iter=allonevk.end();
		unordered_set<string>::iterator iters;
		iters = (*(--iter)).second.begin();
		return *iters;
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (allonevk.size() == 0)
			return "";
		map<int, unordered_set<string>>::iterator iter = allonevk.begin();
		unordered_set<string>::iterator iters;
		iters = (*iter).second.begin();
		return *iters;
	}
private:
	unordered_map<string, int> allonekv;
	//unordered_map<int, unordered_set<string>> allonevk;unordered_map效率要比map但是前者只提供单向迭代，新的编译器支持双向迭代。。。
	map<int, unordered_set<string>> allonevk;
};