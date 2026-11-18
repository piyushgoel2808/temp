/*
 * P13. WAP to implement Huffman Coding and analyze its time complexity.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq)
    {
        this->ch = ch;
        this->freq = freq;
        left = right = NULL;
    }
};

void printCodes(Node *root, char code[], int top)
{
    int i;
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
        for (i = 0; i < top; i++)
        {
            cout << code[i];
        }
        cout << "\n";
    }
}

void buildHuffmanTree(char data[], int freq[], int size)
{
    Node *nodes[20];
    Node *root = NULL;
    Node *top;
    int count, i, min1, min2;
    char code[20];

    for (i = 0; i < size; i++)
    {
        nodes[i] = new Node(data[i], freq[i]);
    }

    for (count = 0; count < size - 1; count++)
    {
        min1 = -1;
        min2 = -1;
        for (i = 0; i < size; i++)
        {
            if (nodes[i] != NULL)
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

        top = new Node('$', nodes[min1]->freq + nodes[min2]->freq);
        top->left = nodes[min1];
        top->right = nodes[min2];

        nodes[min1] = top;
        nodes[min2] = NULL;
        root = top;
    }

    printCodes(root, code, 0);
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = 6;

    clrscr();

    buildHuffmanTree(arr, freq, size);

    getch();
    return 0;
}
