#include "include.h"

using namespace std;

template<typename T1, typename T2>
void print(unordered_map<T1, T2> hash) {
    if (hash.size() == 0)
        cout << "null!" << endl;
    for_each(hash.begin(), hash.end(), [](pair<T1, T2> a) {
        cout << "key : " << a.first << ", value : " << a.second << endl; });
}

template<typename T1, typename T2>
void print(map<T1, T2> hash) {
    if (hash.size() == 0)
        cout << "null!" << endl;
    for_each(hash.begin(), hash.end(), [](pair<T1, T2> a) {
        cout << "key : " << a.first << ", value : " << a.second << endl; });
}

template<typename T>
void print(multiset<T> hash) {
    if (hash.size() == 0)
        cout << "null!" << endl;
    for_each(hash.begin(), hash.end(), [](T a) {
        cout << "value : " << a << endl; });
}

template<typename T>
void print(unordered_multiset<T> hash) {
    if (hash.size() == 0)
        cout << "null!" << endl;
    for_each(hash.begin(), hash.end(), [](T a) {
        cout << "value : " << a << endl; });
}

void printline() {
    cout << "-----------------------------------------------" << endl;

}

#ifdef mai
int main() {
    /*map<int, int> hash;*/
    unordered_map<int, int> hash;

    vector<int> vec{ 1,2,1,3,5,4,5,1,2 };

    for_each(vec.begin(), vec.end(), [&](int a) { hash[a]++; });
    print(hash);

    decltype(hash) a;
    print(a);
    printline();

    unordered_multimap<string, int> c{ {"abc", 0}, {"abc", 2}, {"ab", 8}, {"uyt", 9}, {"loce", 4} };
    vector<pair<string, int>> vecStr{ {"Jack", 1}, {"Bob", 2}, {"Tom",3} };

    copy(vecStr.begin(), vecStr.end(), inserter(c, c.begin()));
    //copy(c.begin(), c.end(), back_inserter(vecStr));
    //copy(c.begin(), c.end(), inserter(vecStr, vecStr.end()));
    //printline();
    print(c);
    printline();
    print(vecStr);
    printline();
    //copy(vecStr.begin(), vecStr.end(),  (c));
    //print(c);

    return 0;
}

#endif

void append(map<string, vector<string>>& mp, string firstname,string lastname) {
    mp[firstname].push_back(lastname);
}

int sumhash(unordered_map<int, int> hash) {
    int res = 0;
    for (auto arr : hash) {

        cout << arr.second << " ";
        res += arr.first * arr.second;
    }
    cout << endl;
    return res;
}


int minOperations(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() * 6 < nums2.size() || nums2.size() * 6 < nums1.size())
        return -1;
    int res = 0, dist = 0;
    unordered_map<int, int> hash_nums1;
    unordered_map<int, int> hash_nums2;

    for_each(nums1.begin(), nums1.end(), [&hash_nums1](int a) {
        hash_nums1[a]++;
        });
    for_each(nums2.begin(), nums2.end(), [&hash_nums2](int a) {
        hash_nums2[a]++;
        });
    int sum1 = sumhash(hash_nums1), sum2 = sumhash(hash_nums2);

    if (sum1 > sum2) {
        swap(hash_nums1, hash_nums2);
        swap(sum1, sum2);
    }
    if (sum1 == sum2)
        return 0;

    for (int i = 1; i <= 6; ++i) {
        while (hash_nums1[i] || hash_nums2[7 - i]) {
            while (hash_nums1[i]) {
                dist = sum2 - sum1;
                if (dist <= 6 - i) {
                    return res + 1;
                }

                res++;
                hash_nums1[i]--;
                sum1 += 6 - i;

                cout << sum1 << " " << sum2 << endl;
            }
            while (hash_nums2[7 - i]) {
                dist = sum2 - sum1;
                if (dist <= 6 - i) {
                    return res + 1;
                }

                res++;
                hash_nums2[7 - i]--;
                sum2 -= 6 - i;
            }
        }
    }

    return res;
}

void buildMap(unordered_map<string, string>& hash) {
    ifstream fs;
    fs.open("example1.txt", fstream::in);
    string text;
    while (getline(fs, text)) {
        string word;
        istringstream ist(text);
        ist >> word;
        string trans_word;
        string tmp = "";
        while (ist >> trans_word) {
            tmp += trans_word + " ";
        }
        tmp = tmp.substr(0, tmp.size() - 1);
        hash.insert(make_pair(word, tmp));
    }
}

string transform(unordered_map<string, string> hash, string text) {
    istringstream ist(text);
    string word;
    string res = "";
    while (ist >> word) {
        if (hash.find(word) != hash.end()) {
            res += hash[word] + " ";
        }
        else
            res += word + " ";
    }
    return res.substr(0, res.size() - 1);
}

void exam1() noexcept{
    unordered_map<string, string> hash;
    buildMap(hash);

    ifstream fs;
    fs.open("wonder_change_words.txt", fstream::in);
    string text;
    while (getline(fs, text)) {
        string tmp = transform(hash, text);
        cout << tmp << endl;
    }
}


int main() {
    /*
    map<string, vector<string>> mp;
    mp["James"].push_back("Wide");
    append(mp, "James", "Kebi");
    auto it = mp.find("James");
    print(it->second);

    for (string str : mp["James"]) {
        cout << "James " << str << endl;
    }



    cout << mp.erase("James") << endl;*/

    unordered_multimap<char, int> res{ {'a', 92},{'a', 91},{'b', 83}, {'c', 73}, {'a', 99},{'b', 82},{'b', 86} };
    /*for (auto it_be = res.lower_bound('a'); \
        it_be != res.upper_bound('a'); ++it_be) {
        cout << "score = " << it_be->second << endl;
    }

    for (auto pos = res.equal_range('a'); \
        pos.first != pos.second; ++pos.first) {
        cout << "score = " << pos.first->second << endl;
    }

    cout << res.count('a') << endl;
    auto it = res.find('b');
    while (it != res.upper_bound('b')) {
        cout << "score = " << it->second << endl;
        it++;
    }
    int n = res.bucket_count();
    for(int i = 0; i < n; ++i)
        cout << res.bucket_size(i) << endl;
    cout << res.max_bucket_count() << endl;*/

    /*exam1();
    cout << res.load_factor() << endl;

    vector<int> arr{ 1,2,3,4,2,5,2,4,2,1,6,2,8,2 };
    cout << *lower_bound(arr.begin(), arr.end(), 2) << endl;

    if (noexcept(exam1))
        cout << "Ss" << endl;*/

    string str = "asdas";
    vector<string> arr;
    arr.push_back(move(str));
    cout << arr[0] << endl;

    return 0;
}