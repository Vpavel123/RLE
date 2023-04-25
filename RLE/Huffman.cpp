#pragma once
#include <iostream>
#include <queue>
#include <unordered_map>
#include <fstream>

//class Huffman {
//public:
//	class Node
//	{
//	public:
//		int a;
//		char c;
//		Node* left, * right;
//
//		Node() { left = right = NULL; }
//
//		Node(Node* L, Node* R)
//		{
//			left = L;
//			right = R;
//			a = L->a + R->a;
//		}
//	};
//
//
//	struct MyCompare
//	{
//		bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
//	};
//
//
//	std::vector<bool> code;
//	std::map<char, std::vector<bool> > table;
//
//	void BuildTable(Node* root)
//	{
//		if (root->left != NULL)
//		{
//			code.push_back(0);
//			BuildTable(root->left);
//		}
//
//		if (root->right != NULL)
//		{
//			code.push_back(1);
//			BuildTable(root->right);
//		}
//
//		if (root->left == NULL && root->right == NULL) table[root->c] = code;
//
//		if (code.empty() != true)
//		{
//			code.pop_back();
//		}
//	}
//
//	void compressFile(std::string input_text, std::string output_text)
//	{
//		std::ifstream f(input_text, std::ios::out | std::ios::binary);
//
//		std::map<char, int> m;
//
//		while (!f.eof())
//		{
//			char c = f.get();
//			m[c]++;
//		}
//
//
//		////// записываем начальные узлы в список list
//
//		std::list<Node*> t;
//		for (std::map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
//		{
//			Node* p = new Node;
//			p->c = itr->first;
//			p->a = itr->second;
//			t.push_back(p);
//		}
//
//
//		//////  создаем дерево		
//
//		while (t.size() != 1)
//		{
//			t.sort(MyCompare());
//
//			Node* SonL = t.front();
//			t.pop_front();
//			Node* SonR = t.front();
//			t.pop_front();
//
//			Node* parent = new Node(SonL, SonR);
//			t.push_back(parent);
//
//		}
//
//		Node* root = t.front();   //root - указатель на вершину дерева
//
//		////// создаем пары 'символ-код':			
//
//		BuildTable(root);
//
//		////// Выводим коды в файл output.txt
//
//		f.clear(); f.seekg(0); // перемещаем указатель снова в начало файла
//
//		std::ofstream g(output_text, std::ios::out | std::ios::binary);
//
//		int count = 0; char buf = 0;
//		while (!f.eof())
//		{
//			char c = f.get();
//			std::vector<bool> x = table[c];
//			for (int n = 0; n < x.size(); n++)
//			{
//				buf = buf | x[n] << (7 - count);
//				count++;
//				if (count == 8) { count = 0;   g << buf; buf = 0; }
//			}
//		}
//
//		f.close();
//		g.close();
//
//		///// считывание из файла output.txt и преобразование обратно
//
//		//std::ifstream F(output_text, std::ios::in | std::ios::binary);
//
//		//setlocale(LC_ALL, "Russian"); // чтоб русские символы отображались в командной строке
//
//		//Node* p = root;
//		//count = 0; char byte;
//		//byte = F.get();
//		//while (!F.eof())
//		//{
//		//	bool b = byte & (1 << (7 - count));
//		//	if (b) p = p->right; else p = p->left;
//		//	if (p->left == NULL && p->right == NULL) { std::cout << p->c; p = root; }
//		//	count++;
//		//	if (count == 8) { count = 0; byte = F.get(); }
//		//}
//
//		//F.close();
//	}
//
//	void DecompressFile(std::string input_text, std::string output_text)
//	{
//		std::ifstream f(input_text, std::ios::in | std::ios::binary);
//		std::ofstream g(output_text, std::ios::out | std::ios::binary);
//
//		std::map<char, int> m;
//
//		while (!f.eof())
//		{
//			char c = f.get();
//			m[c]++;
//		}
//
//
//		////// записываем начальные узлы в список list
//
//		std::list<Node*> t;
//		for (std::map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
//		{
//			Node* p = new Node;
//			p->c = itr->first;
//			p->a = itr->second;
//			t.push_back(p);
//		}
//
//
//		//////  создаем дерево		
//
//		while (t.size() != 1)
//		{
//			t.sort(MyCompare());
//
//			Node* SonL = t.front();
//			t.pop_front();
//			Node* SonR = t.front();
//			t.pop_front();
//
//			Node* parent = new Node(SonL, SonR);
//			t.push_back(parent);
//
//		}
//
//		Node* root = t.front();   //root - указатель на вершину дерева
//
//		////// создаем пары 'символ-код':			
//
//		BuildTable(root);
//
//		////// Выводим коды в файл output.txt
//		f.clear(); f.seekg(0); // перемещаем указатель снова в начало файла
//
//		setlocale(LC_ALL, "Russian"); // чтоб русские символы отображались в командной строке
//		Node* p = root;
//		int count = 0; char byte = 0;
//		byte = f.get();
//		while (!f.eof())
//		{
//			bool b = byte & (1 << (7 - count));
//			if (b)
//			{
//				p = p->right;
//			}
//			else 
//			{
//				p = p->left;
//			}
//
//			if (p->left == NULL && p->right == NULL) 
//			{ 
//				std::cout << p->c; 
//				p = root; 
//			}
//			count++;
//			if (count == 8) 
//			{ 
//				count = 0; 
//				byte = f.get(); 
//			}
//		}
//
//		f.close();
//		g.close();
//	}
//};

class Huffman {
public:
    // Структура для узла дерева Хаффмана
    struct Node
    {
        char ch;
        int freq;
        Node* left, * right;

        Node(char ch, int freq, Node* left, Node* right) : ch(ch), freq(freq), left(left), right(right) {}
    };

    // Сравнение узлов дерева по их частоте
    struct compareNodes
    {
        bool operator()(Node* left, Node* right)
        {
            return left->freq > right->freq;
        }
    };

    // Создание дерева Хаффмана
    Node* buildHuffmanTree(std::string text)
    {
        // Подсчет частоты символов
        std::unordered_map<char, int> freq;
        for (char c : text)
        {
            freq[c]++;
        }

        // Создание очереди с приоритетами
        std::priority_queue<Node*, std::vector<Node*>, compareNodes> pq;
        for (auto pair : freq)
        {
            pq.push(new Node(pair.first, pair.second, nullptr, nullptr));
        }

        // Строим дерево Хаффмана из узлов из очереди
        while (pq.size() > 1)
        {
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();

            pq.push(new Node('\0', left->freq + right->freq, left, right));
        }

        return pq.top();
    }

    // Рекурсивно проходим по дереву и записываем кодированный текст в мапу
    void encode(Node* node, std::string code, std::unordered_map<char, std::string>& encoding)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            encoding[node->ch] = code;
        }

        encode(node->left, code + '0', encoding);
        encode(node->right, code + '1', encoding);
    }

    // Кодируем текст с помощью дерева Хаффмана и возвращаем строку с битовой записью
    std::string encodeText(std::string text, std::unordered_map<char, std::string> encoding)
    {
        std::string result = "";
        for (char c : text)
        {
            result += encoding[c];
        }

        return result;
    }

    // Раскодируем текст, используя дерево Хаффмана
    std::string decodeText(std::string encodedText, Node* root)
    {
        std::string result = "";
        Node* node = root;
        for (char bit : encodedText)
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                result += node->ch;
                node = root;
            }

            if (bit == '0')
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            result += node->ch;
        }

        return result;
    }

    // Кодировка файла с помощью алгоритма Хаффмана
    void encodeFile(std::string inputFile, std::string outputFile)
    {
        // Читаем файл
        std::ifstream in(inputFile, std::ios::binary);
        std::string text((std::istreambuf_iterator<char>(in)), (std::istreambuf_iterator<char>()));
        in.close();

        // Создание дерева Хаффмана и таблицы кодировки
        Node* root = buildHuffmanTree(text);
        std::unordered_map<char, std::string> encoding;
        encode(root, "", encoding);

        // Кодируем текст и записываем битовую запись в файл
        std::string encodedText = encodeText(text, encoding);
        std::ofstream out(outputFile, std::ios::out | std::ios::binary);
        out.write((char*)&encoding, sizeof(encoding));
        out.write((char*)&encodedText[0], encodedText.size());
        out.close();
    }

    // Раскодировка файла с помощью алгоритма Хаффмана
    void decodeFile(std::string inputFile, std::string outputFile)
    {
        // Читаем файл
        std::ifstream in(inputFile, std::ios::binary);
        std::unordered_map<char, std::string> encoding;
        in.read((char*)&encoding, sizeof(encoding));

        // Создаем
        // дерево Хаффмана из таблицы кодировки
        Node* root = new Node('\0', 0, nullptr, nullptr);
        for (auto pair : encoding)
        {
            Node* node = root;
            for (char bit : pair.second)
            {
                if (bit == '0')
                {
                    if (node->left == nullptr)
                    {
                        node->left = new Node('\0', 0, nullptr, nullptr);
                    }
                    node = node->left;
                }
                else
                {
                    if (node->right == nullptr)
                    {
                        node->right = new Node('\0', 0, nullptr, nullptr);
                    }
                    node = node->right;
                }
            }
            node->ch = pair.first;
        }

        // Раскодируем битовую запись и записываем раскодированный текст в файл
        std::string encodedText((std::istreambuf_iterator<char>(in)), (std::istreambuf_iterator<char>()));
        in.close();
        std::string decodedText = decodeText(encodedText, root);
        std::ofstream out(outputFile, std::ios::out | std::ios::binary);
        out.write((char*)&decodedText[0], decodedText.size());
        out.close();
    }
};