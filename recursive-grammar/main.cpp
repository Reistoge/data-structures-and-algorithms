#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
vector<string> S;
vector<int> maxDepth;
int MAX_STRING_SIZE = 50;
void expandGrammar(const string &current, vector<string> &results, int depth, int maxD, map<pair<string, int>, bool> &memo)
{
    if (depth > maxD)
    {
        return;
    }
    
    // Prevent strings from growing too large (this prevents infinite expansion)
    if (current.length() > MAX_STRING_SIZE) // Reasonable limit
    {
        return;
    }
    
    // Memoization to prevent revisiting same state
    pair<string, int> state = {current, depth};
    if (memo.count(state))
    {
        return;
    }
    memo[state] = true;

    // Check if current string has any non-terminals
    bool hasNonTerminal = false;
    for (char c : current)
    {
        if (isupper(c))
        {
            hasNonTerminal = true;
            break;
        }
    }

    // If no non-terminals, add to results
    if (!hasNonTerminal)
    {
        results.push_back(current);
        return;
    }

    // Find first non-terminal and expand it
    for (int i = 0; i < current.size(); i++)
    {
        if (isupper(current[i]))
        {
            char nonTerminal = current[i];

            // Check if this non-terminal has any productions
            if (grammar.find(nonTerminal) == grammar.end())
            {
                continue;
            }

            // For each production rule of this non-terminal
            for (const string &production : grammar[nonTerminal])
            {
                string newString = current.substr(0, i) + production + current.substr(i + 1);
                expandGrammar(newString, results, depth + 1, maxD, memo);
            }
            break; // Only expand the first non-terminal found
        }
    }
}

int main()
{
    int n;
    cin >> n;

    S.resize(n);
    maxDepth.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> S[i] >> maxDepth[i];
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        char nonTerminal;
        int numProductions;
        cin >> nonTerminal >> numProductions;

        for (int j = 0; j < numProductions; j++)
        {
            string production;
            cin >> production;
            grammar[nonTerminal].push_back(production);
        }
    }

    // Process each starting string
    for (int i = 0; i < n; i++)
    {
        vector<string> results;
        map<pair<string, int>, bool> memo;
        expandGrammar(S[i], results, 0, maxDepth[i], memo);

        cout << "Results for " << S[i] << ":" << endl;
        for (const string &result : results)
        {
            cout << result << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Probar:
1
S 3
0S 1S 0
A 2
0 1
B 1
01
 

1
S 5
2
S 3
(S) () SS
A 2
a b



3
ABC 3
XYZ 2
PQR 4
6
A 2
aB bC
B 2
bA c
C 2
cA d
X 2
xY yZ
Y 2
yX z
Z 2
zX w



1
S 6
4
S 2
ASB ε
A 2
aA a
B 2
bB b
C 1
c


2
START 4
EXPR 3
5
START 2
EXPR END
EXPR 4
NUM OP EXPR VAR
NUM 3
1 2 3
OP 3
+ - *
VAR 3
x y z
END 1
;


1
LIST 5
3
LIST 3
ITEM ,LIST ITEM ε
ITEM 4
a b c d
COMMA 1
,
*/