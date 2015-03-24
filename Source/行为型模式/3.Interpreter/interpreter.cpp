/** 	
　　Interpreter模式的实现
  　File		:Interpreter.cpp 
	Author		:singmelody 
	Date		:2012.11.26
*/

#include <map>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

#define FUNCINFO cout<<__FUNCTION__<<endl;
#define SAFE_DELETE(p) if(p!=NULL){ delete p,p=NULL; }

class Expression;
typedef map<string,Expression *> StrExp;

class Expression
{
public:
	Expression() { FUNCINFO; }
	virtual ~Expression() { FUNCINFO; }
	virtual int Interpret(StrExp & strexp) = 0;
};

class Number : public Expression
{
public:
	Number(int number) : m_number(number){ FUNCINFO; }
	~Number() { FUNCINFO; }
	int Interpret(StrExp &strexp)
	{
		FUNCINFO;
		return m_number;
	}
private:
	int m_number;
};

class Plus : public Expression
{
private:
	Expression *m_leftExp;
	Expression *m_rightExp;
public:
	Plus(Expression *left,Expression *right):m_leftExp(left),m_rightExp(right){ FUNCINFO;}
	~Plus() { FUNCINFO;  }

	int Interpret(StrExp & strexp)
	{
		FUNCINFO;
		return m_leftExp->Interpret(strexp) + m_rightExp->Interpret(strexp);
	}
};

class Minus : public Expression
{
private:
	Expression *m_leftExp;
	Expression *m_rightExp;
public:
	Minus(Expression *left,Expression *right):m_leftExp(left),m_rightExp(right){ FUNCINFO;}
	~Minus(){ FUNCINFO; }

	int Interpret(StrExp & strexp)
	{
		FUNCINFO;
		return m_leftExp->Interpret(strexp) - m_rightExp->Interpret(strexp);
	}
};

class Variable : public Expression
{
private:
	string	m_name;
public:
	Variable(string name):m_name(name) { FUNCINFO; }
	~Variable(){ FUNCINFO; }
	
	int Interpret(StrExp &strexp)
	{
		FUNCINFO;
		if(strexp.find(m_name) != strexp.end())
			return strexp[m_name]->Interpret(strexp);
		
		return 0;
	}

};

class Evaluator : public Expression
{
private:
	Expression* m_syntaxTree;
public:
	Evaluator(string & exp)
	{
		FUNCINFO;
		std::stack<Expression *> expressionStack;
		
		for(int i = 0; i < exp.size();++i)
		{
			char token = exp[i];
			if(token == '+')
			{
				Expression *right = expressionStack.top();
				expressionStack.pop();
				Expression *left  = expressionStack.top();
				expressionStack.pop();
				Expression *subExpression = new Plus(left,right);
				expressionStack.push(subExpression);
			}
			else if(token == '-')
			{

				Expression *right = expressionStack.top();
				expressionStack.pop();
				Expression *left  = expressionStack.top();
				expressionStack.pop();
				Expression *subExpression = new Minus(left,right);
				expressionStack.push(subExpression);
			}
			else
			{
				char tmp[2] = {token,'\0'}; 
				string str(tmp);
				expressionStack.push(new Variable(str));
			}
		}
		m_syntaxTree = expressionStack.top();
		expressionStack.pop();
	}

	~Evaluator() { FUNCINFO; }

	int Interpret(StrExp & exp) {
		FUNCINFO;
		return m_syntaxTree->Interpret(exp);
    }
};

int main()
{
	string expression = "wxz-+";
	Expression* sentence = new Evaluator(expression);
	StrExp variables;
	variables["x"] = new Number(5);
	variables["w"] = new Number(10);
	variables["z"] = new Number(42);

	cout<<sentence->Interpret(variables)<<endl;

	for(StrExp::iterator itr = variables.begin();
		itr != variables.end();++itr)
	{
		SAFE_DELETE(itr->second);
	}
	variables.clear();
	SAFE_DELETE(sentence);
	return 0;
}