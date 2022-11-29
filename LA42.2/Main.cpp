#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	char uIn = ' ';
	stack<int> rpnS = stack<int>();
	queue<char> rpnQ = queue<char>();

	while (uIn != 'l') {
		cout << "\n\nInput a single integer or an operation (+ - * /)" << endl;
		uIn = ' ';
		while (tolower(uIn) != 'q') {
			cin >> uIn;
			if (isdigit(uIn)) {
				rpnS.push(((int)uIn) - 48);
				rpnQ.push(uIn);
			}

			switch (uIn) {
			case '+':
				rpnS.push(rpnS.top() + rpnS.top());
				rpnQ.push(uIn);
				break;
			case '-':
				rpnS.push(rpnS.top() - rpnS.top());
				rpnQ.push(uIn);
				break;
			case '*':
				rpnS.push(rpnS.top() * rpnS.top());
				rpnQ.push(uIn);
				break;
			case '/':
				rpnS.push(rpnS.top() / rpnS.top());
				rpnQ.push(uIn);
				break;
			case 'l':
				return 1;
			}
		}
		rpnQ.push('=');

		while (!rpnQ.empty()) {
			cout << rpnQ.front() << " ";
			rpnQ.pop();
		}
		cout << rpnS.top() << endl;

		rpnS = stack<int>();
		rpnQ = queue<char>();
	}
}
