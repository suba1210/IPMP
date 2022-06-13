struct Node
{
    Node *links[2];

    bool containsKey(int num)
    {
        return links[num] != NULL;
    }

    Node *get(int num)
    {
        return links[num];
    }

    void put(int num, Node *node)
    {
        links[num] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution
{
public:
    int max_xor(int arr[], int n)
    {
        int maxVal = 0;
        Trie trieObj;

        trieObj.insert(arr[0]);
        for (int i = 1; i < n; i++)
        {
            maxVal = max(maxVal, trieObj.findMax(arr[i]));
            trieObj.insert(arr[i]);
        }

        return maxVal;
    }
};