// Crispin Bernier, chb2ab, lab01, postfixCalculator.cpp, 9/15/14

#include <iostream> 
#include <stack>
#include "postfixCalculator.h"

using namespace std;

postfixCalculator::postfixCalculator() {
}

void postfixCalculator::addNumber(int x) {
st.push(x);
}

int postfixCalculator::getNumber() {
return st.top();
}

void postfixCalculator::print() {
cout << st.top() << endl;
}

int postfixCalculator::add() {
int lval, rval, result;
rval = st.top();
st.pop();
lval = st.top();
st.pop();
result = lval + rval;
st.push(result);
return result;
}

int postfixCalculator::subtract() {
int lval, rval, result;
rval = st.top();
st.pop();
lval = st.top();
st.pop();
result = lval - rval;
st.push(result);
return result;
}

int postfixCalculator::multiply() {
int lval, rval, result;
rval = st.top();
st.pop();
lval = st.top();
st.pop();
result = lval * rval;
st.push(result);
return result;
}

int postfixCalculator::divide() {
int lval, rval, result;
rval = st.top();
st.pop();
lval = st.top();
st.pop();
result = lval / rval;
st.push(result);
return result;
}

int postfixCalculator::negate() {
int val = st.top();
st.pop();
val = val * (-1);
st.push(val);
return val;
}

void postfixCalculator::empty() {
while (!(st.empty()))
    st.pop();
}
