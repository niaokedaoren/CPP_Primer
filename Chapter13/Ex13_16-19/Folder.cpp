#include "Folder.h"
#include <iostream>

using namespace std;

Folder::Folder(const Folder &other): 
	folderName(other.folderName+"_copy"), messages(other.messages)
{
	putFldrInMsgSet(other.messages);
}

Folder& Folder::operator=(const Folder &other)
{
	if (this != &other)
	{
		removeFldrFromMsgSet();
		messages = other.messages;
		putFldrInMsgSet(other.messages);
	}

	return *this;
}

Folder::~Folder()
{
	removeFldrFromMsgSet();
}

void Folder::addMsg(Message *msgPtr)
{
	messages.insert(msgPtr);
	msgPtr->addFldr(this);
}

void Folder::remMsg(Message *msgPtr)
{
	messages.erase(msgPtr);
	msgPtr->remFldr(this);
}

void Folder::print() const
{
	cout << "Folder Name: " << folderName << endl;
	for (auto itr=messages.begin(); itr!=messages.end(); itr++)
	{
		cout << "\t" << (*itr)->getContents() << endl;
	}
}

string Folder::getFldrName() const
{
	return folderName;
}

void Folder::putFldrInMsgSet(const unordered_set<Message*> &other)
{
	for (auto itr=other.cbegin(); itr!=other.cend(); itr++)
	{
		(*itr)->addFldr(this);
	}
}

void Folder::removeFldrFromMsgSet()
{
	for (auto itr=messages.begin(); itr!=messages.end(); itr++)
	{
		(*itr)->remFldr(this);
	}

	messages.clear();
}
