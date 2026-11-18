/*
 * P13. WAP to implement Huffman Coding and analyze its time complexity.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq)
    {
        this->ch = ch;
        this->freq = freq;
        left = right = nullptr;
    }
};

void printCodes(Node *root, char code[], int top)
{
    if (!root)
        return;

    if (root->left)
    {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }

    if (root->right)
    {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right)
    {
        cout << root->ch << ": ";
        for (int i = 0; i < top; i++)
        {
            cout << code[i];
        }
        cout << endl;
    }
}

void buildHuffmanTree(char data[], int freq[], int size)
{
    Node *nodes[20];
    for (int i = 0; i < size; i++)
    {
        nodes[i] = new Node(data[i], freq[i]);
    }

    Node *root = nullptr;
    for (int count = 0; count < size - 1; count++)
    {
        int min1 = -1, min2 = -1;
        for (int i = 0; i < size; i++)
        {
            if (nodes[i] != nullptr)
            {
                if (min1 == -1 || nodes[i]->freq < nodes[min1]->freq)
                {
                    min2 = min1;
                    min1 = i;
                }
                else if (min2 == -1 || nodes[i]->freq < nodes[min2]->freq)
                {
                    min2 = i;
                }
            }
        }

        Node *top = new Node('$', nodes[min1]->freq + nodes[min2]->freq);
        top->left = nodes[min1];
        top->right = nodes[min2];

        nodes[min1] = top;
        nodes[min2] = nullptr;
        root = top;
    }

    char code[20];
    printCodes(root, code, 0);
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = 6;

    buildHuffmanTree(arr, freq, size);

    return 0;
}
