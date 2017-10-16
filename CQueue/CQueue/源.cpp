/*用两个栈实现一个队列*/
template <typename T> class CQueue //类模板 
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& element){
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead(){
	while (!stack1.empty()){
			//stack2.push(stack1.pop());
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	if (stack2.empty())
		throw new exception("queue is empty");

	T head = stack2.top();
	stack2.pop();
	
	return head;
}