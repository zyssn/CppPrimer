#include "test.h"


void testStrBlobPtr() {
    ifstream f("test.txt");
    if (f) {
        string tmp;
        StrBlob s;
        while (f >> tmp) {
            s.push_back(tmp);
        }
        cout << "Read all word" << endl;
        cout << "Show them" << endl;
        for (StrBlobPtr p = s.begin(); !eq(p, s.end()); p.incr()) {
            cout << p.deref() << " ";
        }
        cout << endl;
    }
    else {
        cout << "Read file error" << endl;
        exit(1);
    }
    f.close();
}

void testAllocater()
{
    int n;
    cin >> n;
    allocator<string> alloc;
    string s;
    string *p = alloc.allocate(n);
    string *q = p;

    while (cin >> s && q != p + n) {
        alloc.construct(q++, s);
    }
    const size_t size = q - p;

    cout << size << endl;

    //// 扩容并转移 有问题，后续处理
    vector<string> str(p, p + size);
    cout << str.size() << endl;
    auto newP = alloc.allocate(str.size() * 2);
    // uninitialized_fill_n的第三个参数必须指向没有构造的地址
    auto newQ = uninitialized_copy(str.begin(), str.end(), newP);
    uninitialized_fill_n(newQ, 2 * n, "abcde");
    str.resize(0);
    str = vector<string>(newQ, newQ + 2 * n);

    cout << endl;
    cout << "****************************" << endl;
    cout << endl;
    alloc.deallocate(p, n);
    alloc.deallocate(newP, 2 * n);
    return;
}

MyTextQuery::MyTextQuery(string path)
{
    ifstream fs2;
    fs2.open(path, ifstream::in);
    string str;
    line_no linenum = 0;

    while (getline(fs2, str)) {
        string tmp;
        ostringstream lines;
        istringstream is(str);
        while (is >> tmp) {
            if (mp[tmp].size() == 0 || linenum != mp[tmp].back()) {
                mp[tmp].push_back(linenum);
            }
            lines << " " << tmp;
        }
        linenum++;
        content_in_a_line.push_back(lines.str());
    }
    fs2.close();
}

void MyTextQuery::myprint(string word)
{
    int count = mp[word].size();
    cout << word << " occurs " << count << " times." << endl;

    vector<int> arr = mp[word];
    for (auto n : arr) {
        cout << "\t(line " << n << ")" << content_in_a_line[n] << endl;
    }
}
