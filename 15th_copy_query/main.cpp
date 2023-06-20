#include<memory>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<istream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<sstream>
using std::shared_ptr;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::ifstream;
using std::ostream;
using std::cout;
using std::endl;
using std::istringstream;
using std::make_shared;
//查询结果类
class QueryResult {
public:
	typedef vector<string>::size_type line_no;
	friend ostream& print(ostream&, const QueryResult&);
	friend ostream& operator<<(ostream&, const QueryResult&);
	QueryResult(const string& w, shared_ptr<set<line_no>> n, shared_ptr<vector<string>> i) :word(w), nos(n), input(i) {}
	//返回指向保存行号的set的迭代器
	set<line_no>::iterator begin()const {
		return nos->begin();
	}
	set<line_no>::iterator end()const {
		return nos->end();
	}
	shared_ptr<vector<string>> get_file()const {
		return input;
	}
private:
	string word;//查询单词
	shared_ptr<set<line_no>> nos;//单词对应的行数
	shared_ptr<vector<string>> input;//输入文件的vector指针
};
//文本查询类
class TextQuery {
public:
	typedef vector<string>::size_type line_no;
	//构造函数
	TextQuery(ifstream&);
	//查询函数
	QueryResult query(const string&)const;
private:
	shared_ptr<vector<string>> input;//输入文件
	map<string, shared_ptr<set<line_no>>> result;//单词对应的行号
};

ostream& print(ostream& os, const QueryResult& qr) {
	os << qr.word << " occurs: " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << endl;
	for (int i : *qr.nos) {
		cout << "\t(line " << i + 1 << ") " << qr.input->at(i) << endl;
	}
	return os;
}

TextQuery::TextQuery(ifstream& ifs) :input(new vector<string>) {
	line_no lineNo = 0;
	for (string line; getline(ifs, line); lineNo++) {
		input->push_back(line);
		istringstream line_stream(line);
		string text, word;
		for (; line_stream >> text; word.clear()) {
			remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			auto& nos = result[word];
			if (!nos)nos.reset(new set<line_no>);//对象是智能指针
			nos->insert(lineNo);//对象是set
		}
	}
}
QueryResult TextQuery::query(const string& word) const {
	static shared_ptr<set<line_no>> nos(new set<line_no>);
	auto found = result.find(word);
	if (found == result.end()) {
		return QueryResult(word, nos, input);
	}
	else {
		return QueryResult(word, found->second, input);
	}
}

//查询基类
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&)const = 0;
	virtual string rep()const = 0;
};

//查询接口类
class Query {
	//友元操作符
	friend Query operator&(const Query&, const Query&);
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	Query(const string& word);//只向外界提供wordQuery成员的初始化

	string rep()const {
		return q->rep();
	}
	//查询函数接口
	QueryResult eval(const TextQuery& tq)const {
		return q->eval(tq);
	}
private:
	//此构造函数不允许外界调用
	Query(shared_ptr<Query_base> query) :q(query) { cout << "调用 Query ctor" << endl; };
	//指向查询类的指针
	shared_ptr<Query_base> q;
};
//重载<<输出Query
ostream& operator<<(ostream& os, const Query& query) {
	return os << query.rep() << endl;
}
//重载<<输出QueryResult
ostream& operator<<(ostream& os, const QueryResult& qr) {
	os << qr.word << " occurs: " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << endl;
	for (int i : *qr.nos) {
		cout << "\t(line " << i + 1 << ") " << qr.input->at(i) << endl;
	}
	return os;
}
//单词查询类
class WordQuery :public Query_base {
	friend class Query;

	WordQuery(const string& s) :query_word(s) { cout << "调用 wordQuery ctor" << endl; }

	string rep() const override {
		return query_word;
	}

	QueryResult eval(const TextQuery& tq)const override {
		return tq.query(query_word);
	}

	string query_word;
};

//Query构造函数
inline
Query::Query(const string& word) :q(new WordQuery(word)) { cout << "调用 Query ctor" << endl; };

//Not查询类
class NotQuery : public Query_base {
	friend Query operator~(const Query&);

	NotQuery(const Query& q) :query(q) { cout << "调用 NotQuery ctor" << endl; }

	string rep()const override {
		return "~(" + query.rep() + ")";
	}

	QueryResult eval(const TextQuery& tq)const override {
		auto result = query.eval(tq);

		auto ret_lines = make_shared<set<line_no>>();
		auto beg = result.begin(), end = result.end();
		line_no sz = result.get_file()->size();

		for (size_t n = 0; n != sz; n++) {
			if (beg == end || *beg != n)
				ret_lines->insert(n);
			else if (beg != end)
				beg++;
		}
		return QueryResult(rep(), ret_lines, result.get_file());
	}

	Query query;
};

inline
Query operator~(const Query& query) {
	return shared_ptr<Query_base>(new NotQuery(query));
}

//二元查询抽象基类
class BinaryQuery :public Query_base {
protected:
	BinaryQuery(const Query& l, const Query& r, const string& op) :lhs(l), rhs(r), opSym(op) { cout << "调用 BinaryQuery ctor" << endl; }
	string rep()const override {
		return lhs.rep() + opSym + rhs.rep();
	}
	Query lhs, rhs;
	string opSym;
};

//and查询类
class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query&);

	AndQuery(const Query& l, const Query& r) :BinaryQuery(l, r, "&") { cout << "调用 AndQuery ctor" << endl; };
	QueryResult eval(const TextQuery& tq)const override {
		auto left = lhs.eval(tq), right = rhs.eval(tq);
		auto ret_line = make_shared<set<line_no>>();//构造一个智能指针，指向空的结果集合

		set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_line, ret_line->begin()));//取并集
		//inserter(*ret_line,ret_line->begin())插入迭代器，调用的是set<line_no>::insert();

		return QueryResult(rep(), ret_line, left.get_file());
	}

};
inline
Query operator&(const Query& lhs, const Query& rhs) {
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

//Or查询类
class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query&);

	OrQuery(const Query& l, const Query& r) :BinaryQuery(l, r, "|") { cout << "调用 OrQuery ctor" << endl; };
	//Or类型版本的eval函数
	QueryResult eval(const TextQuery& tq)const override {
		auto left = lhs.eval(tq), right = rhs.eval(tq);//分别获取左右两部分的查询结果
		auto ret_line = make_shared<set<line_no>>(left.begin(), left.end());
		ret_line->insert(right.begin(), right.end());//取左右两部分的查询并集

		return QueryResult(rep(), ret_line, left.get_file());//返回查询结果
	}
};
inline
Query operator|(const Query& lhs, const Query& rhs) {
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


#include<iostream>
using std::cout;
using std::cin;
string fileName = "Alice.txt";//文件路径

void runQuery(ifstream& ifs, Query& q) {
	TextQuery tq(ifs);
	cout << q;//打印处理对象，重载了操作符
	cout << q.eval(tq);//打印处理结果，重载了操作符
}

int main(int argc, char** argv) {
	ifstream ifs(fileName);
	Query q = Query("fiery") & Query("mountain") | Query("mountain");
	if (ifs)
		runQuery(ifs, q);
	else
		std::cerr << "Cannot open this file!" << fileName;
}


