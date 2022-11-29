#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	char uIn = ' ';
	stack<int> rpnS = stack<int>();
	queue<int> rpnQ = queue<int>();

	while (uIn != 'l') {
		cout << "Input a single integer or an operation (+ - * /)" << endl;
		while (tolower(uIn) != 'q') {
			cin >> uIn;
			if (isdigit(uIn)) {
				rpnS.push(uIn);
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
		}
		cout << rpnS.top();

		rpnS = stack<int>();
		rpnQ = queue<int>();
	}
}