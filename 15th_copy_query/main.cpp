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
//��ѯ�����
class QueryResult {
public:
	typedef vector<string>::size_type line_no;
	friend ostream& print(ostream&, const QueryResult&);
	friend ostream& operator<<(ostream&, const QueryResult&);
	QueryResult(const string& w, shared_ptr<set<line_no>> n, shared_ptr<vector<string>> i) :word(w), nos(n), input(i) {}
	//����ָ�򱣴��кŵ�set�ĵ�����
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
	string word;//��ѯ����
	shared_ptr<set<line_no>> nos;//���ʶ�Ӧ������
	shared_ptr<vector<string>> input;//�����ļ���vectorָ��
};
//�ı���ѯ��
class TextQuery {
public:
	typedef vector<string>::size_type line_no;
	//���캯��
	TextQuery(ifstream&);
	//��ѯ����
	QueryResult query(const string&)const;
private:
	shared_ptr<vector<string>> input;//�����ļ�
	map<string, shared_ptr<set<line_no>>> result;//���ʶ�Ӧ���к�
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
			if (!nos)nos.reset(new set<line_no>);//����������ָ��
			nos->insert(lineNo);//������set
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

//��ѯ����
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&)const = 0;
	virtual string rep()const = 0;
};

//��ѯ�ӿ���
class Query {
	//��Ԫ������
	friend Query operator&(const Query&, const Query&);
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	Query(const string& word);//ֻ������ṩwordQuery��Ա�ĳ�ʼ��

	string rep()const {
		return q->rep();
	}
	//��ѯ�����ӿ�
	QueryResult eval(const TextQuery& tq)const {
		return q->eval(tq);
	}
private:
	//�˹��캯��������������
	Query(shared_ptr<Query_base> query) :q(query) { cout << "���� Query ctor" << endl; };
	//ָ���ѯ���ָ��
	shared_ptr<Query_base> q;
};
//����<<���Query
ostream& operator<<(ostream& os, const Query& query) {
	return os << query.rep() << endl;
}
//����<<���QueryResult
ostream& operator<<(ostream& os, const QueryResult& qr) {
	os << qr.word << " occurs: " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << endl;
	for (int i : *qr.nos) {
		cout << "\t(line " << i + 1 << ") " << qr.input->at(i) << endl;
	}
	return os;
}
//���ʲ�ѯ��
class WordQuery :public Query_base {
	friend class Query;

	WordQuery(const string& s) :query_word(s) { cout << "���� wordQuery ctor" << endl; }

	string rep() const override {
		return query_word;
	}

	QueryResult eval(const TextQuery& tq)const override {
		return tq.query(query_word);
	}

	string query_word;
};

//Query���캯��
inline
Query::Query(const string& word) :q(new WordQuery(word)) { cout << "���� Query ctor" << endl; };

//Not��ѯ��
class NotQuery : public Query_base {
	friend Query operator~(const Query&);

	NotQuery(const Query& q) :query(q) { cout << "���� NotQuery ctor" << endl; }

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

//��Ԫ��ѯ�������
class BinaryQuery :public Query_base {
protected:
	BinaryQuery(const Query& l, const Query& r, const string& op) :lhs(l), rhs(r), opSym(op) { cout << "���� BinaryQuery ctor" << endl; }
	string rep()const override {
		return lhs.rep() + opSym + rhs.rep();
	}
	Query lhs, rhs;
	string opSym;
};

//and��ѯ��
class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query&);

	AndQuery(const Query& l, const Query& r) :BinaryQuery(l, r, "&") { cout << "���� AndQuery ctor" << endl; };
	QueryResult eval(const TextQuery& tq)const override {
		auto left = lhs.eval(tq), right = rhs.eval(tq);
		auto ret_line = make_shared<set<line_no>>();//����һ������ָ�룬ָ��յĽ������

		set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_line, ret_line->begin()));//ȡ����
		//inserter(*ret_line,ret_line->begin())��������������õ���set<line_no>::insert();

		return QueryResult(rep(), ret_line, left.get_file());
	}

};
inline
Query operator&(const Query& lhs, const Query& rhs) {
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

//Or��ѯ��
class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query&);

	OrQuery(const Query& l, const Query& r) :BinaryQuery(l, r, "|") { cout << "���� OrQuery ctor" << endl; };
	//Or���Ͱ汾��eval����
	QueryResult eval(const TextQuery& tq)const override {
		auto left = lhs.eval(tq), right = rhs.eval(tq);//�ֱ��ȡ���������ֵĲ�ѯ���
		auto ret_line = make_shared<set<line_no>>(left.begin(), left.end());
		ret_line->insert(right.begin(), right.end());//ȡ���������ֵĲ�ѯ����

		return QueryResult(rep(), ret_line, left.get_file());//���ز�ѯ���
	}
};
inline
Query operator|(const Query& lhs, const Query& rhs) {
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


#include<iostream>
using std::cout;
using std::cin;
string fileName = "Alice.txt";//�ļ�·��

void runQuery(ifstream& ifs, Query& q) {
	TextQuery tq(ifs);
	cout << q;//��ӡ������������˲�����
	cout << q.eval(tq);//��ӡ�������������˲�����
}

int main(int argc, char** argv) {
	ifstream ifs(fileName);
	Query q = Query("fiery") & Query("mountain") | Query("mountain");
	if (ifs)
		runQuery(ifs, q);
	else
		std::cerr << "Cannot open this file!" << fileName;
}


