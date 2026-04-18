#include <iostream>
#include <string>
using namespace std;

// 哈夫曼树结点结构
struct HTNode {
    char ch;
    int weight;
    int parent;
    int lchild;
    int rchild;
};

// 选择两个权值最小的结点
void Select(HTNode HT[], int n, int &s1, int &s2) {
    int min1 = 999999, min2 = 999999;
    s1 = s2 = -1;
    for (int i = 0; i < n; i++) {
        if (HT[i].parent == -1) {
            if (HT[i].weight < min1) {
                min2 = min1;
                s2 = s1;
                min1 = HT[i].weight;
                s1 = i;
            } else if (HT[i].weight < min2) {
                min2 = HT[i].weight;
                s2 = i;
            }
        }
    }
}

// 创建哈夫曼树
void CreateHuffman(HTNode HT[], int n) {
    if (n <= 1) return;
    int m = 2 * n - 1;

    for (int i = 0; i < m; i++) {
        HT[i].parent = -1;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
    }

    for (int i = n; i < m; i++) {
        int s1, s2;
        Select(HT, i, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

// 哈夫曼编码
void HuffmanCoding(HTNode HT[], string HC[], int n) {
    for (int i = 0; i < n; i++) {
        string code = "";
        int p = i;

        int parent = HT[p].parent;
        while (parent != -1) {
            if (HT[parent].lchild == p) {
                code = "0" + code;
            } else {
                code = "1" + code;
            }
            p = parent;
            parent = HT[p].parent;
        }
        HC[i] = code;
    }
}

// 加密：明文转二进制编码
void Encrypt(string str, string HC[], char letters[], int n, string &result) {
    result = "";
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }
        for (int j = 0; j < n; j++) {
            if (c == letters[j]) {
                result = result + HC[j];
                break;
            }
        }
    }
}

// 解密：二进制编码转明文
void Decode(HTNode HT[], string code, int n, char letters[], string &result) {
    result = "";
    int m = 2 * n - 1;
    int p = m - 1;

    for (int i = 0; i < code.length(); i++) {
        if (code[i] == '0') {
            p = HT[p].lchild;
        } else {
            p = HT[p].rchild;
        }
        if (HT[p].lchild == -1 && HT[p].rchild == -1) {
            result = result + letters[p];
            p = m - 1;
        }
    }
}

int main() {
    int n = 26;
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int freq[] = {8, 2, 3, 4, 13, 2, 2, 6, 7, 1, 1, 4, 2, 7, 8, 2, 1, 6, 6, 9, 3, 1, 2, 1, 2, 1};

    int m = 2 * n - 1;
    HTNode *HT = new HTNode[m];
    string *HC = new string[n];

    for (int i = 0; i < n; i++) {
        HT[i].ch = letters[i];
        HT[i].weight = freq[i];
    }

    CreateHuffman(HT, n);
    HuffmanCoding(HT, HC, n);

    cout << "Huffman Code Table:" << endl;
    for (int i = 0; i < n; i++) {
        cout << letters[i] << ": " << HC[i] << endl;
    }

    cout << "\nEnter string to encrypt (lowercase letters only): ";
    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + 32;
        }
    }

    string encrypted;
    Encrypt(input, HC, letters, n, encrypted);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted;
    Decode(HT, encrypted, n, letters, decrypted);
    cout << "Decrypted: " << decrypted << endl;

    delete[] HT;
    delete[] HC;
    return 0;
}