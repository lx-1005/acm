#ifdef LOCAL
#include "F:/coder/acm/dbg.hpp"
#define INPUT_FILE "F:\coder\acm\Leetcode\input.txt"
#define OUTPUT_FILE "F:\coder\acm\Leetcode\output.txt"
#define ERROR_FILE "F:\coder\acm\Leetcode\error.txt"
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;

#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define REP(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define bitcnt(x) __builtin_popcountll(x) // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))          // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) (__builtin_ctz(x))   // 返回x的二进制末尾0的数量，等价于x的最低位1是第几位
#define bitcnt_headzero(x) (__builtin_clz(x))   // 返回x的二进制开头0的数量
#define SZ(x) (int)(x.size())
#define log2(x) log(x) / log(2)

using VI = std::vector<int>;
using VVI = std::vector<VI>;
using LL = long long;
using VLL = std::vector<LL>;
using VB = std::vector<bool>;
using VVB = std::vector<std::vector<bool>>;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;

// 支持下标访问的ordered_set/ordered_multiset
// 使用:
//      ordered_set<int> s; 或 ordered_multiset<int> s;
//      s.find_by_order(下标); // 返回s[下标]的迭代器
//      s.order_of_key(x); // 返回s中严格<x的元素个数
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T1, typename T2> T1 MOD(T1 a, T2 m){return (T1)(a%m+m)%m;} // 求 a%m
LL gcd(LL a,LL b){return __gcd(a,b);} // a和b的最大公约数
LL lcm(LL a,LL b){return a/__gcd(a, b)*b;} // a和b的最小公倍数
LL quick_power(LL x, LL y, LL mod){LL res=1,cur=x;while(y){if(y&1)res=res*cur%mod;cur=cur*cur%mod;y>>=1;}return (res%mod+mod)%mod;}
inline int combination(int n,int k){int sum=0;if(n==k||k==0){return 1;}else{return combination(n-1,k)+ combination(n-1,k-1);}}
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');return;}

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}



ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ",";
    }
    return "[" + result.substr(0, result.length() - 1) + "]";
}




string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ",";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 1) + "]";
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

string boolTostring(bool input) {
    return input ? "true" : "false";
}



bool stringToBool(string input) {
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input == "true";
}
string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ",";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 1) + "]";
}



TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}


string boolVectorToString(vector<bool> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        bool boolean = list[index];
        result += boolTostring(boolean) + ",";
    }
    return "[" + result.substr(0, result.length() - 1) + "]";
}


string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}


void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}
void prettyPrintLinkedList(ListNode* node) {
    while (node && node->next) {
        cout << node->val << "->";
        node = node->next;
    }

    if (node) {
        cout << node->val << endl;
    } else {
        cout << "Empty LinkedList" << endl;
    }
}