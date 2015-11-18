/* The basic idea is to demonstrate Observer pattern.
 * TextWindow is an observer for an TextContainer. U menja UserClass is an observer for an LimitedCounter
 * TextContainer is a subject that notifies the TextWindow every time the TextContainer is modified.
U menja LimitedCounter is a subject that notifies the UserClass every time the LimitedCounter is modified.
 * As a result the TextWindow displays the last strings from the container in the TextWindow.
As a result UserClass displays the message that limit has been reached.
 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract interface of Subject. This only specifies the functions
// that are necessary to implement in the subject.
class Observer;
class Subject {
public:
	virtual void Attach(Observer *o) = 0; // Set 
	virtual void Detach(Observer *o) = 0;
	virtual void Notify() = 0;
};

// Abstract interface of Observer
class Observer {
public:
	virtual void Update() = 0; 
};

class TextContainer;
class TextWindow: public Observer {
public:
	TextWindow(int rows0, TextContainer *tc = 0);
	void displayWindow();
	void setSubject(TextContainer *tc); // Could be done in constr.
	//For observer pattern
	void Update();  // Handle Notification
private:
	int rows;  // Window size in rows
	TextContainer *tc;
};

class TextContainer: public Subject {
public:
	TextContainer();
	void addString(const string& s);
	const string& getString(int orderNo);
	int getSize();
	void display();
	// From the Subject
	void Attach(Observer *o);
	void Detach(Observer *o);
	void Notify();
private:
	vector<string> strings;
	//for observer pattern
	vector<Observer*> observers;
};

void main() {
	TextContainer tc; //limcounter
	TextWindow tw(3); //observer

	tc.Attach(&tw);
	tw.setSubject(&tc);

	tc.addString("aaa");  
	tc.addString("bbbbb"); 
	tc.addString("ccccccc");
	tc.addString("ddddddddd");
	tc.addString("eeeeeeeeeeee");
}

TextContainer::TextContainer() { }

void TextContainer::addString(const string& s) {
	strings.push_back(s);
	Notify();
}

const string&TextContainer::getString(int orderNo) { return strings[orderNo]; }

int TextContainer::getSize()  { return strings.size(); }

void TextContainer::Attach(Observer *o) { observers.push_back(o); }

// Detach is not implemented
void TextContainer::Detach(Observer *o) { }

void TextContainer::Notify() {
	for (int i = 0; i < observers.size() ; i++)
		observers[i]->Update();
}

TextWindow::TextWindow(int rows0, TextContainer *tc) { rows = rows0; }

void TextWindow::displayWindow() {
	int firstRow;

	cout << "----------------" << endl;
	if (tc->getSize() < rows) {
		for (int i = 0; i < tc->getSize() ; i++)
			cout << tc->getString(i) << endl;
	}
	else {
		firstRow = tc->getSize() - rows;
		for (int i = 0; i < rows ; i++)
			cout << tc->getString(firstRow + i) << endl;
	}
	cout << "----------------" << endl;
}

void TextWindow::setSubject(TextContainer *tc) {  this->tc = tc ;}

void TextWindow::Update() { displayWindow(); }
*/