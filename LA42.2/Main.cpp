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
				rpnS.push((int)(uIn - 48));
				rpnQ.push(uIn);
			}
			int a = 0, b = 0;
			switch (uIn) {
			case '+':
				a = rpnS.top();
				rpnS.pop();
				b = rpnS.top();
				rpnS.pop();
				rpnS.push(a + b);
				rpnQ.push(uIn);
				break;
			case '-':
				a = rpnS.top();
				rpnS.pop();
				b = rpnS.top();
				rpnS.pop();
				rpnS.push(b - a);
				rpnQ.push(uIn);
				break;
			case '*':
				a = rpnS.top();
				rpnS.pop();
				b = rpnS.top();
				rpnS.pop();
				rpnS.push(a * b);
				rpnQ.push(uIn);
				break;
			case '/':
				a = rpnS.top();
				rpnS.pop();
				b = rpnS.top();
				rpnS.pop();
				rpnS.push(b / a);
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
