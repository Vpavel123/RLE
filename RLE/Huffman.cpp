#pragma once
#include <vector>
#include <map>
#include <fstream>
#include <list>

class Huffman
{
public:
    class Node
    {
    public:
        int a;
        char c;
        Node* left, * right;

        Node() { left = right = nullptr; }

        Node(Node* L, Node* R)
        {
            left = L;
            right = R;
            a = L->a + R->a;
        }
    };


    struct MyCompare
    {
        bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
    };


    std::vector<bool> code;
    std::map<char, std::vector<bool> > table;

    void BuildTable(Node* root)
    {
        if (root->left != NULL)
        {
            code.push_back(0);
            BuildTable(root->left);
        }

        if (root->right != NULL)
        {
            code.push_back(1);
            BuildTable(root->right);
        }

        if (root->c) table[root->c] = code;

        code.pop_back();
    }

    void Huffman_compress_file(std::string input_file_name, std::string output_file_name) 
    {
        std::ifstream f(input_file_name);

        std::map<char, int> m;

        while (!f.eof())
        {
            char c = f.get();
            m[c]++;
        }

        ////// записываем начальные узлы в список list

        std::list<Node*> t;
        for (std::map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
        {
            Node* p = new Node;
            p->c = itr->first;
            p->a = itr->second;
            t.push_back(p);
        }

        //////  создаем дерево     

        while (t.size() != 1)
        {
            t.sort(MyCompare());

            Node* SonL = t.front();
            t.pop_front();
            Node* SonR = t.front();
            t.pop_front();

            Node* parent = new Node(SonL, SonR);
            t.push_back(parent);

        }

        Node* root = t.front();   //root - указатель на вершину дерева

        ////// создаем пары 'символ-код':           

        BuildTable(root);

        f.clear(); f.seekg(0); // перемещаем указатель снова в начало файла

        std::ofstream g(output_file_name, std::ios::out | std::ios::binary);

        int count = 0; char buf = 0;
        while (!f.eof())
        {
            char c = f.get();
            std::vector<bool> x = table[c];
            for (int n = 0; n < x.size(); n++)
            {
                buf = buf | x[n] << (7 - count);
                count++;
                if (count == 8) { count = 0;   g << buf; buf = 0; }
            }
        }

        f.close();
        g.close();
    }

    void Huffman_Decompress(std::string input_file_name, std::string output_file_name)
    {
       
    }
};


//int main(int argc, char* argv[])
//{
//    ////// считаем частоты символов   
//
//
//    ///// считывание из файла output.txt и преобразование обратно
//
//    std::ifstream F("output.txt", std::ios::in | std::ios::binary);
//
//    setlocale(LC_ALL, "Russian"); // чтоб русские символы отображались в командной строке
//
//    Node* p = root;
//    count = 0; char byte;
//    byte = F.get();
//    while (!F.eof())
//    {
//        bool b = byte & (1 << (7 - count));
//        if (b) p = p->right; else p = p->left;
//        if (p->left == NULL && p->right == NULL) { std::cout << p->c; p = root; }
//        count++;
//        if (count == 8) { count = 0; byte = F.get(); }
//    }
//
//    F.close();
//
//    return 0;
//}
