#include <fstream>

#include <iostream>

#include <string>

using namespace std;

class Node
{

public:
    string data = "";

    Node *par;

    Node *left;

    Node *right;

    Node() : data(""), par(nullptr), left(nullptr), right(nullptr) {}
};

class BST
{

public:
    Node *v;

    BST() { v = nullptr; }

    Node *parent() const
    {

        if (v == nullptr)

            return nullptr;

        return v->par;
    }

    Node *left() const { return v->left; }

    Node *right() const { return v->right; }

    bool isRoot() const
    {

        if (v == nullptr)

            return false;

        return v->par == nullptr;
    }

    bool isExternal() const
    {

        if (v == nullptr)

            return false;

        return v->left == nullptr && v->right == nullptr;
    }

    bool isInternal() const
    {

        if (v == nullptr)

            return false;

        return v->left != nullptr || v->right != nullptr;
    }

    string &data() const { return v->data; }

    void addNode(const string &data)
    {

        Node *newNode = new Node();

        // newNode->data = data;
        newNode->data.append(data);

        newNode->par = nullptr;

        newNode->left = nullptr;

        newNode->right = nullptr;

        if (isRoot())
        {

            v = newNode;

            return;
        }
        else
        {

            Node *current = v;

            while (true)
            {

                if (data < current->data)
                {

                    if (current->left == nullptr)
                    {

                        current->left = newNode;

                        newNode->par = current;

                        return;
                    }
                    else
                    {

                        current = current->left;
                    }
                }
                else if (data > current->data)
                {

                    if (current->right == nullptr)
                    {

                        current->right = newNode;

                        newNode->par = current;

                        return;
                    }
                    else
                    {

                        current = current->right;
                    }
                }
                else
                {

                    delete newNode;

                    return;
                }
            }
        }
    }

    void printAncestors(Node *node)
    {

        if (node == nullptr)

            return;

        cout << node->data << endl;

        printAncestors(node->par);
    }

    void clear(Node *node)
    {

        if (node == nullptr)

            return;

        clear(node->left);

        clear(node->right);

        if (node->par != nullptr)
        {

            if (node->par->left == node)

                node->par->left = nullptr;

            else if (node->par->right == node)

                node->par->right = nullptr;
        }

        delete node;
    }

    Node *getRoot() const { return v; }
};

int main()
{

    BST *inputTree = new BST();

    BST *outputTree = nullptr;

    for (int i = 1; i <= 1; i++)
    {

        string input = "inputs/input." + to_string(i) + ".txt";

        string output = "outputs/output." + to_string(i) + ".txt";

        ifstream inputFile(input);

        if (!inputFile)
        {

            cerr << "Failed to open input file: " << input << endl;

            continue;
        }

        ////////////////////////// this part! //////////////////////////

        string line;

        int lineNumber = 0;

        while (getline(inputFile, line))
        {

            lineNumber++;

            cout << lineNumber << endl;

            if (lineNumber >= 4)
            {

                cout << "s";

                inputTree->addNode(line);
            }
        }

        ////////////////////////// this part! //////////////////////////

        inputFile.close();

        inputTree->printAncestors(inputTree->getRoot());

        inputTree->clear(inputTree->getRoot());
    }

    delete inputTree;

    delete outputTree;

    return 0;
}