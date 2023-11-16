//2019203102 유지성

#include <cctype>     
#include <cstdlib>    
#include <cstring>    
#include <iostream>   
#include <stack>      
#include <string>
#include <fstream>
using namespace std;

char read_and_evaluate(string ins);
void evaluate(stack<char>& numbers);
void read_file(char opAt[][3], char opHash[][3], char opAnd[][3]);

int parenthesisNum = 0;
int braceNum = 0;
int bracketNum = 0;

int main()
{
	char answer;
	string input;

	cout << "수식을 입력하시오:" << endl;
	while (true)
	{
		cin >> input;

		if (input == "EOI")
		{
			break;
		}

		answer = read_and_evaluate(input);

		if (parenthesisNum == 0 && braceNum == 0 && bracketNum == 0)
			cout << "결과: " << answer << endl;
		else
			cout << "Error!\n";
	}
	return EXIT_SUCCESS;
}


char read_and_evaluate(string ins)
{
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';
	const char LEFT_BRACE = '{';
	const char RIGHT_BRACE = '}';
	const char LEFT_BRACKET = '[';
	const char RIGHT_BRACKET = ']';

	stack<char> numbers;
	stack<char> operations;

	parenthesisNum = 0;
	braceNum = 0;
	bracketNum = 0;

	char number;
	char symbol;

	while (!ins.empty())
	{
		if (strchr("abc", ins.front()) != NULL)
		{
			number = ins.front();
			ins.erase(0, 1);
			numbers.push(number);
		}
		else if (strchr("@#&", ins.front()) != NULL)
		{
			symbol = ins.front();
			ins.erase(0, 1);

			while (!operations.empty() && operations.top() != LEFT_PARENTHESIS &&
				operations.top() != LEFT_BRACE && operations.top() != LEFT_BRACKET && symbol != '&')
			{
				numbers.push(operations.top());
				operations.pop();
			}

			operations.push(symbol);
		}
		else if (ins.front() == LEFT_PARENTHESIS || ins.front() == LEFT_BRACE || ins.front() == LEFT_BRACKET)
		{
			symbol = ins.front();
			ins.erase(0, 1);
			switch (symbol)
			{
			case LEFT_PARENTHESIS: parenthesisNum++;
				break;
			case LEFT_BRACE: braceNum++;
				break;
			case LEFT_BRACKET: bracketNum++;
				break;
			}
			operations.push(symbol);
		}

		else if (ins.front() == RIGHT_PARENTHESIS)
		{
			ins.erase(0, 1);

			//괄호 체크
			if (parenthesisNum == 0)
			{
				parenthesisNum = -1;
				return 888;
			}

			while (operations.top() != LEFT_PARENTHESIS)
			{
				symbol = operations.top();

				if (symbol == LEFT_BRACE || symbol == LEFT_BRACKET)
				{
					parenthesisNum = -1;
					return 888;
				}

				numbers.push(symbol);
				operations.pop();
			}

			parenthesisNum--;
			operations.pop();
		}
		else if (ins.front() == RIGHT_BRACE)
		{
			ins.erase(0, 1);

			//괄호 체크
			if (braceNum == 0)
			{
				braceNum = -1;
				return 888;
			}

			while (operations.top() != LEFT_BRACE)
			{
				symbol = operations.top();

				if (symbol == LEFT_PARENTHESIS || symbol == LEFT_BRACKET)
				{
					braceNum = -1;
					return 888;
				}

				numbers.push(symbol);
				operations.pop();
			}

			braceNum--;
			operations.pop();
		}
		else if (ins.front() == RIGHT_BRACKET)
		{
			ins.erase(0, 1);

			//괄호 체크
			if (bracketNum == 0)
			{
				bracketNum = -1;
				return 888;
			}

			while (operations.top() != LEFT_BRACKET)
			{
				symbol = operations.top();

				if (symbol == LEFT_PARENTHESIS || symbol == LEFT_BRACE)
				{
					bracketNum = -1;
					return 888;
				}

				numbers.push(symbol);
				operations.pop();
			}

			bracketNum--;
			operations.pop();
		}

		else
			ins.erase(0, 1);
	}

	while (!operations.empty())
	{
		numbers.push(operations.top());
		operations.pop();
	}

	evaluate(numbers);

	return numbers.top();
}

void evaluate(stack<char>& numbers)
{
	char opAt[3][3];
	char opHash[3][3];
	char opAnd[3][3];

	read_file(opAt, opHash, opAnd);

	stack<char> rNumbers;
	while (!numbers.empty())
	{
		rNumbers.push(numbers.top());
		numbers.pop();
	}

	while (!rNumbers.empty())
	{
		if (rNumbers.top() != '\0' && strchr("@#&", rNumbers.top()) != NULL)
		{
			// operator일 때
			char n1 = numbers.top() - 'a';
			numbers.pop();
			char n2 = numbers.top() - 'a';
			numbers.pop();

			char op = rNumbers.top();
			rNumbers.pop();

			switch (op)
			{
			case '@':
				rNumbers.push(opAt[n2][n1]);
				break;
			case '#':
				rNumbers.push(opHash[n2][n1]);
				break;
			case '&':
				rNumbers.push(opAnd[n2][n1]);
				break;
			}
		}

		else
		{
			// 알파벳일 때
			numbers.push(rNumbers.top());
			rNumbers.pop();
		}
	}
}

void read_file(char opAt[][3], char opHash[][3], char opAnd[][3])
{
	ifstream file;
	file.open("operations.txt");

	char ch;

	while (file.peek() != EOF)
	{
		file >> ch;

		if (ch == '@')
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					file >> opAt[i][j];
		}
		else if (ch == '#')
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					file >> opHash[i][j];
		}
		else if (ch == '&')
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					file >> opAnd[i][j];
		}
	}

	file.close();
}